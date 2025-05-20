//FormAI DATASET v1.0 Category: Online Examination System ; Style: active
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//Structure for the questions
struct Question{
    char ques[500];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correct_option;
    int marks;
}question[10];

//Function to add questions to the array of structures
void add_questions(int i){ 
    printf("\nEnter the question: ");
    scanf(" %[^\n]s",question[i].ques);
    printf("\nEnter option A: ");
    scanf(" %[^\n]s",question[i].optionA);
    printf("\nEnter option B: ");
    scanf(" %[^\n]s",question[i].optionB);
    printf("\nEnter option C: ");
    scanf(" %[^\n]s",question[i].optionC);
    printf("\nEnter option D: ");
    scanf(" %[^\n]s",question[i].optionD);
    printf("\nEnter the correct option(A/B/C/D): ");
    scanf(" %c",&question[i].correct_option);
    printf("\nEnter the marks allocated: ");
    scanf("%d",&question[i].marks);
}

//Function to display the questions
void display_question(int i){
    printf("\nQ%d. %s\n",i+1,question[i].ques);
    printf("A. %s\n",question[i].optionA);
    printf("B. %s\n",question[i].optionB);
    printf("C. %s\n",question[i].optionC);
    printf("D. %s\n",question[i].optionD);
}

//Function to take the test
int take_test(int n){
    int score=0;
    char response;
    printf("\n**************************************");
    printf("\nYOUR TEST STARTS NOW!!!");
    printf("\n**************************************\n\n");
    for(int i=0;i<n;i++){
        display_question(i);
        printf("\nEnter your response(A/B/C/D)?");
        scanf(" %c",&response);
        
        //Check if the response is correct and give marks accordingly
        if(toupper(response) == toupper(question[i].correct_option)){
            printf("\nCorrect Answer! You got %d marks\n",question[i].marks);
            score=score+question[i].marks;
        }
        else{
            printf("\nWrong Answer! The correct answer is %c\n",question[i].correct_option);
        }
    }
    return score;
}

//Main function
int main(){
    int choice, n, total_marks=0;
    printf("\n\n----------------------------------------------");
    printf("\nONLINE EXAMINATION SYSTEM");
    printf("\n----------------------------------------------\n");
    
    //Menu-driven program
    while(1){
        printf("\nSelect an option from the following:");
        printf("\n1. Add questions");
        printf("\n2. Display questions");
        printf("\n3. Take test");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the number of questions to be added: ");
                scanf("%d",&n);
                printf("\nEnter the details for %d questions.",n);
                for(int i=0;i<n;i++){
                    printf("\nDetails for question %d:",i+1);
                    add_questions(i);
                    total_marks=total_marks+question[i].marks;
                }
                printf("\n Questions added successfully!!!");
                break;
            
            case 2:
                if(total_marks == 0){
                    printf("\nNo questions available. Please add questions first!!!");
                }
                else{
                    printf("\nQuestions in the database:");
                    for(int i=0;i<n;i++){
                        display_question(i);
                    }
                }
                break;

            case 3:
                if(total_marks == 0){
                    printf("\nNo questions available. Please add questions first!!!");
                }
                else{
                    int score = take_test(n);
                    printf("\n**************************************");
                    printf("\nYOUR TEST IS OVER!!!");
                    printf("\n**************************************");
                    printf("\nYour final score is %d out of %d",score,total_marks);
                }
                break;

            case 4:
                printf("\nThank you. Exiting the program!!!");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again!!!");
        }
    }
    return 0;
}