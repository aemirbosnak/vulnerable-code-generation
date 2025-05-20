//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

typedef struct{
    char name[MAX];
    int rollno;
    char address[MAX];
    char phone[20];
} student;

student database[MAX];
int count = 0;

void addStudent(){
    printf("Enter name: ");
    scanf("%s",&database[count].name);
    printf("Enter roll number: ");
    scanf("%d",&database[count].rollno);
    printf("Enter address: ");
    scanf("%s",&database[count].address);
    printf("Enter phone number: ");
    scanf("%s",&database[count].phone);
    count++;
    printf("\nRecord added successfully!\n");
}

void removeStudent(){
    char name[MAX];
    printf("Enter name of student to be removed: ");
    scanf("%s",&name);
    int i;
    for(i=0;i<count;i++){
        if(strcmp(name,database[i].name)==0){
            printf("\nRecord removed successfully!\n");
            memmove(&database[i],&database[i+1],(count-i-1)*sizeof(student));
            count--;
            break;
        }
    }
}

void displayStudents(){
    printf("\nName\tRoll No.\tAddress\tPhone\n");
    int i;
    for(i=0;i<count;i++){
        printf("%s\t%d\t%s\t%s\n",database[i].name,database[i].rollno,database[i].address,database[i].phone);
    }
}

int main(){
    char choice;
    while(TRUE){
        printf("\nEnter 1 to add student\nEnter 2 to remove student\nEnter 3 to display students\nEnter 4 to exit\n");
        scanf("%c",&choice);
        switch(choice){
            case '1':
                addStudent();
                break;
            case '2':
                removeStudent();
                break;
            case '3':
                displayStudents();
                break;
            case '4':
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}