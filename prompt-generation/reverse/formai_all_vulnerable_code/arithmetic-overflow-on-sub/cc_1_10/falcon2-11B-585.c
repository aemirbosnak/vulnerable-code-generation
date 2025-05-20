//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10
#define NUM_CHOICES 4

int main() {
    // Create an array of questions
    char* questions[] = {
        "Which element has the atomic number 1?",
        "What is the symbol for gold?",
        "What is the symbol for oxygen?",
        "What element has the atomic number 8?",
        "What is the symbol for tin?",
        "What is the symbol for iron?",
        "What is the symbol for silicon?",
        "What element has the atomic number 6?",
        "What element has the atomic number 17?",
        "What is the symbol for neon?"
    };

    // Create an array of answers
    int answers[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };

    // Shuffle the questions and answers
    srand(time(NULL));
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int j = rand() % NUM_QUESTIONS;
        char* temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
        int temp2 = answers[i];
        answers[i] = answers[j];
        answers[j] = temp2;
    }

    // Print the questions
    printf("Periodic Table Quiz\n\n");
    printf("1. Which element has the atomic number 1?\n");
    printf("2. What is the symbol for gold?\n");
    printf("3. What is the symbol for oxygen?\n");
    printf("4. What element has the atomic number 8?\n");
    printf("5. What is the symbol for tin?\n");
    printf("6. What is the symbol for iron?\n");
    printf("7. What is the symbol for silicon?\n");
    printf("8. What element has the atomic number 6?\n");
    printf("9. What element has the atomic number 17?\n");
    printf("10. What is the symbol for neon?\n\n");

    // Print the answers
    printf("Answers:\n");
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("%d. ", i + 1);
        for (int j = 0; j < NUM_CHOICES; j++) {
            printf("%s", (answers[i] == j + 1)? "A" : " ");
        }
        printf("\n");
    }

    // Get user input
    printf("Enter the number of the question you want to answer:\n");
    int answer;
    scanf("%d", &answer);

    // Check the answer
    if (answer >= 1 && answer <= NUM_QUESTIONS) {
        int index = answer - 1;
        if (answers[index] == (int)getchar() - 1) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n", answers[index]);
        }
    } else {
        printf("Invalid input. Please enter a number between 1 and 10.\n");
    }

    return 0;
}