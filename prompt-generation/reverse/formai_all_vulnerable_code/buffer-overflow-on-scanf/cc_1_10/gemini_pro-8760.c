//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random string
char *generate_random_string(int length) {
    char *str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[length] = '\0';
    return str;
}

// Function to compare two strings
int compare_strings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) {
        return 0;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the typing speed
int calculate_typing_speed(int length, double time) {
    return (length / 5) * (1 / time);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the string to be typed
    int length;
    printf("Enter the length of the string to be typed: ");
    scanf("%d", &length);

    // Generate a random string
    char *str = generate_random_string(length);

    // Print the string to be typed
    printf("\nType the following string: %s\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the input string from the user
    char *input_str = malloc(length + 1);
    scanf("%s", input_str);

    // Stop the timer
    clock_t end = clock();

    // Calculate the typing speed
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    int typing_speed = calculate_typing_speed(length, time);

    // Compare the input string with the original string
    int is_correct = compare_strings(str, input_str);

    // Print the results
    if (is_correct) {
        printf("\nCorrect! Your typing speed is %d words per minute.\n", typing_speed);
    } else {
        printf("\nIncorrect! Please try again.\n");
    }

    // Free the allocated memory
    free(str);
    free(input_str);

    return 0;
}