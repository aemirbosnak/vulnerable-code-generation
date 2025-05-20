//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of given length
char *generate_random_string(int length) {
    char *str = malloc(length + 1);
    if (str == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    for (int i = 0; i < length; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[length] = '\0';
    return str;
}

// Function to check if two strings are equal
int compare_strings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1!= len2) {
        return 0;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[i]!= str2[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to print the result of the test
void print_result(int correct_answers, int total_questions, double accuracy, int wpm) {
    printf("You got %d out of %d questions correct (%.2f%% accuracy)\n", correct_answers, total_questions, accuracy * 100);
    printf("Your typing speed is %d words per minute\n", wpm);
}

int main() {
    srand(time(NULL));
    int length = 10;
    int num_questions = 10;
    char *correct_answers = generate_random_string(length);
    int total_questions = 0;
    int correct_answers_count = 0;
    double accuracy = 0.0;
    int wpm = 0;

    // Start the test
    printf("Welcome to the Typing Speed Test!\n");
    for (int i = 0; i < num_questions; i++) {
        char *question = generate_random_string(length);
        printf("Question %d: %s\n", i + 1, question);
        char input[length + 1];
        scanf("%s", input);
        total_questions++;
        if (compare_strings(input, question)) {
            correct_answers_count++;
        }
    }

    // Calculate the result
    accuracy = (double)correct_answers_count / total_questions * 100.0;
    wpm = (int)(total_questions / (5.0 * (double)num_questions / 60.0));

    // Print the result
    print_result(correct_answers_count, total_questions, accuracy, wpm);

    return 0;
}