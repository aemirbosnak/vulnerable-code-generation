//FormAI DATASET v1.0 Category: Online Examination System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure definition for the questions
struct question {
    char questionStatement[500];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correctOption;
    int marks;
};

//Function to input the questions
void inputQuestions(struct question *q, int num) {
    int i;
    getchar(); //To clear the newline character in buffer
    for(i=0; i<num; i++) {
        printf("\nEnter question statement:\n");
        fgets(q[i].questionStatement, 500, stdin);
        printf("\nEnter option A:\n");
        fgets(q[i].optionA, 100, stdin);
        printf("\nEnter option B:\n");
        fgets(q[i].optionB, 100, stdin);
        printf("\nEnter option C:\n");
        fgets(q[i].optionC, 100, stdin);
        printf("\nEnter option D:\n");
        fgets(q[i].optionD, 100, stdin);
        printf("\nEnter the correct option (A/B/C/D):\n");
        scanf("%c", &q[i].correctOption);
        printf("\nEnter marks for this question:\n");
        scanf("%d", &q[i].marks);
        getchar(); //To clear the newline character in buffer
    }
}

//Function to display the questions
void displayQuestions(struct question *q, int num) {
    int i;
    printf("\n%-5s%-s\n", "Ques", "Question Statement");
    for(i=0; i<num; i++) {
        printf("%-5d%-s\n", i+1, q[i].questionStatement);
        printf("%-7s%-s\n", "A)", q[i].optionA);
        printf("%-7s%-s\n", "B)", q[i].optionB);
        printf("%-7s%-s\n", "C)", q[i].optionC);
        printf("%-7s%-s\n", "D)", q[i].optionD);
    }
}

//Function to start the exam
void startExam(struct question *q, int num) {
    int score=0, i;
    char answer;
    printf("\nInstructions:");
    printf("\n1. Each question carries equal marks.");
    printf("\n2. There is no negative marking.");
    printf("\n3. Enter the correct option (A/B/C/D) in capital letters.\n");

    for(i=0; i<num; i++) {
        printf("\nQues %d:\n", i+1);
        printf("%s\n", q[i].questionStatement);
        printf("A) %sB) %sC) %sD) %s\n", q[i].optionA, q[i].optionB, q[i].optionC, q[i].optionD);
        printf("Enter answer: ");
        scanf("%c", &answer);
        getchar();
        if(answer == q[i].correctOption) {
            printf("\nCorrect Answer! You scored %d marks in this question\n", q[i].marks);
            score += q[i].marks;
        }
        else printf("\nIncorrect Answer! The correct option is %c. Zero marks awarded for this question.\n", q[i].correctOption);
    }
    printf("\nYour total score is %d out of %d\n", score, num*5);
}

int main() {
    struct question q[10];
    int num;

    printf("Enter the number of questions (Max 10): ");
    scanf("%d", &num);
    if(num>10) {
        printf("Invalid Input. Number of questions can't be more than 10.\n");
        exit(EXIT_FAILURE);
    }

    inputQuestions(q, num);
    printf("\nQuestions Entered:\n");
    displayQuestions(q, num);
    printf("\nAll the best for your exam!\n");
    startExam(q, num);

    return 0;
}