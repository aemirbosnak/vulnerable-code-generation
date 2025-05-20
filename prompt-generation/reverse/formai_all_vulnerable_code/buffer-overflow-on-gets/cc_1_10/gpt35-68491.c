//FormAI DATASET v1.0 Category: Online Examination System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[20];
    int id;
    int marks[5];//for 5 subjects
};

void instructions(){
    printf("\t\t\tInstructions\n");
    printf("------------------------------------------------------------\n");
    printf("1. This exam consist of 5 subjective questions.\n");
    printf("2. You have one hour to complete the exam.\n");
    printf("3. Once you start the exam, you can not take a break.\n");
    printf("4. Avoid copying or sharing the answers.\n");
    printf("5. Any violation of exam rules will lead to disqualification.\n\n");
}

void enter_student_details(struct student *s){
    printf("Enter the following details:\n");
    printf("Name: ");
    gets(s->name);
    fflush(stdin);//to clear input buffer
    printf("ID: ");
    scanf("%d", &(s->id));
}

void display_marks(struct student *s, int total){
    printf("\n\n------------------------------------------------------------\n");
    printf("Details of the student:\nName: %s\nID: %d\nMarks obtained: %d/%d\n", s->name, s->id, total, 50);//total marks for the exam is 50
    printf("------------------------------------------------------------\n\n");
}

int main(){
    int i, total=0;
    char answer[100], c;
    struct student s;
    instructions();
    enter_student_details(&s);
    printf("Press Enter key to start the exam.");
    scanf("%c",&c);
    fflush(stdin);//to clear input buffer
    printf("\n\n");
    for(i = 0; i < 5; i++) {
        printf("Question %d:\n", i+1);
        gets(answer);
        if(strcmp(answer, "xyz") == 0)//answer to the question
            total += 10;//marks for each correct answer is 10
    }
    display_marks(&s, total);
    return 0;
}