//FormAI DATASET v1.0 Category: Educational ; Style: Dennis Ritchie
/* This is a program that uses structures to create a database of students */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

/* Define the student structure */
struct student {
    char name[50];
    int age;
    int grade;
};

/* Declare the database array */
struct student database[MAX_STUDENTS];

/* Declare the function prototypes */
void add_student();
void print_database();

/* The main function */
int main() {
    printf("Welcome to the student database program!\n\n");

    while (1) {
        int choice;
        printf("Select an option:\n");
        printf("1. Add a student\n");
        printf("2. Print the database\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_student();
                break;
            case 2:
                print_database();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}

/* The function to add a student */
void add_student() {
    static int num_students = 0;

    if (num_students < MAX_STUDENTS) {
        struct student new_student;

        printf("Enter the student's name: ");
        scanf("%s", new_student.name);

        printf("Enter the student's age: ");
        scanf("%d", &new_student.age);

        printf("Enter the student's grade: ");
        scanf("%d", &new_student.grade);

        database[num_students++] = new_student;

        printf("New student added to the database.\n\n");
    } else {
        printf("Database is full! Cannot add anymore students.\n\n");
    }
}

/* The function to print the database */
void print_database() {
    printf("Student Name\tAge\tGrade\n");

    for (int i = 0; i < MAX_STUDENTS && strlen(database[i].name) > 0; i++) {
        printf("%s\t\t%d\t%d\n", database[i].name, database[i].age, database[i].grade);
    }

    printf("\n");
}