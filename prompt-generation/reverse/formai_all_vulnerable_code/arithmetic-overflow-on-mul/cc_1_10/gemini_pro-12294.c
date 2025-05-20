//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Random string generator
char *random_string(int len) {
    char *str = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[len] = '\0';
    return str;
}

// Typing test function
int typing_test(char *target, int time_limit) {
    time_t start_time = time(NULL);
    char *input = malloc(strlen(target) + 1);
    int chars_typed = 0;

    printf("Type the following text as quickly and accurately as possible:\n%s\n", target);
    while (time(NULL) - start_time < time_limit) {
        scanf("%s", input);
        chars_typed += strlen(input);
        if (strcmp(input, target) == 0) {
            break;
        }
    }
    free(input);
    return chars_typed;
}

// Main function
int main() {
    srand(time(NULL));

    // Get user input
    int num_words = 0, time_limit = 0;
    printf("Enter the number of words to type: ");
    scanf("%d", &num_words);
    printf("Enter the time limit (in seconds): ");
    scanf("%d", &time_limit);

    // Generate random text
    char *target = malloc((num_words * 5) + 1); // assuming average word length is 5
    for (int i = 0; i < num_words; i++) {
        strcat(target, random_string(5));
        strcat(target, " ");
    }
    target[strlen(target) - 1] = '\0'; // remove trailing space

    // Run the typing test
    int chars_typed = typing_test(target, time_limit);
    free(target);

    // Calculate and print the results
    float wpm = (float)chars_typed / 5 / time_limit * 60;
    printf("\nYour typing speed: %.2f WPM\n", wpm);

    return 0;
}