//FormAI DATASET v1.0 Category: Online Examination System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct question {
    int id;
    char question[200];
    int correctAnswer;
} Question;

void printMenu() {
    printf("1. Add a question\n");
    printf("2. Take the exam\n");
    printf("3. View all questions\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
}

int addQuestion(Question questions[], int numQuestions) {
    if(numQuestions >= 50) {
       printf("Max number of questions reached.\n");
       return numQuestions;
    }
    int id = numQuestions + 1;
    Question newQuestion;
    newQuestion.id = id;
    printf("Enter the question (max 200 characters): ");
    scanf(" %[^\n]s", newQuestion.question);
    printf("Enter the number of the correct answer (1-4): ");
    scanf("%d", &newQuestion.correctAnswer);
    if(newQuestion.correctAnswer < 1 || newQuestion.correctAnswer > 4) {
        printf("Invalid answer. Question not added.\n");
        return numQuestions;
    }
    questions[numQuestions] = newQuestion;
    printf("Question added successfully!\n");
    return numQuestions + 1;
}

int takeExam(Question questions[], int numQuestions) {
    int score = 0;
    int userAnswer;
    for(int i = 0; i < numQuestions; i++) {
        printf("%d. %s\n", questions[i].id, questions[i].question);
        printf("Enter your answer (1-4): ");
        scanf("%d", &userAnswer);
        if(userAnswer == questions[i].correctAnswer) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }
    }
    printf("Your score is: %d/%d\n", score, numQuestions);
    return score;
}

void viewQuestions(Question questions[], int numQuestions) {
    printf("ID  Question\n");
    printf("--  --------\n");
    for(int i = 0; i < numQuestions; i++) {
        printf("%2d. %s\n", questions[i].id, questions[i].question);
    }
}

int main() {
    Question questions[50];
    int numQuestions = 0;
    int choice = 0;
    while(choice != 4) {
        printMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                numQuestions = addQuestion(questions, numQuestions);
                break;
            case 2:
                takeExam(questions, numQuestions);
                break;
            case 3:
                viewQuestions(questions, numQuestions);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}