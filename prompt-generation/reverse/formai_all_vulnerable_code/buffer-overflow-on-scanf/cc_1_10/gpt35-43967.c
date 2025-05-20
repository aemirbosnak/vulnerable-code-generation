//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct student {
    int id;
    char name[20];
    float gpa;
};

typedef struct student Student;

void add_student(Student *db, int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Error: Database full.\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &(db[*count].id));

    printf("Enter student name: ");
    scanf("%s", db[*count].name);

    printf("Enter student GPA: ");
    scanf("%f", &(db[*count].gpa));

    (*count)++;
}

void print_student(Student *s) {
    printf("%d\t%s\t%.2f\n", s->id, s->name, s->gpa);
}

void print_all_students(Student *db, int count) {
    printf("ID\tName\tGPA\n");
    for (int i = 0; i < count; i++) {
        print_student(&db[i]);
    }
}

void search_student_by_id(Student *db, int count) {
    int id_to_search;
    printf("Enter student ID: ");
    scanf("%d", &id_to_search);

    for (int i = 0; i < count; i++) {
        if (db[i].id == id_to_search) {
            print_student(&db[i]);
            return;
        }
    }

    printf("Error: Student not found.\n");
}

void delete_student_by_id(Student *db, int *count) {
    int id_to_delete;
    printf("Enter student ID: ");
    scanf("%d", &id_to_delete);

    for (int i = 0; i < *count; i++) {
        if (db[i].id == id_to_delete) {
            memmove(&db[i], &db[i+1], (*count-i-1) * sizeof(Student));
            (*count)--;
            printf("Student deleted from database.\n");
            return;
        }
    }

    printf("Error: Student not found.\n");
}

int menu() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Add student.\n");
    printf("2. Print all students.\n");
    printf("3. Search student by ID.\n");
    printf("4. Delete student by ID.\n");
    printf("5. Quit.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int count = 0;
    Student db[MAX_RECORDS];

    int choice;
    do {
        choice = menu();

        switch(choice) {
            case 1:
                add_student(db, &count);
                break;
            case 2:
                print_all_students(db, count);
                break;
            case 3:
                search_student_by_id(db, count);
                break;
            case 4:
                delete_student_by_id(db, &count);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Error: Invalid option.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}