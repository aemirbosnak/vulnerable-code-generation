//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define FILENAME "students.txt"

struct Student {
    int id;
    char name[30];
    float gpa;
};

void add_student();
void list_students();
void search_student();

int main() {
    int choice;

    while (1) {
        printf("\n----- Student Management System -----\n");
        printf("1. Add Student\n");
        printf("2. List Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
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
                search_student();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_student() {
    struct Student student;
    FILE *file = fopen(FILENAME, "a");
    
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &student.id);
    printf("Enter Student Name: ");
    getchar();  // Consume the newline after the integer input
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = 0;  // Remove the newline character
    printf("Enter GPA: ");
    scanf("%f", &student.gpa);

    fprintf(file, "%d,%s,%.2f\n", student.id, student.name, student.gpa);
    printf("Student added successfully!\n");
    
    fclose(file);
}

void list_students() {
    struct Student student;
    FILE *file = fopen(FILENAME, "r");
    
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n----- List of Students -----\n");
    while (fscanf(file, "%d,%29[^,],%f\n", &student.id, student.name, &student.gpa) == 3) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", student.id, student.name, student.gpa);
    }
    
    fclose(file);
}

void search_student() {
    int id;
    struct Student student;
    int found = 0;
    FILE *file = fopen(FILENAME, "r");
    
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    while (fscanf(file, "%d,%29[^,],%f\n", &student.id, student.name, &student.gpa) == 3) {
        if (student.id == id) {
            printf("Student Found: ID: %d, Name: %s, GPA: %.2f\n", student.id, student.name, student.gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No student found with ID: %d\n", id);
    }

    fclose(file);
}