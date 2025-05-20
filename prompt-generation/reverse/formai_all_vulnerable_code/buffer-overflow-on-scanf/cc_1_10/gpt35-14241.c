//FormAI DATASET v1.0 Category: Database simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // maximum number of records allowed

struct Student{
    int id;
    char name[50];
    int age;
    char program[50];
};

struct Student students[MAX_RECORDS]; // array to store student records
int num_of_students = 0; // track the number of student records

void addStudent(){
    if(num_of_students >= MAX_RECORDS){
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }
    struct Student newStudent;
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student age: ");
    scanf("%d", &newStudent.age);
    printf("Enter student program: ");
    scanf("%s", newStudent.program);
    newStudent.id = num_of_students + 1;
    students[num_of_students] = newStudent;
    num_of_students++;
    printf("New student added successfully.\n");
}

void displayStudents(){
    if(num_of_students == 0){
        printf("No student records found.\n");
        return;
    }
    printf("%-5s %-20s %-5s %-20s\n", "ID", "Name", "Age", "Program");
    for(int i=0; i<num_of_students; i++){
        struct Student currStudent = students[i];
        printf("%-5d %-20s %-5d %-20s\n", currStudent.id, currStudent.name, currStudent.age, currStudent.program);
    }
}

void removeStudent(){
    if(num_of_students == 0){
        printf("No student records found.\n");
        return;
    }
    int idToRemove;
    printf("Enter the ID of the student to remove: ");
    scanf("%d", &idToRemove);
    int indexToRemove = -1;
    for(int i=0; i<num_of_students; i++){
        if(students[i].id == idToRemove){
            indexToRemove = i;
            break;
        }
    }
    if(indexToRemove == -1){
        printf("Student record not found.\n");
        return;
    }
    for(int i=indexToRemove; i<num_of_students-1; i++){
        students[i] = students[i+1];
    }
    num_of_students--;
    printf("Student record removed successfully.\n");
}

int main(){
    printf("Welcome to the Student Database.\n");
    int choice;
    do{
        printf("Enter 1 to add a new student record.\n");
        printf("Enter 2 to display all student records.\n");
        printf("Enter 3 to remove a student record.\n");
        printf("Enter 4 to exit the program.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                removeStudent();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }while(choice != 4);
    return 0;
}