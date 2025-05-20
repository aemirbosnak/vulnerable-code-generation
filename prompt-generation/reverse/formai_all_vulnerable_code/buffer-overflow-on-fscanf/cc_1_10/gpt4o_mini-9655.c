//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "students.txt"

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Cannot add more students, limit reached!\n");
        return;
    }
    
    Student new_student;
    new_student.id = student_count + 1;

    printf("Enter student name: ");
    scanf("%s", new_student.name); // Basic input, ideally use fgets for safety
    
    printf("Enter student grade: ");
    scanf("%f", &new_student.grade);
    
    students[student_count] = new_student;
    student_count++;
    
    printf("Student added successfully!\n");
}

void list_students() {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }
    
    printf("\nList of Students:\n");
    for (int i = 0; i < student_count; i++) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

void save_students_to_file() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < student_count; i++) {
        fprintf(file, "%d %s %.2f\n", students[i].id, students[i].name, students[i].grade);
    }

    fclose(file);
    printf("Students saved to '%s' successfully!\n", FILE_NAME);
}

void load_students_from_file() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("File not found or error opening file!\n");
        return;
    }

    while (fscanf(file, "%d %s %f", &students[student_count].id, students[student_count].name, &students[student_count].grade) == 3) {
        student_count++;
        if (student_count >= MAX_STUDENTS) {
            printf("Maximum student limit reached while loading from file!\n");
            break;
        }
    }

    fclose(file);
    printf("Students loaded from '%s' successfully! Total: %d\n", FILE_NAME, student_count);
}

int main() {
    int choice;

    load_students_from_file();

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. List Students\n");
        printf("3. Save Students to File\n");
        printf("4. Load Students from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                list_students();
                break;
            case 3:
                save_students_to_file();
                break;
            case 4:
                load_students_from_file();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}