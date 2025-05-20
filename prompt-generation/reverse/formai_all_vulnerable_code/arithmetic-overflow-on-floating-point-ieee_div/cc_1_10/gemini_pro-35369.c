//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUF_SIZE 1024

// Generates a random string of length n.
char *generate_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Compares two strings and returns the number of errors.
int compare_strings(char *str1, char *str2) {
    int errors = 0;
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            errors++;
        }
    }
    return errors;
}

int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Get the user's name.
    char name[BUF_SIZE];
    printf("Please enter your name: ");
    scanf("%s", name);

    // Get the user's desired test length.
    int length;
    printf("Please enter the desired test length (in words): ");
    scanf("%d", &length);

    // Generate a random string of the desired length.
    char *str = generate_string(length);

    // Display the string to the user.
    printf("Please type the following string as accurately and quickly as possible:\n%s\n", str);

    // Start the timer.
    clock_t start = clock();

    // Get the user's input.
    char input[BUF_SIZE];
    scanf("%s", input);

    // Stop the timer.
    clock_t end = clock();

    // Calculate the elapsed time.
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    // Compare the user's input to the original string.
    int errors = compare_strings(str, input);

    // Calculate the typing speed.
    double speed = (double)length / elapsed;

    // Display the results.
    printf("Your typing speed is %.2f words per minute with %d errors.\n", speed, errors);

    // Free the allocated memory.
    free(str);

    return 0;
}