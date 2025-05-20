//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string
char *generate_random_string(int length) {
    char *str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[length] = '\0';
    return str;
}

// Function to compare two strings
int compare_strings(char *str1, char *str2) {
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    if (length1 != length2) {
        return 0;
    }
    for (int i = 0; i < length1; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the user's name
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    // Get the user's desired test length
    int length;
    printf("Enter the desired test length (in seconds): ");
    scanf("%d", &length);

    // Generate a random string
    char *str = generate_random_string(length);

    // Start the timer
    time_t start_time = time(NULL);

    // Get the user's input
    char input[1000];
    printf("Type the following string as accurately and quickly as possible:\n%s\n", str);
    scanf("%s", input);

    // Stop the timer
    time_t end_time = time(NULL);

    // Calculate the user's typing speed
    int time_taken = end_time - start_time;
    float speed = (float)length / time_taken;

    // Check if the user's input is correct
    int correct = compare_strings(str, input);

    // Print the results
    printf("\nResults:\n");
    printf("Name: %s\n", name);
    printf("Test length: %d seconds\n", length);
    printf("Typing speed: %.2f words per minute\n", speed);
    if (correct) {
        printf("Accuracy: 100%%\n");
    } else {
        printf("Accuracy: %.2f%%\n", (float)length / strlen(input) * 100);
    }

    return 0;
}