//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int roll_no;
    char name[50];
    int marks;
} Student;

void insert_record(Student db[], int* size);
void delete_record(Student db[], int* size);
void search_record(Student db[], int size);
void print_database(Student db[], int size);

int main() {
    Student db[MAX_RECORDS];
    int choice, size = 0;

    do {
        printf("\n--- Student Database Simulation ---\n");
        printf("\nChoose an operation:\n");
        printf("[1] Insert a record\n");
        printf("[2] Delete a record\n");
        printf("[3] Search for a record\n");
        printf("[4] Print the database\n");
        printf("[0] Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_record(db, &size);
                break;
            case 2:
                delete_record(db, &size);
                break;
            case 3:
                search_record(db, size);
                break;
            case 4:
                print_database(db, size);
                break;
            case 0:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void insert_record(Student db[], int* size) {
    if (*size == MAX_RECORDS) {
        printf("\nDatabase is full. Cannot insert new record.\n");
        return;
    }

    Student temp;
    printf("\nEnter student's roll number: ");
    scanf("%d", &temp.roll_no);

    // Check if roll number already exists in database
    for (int i = 0; i < *size; i++) {
        if (temp.roll_no == db[i].roll_no) {
            printf("\nRecord with roll number %d already exists in database.\n", temp.roll_no);
            return;
        }
    }

    printf("Enter student's name: ");
    getchar();
    fgets(temp.name, 50, stdin);
    temp.name[strcspn(temp.name, "\n")] = 0;  // Removes trailing newline character

    printf("Enter student's marks: ");
    scanf("%d", &temp.marks);

    db[*size] = temp;
    (*size)++;
    printf("\nRecord added successfully.\n");
}

void delete_record(Student db[], int* size) {
    if (*size == 0) {
        printf("\nDatabase is already empty. Cannot delete record.\n");
        return;
    }

    int roll_no;
    printf("\nEnter the roll number of student whose record is to be deleted: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < *size; i++) {
        if (roll_no == db[i].roll_no) {
            for (int j = i; j < *size - 1; j++) {
                db[j] = db[j + 1];
            }
            (*size)--;
            printf("\nRecord with roll number %d deleted successfully.\n", roll_no);
            return;
        }
    }

    printf("\nRecord with roll number %d not found in database.\n", roll_no);
}

void search_record(Student db[], int size) {
    if (size == 0) {
        printf("\nDatabase is empty. Cannot search for record.\n");
        return;
    }

    int roll_no;
    printf("\nEnter the roll number of student whose record is to be searched: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < size; i++) {
        if (roll_no == db[i].roll_no) {
            printf("\nRecord found:\n");
            printf("Roll number: %d\n", db[i].roll_no);
            printf("Name: %s\n", db[i].name);
            printf("Marks: %d\n", db[i].marks);
            return;
        }
    }

    printf("\nRecord with roll number %d not found in database.\n", roll_no);
}

void print_database(Student db[], int size) {
    if (size == 0) {
        printf("\nDatabase is empty. Cannot print records.\n");
        return;
    }

    printf("\n--- Student Database ---\n");

    for (int i = 0; i < size; i++) {
        printf("\nRecord %d:\n", i + 1);
        printf("Roll number: %d\n", db[i].roll_no);
        printf("Name: %s\n", db[i].name);
        printf("Marks: %d\n", db[i].marks);
    }
}