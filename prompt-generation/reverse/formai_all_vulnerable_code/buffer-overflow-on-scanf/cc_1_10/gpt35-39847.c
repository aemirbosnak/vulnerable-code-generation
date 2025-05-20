//FormAI DATASET v1.0 Category: Online Examination System ; Style: automated
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 

struct question 
{ 
    int qno; 
    char ques[300], opt1[100], opt2[100], opt3[100], opt4[100]; 
    int ans; 
}; 

typedef struct question QUESTIONS;

int score = 0;

void printScore()
{
    printf("-------------------------\n");
    printf("      Your Score is %d    \n",score);
    printf("-------------------------\n");
}

int main() 
{ 
    int n, i, j, choice; 
    printf("\n\n\n\t\t********************************************\n");
    printf("\t\t\t Welcome to C Online Examination System!\n");
    printf("\t\t********************************************\n\n\n");

    printf("\t\tPlease enter the number of questions you want in the exam: "); 
    scanf("%d",&n); 

    QUESTIONS test[n]; 

    for (i=0; i<n; i++) 
    { 
        test[i].qno = i+1; 
        printf("\n\n\n\t\tPlease enter Question %d\n",test[i].qno);
        printf("\n\t\tQuestion: "); 
        scanf(" %[^\n]s",test[i].ques); 
        printf("\n\t\tOption 1: "); 
        scanf(" %[^\n]s",test[i].opt1); 
        printf("\n\t\tOption 2: "); 
        scanf(" %[^\n]s",test[i].opt2); 
        printf("\n\t\tOption 3: "); 
        scanf(" %[^\n]s",test[i].opt3); 
        printf("\n\t\tOption 4: "); 
        scanf(" %[^\n]s",test[i].opt4); 
        printf("\n\t\tPlease enter the correct option for the above question: "); 
        scanf("%d",&test[i].ans); 
    } 

    printf("\n\n\n\t\tGreat! You have successfully created your question set.\n\n\n"); 

    printf("\n\t\tYou are now ready to take the exam. All the best!\n\n");

    for (i=0; i<n; i++) 
    { 
        printf("\n\n\n\t\t---------------------------------------------\n"); 
        printf("\n\t\tQuestion %d: %s\n",test[i].qno,test[i].ques); 
        printf("\n\t\tOption 1: %s\n",test[i].opt1); 
        printf("\n\t\tOption 2: %s\n",test[i].opt2); 
        printf("\n\t\tOption 3: %s\n",test[i].opt3); 
        printf("\n\t\tOption 4: %s\n",test[i].opt4); 
        printf("\n\t\tPlease enter your answer (1/2/3/4): "); 
        scanf("%d",&choice); 

        if (test[i].ans == choice) 
        { 
            printf("\n\t\tCorrect Answer! You get 5 points.\n"); 
            score += 5;
        } 
        else 
        { 
            printf("\n\t\tWrong Answer! You lose 2 points.\n"); 
            score -= 2;
        } 

    } 

    printScore();

    return 0; 
}