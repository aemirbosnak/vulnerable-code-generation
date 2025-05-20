//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of given length
void generate_string(char *str, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        str[i] = charset[rand() % sizeof(charset)];
    }
    str[length] = '\0';
}

// Function to check if a string is correct
int check_string(char *correct_str, char *user_str) {
    int correct = 0;
    int incorrect = 0;
    int length = strlen(correct_str);

    for (int i = 0; i < length; i++) {
        if (correct_str[i] == user_str[i]) {
            correct++;
        } else {
            incorrect++;
        }
    }

    if (correct == length) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int num_tests = 5; // Number of tests to run
    int length = 10; // Length of the string to type
    int correct = 0; // Number of correct tests
    int incorrect = 0; // Number of incorrect tests

    printf("Welcome to the typing speed test!\n");
    printf("You will be given %d strings to type.\n", num_tests);
    printf("Each string will be %d characters long.\n", length);
    printf("Type as accurately and quickly as possible!\n\n");

    char correct_str[length];
    char user_str[length];

    for (int i = 0; i < num_tests; i++) {
        generate_string(correct_str, length);
        printf("Test %d:\n", i + 1);
        printf("Correct string: %s\n", correct_str);
        fflush(stdout);
        scanf("%s", user_str);
        if (check_string(correct_str, user_str)) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect.\n");
            incorrect++;
        }
        printf("\n");
    }

    printf("Test results:\n");
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);

    return 0;
}