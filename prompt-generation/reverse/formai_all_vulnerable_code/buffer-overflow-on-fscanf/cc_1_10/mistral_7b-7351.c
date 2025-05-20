//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <ctype.h>
#include <signal.h>

#define ROWS 10
#define COLS 20
#define MAX_WORD_LEN 15

struct timeval start, end;
char words[ROWS][COLS][MAX_WORD_LEN + 1];
char user_input[MAX_WORD_LEN + 1];
int word_index, i, j;
int correct_chars = 0;

void init_matrix() {
    FILE *fp;
    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            fscanf(fp, "%s", words[i][j]);
            strcat(words[i][j], " ");
        }
    }
    fclose(fp);
}

void signal_handler(int sig) {
    printf("\nTime taken to type '%s': %.2f seconds\n", words[word_index],
           (end.tv_sec + end.tv_usec / 1000000.0 -
            start.tv_sec - start.tv_usec / 1000000.0));
    exit(0);
}

int main() {
    init_matrix();
    signal(SIGINT, signal_handler);

    word_index = rand() % ROWS;
    printf("\nType the following word exactly as it is shown:\n");
    printf("%s\n", words[word_index]);

    gettimeofday(&start, NULL);

    fflush(stdout);
    fgets(user_input, MAX_WORD_LEN, stdin);
    user_input[strlen(user_input) - 1] = '\0';

    for (i = 0; i < strlen(words[word_index]); i++) {
        if (tolower(words[word_index][i]) != tolower(user_input[i])) {
            printf("\nIncorrect character. Try again.\n");
            gettimeofday(&start, NULL);
            fgets(user_input, MAX_WORD_LEN, stdin);
            user_input[strlen(user_input) - 1] = '\0';
            i = -1;
        } else {
            correct_chars++;
        }
    }

    if (correct_chars == strlen(words[word_index])) {
        printf("\nCorrect! New word coming up...\n");
    }

    gettimeofday(&end, NULL);

    return 0;
}