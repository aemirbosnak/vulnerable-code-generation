//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, length, errors = 0;
    char input, rand_char;
    clock_t start, end;
    double time_taken;

    srand(time(0)); // Initialize seed for random character generation

    char quote[] = "To be or not to be, that is the question.";

    length = sizeof(quote) / sizeof(quote[0]); // Determine quote length

    printf("Welcome to the Medieval Typing Speed Test!\n\n");
    printf("Your task is to type the following quote as quickly and accurately as possible:\n\n");
    printf("%s\n\n", quote);
    printf("Press Enter to begin.\n");

    getchar(); // Wait for user to press Enter to start

    start = clock(); // Start timer

    for (i = 0; i < length - 1; i++) { // Loop through quote characters, excluding null terminator
        rand_char = (char)((rand() % 26) + 97); // Generate random lower case letter
        printf("%c", rand_char); // Print random character
        input = getchar(); // Get user input
        if (input != quote[i]) { // Check if input matches quote character
            errors++;
        }
    }

    end = clock(); // End timer

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate time taken

    printf("\n\n");

    if (errors == 0) {
        printf("Congratulations, you typed the quote without any errors!\n");
    } else {
        printf("You made %d errors while typing the quote.\n", errors);
    }

    printf("It took you %.2f seconds to type the quote.\n", time_taken);

    return 0;
}