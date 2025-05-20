//FormAI DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUMBER_OF_WORDS 1000

int main() {
    char words[MAX_NUMBER_OF_WORDS][MAX_WORD_LENGTH];
    int count[MAX_NUMBER_OF_WORDS];
    int i, j, length, wordCount = 0, flag;
    char input[500];

    printf("Enter a string:\n");
    fgets(input, 500, stdin);

    length = strlen(input);

    if (input[length - 1] != '\n') {
        printf("The input is too long.\n");
        return 0;
    } else {
        input[length - 1] = '\0';
    }

    length = strlen(input);

    for (i = 0; i < length; i++) {
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t') {
            wordCount++;
        }
    }

    for (i = 0; i < wordCount; i++) {
        count[i] = 1;
    }

    for (i = 0; i < wordCount; i++) {
        flag = 1;

        if (i != 0) {
            for (j = 0; j < i; j++) {
               if (strcmp(words[j], strtok(input + j, " ")) == 0) {
                  flag = 0;
                  count[j]++;
                  break;
               } else {
                  flag = 1;
               }
            }
        }

        if (flag) {
            strcpy(words[i], strtok(input + i, " "));
        }
    }

    printf("\nWord Count Result\n-----------------\n");

    for (i = 0; i < wordCount; i++) {
        if (count[i] != 0) {
            printf("%s: %d\n", words[i], count[i]);
        }
    }

    return 0;
}