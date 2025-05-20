//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    float gpa;
} Student;

void addStudent(Student *students, int *count);
void viewStudents(const Student *students, int count);
void saveToFile(const Student *students, int count);
void loadFromFile(Student *students, int *count);
void updateStudent(Student *students, int count);
void deleteStudent(Student *students, int *count);

int main() {
    Student students[MAX_RECORDS];
    int choice, count = 0;

    loadFromFile(students, &count);

    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Save and Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                viewStudents(students, count);
                break;
            case 3:
                updateStudent(students, count);
                break;
            case 4:
                deleteStudent(students, &count);
                break;
            case 5:
                saveToFile(students, count);
                printf("Data saved. Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudent(Student *students, int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Cannot add more students. Maximum records reached.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", students[*count].name);
    printf("Enter age: ");
    scanf("%d", &students[*count].age);
    printf("Enter GPA: ");
    scanf("%f", &students[*count].gpa);
    (*count)++;
    printf("Student added successfully.\n");
}

void viewStudents(const Student *students, int count) {
    if (count == 0) {
        printf("No student records found.\n");
        return;
    }
    printf("\nStudent Records:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d, GPA: %.2f\n", students[i].name, students[i].age, students[i].gpa);
    }
}

void saveToFile(const Student *students, int count) {
    FILE *file = fopen("students.txt", "w");
    if (!file) {
        printf("Error saving data.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f\n", students[i].name, students[i].age, students[i].gpa);
    }
    fclose(file);
}

void loadFromFile(Student *students, int *count) {
    FILE *file = fopen("students.txt", "r");
    if (!file) {
        return;  // No file to load, will start with 0 records.
    }
    while (fscanf(file, "%s %d %f", students[*count].name, &students[*count].age, &students[*count].gpa) == 3) {
        (*count)++;
    }
    fclose(file);
}

void updateStudent(Student *students, int count) {
    char name[NAME_LENGTH];
    printf("Enter the name of the student to update: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Updating details for %s:\n", name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            printf("Enter new GPA: ");
            scanf("%f", &students[i].gpa);
            printf("Student updated successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void deleteStudent(Student *students, int *count) {
    char name[NAME_LENGTH];
    printf("Enter the name of the student to delete: ");
    scanf("%s", name);
    for (int i = 0; i < *count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student deleted successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}