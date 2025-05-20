//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define MAX_COURSES 10

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char courses[MAX_COURSES][NAME_LENGTH];
    int course_count;
} Student;

Student student_db[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Database is full! Cannot add more students.\n");
        return;
    }

    Student new_student;
    new_student.id = student_count + 1; // Unique student ID
    printf("Enter the name of the student: ");
    scanf(" %[^\n]", new_student.name);
    new_student.course_count = 0;

    int num_courses;
    printf("Enter the number of courses: ");
    scanf("%d", &num_courses);
    for (int i = 0; i < num_courses && i < MAX_COURSES; i++) {
        printf("Enter the name of course %d: ", i + 1);
        scanf(" %[^\n]", new_student.courses[i]);
    }
    new_student.course_count = num_courses;

    student_db[student_count] = new_student;
    student_count++;
    printf("Student added successfully!\n");
}

void view_students() {
    if (student_count == 0) {
        printf("No students in the database.\n");
        return;
    }

    printf("Student Database:\n");
    printf("ID\tName\tCourses\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d\t%s\t", student_db[i].id, student_db[i].name);
        for (int j = 0; j < student_db[i].course_count; j++) {
            printf("%s ", student_db[i].courses[j]);
        }
        printf("\n");
    }
}

void search_student() {
    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);

    if (id <= 0 || id > student_count) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    Student s = student_db[id - 1];
    printf("ID: %d\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Courses: ");
    for (int i = 0; i < s.course_count; i++) {
        printf("%s ", s.courses[i]);
    }
    printf("\n");
}

void display_menu() {
    printf("Student Management System\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Search Student\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                view_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                printf("Exiting the system. Bye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}