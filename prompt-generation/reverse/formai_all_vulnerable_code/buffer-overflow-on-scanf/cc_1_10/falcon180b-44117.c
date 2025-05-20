//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_problems = 10;
    int num_elements = 118;
    int score = 0;
    int i, j;
    char element[3];
    char symbol[3];
    int atomic_number;
    int correct_answers = 0;
    int user_answers[num_problems];
    int correct_answers_array[num_problems];
    char *answers[num_problems];
    char *correct_answers_string[num_problems];
    srand(time(NULL));

    // Initialize the arrays with random elements and their correct answers
    for (i = 0; i < num_problems; i++) {
        atomic_number = rand() % num_elements + 1;
        sprintf(element, "%d", atomic_number);
        sprintf(symbol, "%c", 'A' + atomic_number - 1);
        answers[i] = element;
        correct_answers_string[i] = symbol;
        correct_answers_array[i] = atomic_number;
    }

    // Shuffle the arrays to randomize the order of the problems
    for (i = 0; i < num_problems; i++) {
        j = rand() % num_problems;
        char *temp = answers[i];
        answers[i] = answers[j];
        answers[j] = temp;
        int temp_int = correct_answers_array[i];
        correct_answers_array[i] = correct_answers_array[j];
        correct_answers_array[j] = temp_int;
    }

    // Display the quiz to the user
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("There are %d problems in this quiz.\n", num_problems);
    for (i = 0; i < num_problems; i++) {
        printf("Problem %d: %s\n", i+1, answers[i]);
    }

    // Get the user's answers
    for (i = 0; i < num_problems; i++) {
        printf("Enter your answer for problem %d: ", i+1);
        scanf("%d", &user_answers[i]);
    }

    // Check the user's answers and display the results
    printf("\nChecking your answers...\n");
    for (i = 0; i < num_problems; i++) {
        if (user_answers[i] == correct_answers_array[i]) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", correct_answers_string[i]);
        }
    }

    // Display the user's score
    printf("\nYou got %d out of %d problems correct.\n", correct_answers, num_problems);

    return 0;
}