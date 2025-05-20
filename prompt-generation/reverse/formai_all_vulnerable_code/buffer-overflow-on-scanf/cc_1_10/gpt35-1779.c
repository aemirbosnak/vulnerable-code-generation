//FormAI DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct student_record {
    int id;
    char name[30];
    float gpa;
};

void add_student(struct student_record *records);
void list_students(struct student_record *records);
void find_student(struct student_record *records, int id);
void update_student(struct student_record *records, int id);
void delete_student(struct student_record *records, int id);

int current_size = 0;

int main() {
    struct student_record records[MAX_RECORDS];
    char choice;
    int id;

    while (1) {
        printf("\n\n----- STUDENT DATABASE SIMULATION -----\n");
        printf("1. Add a new student\n");
        printf("2. List all students\n");
        printf("3. Find a student\n");
        printf("4. Update a student's information\n");
        printf("5. Delete a student\n");
        printf("6. Quit\n");
        printf("---------------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_student(records);
                break;
            case '2':
                list_students(records);
                break;
            case '3':
                printf("Enter the student ID: ");
                scanf("%d", &id);
                find_student(records, id);
                break;
            case '4':
                printf("Enter the student ID: ");
                scanf("%d", &id);
                update_student(records, id);
                break;
            case '5':
                printf("Enter the student ID: ");
                scanf("%d", &id);
                delete_student(records, id);
                break;
            case '6':
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

void add_student(struct student_record *records) {
    int id;
    char name[30];
    float gpa;

    printf("Enter the student's ID (1-%d): ", MAX_RECORDS);
    scanf("%d", &id);

    if (id < 1 || id > MAX_RECORDS) {
        printf("Invalid ID.\n");
        return;
    }

    if (current_size >= id) {
        printf("A student with that ID already exists.\n");
        return;
    }

    printf("Enter the student's name: ");
    scanf("%s", name);

    printf("Enter the student's GPA: ");
    scanf("%f", &gpa);

    struct student_record student = {id, name, gpa};
    records[id-1] = student;
    current_size++;
}

void list_students(struct student_record *records) {
    if (current_size == 0) {
        printf("There are no students in the database.\n");
        return;
    }

    printf("ID\tNAME\t\tGPA\n");

    for (int i = 0; i < current_size; i++) {
        struct student_record student = records[i];
        printf("%d\t%s\t\t%.2f\n", student.id, student.name, student.gpa);
    }
}

void find_student(struct student_record *records, int id) {
    if (id < 1 || id > MAX_RECORDS) {
        printf("Invalid ID.\n");
        return;
    }

    if (current_size < id) {
        printf("No student with that ID exists.\n");
        return;
    }

    struct student_record student = records[id-1];
    printf("ID\tNAME\t\tGPA\n");
    printf("%d\t%s\t\t%.2f\n", student.id, student.name, student.gpa);
}

void update_student(struct student_record *records, int id) {
    if (id < 1 || id > MAX_RECORDS) {
        printf("Invalid ID.\n");
        return;
    }

    if (current_size < id) {
        printf("No student with that ID exists.\n");
        return;
    }

    struct student_record *student = &records[id-1];
    printf("Enter the new name (leave blank to keep current name): ");
    char name[30];
    scanf("%s", name);

    if (strcmp(name, "") != 0) {
        strcpy(student->name, name);
    }

    printf("Enter the new GPA (leave blank to keep current GPA): ");
    char gpa_str[10];
    scanf("%s", gpa_str);

    if (strcmp(gpa_str, "") != 0) {
        float gpa = atof(gpa_str);
        student->gpa = gpa;
    }

    printf("Student updated.\n");
}

void delete_student(struct student_record *records, int id) {
    if (id < 1 || id > MAX_RECORDS) {
        printf("Invalid ID.\n");
        return;
    }

    if (current_size < id) {
        printf("No student with that ID exists.\n");
        return;
    }

    struct student_record *student = &records[id-1];
    *student = (struct student_record){0, "", 0};
    current_size--;
    printf("Student deleted.\n");
}