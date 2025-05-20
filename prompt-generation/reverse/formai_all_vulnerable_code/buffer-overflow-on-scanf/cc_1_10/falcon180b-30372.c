//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    FILE *file;
    char filename[50];
    char word[MAX_WORD_LEN];
    char line[100];
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            for (i = 0; i < strlen(token); i++) {
                if (!isalpha(token[i])) {
                    token[i] = '\0';
                    break;
                }
            }
            int j;
            for (j = 0; j < numWords; j++) {
                if (strcmp(words[j].word, token) == 0) {
                    words[j].count++;
                    break;
                }
            }
            if (j == numWords) {
                strcpy(words[numWords].word, token);
                words[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(file);

    return 0;
}