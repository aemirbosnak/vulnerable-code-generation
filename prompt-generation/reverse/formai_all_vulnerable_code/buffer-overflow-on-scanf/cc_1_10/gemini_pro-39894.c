//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Function to generate a random string of length n
char* generate_random_string(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + (rand() % 26);
    }
    str[n] = '\0';
    return str;
}

// Function to compare two strings
int compare_strings(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return FALSE;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return TRUE;
    } else {
        return FALSE;
    }
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Get the user's name
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    // Get the user's target typing speed
    int target_speed;
    printf("Enter your target typing speed (wpm): ");
    scanf("%d", &target_speed);

    // Generate a random string of length 50
    char* target_string = generate_random_string(50);

    // Start the timer
    time_t start_time = time(NULL);

    // Prompt the user to start typing
    printf("Start typing when you're ready:\n");
    printf("%s", target_string);

    // Get the user's input
    char input[50];
    scanf("%s", input);

    // Stop the timer
    time_t end_time = time(NULL);

    // Calculate the user's typing speed
    int elapsed_time = end_time - start_time;
    int num_words = strlen(target_string) / 5;
    int typing_speed = num_words / elapsed_time * 60;

    // Compare the user's input to the target string
    int correct = compare_strings(input, target_string);

    // Print the results
    printf("\nYour typing speed is: %d wpm\n", typing_speed);
    if (correct) {
        printf("Congratulations! You typed the string correctly.\n");
    } else {
        printf("Sorry, you made a mistake while typing the string.\n");
    }

    // Free the allocated memory
    free(target_string);

    return 0;
}