//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define STR_LEN 50

int main() {
    char input[STR_LEN];
    char word[STR_LEN];
    int i, len, start_time, end_time, elapsed_time, total_words = 0, correct_words = 0;
    const char* words[] = {"apple", "banana", "cherry", "dragonfruit", "elderberry", "fig",
                           "grapefruit", "honeydew", "iambic", "jamboree", "kangaroo", "lemonade",
                           "mango", "nectarine", "orange", "peach", "quince", "raspberry",
                           "strawberry", "tangerine", "umbrella", "victorious", "watermelon",
                           "xylophone", "yellowtail", "zebra"};

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type each word as fast as you can.\n");
    printf("Press enter after each word.\n");
    printf("Type 'quit' to exit the program.\n\n");

    srand(time(NULL));

    while (1) {
        // Get a random word
        strcpy(word, words[rand() % 26]);
        len = strlen(word);

        // Print the word and get the start time
        printf("%s\n", word);
        start_time = clock();

        // Get the user's input
        fgets(input, STR_LEN, stdin);
        input[strcspn(input, "\n")] = 0;

        // Check if the user wants to quit
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Check if the input is correct
        total_words++;
        if (strcmp(word, input) == 0) {
            correct_words++;
        }

        // Calculate the elapsed time and print the result
        end_time = clock();
        elapsed_time = (end_time - start_time) / (CLOCKS_PER_SEC / 1000);
        printf("Elapsed time: %d ms\n\n", elapsed_time);
    }

    // Print the final result
    printf("Typing speed: %.2f words per minute\n", (float) (correct_words * 60) / (total_words * 0.5));
    printf("Goodbye!\n");

    return 0;
}