//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_QUESTIONS 10

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    int group;
    int period;
};

struct element elements[MAX_ELEMENTS] = {
    {"H", 'Hydrogen', 1, 1, 1},
    {"He", 'Helium', 2, 18, 1},
    {"Li", 'Lithium', 3, 1, 2},
    {"Be", 'Beryllium', 4, 2, 2},
    {"B", 'Boron', 5, 13, 2},
    {"C", 'Carbon', 6, 14, 2},
    {"N", 'Nitrogen', 7, 15, 2},
    {"O", 'Oxygen', 8, 16, 2},
    {"F", 'Fluorine', 9, 17, 2},
    {"Ne", 'Neon', 10, 18, 2}
};

void shuffleArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int numQuestions;
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? ");
    scanf("%d", &numQuestions);

    if (numQuestions > MAX_QUESTIONS || numQuestions < 1) {
        printf("Invalid number of questions.\n");
        return 1;
    }

    int questionIndex = 0;
    int correctAnswers = 0;
    int wrongAnswers = 0;

    printf("\n");

    for (int i = 0; i < numQuestions; i++) {
        // Shuffle the array of elements
        shuffleArray(elements, MAX_ELEMENTS);

        // Ask a random question
        int index = rand() % MAX_ELEMENTS;
        printf("Question %d: What is the symbol for the element with atomic number %d? ", i + 1, elements[index].atomic_number);

        // Get the user's answer
        char answer[4];
        scanf("%s", answer);

        // Check if the answer is correct
        if (strcmp(answer, elements[index].symbol) == 0) {
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[index].symbol);
            wrongAnswers++;
        }

        questionIndex++;
    }

    printf("\n");
    printf("You answered %d questions correctly and %d questions incorrectly.\n", correctAnswers, wrongAnswers);

    return 0;
}