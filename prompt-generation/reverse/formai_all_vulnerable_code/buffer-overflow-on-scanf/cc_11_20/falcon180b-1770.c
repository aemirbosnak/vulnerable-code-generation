//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 20
#define MAX_USERS 100

typedef struct {
    char name[20];
    int score;
    int num_words;
    int num_correct_words;
    int num_incorrect_words;
    int time_taken;
} User;

User users[MAX_USERS];

int num_users;

int main() {
    char word[MAX_WORD_LENGTH];
    FILE *fp;
    int i, j, k;
    int num_words;
    int num_correct_words = 0;
    int num_incorrect_words = 0;
    int time_taken;
    int correct_flag = 0;
    char input_word[MAX_WORD_LENGTH];

    srand(time(NULL));

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        exit(0);
    }

    fscanf(fp, "%d", &num_words);

    for (i = 0; i < num_words; i++) {
        fscanf(fp, "%s", word);
        strcpy(input_word, word);
        strcat(input_word, " ");
        for (j = 0; j < strlen(input_word); j++) {
            if (islower(input_word[j])) {
                input_word[j] = toupper(input_word[j]);
            }
        }
        printf("Word %d: %s\n", i+1, input_word);
    }

    fclose(fp);

    printf("\nEnter your name: ");
    scanf("%s", users[num_users].name);
    num_users++;

    time_taken = 0;
    correct_flag = 0;

    while (correct_flag == 0) {
        printf("\nEnter the word: ");
        scanf("%s", input_word);
        for (i = 0; i < strlen(input_word); i++) {
            if (islower(input_word[i])) {
                input_word[i] = toupper(input_word[i]);
            }
        }

        for (i = 0; i < num_words; i++) {
            if (strcmp(input_word, word) == 0) {
                correct_flag = 1;
                num_correct_words++;
                break;
            }
        }

        if (correct_flag == 0) {
            num_incorrect_words++;
        }

        time_taken++;
    }

    users[num_users-1].score = (num_correct_words * 5) - (num_incorrect_words * 2);
    users[num_users-1].num_words = num_words;
    users[num_users-1].num_correct_words = num_correct_words;
    users[num_users-1].num_incorrect_words = num_incorrect_words;
    users[num_users-1].time_taken = time_taken;

    printf("\nUser: %s\n", users[num_users-1].name);
    printf("Score: %d\n", users[num_users-1].score);
    printf("Number of correct words: %d\n", users[num_users-1].num_correct_words);
    printf("Number of incorrect words: %d\n", users[num_users-1].num_incorrect_words);
    printf("Time taken: %d seconds\n", users[num_users-1].time_taken);

    return 0;
}