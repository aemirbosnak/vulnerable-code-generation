//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;

void load_words() {
    FILE *fp;
    char ch;
    int i = 0;

    fp = fopen("words.txt", "r");

    if (fp == NULL) {
        printf("Error loading words.txt\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            words[i][strlen(words[i]) - 1] = '\0'; // remove newline character
            i++;
        } else {
            words[i][strlen(words[i])] = ch;
        }
    }

    num_words = i;

    fclose(fp);
}

void start_test() {
    int i, j, k, correct = 0;
    char input[MAX_WORD_LENGTH];
    int position = 0;

    for (i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
        for (j = 0; j < strlen(words[i]); j++) {
            printf("_");
        }
        printf("\n");
    }

    position = 0;

    for (i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
        for (j = 0; j < strlen(words[i]); j++) {
            if (position == j) {
                printf("*");
            } else {
                printf("_");
            }
        }
        printf("\n");

        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // remove newline character

        if (strcmp(input, words[i]) == 0) {
            correct++;
        }

        position++;
    }

    printf("You typed %d words correctly.\n", correct);
    printf("Your typing speed is %d WPM.\n", correct * 60 / (5.0 * num_words));
}

int main() {
    srand(time(NULL));

    load_words();

    start_test();

    return 0;
}