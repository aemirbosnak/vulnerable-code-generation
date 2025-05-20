//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Typing Speed Test game!\n");
    printf("Your goal is to type as many words as you can in 60 seconds.\n");

    // array of possible words
    char words[][20] = {"apple", "banana", "cherry", "dog", "elephant", "football", "guitar", "hamburger", "instrument", "jacket", "kindergarten", "laptop", "mountain", "notebook", "orange", "pineapple", "quartz", "rainbow", "saxophone", "telephone", "umbrella", "violin", "watermelon", "xylophone", "yellow", "zebra"};

    // seed random number generator
    srand(time(NULL));

    // variable declarations
    char input[20];
    int word_count = 0;
    int time_remaining = 60;
    time_t start_time = time(NULL);

    // loop for 60 seconds
    while (time_remaining > 0) {
        // choose a random word
        int random_index = rand() % 26;
        char * word = words[random_index];

        // print the word
        printf("%s: ", word);

        // get user input
        scanf("%s", input);

        // check if input matches word
        if (strcmp(input, word) == 0) {
            printf("Correct!\n");
            word_count++;
        }
        else {
            printf("Incorrect!\n");
        }

        // update time
        time_t elapsed_time = time(NULL) - start_time;
        time_remaining = 60 - elapsed_time;
    }

    // print results
    printf("Time's up! You typed %d words.\n", word_count);
    return 0;
}