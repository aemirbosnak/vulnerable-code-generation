//FormAI DATASET v1.0 Category: Online Examination System ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structure for questions
struct question{
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    char correct_option[50];
};

//Declaration and initialization of questions
struct question que[] = {
        {"Which is a dynamically typed language?","C","Java","Python","Javascript","Python"},
        {"Who is the founder of C language?","Ken Thompson","Dennis Ritchie","Bjarne Stroustrup","James Gosling","Dennis Ritchie"},
        {"What is the full form of HTML?","Hyper Text Markup Language","Hyperlink Text Markup Language","Hyperlinking Text Markup Language","Hypertext Transfer Markup Language","Hyper Text Markup Language"},
        {"Which is a popular package manager for JavaScript?","npm","JPM","APT","RPM","npm"},
        {"What does CSS stand for?","Cascading Style Sheets","Creative Style Sheets","Computer Style Sheets","Colorful Style Sheets","Cascading Style Sheets"}
    };

int main(){
    int marks = 0; //Initializing marks to 0
    printf("Welcome to the Online Examination System\n");
    printf("The exam consists of 5 multiple choice questions.\n");
    printf("Each question carries 2 marks.\n");
    printf("Enter the correct option number(1-4) for each question.\n\n");

    for(int i=0;i<5;i++){
        printf("Q%d: %s\n", i+1, que[i].question);
        printf(" 1. %s\n 2. %s\n 3. %s\n 4. %s\n",que[i].option1, que[i].option2, que[i].option3, que[i].option4);
        char ans[50];
        int isValid = 0; //To check if the entered option is in range (1-4)
        while(!isValid){
            printf("Enter your answer: ");
            scanf("%s",ans);
            if(strcmp(ans,"1")==0 || strcmp(ans,"2")==0 || strcmp(ans,"3")==0 || strcmp(ans,"4")==0)
                isValid = 1;
        }
        if(strcmp(ans,que[i].correct_option)==0)
            marks += 2;
        printf("\n");
    }

    printf("Your total score is %d\n",marks);
    if(marks>=6)
        printf("Congratulations!!! You have passed the exam.\n");
    else
        printf("Sorry, You have not passed the exam.\n");
    return 0;
}