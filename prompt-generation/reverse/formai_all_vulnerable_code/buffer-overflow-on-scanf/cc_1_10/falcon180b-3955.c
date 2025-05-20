//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_LENGTH 5 // length of words to be typed
#define WORDS_PER_MINUTE 200 // target words per minute
#define MAX_WORDS 100 // maximum number of words to be typed

// function to generate random word
char* generate_word(void) {
    static char words[] = "apple banana cherry date fig grape lemon mango orange peach plum raspberry strawberry watermelon";
    char* word = malloc(WORD_LENGTH + 1);
    strncpy(word, words, WORD_LENGTH);
    word[WORD_LENGTH] = '\0';
    return word;
}

// function to check if word is correct
int check_word(char* typed, char* correct) {
    int len = strlen(typed);
    int correct_len = strlen(correct);
    if (len!= correct_len) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (typed[i]!= correct[i]) {
            return 0;
        }
    }
    return 1;
}

// function to print results
void print_results(int correct, int total, double speed) {
    printf("Results:\n");
    printf("Correct words: %d\n", correct);
    printf("Total words: %d\n", total);
    printf("Speed: %.2f WPM\n", speed);
}

// main function
int main() {
    srand(time(NULL));
    char* typed;
    char* correct;
    int correct_count = 0;
    int total_count = 0;
    double speed = 0;
    int num_words = 0;

    // get user input for number of words
    printf("Enter number of words to type (max %d): ", MAX_WORDS);
    scanf("%d", &num_words);

    // loop through words
    for (int i = 0; i < num_words; i++) {
        // generate random word
        char* word = generate_word();

        // display word to type
        printf("Type the following word: %s\n", word);

        // get user input
        typed = malloc(WORD_LENGTH + 1);
        scanf("%s", typed);

        // check if word is correct
        correct = word;
        if (check_word(typed, correct)) {
            correct_count++;
        }
        total_count++;

        // calculate speed
        speed = (double)correct_count / (double)total_count * (double)WORDS_PER_MINUTE;

        // free memory
        free(typed);
        free(correct);
    }

    // print results
    print_results(correct_count, total_count, speed);

    return 0;
}