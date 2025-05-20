//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10

typedef struct {
    char name[20];
    int atomic_number;
} Element;

Element elements[NUM_QUESTIONS] = {
    {"Hydrogen", 1},
    {"Helium", 2},
    {"Lithium", 3},
    {"Boron", 5},
    {"Carbon", 6},
    {"Nitrogen", 7},
    {"Oxygen", 8},
    {"Sodium", 11},
    {"Magnesium", 12},
    {"Aluminum", 13}
};

void print_element(Element e) {
    printf("%s (%d)\n", e.name, e.atomic_number);
}

int main() {
    srand(time(NULL));
    int score = 0;
    int question_number = 0;

    while (question_number < NUM_QUESTIONS) {
        Element question = elements[rand() % NUM_QUESTIONS];
        char user_answer[20];
        int user_number;

        print_element(question);
        printf("Enter the atomic number: ");
        scanf("%s", user_answer);

        if (sscanf(user_answer, "%d", &user_number) == 1) {
            if (user_number == question.atomic_number) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect! The atomic number is %d.\n", question.atomic_number);
            }
        } else {
            printf("Invalid input. Please enter a number.\n");
        }

        question_number++;
    }

    printf("Quiz complete! Your score is %d out of %d.\n", score, NUM_QUESTIONS);

    return 0;
}