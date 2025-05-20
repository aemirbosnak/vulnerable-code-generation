//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of length n
char *generate_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to compare two strings and calculate the accuracy
int compare_strings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < len1; i++) {
        if (str1[i] == str2[i]) {
            count++;
        }
    }
    return (count * 100) / len1;
}

// Function to calculate the typing speed
double calculate_speed(int num_chars, int time_taken) {
    return ((double)num_chars / time_taken) * 60;
}

int main() {
    // Set the difficulty level (1-3)
    int difficulty;
    printf("Enter difficulty level (1-3): ");
    scanf("%d", &difficulty);

    // Set the test duration (in seconds)
    int duration;
    printf("Enter test duration (in seconds): ");
    scanf("%d", &duration);

    // Set the number of characters to type
    int num_chars;
    switch (difficulty) {
        case 1:
            num_chars = 100;
            break;
        case 2:
            num_chars = 150;
            break;
        case 3:
            num_chars = 200;
            break;
        default:
            printf("Invalid difficulty level. Exiting.\n");
            return 1;
    }

    // Generate the random string
    char *str = generate_string(num_chars);

    // Start the timer
    time_t start = time(NULL);

    // Display the string to the user
    printf("Type the following string as accurately as possible:\n\n%s\n\n", str);

    // Wait for the user to finish typing
    char typed_str[num_chars + 1];
    fgets(typed_str, num_chars + 1, stdin);

    // Stop the timer
    time_t end = time(NULL);

    // Calculate the time taken
    int time_taken = end - start;

    // Calculate the accuracy
    int accuracy = compare_strings(str, typed_str);

    // Calculate the typing speed
    double speed = calculate_speed(num_chars, time_taken);

    // Display the results
    printf("\nResults:\n");
    printf("Accuracy: %d%%\n", accuracy);
    printf("Typing speed: %.2f WPM\n", speed);

    return 0;
}