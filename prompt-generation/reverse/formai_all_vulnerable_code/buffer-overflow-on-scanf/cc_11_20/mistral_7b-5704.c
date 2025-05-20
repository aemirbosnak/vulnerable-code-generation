//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int main() {
    FILE *file;
    char filename[100];
    char line[1024];
    char word[MAX_WORD_LENGTH];
    int i, j;
    Word words[MAX_NUM_WORDS];

    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    i = j = 0;

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " .,\n\t");

        while (token != NULL) {
            for (; i < MAX_NUM_WORDS && strcmp(words[i].word, token); i++);

            if (i == MAX_NUM_WORDS) {
                if (i > 0 && strcmp(words[i - 1].word, token) == 0) {
                    words[i - 1].count++;
                } else {
                    strcpy(words[i].word, token);
                    words[i].count = 1;
                    i++;
                }
            }

            if (strlen(token) > MAX_WORD_LENGTH) {
                printf("Warning: word '%s' is too long.\n", token);
                break;
            }

            token = strtok(NULL, " .,\n\t");
        }
    }

    fclose(file);

    printf("\nWord frequencies:\n");

    for (i = 0; i < MAX_NUM_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s\t%d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}