//FormAI DATASET v1.0 Category: Database simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int age;
    float gpa;
};

void add_student(struct student db[], int *num_students);
void find_student(struct student db[], int num_students);
void print_students(struct student db[], int num_students);

int main() {
    struct student db[50];
    int num_students = 0;
    char option;

    while(1) {
        printf("\n--- STUDENT DATABASE ---\n");
        printf("1. Add Student\n");
        printf("2. Find Student\n");
        printf("3. Print All Students\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf(" %c", &option);

        switch(option) {
            case '1':
                add_student(db, &num_students);
                break;
            case '2':
                find_student(db, num_students);
                break;
            case '3':
                print_students(db, num_students);
                break;
            case '4':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

void add_student(struct student db[], int *num_students) {
    if(*num_students >= 50) {
        printf("Database is full. Cannot add more students.\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]", db[*num_students].name);

    printf("Enter age: ");
    scanf(" %d", &db[*num_students].age);

    printf("Enter GPA: ");
    scanf(" %f", &db[*num_students].gpa);

    (*num_students)++;
    printf("Student added successfully.\n");
}

void find_student(struct student db[], int num_students) {
    char name[50];
    int i, found = 0;

    printf("Enter name: ");
    scanf(" %[^\n]", name);

    for(i = 0; i < num_students; i++) {
        if(strcmp(db[i].name, name) == 0) {
            found = 1;
            printf("Name: %s\n", db[i].name);
            printf("Age: %d\n", db[i].age);
            printf("GPA: %.2f\n", db[i].gpa);
            break;
        }
    }

    if(!found) {
        printf("Student not found.\n");
    }
}

void print_students(struct student db[], int num_students) {
    int i;

    printf("Name\tAge\tGPA\n");
    printf("------------------------\n");

    for(i = 0; i < num_students; i++) {
        printf("%s\t%d\t%.2f\n", db[i].name, db[i].age, db[i].gpa);
    }

    printf("------------------------\n");
}