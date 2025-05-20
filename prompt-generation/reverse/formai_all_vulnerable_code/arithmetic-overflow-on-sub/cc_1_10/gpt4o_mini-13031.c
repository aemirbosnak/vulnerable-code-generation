//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define WORD_COUNT 10
#define MAX_WORD_LENGTH 15
#define TIME_LIMIT 30

const char *word_list[WORD_COUNT] = {
    "whimsical", "phosphorescent", "gossamer", "serendipity", 
    "ephemeral", "quintessential", "fragile", "luminous", 
    "labyrinthine", "melancholia"
};

void display_instructions() {
    printf("** Welcome to the Surreal Typing Speed Test **\n");
    printf("You will have %d seconds to type the following magical words:\n\n", TIME_LIMIT);
}

void generate_random_words(char generated_words[WORD_COUNT][MAX_WORD_LENGTH]) {
    for (int i = 0; i < WORD_COUNT; i++) {
        int random_index = rand() % WORD_COUNT;
        strcpy(generated_words[i], word_list[random_index]);
    }
}

void display_words(char generated_words[WORD_COUNT][MAX_WORD_LENGTH]) {
    printf("Words:\n");
    for (int i = 0; i < WORD_COUNT; i++) {
        printf("%s ", generated_words[i]);
    }
    printf("\n\n");
}

void start_typing_test(char generated_words[WORD_COUNT][MAX_WORD_LENGTH]) {
    char user_input[WORD_COUNT * MAX_WORD_LENGTH];
    time_t start_time = time(NULL);
    time_t end_time = start_time + TIME_LIMIT;

    printf("Begin typing now! Your time starts...\n");
    printf("\n");

    for (int i = 0; i < TIME_LIMIT; i++) {
        sleep(1);
        printf("%ld seconds remaining...\n", end_time - time(NULL));
    }

    printf("Time's up! Please enter the words you typed:\n");

    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\n")] = 0;  // Remove trailing newline

    printf("You entered: \"%s\"\n", user_input);
}

void evaluate_results(char generated_words[WORD_COUNT][MAX_WORD_LENGTH], const char *user_input) {
    char *token = strtok(user_input, " ");
    int correct_count = 0;
    
    for (int i = 0; i < WORD_COUNT && token != NULL; i++) {
        if (strcmp(token, generated_words[i]) == 0) {
            correct_count++;
        }
        token = strtok(NULL, " ");
    }

    float accuracy = (float)correct_count / WORD_COUNT * 100;
    printf("You typed %d words correctly out of %d words.\n", correct_count, WORD_COUNT);
    printf("Your accuracy is: %.2f%%\n", accuracy);
}

int main() {
    srand(time(NULL));
    char generated_words[WORD_COUNT][MAX_WORD_LENGTH];
    
    display_instructions();
    generate_random_words(generated_words);
    display_words(generated_words);
    start_typing_test(generated_words);
    
    char user_input[WORD_COUNT * MAX_WORD_LENGTH];
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\n")] = 0;  // Remove trailing newline

    evaluate_results(generated_words, user_input);
    
    printf("Thank you for participating in this surreal journey through words!\n");
    printf("May your thoughts remain ever whimsical.\n");

    return 0;
}