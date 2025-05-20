//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_LENGTH 20
#define NUM_WORDS 10

void print_word(char *word) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        printf("%c", word[i]);
        fflush(stdout);
        usleep(50000);
    }
    printf(" ");
}

int main() {
    int i, j, correct_count = 0;
    char words[NUM_WORDS][WORD_LENGTH];
    char input[WORD_LENGTH];
    FILE *fp;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (i = 0; i < NUM_WORDS; i++) {
        fgets(words[i], WORD_LENGTH, fp);
        words[i][strlen(words[i]) - 1] = '\0';
    }

    fclose(fp);

    srand(time(NULL));
    int random_word = rand() % NUM_WORDS;

    printf("Typing Speed Test\n");
    printf("------------------\n");
    printf("Type the following word correctly:\n");
    print_word(words[random_word]);
    printf("\nYour input: ");
    scanf("%s", input);

    if (strcmp(input, words[random_word]) == 0) {
        correct_count++;
        printf("Correct!\n");
    } else {
        printf("Incorrect. The correct answer was: %s\n", words[random_word]);
    }

    for (i = 0; i < 5; i++) {
        print_word(words[rand() % NUM_WORDS]);
        scanf("%s", input);
        if (strcmp(input, words[rand() % NUM_WORDS]) != 0) {
            printf("Game over! Your final score is: %d\n", correct_count);
            break;
        }
        correct_count++;
        printf("Correct!\n");
    }

    if (i == 5) {
        printf("Congratulations! You completed the test.\n");
    }

    return 0;
}