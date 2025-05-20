//LLAMA2-13B DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100
#define MAGIC_NUMBER 37

void spellCheck(char *word);
void printCorrectedWord(char *word);

int main() {
    char word[MAX_LENGTH];
    int i, j, incorrect = 0;
    clock_t start, end;

    printf("Welcome to the Spell Checker! Please enter a word: ");
    fgets(word, MAX_LENGTH, stdin);

    start = clock();
    spellCheck(word);
    end = clock();

    incorrect = (int) (end - start) / 1000;

    if (incorrect > 0) {
        printf("Your word contains %d incorrect spellings.\n", incorrect);
        printCorrectedWord(word);
    } else {
        printf("Your word is spelled correctly!\n");
    }

    return 0;
}

void spellCheck(char *word) {
    int i, j, k, count = 0;
    char c;
    char correct[MAX_LENGTH];

    for (i = 0; i < strlen(word); i++) {
        c = word[i];

        if (isalpha(c)) {
            for (j = 0; j < strlen(word); j++) {
                if (word[j] == c) {
                    break;
                }
            }

            if (j == strlen(word)) {
                count++;
            }
        }
    }

    if (count > 0) {
        for (i = 0; i < strlen(word); i++) {
            c = word[i];

            if (isalpha(c)) {
                for (j = 0; j < strlen(word); j++) {
                    if (word[j] == c) {
                        break;
                    }
                }

                if (j == strlen(word)) {
                    correct[i] = word[i];
                } else {
                    correct[i] = word[j];
                }
            }
        }

        for (i = 0; i < strlen(word); i++) {
            word[i] = correct[i];
        }
    }
}

void printCorrectedWord(char *word) {
    int i;

    printf("Corrected word: ");

    for (i = 0; i < strlen(word); i++) {
        printf("%c", word[i]);
    }

    printf("\n");
}