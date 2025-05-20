//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    WordCount words[MAX_NUM_WORDS] = {{'\0'}};
    int numWords = 0;

    printf("Enter filename: ");
    scanf("%s", line);

    file = fopen(line, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= MAX_NUM_WORDS) {
                    printf("Maximum number of words reached.\n");
                    break;
                }
                strcpy(words[numWords].word, token);
                words[numWords].count = 1;
                numWords++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(file);

    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}