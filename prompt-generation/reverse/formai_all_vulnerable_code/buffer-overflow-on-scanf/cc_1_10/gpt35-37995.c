//FormAI DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Student;

int main() {
    Student database[MAX_STUDENTS];
    int num_students = 0;

    // Add a student to the database
    Student new_student;
    printf("Enter student ID: ");
    scanf("%d", &new_student.id);
    printf("Enter student name: ");
    scanf("%s", new_student.name);
    printf("Enter student age: ");
    scanf("%d", &new_student.age);

    database[num_students] = new_student;
    num_students++;

    // Search for a student in the database
    int search_id;
    printf("Enter ID of student to search for: ");
    scanf("%d", &search_id);

    int found = 0;
    for (int i = 0; i < num_students; i++) {
        if (database[i].id == search_id) {
            found = 1;
            printf("Student ID: %d\n", database[i].id);
            printf("Student Name: %s\n", database[i].name);
            printf("Student Age: %d\n", database[i].age);
            break;
        }
    }

    if (!found) {
        printf("Student not found in database.\n");
    }

    // Delete a student from the database
    int delete_id;
    printf("Enter ID of student to delete: ");
    scanf("%d", &delete_id);

    int delete_index = -1;
    for (int i = 0; i < num_students; i++) {
        if (database[i].id == delete_id) {
            delete_index = i;
            break;
        }
    }

    if (delete_index != -1) {
        for (int i = delete_index + 1; i < num_students; i++) {
            database[i - 1] = database[i];
        }
        num_students--;
        printf("Student with ID %d was deleted.\n", delete_id);
    } else {
        printf("Student not found in database.\n");
    }

    return 0;
}