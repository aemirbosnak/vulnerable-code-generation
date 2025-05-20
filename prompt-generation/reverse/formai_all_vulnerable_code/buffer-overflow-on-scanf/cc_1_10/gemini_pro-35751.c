//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of length n
char *generateString(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[n] = '\0';
    return str;
}

// Function to compare two strings and calculate the typing speed
void compareStrings(char *str1, char *str2, int timeTaken) {
    int errors = 0;
    for (int i = 0; i < strlen(str1); i++) {
        if (str1[i] != str2[i]) {
            errors++;
        }
    }

    int speed = (strlen(str1) - errors) * 60 / timeTaken;
    printf("Your typing speed is: %d words per minute\n", speed);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Get the user's name
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);

    // Generate a random string
    char *str = generateString(100);

    // Display the string to the user
    printf("Type the following string as quickly and accurately as possible:\n\n%s\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char input[100];
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    int timeTaken = (end - start) / CLOCKS_PER_SEC;

    // Compare the strings and calculate the typing speed
    compareStrings(str, input, timeTaken);

    return 0;
}