//FormAI DATASET v1.0 Category: Online Examination System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defining a structure to hold student's details
struct student{
    char name[50];
    int roll_no;
    char branch[10];
    int marks;
};

//function to take student's details as input
void enter_details(struct student *s){
    printf("Enter the student's name: ");
    fgets(s->name, 50, stdin);
    printf("Enter the student's roll number: ");
    scanf("%d", &s->roll_no);
    printf("Enter the student's branch: ");
    scanf("%s", s->branch);
}

//function to display student's details
void display_details(struct student *s){
    printf("\nStudent's Name: %s", s->name);
    printf("Student's Roll Number: %d", s->roll_no);
    printf("Student's Branch: %s", s->branch);
    printf("Student's Marks: %d", s->marks);
}

//function to take exam
void take_exam(struct student *s){
    printf("Welcome to the Online Exam System!\n");
    printf("Please answer the following questions:\n");
    printf("Q1: What is the capital of India?\n");
    printf("a. New Delhi\n");
    printf("b. Mumbai\n");
    printf("c. Chennai\n");
    printf("d. Kolkata\n");
    char ans1;
    printf("Enter your answer (a/b/c/d): ");
    scanf(" %c", &ans1);
    if(ans1=='a'){
        s->marks += 1;
    }
    printf("Q2: Which is the largest planet in our solar system?\n");
    printf("a. Earth\n");
    printf("b. Jupiter\n");
    printf("c. Saturn\n");
    printf("d. Mars\n");
    char ans2;
    printf("Enter your answer (a/b/c/d): ");
    scanf(" %c", &ans2);
    if(ans2=='b'){
        s->marks += 1;
    }
    printf("Q3: Who is the founder of Microsoft?\n");
    printf("a. Steve Jobs\n");
    printf("b. Bill Gates\n");
    printf("c. Mark Zuckerberg\n");
    printf("d. Larry Page\n");
    char ans3;
    printf("Enter your answer (a/b/c/d): ");
    scanf(" %c", &ans3);
    if(ans3=='b'){
        s->marks += 1;
    }
}

//main function
int main(){
    struct student s;
    enter_details(&s);
    take_exam(&s);
    display_details(&s);
    return 0;
}