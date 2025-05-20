//FormAI DATASET v1.0 Category: Database simulation ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student {
    char name[50];
    int id;
    float gpa;
} Student;

// Function to display the menu
int display_menu() {
    int choice;
    printf("\nMENU\n");
    printf("1. Add a student record\n");
    printf("2. Display all student records\n");
    printf("3. Search for a student record\n");
    printf("4. Update a student record\n");
    printf("5. Delete a student record\n");
    printf("6. Exit\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    return choice;
}

// Function to add a student record
void add_record(Student *students, int *num_students) {
    printf("\nEnter the details of the new student:\n");
    printf("Name: ");
    scanf("%s", students[*num_students].name);
    printf("ID: ");
    scanf("%d", &students[*num_students].id);
    printf("GPA: ");
    scanf("%f", &students[*num_students].gpa);
    (*num_students)++;
    printf("The student record has been added successfully.\n");
}

// Function to display all student records
void display_records(Student *students, int num_students) {
    printf("\n%-20s %-10s %-10s\n", "Name", "ID", "GPA");
    for (int i = 0; i < num_students; i++) {
        printf("%-20s %-10d %-10.2f\n", students[i].name, students[i].id, students[i].gpa);
    }
}

// Function to search for a student record
void search_record(Student *students, int num_students) {
    int id;
    printf("\nEnter the ID of the student you want to search for: ");
    scanf("%d", &id);
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            printf("Record found:\n");
            printf("\n%-20s %-10s %-10s\n", "Name", "ID", "GPA");
            printf("%-20s %-10d %-10.2f\n", students[i].name, students[i].id, students[i].gpa);
            return;
        }
    }
    printf("Record not found.\n");
}

// Function to update a student record
void update_record(Student *students, int num_students) {
    int id;
    printf("\nEnter the ID of the student you want to update: ");
    scanf("%d", &id);
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            printf("\nEnter the new details of the student:\n");
            printf("Name: ");
            scanf("%s", students[i].name);
            printf("GPA: ");
            scanf("%f", &students[i].gpa);
            printf("The student record has been updated successfully.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

// Function to delete a student record
void delete_record(Student *students, int *num_students) {
    int id, index = -1;
    printf("\nEnter the ID of the student you want to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *num_students; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Record not found.\n");
        return;
    }
    for (int i = index; i < *num_students - 1; i++) {
        strcpy(students[i].name, students[i + 1].name);
        students[i].id = students[i + 1].id;
        students[i].gpa = students[i + 1].gpa;
    }
    (*num_students)--;
    printf("The student record has been deleted successfully.\n");
}

int main() {
    Student students[50];
    int num_students = 0, choice;
    while (1) {
        choice = display_menu();
        switch (choice) {
            case 1:
                add_record(students, &num_students);
                break;
            case 2:
                display_records(students, num_students);
                break;
            case 3:
                search_record(students, num_students);
                break;
            case 4:
                update_record(students, num_students);
                break;
            case 5:
                delete_record(students, &num_students);
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}