//FormAI DATASET v1.0 Category: Text Summarizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter your text:\n");
    fgets(input, 1000, stdin);

    int size = strlen(input);
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (input[i] == '.') {
            count++;
        }
    }

    if (count == 0) {
        printf("Error: no sentences found in input.\n");
        return 1;
    }

    int n = 0;
    printf("How many sentences do you want in your summary?\n");
    scanf("%d", &n);
    getchar();

    if (n < 1 || n > count) {
        printf("Error: invalid number of sentences.\n");
        return 1;
    }

    char *sentences[100];
    char *temp = strtok(input, ".");
    int index = 0;

    while (temp != NULL) {
        sentences[index] = temp;
        index++;
        temp = strtok(NULL, ".");
    }

    int scores[index];
    for (int i = 0; i < index; i++) {
        scores[i] = 0;
        for (int j = 0; j < strlen(sentences[i]); j++) {
            if (sentences[i][j] == ' ') {
                scores[i]++;
            }
        }
    }

    int summary_indexes[n];
    for (int i = 0; i < n; i++) {
        int max = 0;
        int max_index = -1;
        for (int j = 0; j < index; j++) {
            if (scores[j] > max) {
                max = scores[j];
                max_index = j;
            }
        }
        scores[max_index] = -1;
        summary_indexes[i] = max_index;
    }

    printf("Summary:\n");
    for (int i = 0; i < n; i++) {
        printf("%s.\n", sentences[summary_indexes[i]]);
    }

    return 0;
}