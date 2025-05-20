//FormAI DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_ID_LENGTH 10
#define MAX_GRADE_LENGTH 4
#define MAX_STUDENTS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    char grade[MAX_GRADE_LENGTH];
} Student;

void print_menu(void);
void add_student(Student[], int*);
void print_students(Student[], int);
void search_student(Student[], int);
void delete_student(Student[], int*);

int main(void) {
    Student students[MAX_STUDENTS];
    int num_students = 0;
    int choice = 0;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(students, &num_students);
                break;
            case 2:
                print_students(students, num_students);
                break;
            case 3:
                search_student(students, num_students);
                break;
            case 4:
                delete_student(students, &num_students);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void print_menu(void) {
    printf("Please select an option:\n");
    printf("1. Add a student\n");
    printf("2. Print all students\n");
    printf("3. Search for a student\n");
    printf("4. Delete a student\n");
    printf("5. Exit program\n");
}

void add_student(Student students[], int *num_students) {
    if (*num_students == MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    printf("Please enter the student's name: ");
    scanf("%s", students[*num_students].name);

    printf("Please enter the student's ID: ");
    scanf("%s", students[*num_students].id);
    
    printf("Please enter the student's grade: ");
    scanf("%s", students[*num_students].grade);

    (*num_students)++;
}

void print_students(Student students[], int num_students) {
    if (num_students == 0) {
        printf("No students found.\n");
        return;
    }

    printf("Name\tID\tGrade\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s\t%s\t%s\n", students[i].name, students[i].id, students[i].grade);
    }
}

void search_student(Student students[], int num_students) {
    char search_id[MAX_ID_LENGTH];
    printf("Please enter the ID of the student you want to search for: ");
    scanf("%s", search_id);

    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].id, search_id) == 0) {
            printf("Name: %s\nID: %s\nGrade: %s\n", students[i].name, students[i].id, students[i].grade);
            return;
        }
    }

    printf("Student not found.\n");
}

void delete_student(Student students[], int *num_students) {
    char search_id[MAX_ID_LENGTH];
    printf("Please enter the ID of the student you want to delete: ");
    scanf("%s", search_id);

    for (int i = 0; i < *num_students; i++) {
        if (strcmp(students[i].id, search_id) == 0) {
            *num_students -= 1;
            for (int j = i; j < *num_students; j++) {
                students[j] = students[j + 1];
            }
            printf("Student successfully deleted.\n");
            return;
        }
    }

    printf("Student not found.\n");
}