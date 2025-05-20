//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 50
#define WORD_LENGTH 40
#define NUM_ROUNDS 5

// Function to generate random words
char* generate_random_word() {
    char word[WORD_LENGTH];
    int length = rand() % WORD_LENGTH;
    int i;

    for(i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }

    word[length] = '\0';
    return strdup(word);
}

int main() {
    int rounds_completed = 0;
    int current_round = 0;
    int words_typed_correctly = 0;
    int words_total = 0;
    int elapsed_time = 0;

    srand(time(NULL));

    printf("\n---------------------------------------------------\n");
    printf("|                 Love Typing Test                |\n");
    printf("|                ---------------------------------|\n");
    printf("| You and I will type romantic words to each other  |\n");
    printf("|------------------------------------------------|\n\n");

    while(rounds_completed < NUM_ROUNDS) {
        current_round++;
        printf("\nRound %d\n", current_round);

        char* word_to_type = generate_random_word();
        char input[WORD_LENGTH];

        printf("Type the following romantic word as fast as you can: ");
        printf("%s\n", word_to_type);

        clock_t start = clock();
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        clock_t end = clock();
        elapsed_time += (end - start);

        if(strcmp(word_to_type, input) == 0) {
            words_typed_correctly++;
            words_total++;
        } else {
            printf("Sorry, that's not correct. Try again.\n");
            continue;
        }

        free(word_to_type);
        printf("Well done! That's %d words typed correctly out of %d.\n", words_typed_correctly, words_total);
        printf("Your typing speed is %.2f words per minute.\n", (float) words_typed_correctly * 60 / elapsed_time);
        printf("\n---------------------------------------------------\n");

        rounds_completed++;
    }

    printf("\n---------------------------------------------------\n");
    printf("|                  Love Wins                      |\n");
    printf("|------------------------------------------------|\n");
    printf("| You completed %d rounds and typed %d words correctly.\n", NUM_ROUNDS, words_typed_correctly);
    printf("| Your average typing speed was %.2f words per minute.\n", (float) words_typed_correctly * 60 / elapsed_time);
    printf("|------------------------------------------------|\n");

    return 0;
}