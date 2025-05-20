//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *file;
    char line[1000];
    char *token;
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    printf("Enter filename: ");
    scanf("%s", line);

    file = fopen(line, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Too many words.\n");
                exit(1);
            }
            if (strlen(token) > MAX_WORD_LENGTH) {
                printf("Word too long.\n");
                exit(1);
            }
            for (i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                strcpy(words[numWords].word, token);
                words[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    printf("Word\tCount\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}