//FormAI DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* structure to store student's details */
typedef struct{
    char name[30];
    int age;
    char gender[10];
    char roll_no[20];
} student;

/* structure to store question and answer for each question */
typedef struct{
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int correct_option;
} question;

/* function to display menu */
void display_menu(){
    printf("\n===== ONLINE EXAMINATION SYSTEM =====\n");
    printf("1. Add student details\n");
    printf("2. Start exam\n");
    printf("3. Exit\n");
}

/* function to add student details */
void add_student(student* s){
    printf("\nEnter student details:\n");
    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter age: ");
    scanf("%d", &s->age);
    printf("Enter gender: ");
    scanf("%s", s->gender);
    printf("Enter roll no: ");
    scanf("%s", s->roll_no);
    printf("\nStudent details added successfully!\n");
}

/* function to get questions and their answers */
void get_questions(question* q){
    printf("\nEnter exam details:\n");
    printf("Enter question no 1:\n");
    scanf("%s", q[0].question);
    printf("Option 1: ");
    scanf("%s", q[0].option1);
    printf("Option 2: ");
    scanf("%s", q[0].option2);
    printf("Option 3: ");
    scanf("%s", q[0].option3);
    printf("Option 4: ");
    scanf("%s", q[0].option4);
    printf("Enter correct option (1-4): ");
    scanf("%d", &q[0].correct_option);
    
    printf("\nEnter question no 2:\n");
    scanf("%s", q[1].question);
    printf("Option 1: ");
    scanf("%s", q[1].option1);
    printf("Option 2: ");
    scanf("%s", q[1].option2);
    printf("Option 3: ");
    scanf("%s", q[1].option3);
    printf("Option 4: ");
    scanf("%s", q[1].option4);
    printf("Enter correct option (1-4): ");
    scanf("%d", &q[1].correct_option);
    
    printf("\nEnter question no 3:\n");
    scanf("%s", q[2].question);
    printf("Option 1: ");
    scanf("%s", q[2].option1);
    printf("Option 2: ");
    scanf("%s", q[2].option2);
    printf("Option 3: ");
    scanf("%s", q[2].option3);
    printf("Option 4: ");
    scanf("%s", q[2].option4);
    printf("Enter correct option (1-4): ");
    scanf("%d", &q[2].correct_option);
}

/* function to display questions and get student's answers */
int answer_questions(question* q){
    int marks=0, ans;
    printf("\nAnswer the following questions:\n");
    for(int i=0;i<3;i++){
        printf("\n%s\n", q[i].question);
        printf("1. %s\n", q[i].option1);
        printf("2. %s\n", q[i].option2);
        printf("3. %s\n", q[i].option3);
        printf("4. %s\n", q[i].option4);
        printf("Enter your answer (1-4): ");
        scanf("%d", &ans);
        if(ans==q[i].correct_option)
            marks++;
    }
    return marks;
}

/* main function */
int main(){
    student s;
    int choice, marks;
    question q[3];
    do{
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_student(&s);
                break;
            case 2:
                if(strlen(s.name)==0){
                    printf("\nError: Student details not added.\n");
                    break;
                }
                get_questions(q);
                marks = answer_questions(q);
                printf("\nMarks obtained: %d\n", marks);
                break;
            case 3:
                printf("\nExiting program...");
                exit(0);
                break;
            default:
                printf("\nError: Invalid choice.\n");
                break;
        }
    }while(1);
    return 0;
}