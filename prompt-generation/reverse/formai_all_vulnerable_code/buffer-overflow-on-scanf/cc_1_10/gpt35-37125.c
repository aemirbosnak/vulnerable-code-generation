//FormAI DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// maximum size of database
#define MAX_SIZE 100

// structure for the database
struct student {
    int id;
    char name[50];
    char major[50];
};

typedef struct student Student;

// function prototypes
void insertStudent(Student[], int*, Student*);
void deleteStudent(Student[], int*, int);
void displayDatabase(Student[], int);

int main() {
    Student database[MAX_SIZE]; // array to store database entries
    int numStudents = 0; // variable to keep track of number of students in database
    int choice = 0;

    while (1) {
        printf("\n1. Insert new Student\n2. Delete Student\n3. Display Database\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Student* newStudent = (Student*)malloc(sizeof(Student));
                printf("Enter Student ID: ");
                scanf("%d", &newStudent->id);
                printf("Enter Student Name: ");
                scanf("%s", newStudent->name);
                printf("Enter Student Major: ");
                scanf("%s", newStudent->major);
                insertStudent(database, &numStudents, newStudent);
                break;
            }
            case 2: {
                int id;
                printf("Enter Student ID to delete: ");
                scanf("%d", &id);
                deleteStudent(database, &numStudents, id);
                break;
            }
            case 3: {
                displayDatabase(database, numStudents);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice! Please enter a valid choice (1-4).\n");
                break;
            }
        }
    }

    return 0;
}

// function to insert a new student into the database
void insertStudent(Student database[], int* numStudents, Student* newStudent) {
    if (*numStudents == MAX_SIZE) {
        printf("Database is full! Cannot insert new Student.\n");
        return;
    }
    
    // check if student with same ID already exists
    for (int i = 0; i < *numStudents; i++) {
        if (database[i].id == newStudent->id) {
            printf("Student with same ID already exists in the database! Cannot insert new Student.\n");
            return;
        }
    }

    database[*numStudents] = *newStudent;
    (*numStudents)++;
    printf("Student successfully inserted into the database.\n");
}

// function to delete a student from the database
void deleteStudent(Student database[], int* numStudents, int id) {
    int found = 0;

    for (int i = 0; i < *numStudents; i++) {
        if (database[i].id == id) {
            for (int j = i; j < *numStudents-1; j++) {
                database[j] = database[j+1];
            }
            (*numStudents)--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Student with ID %d successfully deleted from the database.\n", id);
    } else {
        printf("Student with ID %d not found in the database! Cannot delete Student.\n", id);
    }
}

// function to display the database
void displayDatabase(Student database[], int numStudents) {
    if (numStudents == 0) {
        printf("Database is empty!\n");
        return;
    }

    printf("------------------------DATABASE------------------------\n");
    printf("ID\tName\t\tMajor\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t%s\t\t%s\n", database[i].id, database[i].name, database[i].major);
    }
    printf("--------------------------------------------------------\n");
}