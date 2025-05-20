//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of length n
char * generateString(int n) {
    char * str = (char *)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    str[n] = '\0';
    return str;
}

// Function to compare two strings and return the number of errors
int compareStrings(char *str1, char *str2) {
    int n = strlen(str1);
    int errors = 0;
    for (int i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            errors++;
        }
    }
    return errors;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the string from the user
    int n;
    printf("Enter the length of the string: ");
    scanf("%d", &n);

    // Generate a random string
    char * str = generateString(n);

    // Print the string to the user
    printf("Type the following string as fast as you can:\n%s\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char * input = (char *)malloc(sizeof(char) * (n + 1));
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Compare the user's input to the original string
    int errors = compareStrings(str, input);

    // Print the results
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Errors: %d\n", errors);

    // Free the memory allocated for the strings
    free(str);
    free(input);

    return 0;
}