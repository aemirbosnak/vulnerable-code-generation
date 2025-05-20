//FormAI DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    char name[50];
    int id;
    float gpa;
} Student;

void printMenu() {
    printf("\n\nOPTIONS:\n");
    printf("1. Add a new student record\n");
    printf("2. Edit an existing student record\n");
    printf("3. Delete a student record\n");
    printf("4. View a student record\n");
    printf("5. View all student records\n");
    printf("0. Exit\n");
}

void addRecord(Student *students, int *numRecords) {
    if (*numRecords == MAX_RECORDS) {
        printf("\n\nERROR: Database is full\n");
        return;
    }
    
    printf("\n\nEnter student name: ");
    scanf("%s", students[*numRecords].name);
    printf("\nEnter student ID: ");
    scanf("%d", &students[*numRecords].id);
    printf("\nEnter student GPA: ");
    scanf("%f", &students[*numRecords].gpa);
    
    *numRecords += 1;
}

void editRecord(Student *students, int numRecords, int id) {
    int index = -1;
    
    for (int i = 0; i < numRecords; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\n\nERROR: Student not found\n");
        return;
    }
    
    printf("\n\nEnter new student name: ");
    scanf("%s", students[index].name);
    printf("\nEnter new student ID: ");
    scanf("%d", &students[index].id);
    printf("\nEnter new student GPA: ");
    scanf("%f", &students[index].gpa);
}

void deleteRecord(Student *students, int *numRecords, int id) {
    int index = -1;
    
    for (int i = 0; i < *numRecords; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\n\nERROR: Student not found\n");
        return;
    }
    
    for (int i = index; i < *numRecords - 1; i++) {
        students[i] = students[i+1];
    }
    
    *numRecords -= 1;
}

void viewRecord(Student *students, int numRecords, int id) {
    int index = -1;
    
    for (int i = 0; i < numRecords; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\n\nERROR: Student not found\n");
        return;
    }
    
    printf("\n\nName: %s\n", students[index].name);
    printf("ID: %d\n", students[index].id);
    printf("GPA: %.2f\n", students[index].gpa);
}

void viewAllRecords(Student *students, int numRecords) {
    printf("\n\nALL STUDENT RECORDS:\n");
    
    for (int i = 0; i < numRecords; i++) {
        printf("Name: %s\n", students[i].name);
        printf("ID: %d\n", students[i].id);
        printf("GPA: %.2f\n\n", students[i].gpa);
    }
}

int main() {
    Student students[MAX_RECORDS];
    int numRecords = 0;
    int choice, id;
    
    do {
        printMenu();
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addRecord(students, &numRecords);
                break;
            case 2:
                printf("\n\nEnter student ID to edit: ");
                scanf("%d", &id);
                editRecord(students, numRecords, id);
                break;
            case 3:
                printf("\n\nEnter student ID to delete: ");
                scanf("%d", &id);
                deleteRecord(students, &numRecords, id);
                break;
            case 4:
                printf("\n\nEnter student ID to view: ");
                scanf("%d", &id);
                viewRecord(students, numRecords, id);
                break;
            case 5:
                viewAllRecords(students, numRecords);
                break;
            case 0:
                printf("\n\nExiting program...\n");
                break;
            default:
                printf("\n\nERROR: Invalid choice\n");
                break;
        }
    } while (choice != 0);
    
    return 0;
}