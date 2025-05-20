//FormAI DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

struct Student {
    int id;
    char name[MAX_LENGTH];
    int age;
};

void print_menu() {
    printf("1. Add new student\n");
    printf("2. Search for student\n");
    printf("3. Update student information\n");
    printf("4. Delete student\n");
    printf("5. Exit\n");
}

void add_new_student(struct Student* students, int* num_students) {
    printf("Enter student id: ");
    scanf("%d", &students[*num_students].id);
    
    printf("Enter student name: ");
    scanf("%s", students[*num_students].name);
    
    printf("Enter student age: ");
    scanf("%d", &students[*num_students].age);
    
    (*num_students)++;
    
    printf("Student added successfully!\n");
}

void search_for_student(struct Student* students, int num_students) {
    int id;
    printf("Enter student id: ");
    scanf("%d", &id);
    
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            printf("Student found!\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            return;
        }
    }
    
    printf("Student with id %d not found.\n", id);
}

void update_student_information(struct Student* students, int num_students) {
    int id;
    printf("Enter student id: ");
    scanf("%d", &id);
    
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            printf("Enter new student name: ");
            scanf("%s", students[i].name);
            
            printf("Enter new student age: ");
            scanf("%d", &students[i].age);
            
            printf("Student information updated!\n");
            return;
        }
    }
    
    printf("Student with id %d not found.\n", id);
}

void delete_student(struct Student* students, int* num_students) {
    int id;
    printf("Enter student id: ");
    scanf("%d", &id);
    
    for (int i = 0; i < *num_students; i++) {
        if (students[i].id == id) {
            // Shift remaining elements left
            for (int j = i; j < *num_students-1; j++) {
                students[j] = students[j+1];
            }
            
            (*num_students)--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    
    printf("Student with id %d not found.\n", id);
}

int main() {
    int choice;
    struct Student students[MAX_LENGTH];
    int num_students = 0;
    
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_new_student(students, &num_students);
                break;
            case 2:
                search_for_student(students, num_students);
                break;
            case 3:
                update_student_information(students, num_students);
                break;
            case 4:
                delete_student(students, &num_students);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        
    } while (choice != 5);
    
    return 0;
}