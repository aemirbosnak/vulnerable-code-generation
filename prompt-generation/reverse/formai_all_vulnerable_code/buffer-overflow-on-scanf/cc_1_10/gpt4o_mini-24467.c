//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing student information
typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

// Function to add a new student to the file
void add_student(FILE *file) {
    Student s;
    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name); // Read string with spaces
    printf("Enter Student Grade: ");
    scanf("%f", &s.grade);

    fwrite(&s, sizeof(Student), 1, file);
    printf("Student added successfully!\n");
}

// Function to display all students from the file
void display_students(FILE *file) {
    Student s;
    rewind(file); // Move the file pointer to the beginning

    printf("\nList of Students:\n");
    printf("ID\tName\t\tGrade\n");
    printf("---------------------------------\n");
    
    while (fread(&s, sizeof(Student), 1, file)) {
        printf("%d\t%s\t%.2f\n", s.id, s.name, s.grade);
    }
    printf("---------------------------------\n");
}

// Function to search for a student by ID
void search_student(FILE *file) {
    int search_id;
    printf("Enter Student ID to search: ");
    scanf("%d", &search_id);

    Student s;
    rewind(file); // Move the file pointer to the beginning
    int found = 0;

    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.id == search_id) {
            printf("Student Found!\n");
            printf("ID: %d\nName: %s\nGrade: %.2f\n", s.id, s.name, s.grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", search_id);
    }
}

// Function to delete a student by ID
void delete_student(FILE *file) {
    FILE *temp_file = fopen("temp.dat", "wb");
    if (!temp_file) {
        printf("Could not create temporary file.\n");
        return;
    }

    int delete_id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &delete_id);

    Student s;
    rewind(file);
    int found = 0;

    while (fread(&s, sizeof(Student), 1, file)) {
        if (s.id != delete_id) {
            fwrite(&s, sizeof(Student), 1, temp_file);
        } else {
            found = 1;
        }
    }

    fclose(temp_file);
    fclose(file);
    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found) {
        printf("Student with ID %d deleted successfully!\n", delete_id);
    } else {
        printf("Student with ID %d not found.\n", delete_id);
    }
}

// Display menu options for the user
void display_menu() {
    printf("\nMenu:\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Search Student\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FILE *file = fopen("students.dat", "ab+");
    if (!file) {
        printf("Could not open file.\n");
        return 1;
    }

    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student(file);
                break;
            case 2:
                display_students(file);
                break;
            case 3:
                search_student(file);
                break;
            case 4:
                delete_student(file);
                file = fopen("students.dat", "ab+"); // Reopen the file after deletion
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 5);

    fclose(file);
    return 0;
}