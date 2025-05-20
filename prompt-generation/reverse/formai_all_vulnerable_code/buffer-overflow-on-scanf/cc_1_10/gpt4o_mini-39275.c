//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Student;

Student *students[MAX_STUDENTS];
int student_count = 0;

void add_student(int id, const char *name, int age) {
    if (student_count >= MAX_STUDENTS) {
        printf("Database is full, cannot add more students.\n");
        return;
    }
    Student *new_student = (Student *)malloc(sizeof(Student));
    new_student->id = id;
    strncpy(new_student->name, name, NAME_LENGTH);
    new_student->age = age;
    
    students[student_count++] = new_student;
    printf("Added student: %d, %s, %d\n", new_student->id, new_student->name, new_student->age);
}

void display_students() {
    printf("\nStudents List:\n");
    for (int i = 0; i < student_count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", students[i]->id, students[i]->name, students[i]->age);
    }
}

void update_student(int id, const char *new_name, int new_age) {
    for (int i = 0; i < student_count; i++) {
        if (students[i]->id == id) {
            strncpy(students[i]->name, new_name, NAME_LENGTH);
            students[i]->age = new_age;
            printf("Updated student: %d, %s, %d\n", students[i]->id, students[i]->name, students[i]->age);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void delete_student(int id) {
    for (int i = 0; i < student_count; i++) {
        if (students[i]->id == id) {
            free(students[i]);
            students[i] = students[student_count - 1]; // Replace with last
            students[student_count - 1] = NULL; // Nullify previous last
            student_count--;
            printf("Deleted student with ID %d.\n", id);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void free_memory() {
    for (int i = 0; i < student_count; i++) {
        free(students[i]);
    }
}

int main() {
    int choice, id, age;
    char name[NAME_LENGTH];

    while (1) {
        printf("\nDatabase Menu:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID, Name, Age: ");
                scanf("%d %s %d", &id, name, &age);
                add_student(id, name, age);
                break;
            case 2:
                display_students();
                break;
            case 3:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                printf("Enter new Name and Age: ");
                scanf("%s %d", name, &age);
                update_student(id, name, age);
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                delete_student(id);
                break;
            case 5:
                free_memory();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please enter again.\n");
        }
    }
}