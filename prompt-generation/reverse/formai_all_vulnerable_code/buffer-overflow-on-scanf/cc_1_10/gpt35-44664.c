//FormAI DATASET v1.0 Category: Online Examination System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char question[1000];
    char option1[500];
    char option2[500];
    char option3[500];
    char option4[500];
    int answer;
} Question;

void printQuestion(Question q) {
    printf("%s\n", q.question);
    printf("1. %s\n", q.option1);
    printf("2. %s\n", q.option2);
    printf("3. %s\n", q.option3);
    printf("4. %s\n", q.option4);
    printf("Enter your answer (1-4): ");
}

int main() {
    int numQuestions, score = 0;
    char name[50];
    printf("Welcome to the Online Exam System!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! Please enter the number of questions you want to answer: ", name);
    scanf("%d", &numQuestions);
    
    Question *questions = malloc(numQuestions * sizeof(Question));
    
    for(int i = 0; i < numQuestions; i++) {
        printf("\n\nQuestion %d:\n\n", i+1);
        getchar();
        printf("Enter the question: ");
        fgets(questions[i].question, 1000, stdin);
        printf("Enter option 1: ");
        fgets(questions[i].option1, 500, stdin);
        printf("Enter option 2: ");
        fgets(questions[i].option2, 500, stdin);
        printf("Enter option 3: ");
        fgets(questions[i].option3, 500, stdin);
        printf("Enter option 4: ");
        fgets(questions[i].option4, 500, stdin);
        printf("Enter the answer (1-4): ");
        scanf("%d", &questions[i].answer);
    }
    
    printf("\n\nExam for %s\n\n", name);
    
    for(int i = 0; i < numQuestions; i++) {
        printf("\n\nQuestion %d:\n\n", i+1);
        printQuestion(questions[i]);
        int answer;
        scanf("%d", &answer);
        if(answer == questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d\n", questions[i].answer);
        }
    }
    
    printf("\n\nFinal score for %s: %d/%d\n\n", name, score, numQuestions);
    
    free(questions);
    
    return 0;
}