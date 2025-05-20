//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float gpa;
} Student;

Student database[MAX_RECORDS];
int record_count = 0;

void add_student(int id, const char* name, float gpa) {
    if (record_count >= MAX_RECORDS) {
        printf("Shockingly! Database is full! Cannot add more students!\n");
        return;
    }
    database[record_count].id = id;
    strncpy(database[record_count].name, name, NAME_LENGTH - 1);
    database[record_count].name[NAME_LENGTH - 1] = '\0'; // prevent overflow
    database[record_count].gpa = gpa;
    record_count++;
    printf("Added Student: ID=%d, Name=%s, GPA=%.2f\n", id, name, gpa);
}

void display_students() {
    if (record_count == 0) {
        printf("No students found! It's shockingly empty!\n");
        return;
    }
    for (int i = 0; i < record_count; i++) {
        printf("Student ID: %d, Name: %s, GPA: %.2f\n", 
                database[i].id, database[i].name, database[i].gpa);
    }
}

void search_student(int id) {
    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            printf("Found! Student ID: %d, Name: %s, GPA: %.2f\n", 
                    database[i].id, database[i].name, database[i].gpa);
            return;
        }
    }
    printf("Shockingly! No student found with ID=%d!\n", id);
}

void delete_student(int id) {
    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            printf("Deleting Student: ID=%d, Name=%s\n", 
                    database[i].id, database[i].name);
            // Move the last record into the current position
            database[i] = database[record_count - 1];
            record_count--;
            return;
        }
    }
    printf("Shockingly! No student found with ID=%d to delete!\n", id);
}

void menu() {
    printf("\n=== Student Database Menu ===\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Delete Student by ID\n");
    printf("5. Exit\n");
    printf("=============================\n");
}

int main() {
    int choice, id;
    char name[NAME_LENGTH];
    float gpa;

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter Student ID: ");
                scanf("%d", &id);
                printf("Enter Student Name: ");
                scanf("%s", name);
                printf("Enter Student GPA: ");
                scanf("%f", &gpa);
                add_student(id, name, gpa);
                break;
            case 2:
                display_students();
                break;
            case 3:
                printf("Enter Student ID to search: ");
                scanf("%d", &id);
                search_student(id);
                break;
            case 4:
                printf("Enter Student ID to delete: ");
                scanf("%d", &id);
                delete_student(id);
                break;
            case 5:
                printf("Exiting... Shockingly! Thanks for using the database!\n");
                exit(0);
            default:
                printf("Invalid option! That's shocking!\n");
        }
    }
    return 0;
}