//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of given length
char* generate_random_string(int length) {
    char* result = (char*) malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        result[i] = 'a' + rand() % 26; // Generates a random lowercase letter
    }
    result[length - 1] = '\0'; // Add null terminator
    return result;
}

// Function to check if the user's input matches the generated string
int check_input(char* input, char* correct_answer) {
    int length = strlen(correct_answer);
    if (strlen(input)!= length) {
        return 0; // Input is not the correct length
    }
    for (int i = 0; i < length; i++) {
        if (input[i]!= correct_answer[i]) {
            return 0; // Characters do not match
        }
    }
    return 1; // Input is correct
}

// Function to calculate the user's typing speed in words per minute
float calculate_typing_speed(int correct_answers, int incorrect_answers, float time_taken) {
    float wpm = 0;
    if (time_taken > 0) {
        int total_words = correct_answers + incorrect_answers;
        wpm = (float) total_words / (time_taken / 60);
    }
    return wpm;
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    int correct_answers = 0;
    int incorrect_answers = 0;
    float time_taken = 0;

    for (int i = 0; i < num_questions; i++) {
        char* correct_answer = generate_random_string(10); // Generate a random string of length 10
        printf("Question %d: ", i + 1);
        fflush(stdout); // Flush output buffer to ensure prompt is displayed immediately
        time_taken -= difftime(time(NULL), clock()); // Start timer
        char input[100];
        fgets(input, 100, stdin); // Read input from user
        time_taken += difftime(time(NULL), clock()); // Stop timer
        if (check_input(input, correct_answer)) {
            correct_answers++;
        } else {
            incorrect_answers++;
        }
        free(correct_answer); // Free memory used by correct answer string
    }

    float typing_speed = calculate_typing_speed(correct_answers, incorrect_answers, time_taken);
    printf("Your typing speed is %.2f words per minute.\n", typing_speed);

    return 0;
}