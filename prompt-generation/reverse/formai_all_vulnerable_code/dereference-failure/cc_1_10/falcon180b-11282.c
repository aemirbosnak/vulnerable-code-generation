//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_LENGTH 5
#define NUM_WORDS 10
#define NUM_ATTEMPTS 3

char words[NUM_WORDS][WORD_LENGTH] = {"hello", "world", "programming", "typing", "speed", "test", "example", "creative", "enthusiastic", "compiles"};
int word_indices[NUM_WORDS];
int num_correct_attempts = 0;
int num_incorrect_attempts = 0;
int num_attempts_remaining = NUM_ATTEMPTS;

void shuffle_words() {
    for (int i = 0; i < NUM_WORDS; i++) {
        int rand_index = rand() % NUM_WORDS;
        char temp[WORD_LENGTH];
        strcpy(temp, words[i]);
        strcpy(words[i], words[rand_index]);
        strcpy(words[rand_index], temp);
    }
}

void type_word(int word_index) {
    char word[WORD_LENGTH];
    strcpy(word, words[word_index]);
    printf("Type the word '%s': ", word);
    char input[WORD_LENGTH];
    fgets(input, WORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    if (strcmp(input, word) == 0) {
        printf("Correct!\n");
        num_correct_attempts++;
    } else {
        printf("Incorrect.\n");
        num_incorrect_attempts++;
    }
    num_attempts_remaining--;
}

int main() {
    srand(time(NULL));
    shuffle_words();
    int i;
    for (i = 0; i < NUM_WORDS; i++) {
        printf("%d. ", i+1);
        printf("%s\n", words[i]);
    }
    printf("You have %d attempts remaining.\n", NUM_ATTEMPTS);
    for (i = 0; i < NUM_WORDS && num_attempts_remaining > 0; i++) {
        int word_index = word_indices[i];
        type_word(word_index);
    }
    if (num_correct_attempts == NUM_WORDS) {
        printf("Congratulations! You have successfully completed the typing speed test.\n");
    } else {
        printf("Sorry, you did not complete the typing speed test successfully.\n");
    }
    return 0;
}