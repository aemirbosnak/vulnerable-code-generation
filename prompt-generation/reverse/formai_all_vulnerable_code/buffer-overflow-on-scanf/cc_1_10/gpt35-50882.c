//FormAI DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//creating a struct for student record
struct student
{
    char name[20], id[10], department[20];
    int marks;
};

//creating a function to input student details
void input_student_details(struct student *s)
{
    printf("Enter student name: ");
    scanf("%s",s->name);
    printf("Enter student ID: ");
    scanf("%s",s->id);
    printf("Enter student department: ");
    scanf("%s",s->department);
}

//creating a function to conduct exam
int conduct_exam()
{
    int marks = 0;
    char choice[10];
    printf("Welcome to the Online Examination System.\n");
    printf("Please answer the following questions:\n\n");
    printf("Question 1: What is the capital of France?\n");
    printf("a. London    b. Paris    c. Tokyo\n");
    scanf("%s",choice);
    if(strcmp(choice,"b")==0)
        marks = marks + 10;

    printf("\nQuestion 2: Who invented the telephone?\n");
    printf("a. Alexander Graham Bell    b. Thomas Edison    c. Albert Einstein\n");
    scanf("%s",choice);
    if(strcmp(choice,"a")==0)
        marks = marks + 10;

    printf("\nQuestion 3: What is the largest continent in the world?\n");
    printf("a. Asia    b. Africa    c. Europe\n");
    scanf("%s",choice);
    if(strcmp(choice,"a")==0)
        marks = marks + 10;

    printf("\nQuestion 4: What is the currency of Japan?\n");
    printf("a. Yen    b. Dollar    c. Rupee\n");
    scanf("%s",choice);
    if(strcmp(choice,"a")==0)
        marks = marks + 10;

    printf("\nQuestion 5: Which is the longest river in the world?\n");
    printf("a. Amazon    b. Nile    c. Mississippi\n");
    scanf("%s",choice);
    if(strcmp(choice,"b")==0)
        marks = marks + 10;

    printf("\nExam completed.\n");
    return marks;
}

//creating a function to display student record
void display_student_record(struct student s)
{
    printf("\nStudent name: %s\n",s.name);
    printf("Student ID: %s\n",s.id);
    printf("Student department: %s\n",s.department);
    printf("Marks obtained: %d\n",s.marks);
}

int main()
{
    struct student s;
    int marks;

    //input student details
    input_student_details(&s);

    //conduct exam and get marks
    marks = conduct_exam();

    //store marks in student record and display student record
    s.marks = marks;
    display_student_record(s);

    printf("Thank you for using the Online Examination System.\n");

    return 0;
}