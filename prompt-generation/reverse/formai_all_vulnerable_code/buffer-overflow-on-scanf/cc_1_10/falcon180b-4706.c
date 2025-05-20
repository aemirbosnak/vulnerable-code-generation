//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SIZE 50
#define MAX_QUESTIONS 100

struct question{
    char question[SIZE];
    char option1[SIZE];
    char option2[SIZE];
    char option3[SIZE];
    char option4[SIZE];
    char answer[SIZE];
};

struct question questions[MAX_QUESTIONS];

void addQuestion(){
    int i;
    printf("\nEnter the question number: ");
    scanf("%d",&i);
    printf("\nEnter the question: ");
    scanf("%s",questions[i].question);
    printf("\nEnter option 1: ");
    scanf("%s",questions[i].option1);
    printf("\nEnter option 2: ");
    scanf("%s",questions[i].option2);
    printf("\nEnter option 3: ");
    scanf("%s",questions[i].option3);
    printf("\nEnter option 4: ");
    scanf("%s",questions[i].option4);
    printf("\nEnter the answer: ");
    scanf("%s",questions[i].answer);
    printf("\nQuestion added successfully!");
}

void viewQuestions(){
    int i;
    printf("\nQuestions:");
    for(i=0;i<MAX_QUESTIONS;i++){
        printf("\n%d. %s",i+1,questions[i].question);
    }
}

int main(){
    int choice,i;
    char username[SIZE];
    printf("\nEnter your name: ");
    scanf("%s",username);
    printf("\nWelcome %s to the Online Examination System!",username);
    while(1){
        printf("\n\n1. Add question");
        printf("\n2. View questions");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addQuestion();
                break;
            case 2:
                viewQuestions();
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}