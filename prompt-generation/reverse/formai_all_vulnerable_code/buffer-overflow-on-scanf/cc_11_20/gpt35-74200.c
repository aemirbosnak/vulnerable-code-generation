//FormAI DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program simulates a unique indexing system for a student database */

typedef struct Student {
    int roll_no;
    char name[50];
    char course[30];
    float gpa;
} Student;

typedef struct Index {
    char name[50];
    int roll_no;
} Index;

int main() {
    int num_students;
    printf("Welcome to the Student Database Indexing System!\n");
    printf("How many students would you like to input?\n");
    scanf("%d", &num_students);

    Student *students = (Student*)malloc(num_students * sizeof(Student));
    Index *name_index = (Index*)malloc(num_students * sizeof(Index));
    Index *roll_no_index = (Index*)malloc(num_students * sizeof(Index));

    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d:\n", i+1);
        printf("Enter Roll No: ");
        scanf("%d", &(students[i].roll_no));
        printf("Enter Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Enter Course: ");
        scanf(" %[^\n]", students[i].course);
        printf("Enter GPA: ");
        scanf("%f", &(students[i].gpa));

        /* Add index entries for name and roll_no */
        strcpy(name_index[i].name, students[i].name);
        name_index[i].roll_no = students[i].roll_no;
        roll_no_index[i].roll_no = students[i].roll_no;
        strcpy(roll_no_index[i].name, students[i].name);
    }

    /* Sort name_index by name */
    for (int i = 0; i < num_students-1; i++) {
        for (int j = i+1; j < num_students; j++) {
            if (strcmp(name_index[i].name, name_index[j].name) > 0) {
                Index temp = name_index[i];
                name_index[i] = name_index[j];
                name_index[j] = temp;
            }
        }
    }

    /* Sort roll_no_index by roll_no */
    for (int i = 0; i < num_students-1; i++) {
        for (int j = i+1; j < num_students; j++) {
            if (roll_no_index[i].roll_no > roll_no_index[j].roll_no) {
                Index temp = roll_no_index[i];
                roll_no_index[i] = roll_no_index[j];
                roll_no_index[j] = temp;
            }
        }
    }

    /* Search for student by name */
    char search_name[50];
    printf("\nEnter a Name to search for in the database: ");
    scanf(" %[^\n]", search_name);
    int found = 0;
    for (int i = 0; i < num_students; i++) {
        if (strcmp(search_name, name_index[i].name) == 0) {
            printf("\nFound Student with Name: %s\n", name_index[i].name);
            printf("Roll No: %d\n", name_index[i].roll_no);
            printf("Course: %s\n", students[name_index[i].roll_no-1].course);
            printf("GPA: %.2f\n", students[name_index[i].roll_no-1].gpa);
            found = 1;
        }
    }
    if (!found) {
        printf("\nStudent with Name %s not found in the database.\n", search_name);
    }

    /* Search for student by roll no */
    int search_roll_no;
    printf("\nEnter a Roll No to search for in the database: ");
    scanf("%d", &search_roll_no);
    found = 0;
    for (int i = 0; i < num_students; i++) {
        if (search_roll_no == roll_no_index[i].roll_no) {
            printf("\nFound Student with Roll No: %d\n", roll_no_index[i].roll_no);
            printf("Name: %s\n", roll_no_index[i].name);
            printf("Course: %s\n", students[roll_no_index[i].roll_no-1].course);
            printf("GPA: %.2f\n", students[roll_no_index[i].roll_no-1].gpa);
            found = 1;
        }
    }
    if (!found) {
        printf("\nStudent with Roll No %d not found in the database.\n", search_roll_no);
    }

    /* Free memory */
    free(students);
    free(name_index);
    free(roll_no_index);

    return 0;
}