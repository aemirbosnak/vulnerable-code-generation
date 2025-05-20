//FormAI DATASET v1.0 Category: Online Examination System ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for each question
struct question {
    char questionText[200];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    char answer;
    int marks;
};

// Function to add questions to the question bank
int addQuestionToBank(struct question *questionBank, int numQuestions) {
    printf("Enter the question text: ");
    fgets(questionBank[numQuestions].questionText, 200, stdin);
    printf("Enter option A: ");
    fgets(questionBank[numQuestions].optionA, 50, stdin);
    printf("Enter option B: ");
    fgets(questionBank[numQuestions].optionB, 50, stdin);
    printf("Enter option C: ");
    fgets(questionBank[numQuestions].optionC, 50, stdin);
    printf("Enter option D: ");
    fgets(questionBank[numQuestions].optionD, 50, stdin);
    printf("Enter the correct answer (A/B/C/D): ");
    scanf(" %c", &questionBank[numQuestions].answer);
    printf("Enter the marks for this question: ");
    scanf("%d", &questionBank[numQuestions].marks);
    getchar(); // to consume the remaining \n character
    return numQuestions + 1;
}

// Function to display all questions in the question bank
void displayQuestionBank(struct question *questionBank, int numQuestions) {
    printf("Question Bank: \n\n");
    for(int i=0; i<numQuestions; i++) {
        printf("Question %d - %s", i+1, questionBank[i].questionText);
        printf("A) %s", questionBank[i].optionA);
        printf("B) %s", questionBank[i].optionB);
        printf("C) %s", questionBank[i].optionC);
        printf("D) %s", questionBank[i].optionD);
        printf("Correct Option - %c\n", questionBank[i].answer);
        printf("Marks - %d\n\n", questionBank[i].marks);
    }
}

// Function to take the test
void takeTest(struct question *questionBank, int numQuestions) {
    int totalMarks = 0;
    for(int i=0; i<numQuestions; i++) {
        printf("\nQuestion %d - %s", i+1, questionBank[i].questionText);
        printf("A) %s", questionBank[i].optionA);
        printf("B) %s", questionBank[i].optionB);
        printf("C) %s", questionBank[i].optionC);
        printf("D) %s", questionBank[i].optionD);
        printf("Enter your answer (A/B/C/D): ");
        char answer;
        scanf(" %c", &answer);
        if(answer == questionBank[i].answer) {
            printf("Correct Answer!\n");
            totalMarks += questionBank[i].marks;
        } else {
            printf("Wrong Answer!\n");
        }
    }
    printf("\nYour total marks: %d\n", totalMarks);
}

int main() {
    struct question questionBank[100];
    int numQuestions = 0;
    int choice;
    do {
        printf("\n\n\t\t\tONLINE EXAMINATION SYSTEM\n");
        printf("\n1. Add question to the question bank");
        printf("\n2. Display question bank");
        printf("\n3. Take the test");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the remaining \n character
        switch(choice) {
            case 1:{
                numQuestions = addQuestionToBank(questionBank, numQuestions);
                break;
            }
            case 2:{
                displayQuestionBank(questionBank, numQuestions);
                break;
            }
            case 3:{
                takeTest(questionBank, numQuestions);
                break;
            }
            case 4:{
                printf("Exiting the program...\n");
                exit(0);
            }
            default:{
                printf("Invalid choice. Please try again.\n");
            }
        }
    } while(choice != 4);
    return 0;
}