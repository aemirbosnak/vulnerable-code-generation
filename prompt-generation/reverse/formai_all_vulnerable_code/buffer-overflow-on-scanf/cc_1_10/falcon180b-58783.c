//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define NUM_QUESTIONS 10

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    int atomic_weight;
};

struct element elements[MAX_ELEMENTS] = {
    {"H", '1', 1, 1.008},
    {"He", '2', 2, 4.003},
    {"Li", '3', 3, 6.941},
    {"Be", '4', 4, 9.012},
    {"B", '5', 5, 10.81},
    {"C", '6', 6, 12.01},
    {"N", '7', 7, 14.01},
    {"O", '8', 8, 15.99},
    {"F", '9', 9, 18.99},
    {"Ne", 'A', 10, 20.18}
};

void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int score = 0;
    int correct_answers[NUM_QUESTIONS];
    int user_answers[NUM_QUESTIONS];

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions.\n", NUM_QUESTIONS);

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int index = rand() % MAX_ELEMENTS;
        struct element question = elements[index];

        printf("\nQuestion %d:\n", i + 1);
        printf("Symbol: %s\n", question.symbol);
        printf("Name: %c\n", question.name);
        printf("Atomic Number: %d\n", question.atomic_number);
        printf("Atomic Weight: %d\n", question.atomic_weight);

        int choice;
        scanf("%d", &choice);

        if (choice == question.atomic_number) {
            correct_answers[i] = 1;
            score++;
        } else {
            correct_answers[i] = 0;
        }

        user_answers[i] = choice;
    }

    printf("\nYour final score is: %d/%d\n", score, NUM_QUESTIONS);

    return 0;
}