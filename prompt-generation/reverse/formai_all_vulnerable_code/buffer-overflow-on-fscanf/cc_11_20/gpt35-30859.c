//FormAI DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open the file.\n");
        exit(EXIT_FAILURE);
    }

    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int counts[MAX_WORDS] = {0};
    int num_words = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        num_words++;
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        strcpy(words[num_words - 1], word);
        counts[num_words - 1]++;
        while (fscanf(fp, "%s", word) != EOF) {
            num_words++;
            int j;
            for (j = 0; j < strlen(word); j++) {
                word[j] = tolower(word[j]);
            }
            int found = 0;
            int k;
            for (k = 0; k < num_words; k++) {
                if (strcmp(words[k], word) == 0) {
                    counts[k]++;
                    found = 1;
                }
            }
            if (!found) {
                strcpy(words[num_words - 1], word);
                counts[num_words - 1]++;
            }
            if (num_words == MAX_WORDS) {
                break;
            }
        }
    }

    printf("File contains %d words.\n", num_words);

    int i;
    for (i = 0; i < num_words; i++) {
        if (counts[i] > 0) {
            printf("%s: %d\n", words[i], counts[i]);
        }
    }

    fclose(fp);
    return 0;
}