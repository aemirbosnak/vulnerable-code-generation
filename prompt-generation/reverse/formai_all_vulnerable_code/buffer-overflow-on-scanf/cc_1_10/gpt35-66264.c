//FormAI DATASET v1.0 Category: Online Examination System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question {
    int id;
    char question[100];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    char answer[10];
};

// Function to display the questions in quiz format
void displayQuestion(struct question q) {
    printf("\n\nQuestion %d: %s\n", q.id, q.question);
    printf("A. %s\nB. %s\nC. %s\nD. %s\n", q.optionA, q.optionB, q.optionC, q.optionD);
}

int main() {

    // Set up the questions
    struct question q1 = {1, "What is 2+2?", "1", "2", "3", "4", "D"};
    struct question q2 = {2, "Who invented the telephone?", "Thomas Edison", "Alexander Graham Bell", "Henry Ford", "Nikola Tesla", "B"};
    struct question q3 = {3, "What is the capital of France?", "Berlin", "Rome", "Paris", "Madrid", "C"};

    struct question questions[] = {q1, q2, q3};

    char name[20];
    int score = 0;

    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    // Display the questions and grade the quiz
    for (int i = 0; i < 3; i++) {
        displayQuestion(questions[i]);

        char answer[10];
        printf("Enter your answer (A, B, C, or D): ");
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", questions[i].answer);
        }
    }

    // Display the user's score
    printf("\n\nCongratulations %s, you scored %d out of 3!\n", name, score);

    return 0;
}