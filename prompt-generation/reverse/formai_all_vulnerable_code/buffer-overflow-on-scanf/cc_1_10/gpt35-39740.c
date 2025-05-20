//FormAI DATASET v1.0 Category: Online Examination System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    int rollno;
    char name[30];
    int marks[5];
};
struct student s[50];

void add_student(int n){
    int i,j;
    printf("\nEnter details of students:");
    for(i=0;i<n;i++){
        printf("\nStudent[%d]\n",i+1);
        printf("\nEnter Roll No:");
        scanf("%d",&s[i].rollno);
        printf("\nEnter Name:");
        scanf("%s",s[i].name);
        printf("\nEnter Marks of 5 subjects:");
        for(j=0;j<5;j++){
            scanf("%d",&s[i].marks[j]);
        }
    }
}

void show_student(int n){
    int i,j;
    printf("\nStudent Details:\n");
    for(i=0;i<n;i++){
        printf("\nStudent[%d]\n",i+1);
        printf("Roll No=%d\n",s[i].rollno);
        printf("Name=%s\n",s[i].name);
        printf("Marks=");
        for(j=0;j<5;j++){
            printf("%d\t",s[i].marks[j]);
        }
        printf("\n");
    }
}

int main(){
    int n,i,choice;
    printf("\nEnter no of students:");
    scanf("%d",&n);
    do{
        printf("\nMenu\n");
        printf("----------------------\n");
        printf("1.Add Student\n2.Show Student\n3.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: add_student(n);
                    break;
            case 2: show_student(n);
                    break;
            case 3: exit(0);
            default: printf("\nInvalid Choice!!!");
        }
    }while(choice!=3);
    return 0;
}