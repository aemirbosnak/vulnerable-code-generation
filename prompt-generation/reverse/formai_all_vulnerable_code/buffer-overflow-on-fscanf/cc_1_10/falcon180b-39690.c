//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define NUM_WORDS 1000
#define WORD_LENGTH_MIN 3
#define WORD_LENGTH_MAX 10

int main() {
    int i, j, k, correct = 0, wrong = 0;
    char input[100], word[100], correct_word[100];
    FILE *fp;
    srand(time(NULL));

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    for (i = 0; i < NUM_WORDS; i++) {
        fscanf(fp, "%s", word);
        strcpy(correct_word, word);
        for (j = 0; j < strlen(word); j++) {
            k = rand() % 26 + 65;
            if (isalpha(word[j])) {
                input[j] = tolower(word[j]);
            } else {
                input[j] = word[j];
            }
        }
        input[strlen(word)] = '\0';
    }
    fclose(fp);

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given %d words to type.\n", NUM_WORDS);
    printf("Press [Enter] to begin...\n");
    getchar();

    for (i = 0; i < NUM_WORDS; i++) {
        printf("Word #%d: ", i+1);
        scanf(" %[^\n]", input);
        if (strcmp(input, correct_word) == 0) {
            correct++;
        } else {
            wrong++;
        }
        printf("\n");
    }

    printf("You have completed the test.\n");
    printf("Correct: %d\n", correct);
    printf("Wrong: %d\n", wrong);

    return 0;
}