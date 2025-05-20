//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define MAX_SENTENCES 10

int main() {
    char file_name[MAX_LEN];
    char buffer[MAX_LEN];
    FILE *file;
    int i, j, sentence_count = 0, sentence_length = 0;
    char *sentence_buffer[MAX_SENTENCES];
    char *summary_buffer[MAX_SENTENCES];

    printf("Enter the name of the text file: ");
    fgets(file_name, MAX_LEN, stdin);

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    while (fgets(buffer, MAX_LEN, file)) {
        sentence_count++;

        if (sentence_count == 1) {
            j = 0;
            while (buffer[j]!= '\n' && j < MAX_LEN) {
                j++;
            }
            sentence_length = j;
        } else if (sentence_count <= MAX_SENTENCES) {
            sentence_buffer[sentence_count - 1] = (char *)malloc(sentence_length * sizeof(char));
            strncpy(sentence_buffer[sentence_count - 1], buffer, sentence_length);
        }
    }

    for (i = 0; i < sentence_count; i++) {
        summary_buffer[i] = (char *)malloc(sentence_length * sizeof(char));
        j = 0;
        while (sentence_buffer[i][j]!= '\n' && j < sentence_length) {
            summary_buffer[i][j] = sentence_buffer[i][j];
            j++;
        }
        summary_buffer[i][j] = '\0';
    }

    printf("Summary:\n");
    for (i = 0; i < sentence_count; i++) {
        printf("%s\n", summary_buffer[i]);
    }

    fclose(file);

    return 0;
}