//FormAI DATASET v1.0 Category: Database Indexing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

struct student {
    char name[50];
    int id;
    float gpa;
};

// function to print a student record
void print_record(struct student s) {
    printf("Name: %s\n", s.name);
    printf("ID: %d\n", s.id);
    printf("GPA: %.2f\n", s.gpa);
    printf("----------------------\n");
}

// function to print an array of student records
void print_records(struct student records[], int num_records) {
    printf("STUDENT RECORDS:\n");
    for (int i = 0; i < num_records; i++) {
        print_record(records[i]);
    }
}

// function to add a student to the database
void add_student(struct student *database[], int *num_records) {
    // allocate memory for new student record
    struct student *new_record = (struct student*) malloc(sizeof(struct student));
    // get user input for new student
    printf("Enter student name: ");
    scanf("%s", new_record->name);
    printf("Enter student ID: ");
    scanf("%d", &new_record->id);
    printf("Enter student GPA: ");
    scanf("%f", &new_record->gpa);
    // add new student to database
    database[*num_records] = new_record;
    (*num_records)++;
}

// function to search for a student by name using binary search
void search_student(struct student *database[], int num_records) {
    char search_name[50];
    printf("Enter student name to search: ");
    scanf("%s", search_name);
    // sort database by name using selection sort
    for (int i = 0; i < num_records - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < num_records; j++) {
            if (strcmp(database[j]->name, database[min_index]->name) < 0) {
                min_index = j;
            }
        }
        struct student *temp = database[i];
        database[i] = database[min_index];
        database[min_index] = temp;
    }
    // search for student using binary search
    int low = 0;
    int high = num_records - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (strcmp(search_name, database[mid]->name) == 0) {
            print_record(*database[mid]);
            return;
        }
        else if (strcmp(search_name, database[mid]->name) < 0) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    printf("Student not found.\n");
}

int main() {
    struct student *database[MAX_RECORDS];
    int num_records = 0;

    printf("1. Add student\n");
    printf("2. Search for student\n");
    printf("3. Print all records\n");
    printf("4. Exit\n");

    int choice;
    do {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student(database, &num_records);
                break;
            case 2:
                search_student(database, num_records);
                break;
            case 3:
                print_records(database, num_records);
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    // free memory used by database
    for (int i = 0; i < num_records; i++) {
        free(database[i]);
    }

    return 0;
}