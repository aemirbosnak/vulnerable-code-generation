//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct student{
    char name[50];
    int roll_no;
    int marks[5];
};

void addStudent(struct student students[],int *size);
void displayStudents(struct student students[],int size);
void sortStudents(struct student students[],int size);

int main(){
    struct student students[MAX];
    int size=0;

    addStudent(students,&size);
    displayStudents(students,size);
    sortStudents(students,size);

    return 0;
}

void addStudent(struct student students[],int *size){
    char name[50];
    int roll_no,marks[5];

    printf("Enter the name of the student: ");
    scanf("%s",name);

    printf("Enter the roll number of the student: ");
    scanf("%d",&roll_no);

    printf("Enter the marks of the student in 5 subjects:\n");
    for(int i=0;i<5;i++){
        scanf("%d",&marks[i]);
    }

    strcpy(students[*size].name,name);
    students[*size].roll_no=roll_no;

    for(int i=0;i<5;i++){
        students[*size].marks[i]=marks[i];
    }

    (*size)++;
}

void displayStudents(struct student students[],int size){
    printf("Name\tRoll No.\t");
    for(int i=0;i<5;i++){
        printf("%d\t",i+1);
    }
    printf("\n");

    for(int i=0;i<size;i++){
        printf("%s\t%d\t",students[i].name,students[i].roll_no);

        for(int j=0;j<5;j++){
            printf("%d\t",students[i].marks[j]);
        }
        printf("\n");
    }
}

void sortStudents(struct student students[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(students[i].roll_no>students[j].roll_no){
                struct student temp=students[i];
                students[i]=students[j];
                students[j]=temp;
            }
        }
    }
}