//FormAI DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    int grade;
} db[100];

int num_students = 0;

void add_student() {
    printf("Enter student id: ");
    scanf("%d", &db[num_students].id);
    printf("Enter student name: ");
    scanf("%s", db[num_students].name);
    printf("Enter student grade: ");
    scanf("%d", &db[num_students].grade);
    num_students++;
    printf("Student added to database!");
}

void find_student() {
    int id, i;
    printf("Enter student id to search: ");
    scanf("%d", &id);
    for (i = 0; i < num_students; i++) {
        if (db[i].id == id) {
            printf("Student found!\nId: %d\nName: %s\nGrade: %d\n", db[i].id, db[i].name, db[i].grade);
            return;
        }
    }
    printf("Student not found!");
}

void remove_student() {
    int id, i;
    printf("Enter student id to remove: ");
    scanf("%d", &id);
    for (i = 0; i < num_students; i++) {
        if (db[i].id == id) {
            db[i] = db[num_students-1];
            num_students--;
            printf("Student removed from database!");
            return;
        }
    }
    printf("Student not found!");
}

int main() {
    int choice;
    printf("Welcome to the Student Database Simulation Program!\n");
    do {
        printf("\nPlease select an option from the list below:\n");
        printf("1. Add a student to the database\n");
        printf("2. Find a student in the database\n");
        printf("3. Remove a student from the database\n");
        printf("4. Exit program\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_student();
                break;
            case 2:
                find_student();
                break;
            case 3:
                remove_student();
                break;
            case 4:
                printf("Goodbye!");
                return 0;
            default:
                printf("Invalid choice, please try again");
        }
    } while (choice != 4);
    return 0;
}