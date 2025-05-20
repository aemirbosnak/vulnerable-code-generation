//FormAI DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 30
#define MAX_STUDENT_COUNT 50

struct Student {
    int id;
    char name[MAX_NAME_SIZE];
    int age;
    float grade;
};

struct Student student_db[MAX_STUDENT_COUNT];

int num_students = 0;

void add_student() {
    if (num_students < MAX_STUDENT_COUNT) {
        struct Student new_student;
        printf("Enter student ID: ");
        scanf("%d", &new_student.id);
        printf("Enter student name: ");
        scanf("%s", new_student.name);
        printf("Enter student age: ");
        scanf("%d", &new_student.age);
        printf("Enter student grade: ");
        scanf("%f", &new_student.grade);
        student_db[num_students++] = new_student;
        printf("Student added successfully.\n");
    } else {
        printf("Error: Maximum number of students reached.\n");
    }
}

void display_students() {
    if (num_students == 0) {
        printf("No students in database.\n");
    } else {
        printf("%-5s %-15s %-5s %-5s\n", "ID", "NAME", "AGE", "GRADE");
        for (int i = 0; i < num_students; i++) {
            printf("%-5d %-15s %-5d %-5.2f\n", student_db[i].id, student_db[i].name, student_db[i].age, student_db[i].grade);
        }
    }
}

void search_student() {
    int search_id;
    printf("Enter student ID to search: ");
    scanf("%d", &search_id);
    for (int i = 0; i < num_students; i++) {
        if (student_db[i].id == search_id) {
            printf("%-5s %-15s %-5s %-5s\n", "ID", "NAME", "AGE", "GRADE");
            printf("%-5d %-15s %-5d %-5.2f\n", student_db[i].id, student_db[i].name, student_db[i].age, student_db[i].grade);
            return;
        }
    }
    printf("Error: No student found with ID %d.\n", search_id);
}

void update_student() {
    int update_id;
    printf("Enter student ID to update: ");
    scanf("%d", &update_id);
    for (int i = 0; i < num_students; i++) {
        if (student_db[i].id == update_id) {
            printf("Enter new name (or leave blank to keep current value %s): ", student_db[i].name);
            char new_name[MAX_NAME_SIZE];
            scanf("%s", new_name);
            if (strlen(new_name) > 0) {
                strcpy(student_db[i].name, new_name);
            }
            printf("Enter new age (or -1 to keep current value %d): ", student_db[i].age);
            int new_age;
            scanf("%d", &new_age);
            if (new_age != -1) {
                student_db[i].age = new_age;
            }
            printf("Enter new grade (or -1 to keep current value %.2f): ", student_db[i].grade);
            float new_grade;
            scanf("%f", &new_grade);
            if (new_grade != -1) {
                student_db[i].grade = new_grade;
            }
            printf("Student updated successfully.\n");
            return;
        }
    }
    printf("Error: No student found with ID %d.\n", update_id);
}

void delete_student() {
    int delete_id;
    printf("Enter student ID to delete: ");
    scanf("%d", &delete_id);
    for (int i = 0; i < num_students; i++) {
        if (student_db[i].id == delete_id) {
            for (int j = i; j < num_students - 1; j++) {
                student_db[j] = student_db[j + 1];
            }
            num_students--;
            printf("Student deleted successfully.\n");
            return;
        }
    }
    printf("Error: No student found with ID %d.\n", delete_id);
}

int main() {
    char selection;
    do {
        printf("Select an option:\n");
        printf("1. Add student.\n");
        printf("2. Display students.\n");
        printf("3. Search student.\n");
        printf("4. Update student.\n");
        printf("5. Delete student.\n");
        printf("6. Quit.\n");
        printf("Your selection: ");
        scanf(" %c", &selection);
        switch (selection) {
            case '1':
                add_student();
                break;
            case '2':
                display_students();
                break;
            case '3':
                search_student();
                break;
            case '4':
                update_student();
                break;
            case '5':
                delete_student();
                break;
            case '6':
                printf("Goodbye!\n");
                break;
            default:
                printf("Error: Unrecognized option.\n");
                break;
        }
    } while (selection != '6');
    return 0;
}