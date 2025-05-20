//FormAI DATASET v1.0 Category: Database querying ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// example struct to store student data
typedef struct Student {
    char name[50];
    int age;
    char major[50];
    float gpa;
} Student;

// function to add a student to the database
void addStudent(Student *students, int *count) {
    // get user input for student data
    printf("Enter student name: ");
    scanf("%s", students[*count].name);
    printf("Enter student age: ");
    scanf("%d", &students[*count].age);
    printf("Enter student major: ");
    scanf("%s", students[*count].major);
    printf("Enter student GPA: ");
    scanf("%f", &students[*count].gpa);
    
    // increment count
    (*count)++;
    
    // confirm student was added
    printf("Student added to database.\n");
}

// function to print all students in the database
void printStudents(Student *students, int count) {
    // check if database is empty
    if (count == 0) {
        printf("Database is empty.\n");
        return;
    }
    
    // loop through database and print each student
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Major: %s\n", students[i].major);
        printf("GPA: %.2f\n", students[i].gpa);
        printf("\n");
    }
}

// function to search for a student by name
void searchStudent(Student *students, int count) {
    // get user input for name to search for
    char searchTerm[50];
    printf("Enter student name to search for: ");
    scanf("%s", searchTerm);
    
    // loop through database and search for matching name
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, searchTerm) == 0) {
            // print student data and return
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Major: %s\n", students[i].major);
            printf("GPA: %.2f\n", students[i].gpa);
            return;
        }
    }
    
    // student not found
    printf("Student not found.\n");
}

int main() {
    // initialize database variables
    Student *students = malloc(sizeof(Student) * 100);
    int count = 0;
    char choice;
    
    do {
        // display menu and get user choice
        printf("1. Add student\n");
        printf("2. Print all students\n");
        printf("3. Search for student by name\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);
        
        // perform action based on user choice
        switch (choice) {
            case '1':
                addStudent(students, &count);
                break;
            case '2':
                printStudents(students, count);
                break;
            case '3':
                searchStudent(students, count);
                break;
            case '4':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != '4');
    
    // free memory and exit program
    free(students);
    return 0;
}