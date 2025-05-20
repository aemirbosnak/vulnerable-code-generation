//FormAI DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    char name[30];
    int age;
    char course[20];
};

void addStudentToFile(FILE *fptr){
    struct Student student;
    printf("Enter student name: ");
    scanf("%s", student.name);
    printf("Enter student age: ");
    scanf("%d", &student.age);
    printf("Enter student course: ");
    scanf("%s", student.course);
    fwrite(&student, sizeof(student), 1, fptr);
}

void displayStudentsInFile(FILE *fptr){
    struct Student student;
    printf("Students in file:\n");
    while(fread(&student, sizeof(student), 1, fptr) == 1){
        printf("Name: %s\n", student.name);
        printf("Age: %d\n", student.age);
        printf("Course: %s\n", student.course);
    }
}

int main(){
    FILE *fptr;
    int choice;
    fptr = fopen("students.txt", "ab+"); //Opening file in binary append mode
    if(fptr == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    
    do{
        printf("\n1. Add student to file\n");
        printf("2. Display students in file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                addStudentToFile(fptr);
                break;
            
            case 2:
                displayStudentsInFile(fptr);
                break;
            
            case 3:
                printf("Exiting program...\n");
                break;
            
            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 3);
    
    fclose(fptr);
    return 0;
}