//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to print periodic table
void print_periodic_table(int max_elements) {
    printf("Periodic Table:\n");
    for (int i = 1; i <= max_elements; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    for (int i = 1; i <= max_elements; i++) {
        printf("%2s", " ");
        for (int j = 1; j <= max_elements; j++) {
            if (i == j) {
                printf("%2d", i);
            } else {
                printf("%2s", " ");
            }
        }
        printf("\n");
    }
}

// Function to generate random element
void generate_random_element(int max_elements) {
    int element = rand() % max_elements + 1;
    printf("Random element: %d\n", element);
}

// Function to generate quiz question
void generate_quiz_question(int max_elements) {
    int element1 = rand() % max_elements + 1;
    int element2 = rand() % max_elements + 1;

    printf("Question: What is the atomic number of %d?\n", element1);
    printf("Choices: %d, %d, %d, %d\n", element1, element2, element1 + 1, element2 + 1);
}

// Function to check quiz answer
bool check_quiz_answer(int max_elements, int answer) {
    int element = rand() % max_elements + 1;

    if (answer == element) {
        printf("Correct!\n");
        return true;
    } else {
        printf("Incorrect. The correct answer is %d.\n", element);
        return false;
    }
}

// Function to run quiz
void run_quiz(int max_elements, int num_questions) {
    srand(time(NULL));

    for (int i = 0; i < num_questions; i++) {
        generate_quiz_question(max_elements);
        int answer = rand() % 4 + 1;
        bool correct = check_quiz_answer(max_elements, answer);

        if (correct) {
            printf("Score: %d/%d\n", i + 1, num_questions);
        }
    }
}

int main() {
    int max_elements;

    printf("Enter the maximum number of elements to include in the periodic table (1-118): ");
    scanf("%d", &max_elements);

    print_periodic_table(max_elements);
    generate_random_element(max_elements);
    run_quiz(max_elements, 5);

    return 0;
}