//FormAI DATASET v1.0 Category: Database simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_ID_LEN 10

// Define a struct for a student
struct Student {
    char name[MAX_NAME_LEN];
    char id[MAX_ID_LEN];
    int age;
};

// Define a database of students
struct Student database[1000];
int num_students = 0;

// A menu function to display options to the user
void display_menu() {
    printf("\nMenu:\n");
    printf("1. Add a student\n");
    printf("2. Delete a student\n");
    printf("3. Show all students\n");
    printf("4. Search for a student\n");
    printf("5. Quit\n");
}

// A helper function to find a student by ID
int find_student_by_id(char *id) {
    int i;
    for (i = 0; i < num_students; i++) {
        if (strcmp(database[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

// Add a student to the database
void add_student() {
    struct Student new_student;
    printf("\nEnter name:\n");
    scanf("%s", new_student.name);
    printf("Enter ID:\n");
    scanf("%s", new_student.id);
    printf("Enter age:\n");
    scanf("%d", &new_student.age);
    database[num_students] = new_student;
    num_students++;
    printf("Added student to database.\n");
}

// Delete a student from the database
void delete_student() {
    char id[MAX_ID_LEN];
    printf("\nEnter ID of student to delete:\n");
    scanf("%s", id);
    int idx = find_student_by_id(id);
    if (idx == -1) {
        printf("Student not found.\n");
    } else {
        int i;
        for (i = idx; i < num_students - 1; i++) {
            database[i] = database[i + 1];
        }
        num_students--;
        printf("Deleted student from database.\n");
    }
}

// Show all students in the database
void show_all_students() {
    int i;
    printf("\n");
    for (i = 0; i < num_students; i++) {
        printf("Name: %s, ID: %s, Age: %d\n", database[i].name, database[i].id, database[i].age);
    }
}

// Search for a student by ID
void search_student() {
    char id[MAX_ID_LEN];
    printf("\nEnter ID of student to search:\n");
    scanf("%s", id);
    int idx = find_student_by_id(id);
    if (idx == -1) {
        printf("Student not found.\n");
    } else {
        printf("Name: %s, ID: %s, Age: %d\n", database[idx].name, database[idx].id, database[idx].age);
    }
}

int main() {
    int choice;
    do {
        display_menu();
        printf("\nEnter your choice (1-5):\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                delete_student();
                break;
            case 3:
                show_all_students();
                break;
            case 4:
                search_student();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}