//FormAI DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Student;

Student database[100]; // array to store students data
int num_students = 0; // number of students in the database

void add_student() {
    Student s;
    printf("Enter student id: ");
    scanf("%d", &s.id);
    printf("Enter student name: ");
    scanf("%s", s.name);
    printf("Enter student age: ");
    scanf("%d", &s.age);
    database[num_students++] = s;
    printf("Student added successfully.\n");
}

void search_student() {
    int id;
    printf("Enter student id to search: ");
    scanf("%d", &id);
    for (int i = 0; i < num_students; i++) {
        if (database[i].id == id) {
            printf("Student found: id=%d name=%s age=%d\n", 
                database[i].id, database[i].name, database[i].age);
            return;
        }
    }
    printf("Student not found.\n");
}

void print_database() {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add student\n");
        printf("2. Search student\n");
        printf("3. Print database\n");
        printf("Enter your choice (or 0 to quit): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                search_student();
                break;
            case 3:
                print_database();
                break;
            case 0:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}