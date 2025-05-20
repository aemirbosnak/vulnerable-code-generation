//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a question
typedef struct {
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    char answer[10];
} Question;

// Function to read questions from a file
void readQuestions(Question questions[], FILE *fp) {
    int i = 0;
    while (!feof(fp)) {
        fscanf(fp, "%s %s %s %s %s", questions[i].question, questions[i].option1, questions[i].option2, questions[i].option3, questions[i].option4);
        fscanf(fp, "%s", questions[i].answer);
        i++;
    }
}

// Function to display a question
void displayQuestion(Question question) {
    printf("%s\n", question.question);
    printf("A. %s\n", question.option1);
    printf("B. %s\n", question.option2);
    printf("C. %s\n", question.option3);
    printf("D. %s\n", question.option4);
}

// Function to check the answer
int checkAnswer(char answer[], char correctAnswer[]) {
    if (strcmp(answer, correctAnswer) == 0)
        return 1;
    else
        return 0;
}

// Main function
int main() {
    FILE *fp;
    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read questions from the file
    Question questions[100];
    int numQuestions = 0;
    readQuestions(questions, fp);
    fclose(fp);

    // Get user input for number of questions
    printf("Enter the number of questions you want to answer: ");
    scanf("%d", &numQuestions);

    // Display questions and get user answers
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        displayQuestion(questions[i]);
        char answer[10];
        scanf("%s", answer);
        if (checkAnswer(answer, questions[i].answer)) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Incorrect.\n");
        }
    }

    // Display the score
    printf("Your score is: %d out of %d\n", score, numQuestions);

    return 0;
}