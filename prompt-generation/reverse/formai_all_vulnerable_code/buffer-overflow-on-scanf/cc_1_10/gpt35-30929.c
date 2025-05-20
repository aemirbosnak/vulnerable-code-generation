//FormAI DATASET v1.0 Category: Database simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

//Structure to store information of students
struct Student {
    int id;
    char name[50];
    char major[50];
};

//Function to print a student's information
void printStudent(struct Student s) {
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Major: %s\n", s.major);
    printf("\n");
}

//Function to add a new student to the database
void addStudent(struct Student students[], int *count) {
    struct Student s;
    printf("Enter student ID: ");
    scanf("%d", &s.id);
    printf("Enter student name: ");
    scanf("%s", s.name);
    printf("Enter student major: ");
    scanf("%s", s.major);
    students[*count] = s;
    (*count)++;
    printf("Student added to database.\n\n");
}

//Function to search for a student by ID
void searchStudent(struct Student students[], int count) {
    int id;
    printf("Enter student ID to search for: ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++) {
        if(students[i].id == id) {
            printf("Student found!\n");
            printStudent(students[i]);
            return;
        }
    }
    printf("Student not found.\n\n");
}

int main() {
    struct Student students[MAX_SIZE];
    int count = 0;
    int choice;
    
    while(1) {
        printf("Database Menu:\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Exit\n\n");
        
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                searchStudent(students, count);
                break;
            case 3:
                printf("Exiting database.\n");
                exit(0);
            default:
                printf("Invalid choice.\n\n");
        }
    }
    return 0;
}