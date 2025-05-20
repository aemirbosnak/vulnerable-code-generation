//FormAI DATASET v1.0 Category: Database simulation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

struct student{
    int roll;
    char name[30];
    float marks;
};

struct student details[MAX];
//creating a global array that will be our database

int indexPointer = 0;
//indexPointer will be used to keep track of the available index in our database

void insert(){
    //function to insert new student details into the database
    struct student newStudent;
    printf("\nEnter the student's roll number: ");
    scanf("%d",&newStudent.roll);
    printf("Enter the student's name: ");
    scanf("%s",newStudent.name);
    printf("Enter the student's marks: ");
    scanf("%f",&newStudent.marks);

    if(indexPointer < MAX){
        //checking if there is space available in our database
        details[indexPointer++] = newStudent;
        printf("\nRecord successfully added to the database!");
    }else{
        printf("\nDatabase is full, cannot add record!");
    }
}

void search(){
    //function to search for a student's details based on their roll number
    int searchRoll,i,found=0;
    printf("\nEnter the roll number to search: ");
    scanf("%d",&searchRoll);

    for(i=0;i<indexPointer;i++){
        if(details[i].roll==searchRoll){
            found=1;
            printf("\nRecord found!");
            printf("\nRoll number: %d",details[i].roll);
            printf("\nName: %s",details[i].name);
            printf("\nMarks: %.2f",details[i].marks);
            break;
        }
    }

    if(found==0){
        printf("\nRecord not found!");
    }
}

void display(){
    //function to display all the records in the database
    int i;
    printf("\nRoll Number\tName\t\tMarks");
    for(i=0;i<indexPointer;i++){
        printf("\n%d\t\t%s\t\t%.2f",details[i].roll,details[i].name,details[i].marks);
    }
}

int main(){
    int choice;
    do{
        printf("\n\n*** MENU ***");
        printf("\n1. Insert a Record");
        printf("\n2. Search for a Record");
        printf("\n3. Display all Records");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                insert();
                break;
            
            case 2:
                search();
                break;

            case 3:
                if(indexPointer==0){
                    printf("\nDatabase is empty, no records to display!");
                }else{
                    display();
                }
                break;

            case 4:
                exit(0); //exiting the program
                break;

            default:
                printf("\nInvalid choice, please try again!");
                break;
        }
    }while(1); //infinite loop to keep the program running

    return 0;
}