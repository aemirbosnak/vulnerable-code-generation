//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 15
#define MAX_TIME 60

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;
int time_left;

void load_words(char *filename) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        strcpy(words[i], line);
        i++;
    }

    num_words = i;
    fclose(fp);
}

void start_test() {
    printf("Welcome to the typing speed test!\n");
    printf("You will have %d seconds to type as many words as you can.\n", MAX_TIME);
    printf("Press enter to begin.\n");
    getchar();

    time_left = MAX_TIME;
    while (time_left > 0) {
        for (int i = 0; i < num_words; i++) {
            printf("%s ", words[i]);
        }
        printf("\n");
        fflush(stdout);
        getchar();

        for (int i = 0; i < num_words; i++) {
            char input[MAX_WORD_LENGTH];
            scanf("%s", input);

            if (strcmp(input, words[i]) == 0) {
                printf("Correct!\n");
            } else {
                printf("Incorrect!\n");
            }
        }

        time_left--;
        printf("Time left: %d seconds\n", time_left);
        fflush(stdout);
    }

    printf("Test complete!\n");
}

int main() {
    char filename[100];
    printf("Enter the name of the file containing the words:\n");
    scanf("%s", filename);

    load_words(filename);
    start_test();

    return 0;
}