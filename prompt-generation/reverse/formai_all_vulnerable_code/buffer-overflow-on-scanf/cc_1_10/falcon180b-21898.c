//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define NUM_QUESTIONS 10

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    float atomic_weight;
};

struct element elements[NUM_ELEMENTS] = {
    {"H", 'H', 1, 1.008},
    {"He", 'He', 2, 4.003},
    {"Li", 'L', 3, 6.941},
    {"Be", 'B', 4, 9.012},
    {"B", 'B', 5, 10.81},
    {"C", 'C', 6, 12.011},
    {"N", 'N', 7, 14.007},
    {"O", 'O', 8, 15.999},
    {"F", 'F', 9, 18.998},
    {"Ne", 'N', 10, 20.18}
};

void shuffleArray(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        j = rand() % n;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    srand(time(NULL));
    int i, j, score = 0, index;
    char answer;
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions about the elements.\n", NUM_QUESTIONS);
    printf("Each correct answer is worth 1 point.\n");
    for (i = 0; i < NUM_QUESTIONS; i++) {
        index = rand() % NUM_ELEMENTS;
        printf("Question %d: What is the symbol for the element with atomic number %d? ", i + 1, elements[index].atomic_number);
        scanf(" %c", &answer);
        if (answer == elements[index].symbol[0]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %c.\n", elements[index].symbol[0]);
        }
    }
    printf("You scored %d out of %d points.\n", score, NUM_QUESTIONS);
    return 0;
}