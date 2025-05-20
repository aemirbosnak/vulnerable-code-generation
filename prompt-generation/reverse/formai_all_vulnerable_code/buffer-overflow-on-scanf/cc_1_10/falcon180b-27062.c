//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 50

struct student{
    char name[MAX];
    int rollno;
    int marks[5];
};

void addStudent(struct student *s){
    int i;
    printf("\nEnter name of the student: ");
    scanf("%s",s->name);
    printf("Enter roll number of the student: ");
    scanf("%d",&s->rollno);
    for(i=0;i<5;i++){
        printf("Enter marks of subject %d: ",i+1);
        scanf("%d",&s->marks[i]);
    }
}

void displayStudents(struct student s[],int n){
    int i;
    printf("\nName\tRoll No.\t");
    for(i=0;i<5;i++){
        printf("Subject %d\t",i+1);
    }
    printf("\n");
    for(i=0;i<n;i++){
        printf("%s\t%d\t",s[i].name,s[i].rollno);
        for(int j=0;j<5;j++){
            printf("%d\t",s[i].marks[j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter number of students: ");
    scanf("%d",&n);
    struct student s[n];
    printf("\nEnter details of %d students:\n",n);
    for(int i=0;i<n;i++){
        addStudent(&s[i]);
    }
    printf("\nDetails of students:\n");
    displayStudents(s,n);
    return 0;
}