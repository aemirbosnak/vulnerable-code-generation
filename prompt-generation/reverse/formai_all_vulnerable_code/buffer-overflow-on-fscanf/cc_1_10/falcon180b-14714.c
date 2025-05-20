//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX_SIZE 1000
#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWER 50
#define PASS_PERCENTAGE 60
#define FAIL_PERCENTAGE 40

typedef struct{
    char question[MAX_SIZE];
    char options[MAX_OPTIONS][MAX_SIZE];
    char answer[MAX_ANSWER];
    int correct;
}Question;

void main(){
    int numQuestions;
    char choice;
    int score = 0;
    int pass = 0;
    int fail = 0;
    int i,j;
    Question questions[MAX_QUESTIONS];
    FILE *fp;
    fp = fopen("questions.txt","r");
    if(fp == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    while(fscanf(fp,"%d",&numQuestions)!= EOF){
        for(i=0;i<numQuestions;i++){
            fscanf(fp,"%s",questions[i].question);
            questions[i].correct = -1;
            for(j=0;j<MAX_OPTIONS;j++){
                fscanf(fp,"%s",questions[i].options[j]);
            }
        }
    }
    fclose(fp);
    printf("Welcome to the Online Examination System\n");
    printf("You will be asked %d questions\n",numQuestions);
    printf("You need to score at least %d%% to pass\n",PASS_PERCENTAGE);
    for(i=0;i<numQuestions;i++){
        printf("Question %d: %s\n",i+1,questions[i].question);
        for(j=0;j<MAX_OPTIONS;j++){
            printf("%d. %s\n",j+1,questions[i].options[j]);
        }
        printf("Enter your answer: ");
        scanf("%s",questions[i].answer);
        questions[i].answer[strcspn(questions[i].answer, "\n")] = '\0';
        if(strcmp(questions[i].answer,questions[i].options[questions[i].correct])==0){
            score++;
            pass++;
        }
        else{
            fail++;
        }
    }
    printf("\nYour score is %d out of %d\n",score,numQuestions);
    if(score >= (numQuestions * PASS_PERCENTAGE / 100)){
        printf("Congratulations! You have passed the exam with %d%%\n",(score * 100) / numQuestions);
    }
    else{
        printf("Sorry, you have failed the exam with %d%%\n",(score * 100) / numQuestions);
    }
    printf("Thank you for using the Online Examination System\n");
}