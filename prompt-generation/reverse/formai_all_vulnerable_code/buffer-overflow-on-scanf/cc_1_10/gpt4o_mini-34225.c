//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define FILE_NAME "students.txt"

typedef struct {
    char name[NAME_LENGTH];
    int id;
    float grade;
} Student;

void add_student();
void display_students();
void clear_input_buffer();

int main() {
    int choice;

    do {
        printf("Student Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer(); // To clear newline character left by scanf

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 3);

    return 0;
}

void add_student() {
    FILE *file;
    Student student;

    printf("Enter student name: ");
    fgets(student.name, NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = 0; // Remove newline character

    printf("Enter student ID: ");
    scanf("%d", &student.id);
    clear_input_buffer(); // Clear the input buffer

    printf("Enter student grade: ");
    scanf("%f", &student.grade);
    clear_input_buffer(); // Clear the input buffer

    file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Unable to open file!");
        exit(1);
    }

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
    printf("Student added successfully!\n");
}

void display_students() {
    FILE *file;
    Student student;
    int count = 0;

    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        perror("Unable to open file!");
        exit(1);
    }

    printf("\nList of Students:\n");
    printf("===================================\n");
    printf("ID\tName\t\tGrade\n");
    printf("===================================\n");

    while (fread(&student, sizeof(Student), 1, file)) {
        printf("%d\t%-15s\t%.2f\n", student.id, student.name, student.grade);
        count++;
    }

    if (count == 0) {
        printf("No records found.\n");
    }
    
    fclose(file);
}

void clear_input_buffer() {
    while (getchar() != '\n'); // Clear the input buffer
}