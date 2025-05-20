//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_SIZE 50

typedef struct {
    int id;
    char name[NAME_SIZE];
} Student;

typedef struct {
    int id;
    int index; // Points to the index in the main student array
} Index;

Student students[MAX_STUDENTS];
Index indexArray[MAX_STUDENTS];
int studentCount = 0;
int indexCount = 0;

void addStudent(int id, const char *name) {
    if (studentCount >= MAX_STUDENTS) {
        printf("Database is full!\n");
        return;
    }
    students[studentCount].id = id;
    strcpy(students[studentCount].name, name);
    
    // Add entry to index
    indexArray[indexCount].id = id;
    indexArray[indexCount].index = studentCount;
    indexCount++;

    studentCount++;
}

int findStudentIndex(int id) {
    for (int i = 0; i < indexCount; i++) {
        if (indexArray[i].id == id) {
            return indexArray[i].index; // Return the index in the students array
        }
    }
    return -1; // Not found
}

void displayStudent(int index) {
    if (index >= 0 && index < studentCount) {
        printf("Id: %d, Name: %s\n", students[index].id, students[index].name);
    } else {
        printf("Invalid student index!\n");
    }
}

void displayAllStudents() {
    printf("All students:\n");
    for (int i = 0; i < studentCount; i++) {
        displayStudent(i);
    }
}

void displayIndex() {
    printf("Index:\n");
    for (int i = 0; i < indexCount; i++) {
        printf("Id: %d, Index in Students: %d\n", indexArray[i].id, indexArray[i].index);
    }
}

int main() {
    int choice, id;
    char name[NAME_SIZE];

    while (1) {
        printf("\n--- Student Database Menu ---\n");
        printf("1. Add Student\n");
        printf("2. Find Student by Id\n");
        printf("3. Display All Students\n");
        printf("4. Display Index\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Student ID: ");
                scanf("%d", &id);
                printf("Enter Student Name: ");
                scanf(" %[^\n]", name);
                addStudent(id, name);
                break;
            case 2:
                printf("Enter Student ID to find: ");
                scanf("%d", &id);
                int studentIndex = findStudentIndex(id);
                displayStudent(studentIndex);
                break;
            case 3:
                displayAllStudents();
                break;
            case 4:
                displayIndex();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    
    return 0;
}