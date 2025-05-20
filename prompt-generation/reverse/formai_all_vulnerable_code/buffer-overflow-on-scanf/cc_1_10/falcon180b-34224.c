//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 10

// Function to generate a random word
void generate_word(char* word, int length) {
    const char* letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) {
        word[i] = letters[rand() % strlen(letters)];
    }
    word[length] = '\0';
}

// Function to check if the user has typed the word correctly
int check_word(const char* typed, const char* word) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (typed[i]!= word[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to display the result
void display_result(int correct, int total, double speed) {
    printf("Result:\n");
    printf("Correct: %d\n", correct);
    printf("Total: %d\n", total);
    printf("Speed: %0.2f WPM\n", speed);
}

// Main function
int main() {
    srand(time(NULL));
    char* words[MAX_WORDS];
    int word_lengths[MAX_WORDS];
    int num_words = 0;
    char typed[MAX_WORD_LENGTH];
    int correct = 0;
    int total = 0;
    double speed = 0.0;

    printf("Welcome to the typing speed test!\n");
    printf("How many words do you want to type? (Max %d): ", MAX_WORDS);
    scanf("%d", &num_words);

    for (int i = 0; i < num_words; i++) {
        int length = rand() % MAX_WORD_LENGTH + 1;
        words[i] = malloc(length + 1);
        generate_word(words[i], length);
        word_lengths[i] = length;
    }

    printf("Type the following words:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }

    while (total < num_words) {
        printf("Type a word: ");
        scanf("%s", typed);
        total++;

        for (int i = 0; i < num_words; i++) {
            if (check_word(typed, words[i])) {
                correct++;
                break;
            }
        }
    }

    speed = (double)correct / (total * word_lengths[0]);

    display_result(correct, total, speed);

    return 0;
}