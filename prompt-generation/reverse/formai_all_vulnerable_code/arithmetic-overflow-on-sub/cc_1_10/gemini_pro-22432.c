//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char* generate_string(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to compare two strings
int compare_strings(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}

// Function to calculate the typing speed
int calculate_speed(int n, double time) {
    return (n * 60) / time;
}

// Function to print the results
void print_results(int speed) {
    printf("Your typing speed is %d words per minute.\n", speed);
}

int main() {
    srand(time(NULL));

    // Get the length of the string from the user
    int n;
    printf("Enter the length of the string: ");
    scanf("%d", &n);

    // Generate a random string
    char* str = generate_string(n);

    // Print the string to the screen
    printf("Type the following string: %s\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the input from the user
    char* input = malloc(n + 1);
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    double time = (double)(end - start) / CLOCKS_PER_SEC;

    // Compare the input string with the original string
    int correct = compare_strings(str, input);

    // Calculate the typing speed
    int speed = calculate_speed(n, time);

    // Print the results
    if (correct) {
        print_results(speed);
    } else {
        printf("Incorrect input.\n");
    }

    // Free the allocated memory
    free(str);
    free(input);

    return 0;
}