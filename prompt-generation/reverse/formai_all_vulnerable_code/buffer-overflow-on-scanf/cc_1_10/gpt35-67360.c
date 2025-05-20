//FormAI DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[40];
    float gpa;
} Student;

typedef struct {
    Student student_records[MAX_RECORDS];
    int num_records;
} Database;

void add_student_record(Database *db);
void print_database(Database db);
void remove_student_record(Database *db, int id);

int main() {
    Database db;
    db.num_records = 0;

    int choice = 0;
    do {
        printf("1. Add student record\n");
        printf("2. Print database\n");
        printf("3. Remove student record\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student_record(&db);
                break;
            case 2:
                print_database(db);
                break;
            case 3: {
                int id;
                printf("Enter student ID to remove: ");
                scanf("%d", &id);
                remove_student_record(&db, id);
                break;
            }
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}

void add_student_record(Database *db) {
    if (db->num_records == MAX_RECORDS) {
        printf("Database is full. Unable to add student record.\n");
        return;
    }

    Student student;
    student.id = 0;

    do {
        printf("Enter student ID: ");
        scanf("%d", &(student.id));

        for (int i = 0; i < db->num_records; i++) {
            if (db->student_records[i].id == student.id) {
                printf("Student with ID %d already exists. Please enter a different ID.\n", student.id);
                student.id = 0;
                break;
            }
        }
    } while (student.id <= 0);

    printf("Enter student name: ");
    scanf("%s", &(student.name));

    printf("Enter student GPA: ");
    scanf("%f", &(student.gpa));

    db->student_records[db->num_records] = student;
    db->num_records++;

    printf("Student record added successfully.\n");
}

void print_database(Database db) {
    printf("%-10s %-40s %-10s\n", "ID", "Name", "GPA");
    printf("----------------------------------------\n");

    for (int i = 0; i < db.num_records; i++) {
        printf("%-10d %-40s %-10.2f\n", db.student_records[i].id, db.student_records[i].name, db.student_records[i].gpa);
    }
}

void remove_student_record(Database *db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->student_records[i].id == id) {
            for (int j = i; j < db->num_records - 1; j++) {
                db->student_records[j] = db->student_records[j + 1];
            }

            db->num_records--;

            printf("Student record with ID %d removed successfully.\n", id);
            return;
        }
    }

    printf("Student with ID %d not found.\n", id);
}