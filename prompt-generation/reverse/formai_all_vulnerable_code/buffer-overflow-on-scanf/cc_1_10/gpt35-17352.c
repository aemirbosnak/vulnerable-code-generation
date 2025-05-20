//FormAI DATASET v1.0 Category: Online Examination System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    char name[30];
    int rollno;
    int marks;
}Student;

//Function to take student information
void getStudentInfo(Student* s){
    printf("Enter name: ");
    scanf("%s",&s->name);
    printf("Enter rollno: ");
    scanf("%d",&s->rollno);
}

//Function to take student marks
void getStudentMarks(Student* s){
    printf("Enter marks: ");
    scanf("%d",&s->marks);
}

//Function to print student information
void printStudentInfo(Student s){
    printf("Name: %s \t Roll No: %d \t Marks: %d\n",s.name,s.rollno,s.marks);
}

int main(){
    int n,i;
    printf("Enter no of students: ");
    scanf("%d",&n);

    Student* students = (Student*)malloc(n*sizeof(Student));

    for(i=0;i<n;i++){
        printf("\n\nEnter student %d details\n ",i+1);
        getStudentInfo(&students[i]);
        getStudentMarks(&students[i]);
    }

    printf("\n\nEntered details are\n");
    for(i=0;i<n;i++){
        printStudentInfo(students[i]);
    }

    free(students);
    return 0;
}