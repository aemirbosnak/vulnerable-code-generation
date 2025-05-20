//FormAI DATASET v1.0 Category: Database querying ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int id;
    char name[50];
    float marks;
};

void main(){

    int n, id, choice;
    float marks;
    char name[50];

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student *ptr;
    ptr = (struct student*)malloc(n * sizeof(struct student));

    for(int i=0; i<n; i++){
        printf("Enter student id, name and marks (separate each with a space): ");
        scanf("%d %s %f", &(ptr+i)->id, (ptr+i)->name, &(ptr+i)->marks);
    }

    printf("\nEnter your query:\n");
    printf("1. Find details of student with a particular id\n");
    printf("2. Find details of students with marks above a particular value\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){

        case 1: 
            printf("\nEnter the student id: ");
            scanf("%d", &id);
            for(int i=0; i<n; i++){
                if((ptr+i)->id == id){
                    printf("\nStudent details:\n");
                    printf("ID: %d\n", (ptr+i)->id);
                    printf("Name: %s\n", (ptr+i)->name);
                    printf("Marks: %.2f", (ptr+i)->marks);
                    break;
                }
            }
            break;

        case 2:
            printf("\nEnter the minimum marks: ");
            scanf("%f", &marks);
            for(int i=0; i<n; i++){
                if((ptr+i)->marks > marks){
                    printf("\nStudent details:\n");
                    printf("ID: %d\n", (ptr+i)->id);
                    printf("Name: %s\n", (ptr+i)->name);
                    printf("Marks: %.2f", (ptr+i)->marks);
                }
            }
            break;

        default:
            printf("\nInvalid choice. Please enter a valid choice.");
    }

    free(ptr);
}