//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000

// Function to generate a random word
char* generate_word(int length) {
    char* word = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[length] = '\0';
    return word;
}

// Function to check if the typed word is correct
int check_word(char* typed, char* correct) {
    int len = strlen(correct);
    int correct_chars = 0;
    for (int i = 0; i < len; i++) {
        if (typed[i] == correct[i]) {
            correct_chars++;
        }
    }
    return correct_chars == len;
}

// Function to print the results
void print_results(int correct, int incorrect, int total, int wpm, int accuracy) {
    printf("Results:\n");
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Total: %d\n", total);
    printf("WPM: %d\n", wpm);
    printf("Accuracy: %d%%\n", accuracy);
}

int main() {
    srand(time(NULL));

    // Load words from file
    FILE* file = fopen("words.txt", "r");
    char* words[MAX_WORDS];
    int num_words = 0;
    while (fscanf(file, "%s", words[num_words])!= EOF) {
        num_words++;
        if (num_words == MAX_WORDS) {
            break;
        }
    }
    fclose(file);

    // Run typing test
    int correct = 0;
    int incorrect = 0;
    int total = 0;
    int wpm = 0;
    int accuracy = 0;
    char* typed = malloc(100);
    for (int i = 0; i < num_words; i++) {
        char* word = words[i];
        int word_len = strlen(word);
        printf("Type '%s': ", word);
        fflush(stdout);
        fgets(typed, 100, stdin);
        int typed_len = strlen(typed);
        if (typed_len == word_len && check_word(typed, word)) {
            correct++;
        } else {
            incorrect++;
        }
        total++;
        wpm += (word_len / 5) * 60; // Assume 5 characters per word
        accuracy += correct;
    }
    printf("\n");

    // Print results
    print_results(correct, incorrect, total, wpm, accuracy);

    return 0;
}