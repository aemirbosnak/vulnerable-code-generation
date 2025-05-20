//FormAI DATASET v1.0 Category: Online Examination System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct for holding questions and answers
typedef struct {
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int answer;
} Question;

// Function to read questions from file and store in an array
int readQuestions(Question questions[]) {
    FILE *file = fopen("questions.txt", "r");
    if (file == NULL) {
        printf("Error reading the questions file!");
        exit(1);
    }
    int i = 0;
    while (!feof(file)) {
        fgets(questions[i].question, 100, file);
        fgets(questions[i].option1, 50, file);
        fgets(questions[i].option2, 50, file);
        fgets(questions[i].option3, 50, file);
        fgets(questions[i].option4, 50, file);
        fscanf(file, "%d", &questions[i].answer);
        i++;
    }
    fclose(file);
    return i-1;
}

// Function to display the questions and accept answers from the user
int takeTest(Question questions[], int numQuestions) {
    int score = 0;
    for (int i=0; i<numQuestions; i++) {
        printf("\n%d. %s\n", i+1, questions[i].question);
        printf("   1. %s", questions[i].option1);
        printf("   2. %s", questions[i].option2);
        printf("   3. %s", questions[i].option3);
        printf("   4. %s", questions[i].option4);
        int answer;
        printf("\nEnter your answer: ");
        scanf("%d", &answer);
        if (answer == questions[i].answer) {
            score++;
        }
    }
    return score;
}

int main() {
    Question questions[50];
    int numQuestions = readQuestions(questions);
    printf("Welcome to the Online Examination System!\n\n");
    printf("You will be asked a series of %d questions. Select the correct answer by entering the corresponding number.\n\n", numQuestions);
    int score = takeTest(questions, numQuestions);
    printf("\n\nYour score is: %d out of %d\n\n", score, numQuestions);
    return 0;
}