//FormAI DATASET v1.0 Category: Online Examination System ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_QUESTION 10 //Maximum number of questions
#define MAX_QUESTION_LENGTH 100 //Maximum size of question length
#define MAX_OPTIONS 4 //Maximum number of options for each question
#define MAX_NAME_LENGTH 50 //Maximum length of student name


//Structure of questions
struct question {
    char questionText[MAX_QUESTION_LENGTH];
    char options[MAX_OPTIONS][MAX_QUESTION_LENGTH];
    int correctOption;
};

//Function to display the menu
void displayMenu() {
    printf("\n\n\n\tMENU\n");
    printf("\t====\n");
    printf("\t1. Take Exam\n");
    printf("\t2. View Result\n");
    printf("\t3. Exit\n");
    printf("\tPlease enter your choice (1-3): ");
}

//Function to display questions
void displayQuestions(struct question* questions, int numQuestions) {
    printf("\n\n\n\tEXAM\n");
    printf("\t====\n");
    for (int i = 0; i < numQuestions; i++) {
        printf("\n\t%d. %s\n", i+1, questions[i].questionText);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("\t   %c. %s\n", 'a'+j, questions[i].options[j]);
        }
        printf("\n\tPlease enter your choice (a-d): ");
    }
}

//Function to take exam
void takeExam(struct question* questions, int numQuestions, int* score) {
    char answer;
    for (int i = 0; i < numQuestions; i++) {
        printf("\n\t%d. %s\n", i+1, questions[i].questionText);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("\t   %c. %s\n", 'a'+j, questions[i].options[j]);
        }
        printf("\n\tPlease enter your choice (a-d): ");
        scanf(" %c", &answer);
        if (answer == 'a'+questions[i].correctOption) (*score)++;
    }
}

int main() {
    int numQuestions = 0;
    struct question* questions;
    int score = 0, choice;
    char name[MAX_NAME_LENGTH];
    bool examTaken = false;

    while (true) {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                //Take Exam
                printf("\n\tPlease enter your name: ");
                scanf("%s", name);
                if (examTaken) {
                    printf("\n\tYou have already taken the exam!\n");
                    break;
                }
                examTaken = true;
                printf("\n\tPlease answer the following questions: \n");
                takeExam(questions, numQuestions, &score);
                break;
            case 2:
                //View Result
                if (!examTaken) {
                    printf("\n\tYou have not taken the exam yet!\n");
                    break;
                }
                printf("\n\n\n\tRESULT\n");
                printf("\t======\n");
                printf("\tName: %s\n", name);
                printf("\tScore: %d/%d\n", score, numQuestions);
                break;
            case 3:
                //Exit
                free(questions);
                printf("\n\tThank you for using the system!\n");
                return 0;
            default:
                printf("\n\tInvalid choice! Please try again.\n");
        }
    }
    return 0;
}