//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char *generateString(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to compare two strings
int compareStrings(char *str1, char *str2) {
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

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the user's name
    char name[256];
    printf("What is your name? ");
    scanf("%s", name);

    // Get the user's desired test length
    int length;
    printf("How long do you want the test to be (in seconds)? ");
    scanf("%d", &length);

    // Start the timer
    clock_t start = clock();

    // Generate a random string
    char *str = generateString(length);

    // Print the string to the console
    printf("Type the following string as quickly and accurately as possible:\n%s\n", str);

    // Wait for the user to finish typing
    getchar();

    // Stop the timer
    clock_t end = clock();

    // Calculate the user's typing speed
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    int speed = (int)(strlen(str) / time_spent);

    // Print the user's typing speed
    printf("Your typing speed is: %d words per minute\n", speed);

    // Check if the user's input matches the original string
    char input[256];
    printf("Type the string again to check your accuracy:\n");
    scanf("%s", input);
    int correct = compareStrings(str, input);

    // Print the result
    if (correct) {
        printf("Congratulations, you typed the string correctly!\n");
    } else {
        printf("Sorry, you made some mistakes.\n");
    }

    // Free the allocated memory
    free(str);

    return 0;
}