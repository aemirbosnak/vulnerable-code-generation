//FormAI DATASET v1.0 Category: Online Examination System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

int ques_count=0; //Number of questions

//Structure to store the question and answer options
typedef struct{
    char ques[300];
    char options[4][100];
    int correct_ans;
}Question;

//Function to display the question and answer options
void display_question(Question *q){
    printf("\n%s\n",q->ques);
    printf("A. %s\n",q->options[0]);
    printf("B. %s\n",q->options[1]);
    printf("C. %s\n",q->options[2]);
    printf("D. %s\n",q->options[3]);
}

//Function to conduct the examination
void conduct_test(Question *q,int qno,int score){
    char ans;
    if(qno>ques_count){
        printf("\nYour Score : %d",score);
        if(score>=(ques_count/2)){
            printf("\nCongratulations! You have passed the exam.");
        }
        else{
            printf("\nSorry! You have failed the exam.");
        }
        return;
    }
    display_question(&q[qno-1]);
    printf("\nEnter your answer (A/B/C/D) : ");
    scanf(" %c",&ans);
    if(ans=='A' || ans=='a'){
        if(q[qno-1].correct_ans==1){
            printf("\nCorrect Answer!!");
            score++;
        }
        else{
            printf("\nWrong Answer!!");
        }
    }
    else if(ans=='B' || ans=='b'){
        if(q[qno-1].correct_ans==2){
            printf("\nCorrect Answer!!");
            score++;
        }
        else{
            printf("\nWrong Answer!!");
        }
    }
    else if(ans=='C' || ans=='c'){
        if(q[qno-1].correct_ans==3){
            printf("\nCorrect Answer!!");
            score++;
        }
        else{
            printf("\nWrong Answer!!");
        }
    }
    else if(ans=='D' || ans=='d'){
        if(q[qno-1].correct_ans==4){
            printf("\nCorrect Answer!!");
            score++;
        }
        else{
            printf("\nWrong Answer!!");
        }
    }
    else{
        printf("\nInvalid Input!! Please enter A/B/C/D.");
    }
    conduct_test(q,qno+1,score); //Recursive call to handle next question
}

int main(){
    printf("----- Online Examination System -----\n\n");
    printf("Enter the number of questions : ");
    scanf("%d",&ques_count);

    Question *questions = (Question*)malloc(sizeof(Question)*ques_count);

    //Input the questions and answer options
    for(int i=0;i<ques_count;i++){
        printf("\nEnter the Question : ");
        scanf(" %[^\n]%*c",questions[i].ques);
        printf("Enter Option A : ");
        scanf("%s",questions[i].options[0]);
        printf("Enter Option B : ");
        scanf("%s",questions[i].options[1]);
        printf("Enter Option C : ");
        scanf("%s",questions[i].options[2]);
        printf("Enter Option D : ");
        scanf("%s",questions[i].options[3]);
        printf("Enter the Correct Answer (1/2/3/4) : ");
        scanf("%d",&questions[i].correct_ans);
    }

    //Start the exam with first question
    conduct_test(questions,1,0);

    free(questions); //Free the memory allocated for questions array

    return 0;
}