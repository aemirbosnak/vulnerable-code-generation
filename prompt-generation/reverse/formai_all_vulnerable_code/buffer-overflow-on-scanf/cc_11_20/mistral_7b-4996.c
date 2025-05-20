//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *word;
    int count;
} Word;

int main() {
    FILE *fp;
    char filename[100];
    char buffer[1024];
    int len;
    Word words[1000];
    int i, j, k, word_count = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        len = strlen(buffer);
        for (i = 0; i < len; i++) {
            buffer[i] = tolower(buffer[i]);
        }
        for (i = 0, j = 0; i < len; i++) {
            if (buffer[i] != ' ' && buffer[i] != '\t' && buffer[i] != '\n') {
                if (j == 0) {
                    words[word_count].word = malloc(sizeof(char) * (i - j + 2));
                    strncpy(words[word_count].word, buffer + j, i - j);
                    words[word_count].word[i - j + 1] = '\0';
                    words[word_count].count = 1;
                    word_count++;
                    if (word_count >= 1000) {
                        printf("Max number of words reached.\n");
                        break;
                    }
                }
                if (strcmp(words[word_count - 1].word, buffer + i) == 0) {
                    words[word_count - 1].count++;
                }
                j = i;
            }
        }
    }

    fclose(fp);

    printf("\nWord count:\n");
    for (i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    for (i = 0; i < word_count; i++) {
        free(words[i].word);
    }

    return 0;
}