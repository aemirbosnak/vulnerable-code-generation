//FormAI DATASET v1.0 Category: Online Examination System ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Student structure
struct student{
    char name[50];
    int rollno;
    int marks;
}students[100];

//Global Variables
int totalstudents = 0;
int maxmarks = 100;

//Function prototypes
void addstudent();
void viewstudents();
void takeexam();

//Main Function
int main(){
    int choice;
    do{
        printf("\n----------Online Examination System----------\n");
        printf("\n1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Take Exam\n");
        printf("4. Exit\n");
        printf("\nEnter your choice (1-4):");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                addstudent();
                break;
            case 2:
                viewstudents();
                break;
            case 3:
                takeexam();
                break;
            case 4:
                printf("\nThank you for using our Online Examination System.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please select a valid choice (1-4).\n");
        }
    }while(choice!=4);
    return 0;
}

//Function to add students
void addstudent(){
    printf("\n----------Add Student----------\n");
    printf("\nEnter Student name:");
    scanf("%s",students[totalstudents].name);
    printf("Enter Student Roll no:");
    scanf("%d",&students[totalstudents].rollno);
    totalstudents++;
    printf("\nStudent added successfully.\n");
}

//Function to view students
void viewstudents(){
    printf("\n----------Student List----------\n");
    printf("\nName\tRoll No.\n");
    for(int i=0;i<totalstudents;i++){
        printf("%s\t%d\n",students[i].name,students[i].rollno);
    }
}

//Function to take exam
void takeexam(){
    int rollno,marks;
    printf("\n----------Take Exam----------\n");
    printf("\nEnter your Roll no:");
    scanf("%d",&rollno);
    int found = 0;
    for(int i=0;i<totalstudents;i++){
        if(students[i].rollno == rollno){
            found = 1;
            printf("Enter your marks out of %d:",maxmarks);
            scanf("%d",&marks);
            if(marks <= maxmarks){
                students[i].marks = marks;
            }
            else{
                printf("\nInvalid marks. Please enter marks out of %d.\n",maxmarks);
            }
            break;
        }
    }
    if(found == 0){
        printf("\nStudent not found with the given Roll no. Please enter a valid Roll no.\n");
    }
}