//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of length n
char* generate_string(int n) {
    char* str = (char*)malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to compare two strings
int compare_strings(char* str1, char* str2) {
    int n = strlen(str1);
    if (n != strlen(str2)) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the string to be typed
    int n;
    printf("Enter the length of the string to be typed: ");
    scanf("%d", &n);

    // Generate a random string
    char* str = generate_string(n);

    // Print the string to be typed
    printf("Type the following string: %s\n", str);

    // Get the user's input
    char* input = (char*)malloc((n + 1) * sizeof(char));
    scanf("%s", input);

    // Compare the user's input to the original string
    int correct = compare_strings(str, input);

    // Print the result
    if (correct) {
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }

    // Free the allocated memory
    free(str);
    free(input);

    return 0;
}