//FormAI DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Maximum number of records that can be stored
#define MAX_RECORDS 100

// Record structure
typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Record;

// Index structure
typedef struct {
    int id;
    int pos;
} Index;

// Database structure
typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
    Index index[MAX_RECORDS];
    int num_index;
} Database;

// Function to print menu
void print_menu() {
    printf("\nDatabase Indexing System\n");
    printf("------------------------\n");
    printf("1. Add Record\n");
    printf("2. Search Record\n");
    printf("3. Modify Record\n");
    printf("4. Delete Record\n");
    printf("5. Print Records\n");
    printf("6. Exit\n");
    printf("------------------------\n");
    printf("Enter your choice (1-6): ");
}

// Function to add record to database
void add_record(Database* db, int id, char* name, int age, float salary) {
    // Check if maximum number of records have been reached
    if (db->num_records < MAX_RECORDS) {
        // Add record to database
        db->records[db->num_records].id = id;
        strcpy(db->records[db->num_records].name, name);
        db->records[db->num_records].age = age;
        db->records[db->num_records].salary = salary;
        // Add index to database
        db->index[db->num_index].id = id;
        db->index[db->num_index].pos = db->num_records;
        // Update number of records and index
        db->num_records++;
        db->num_index++;
        // Print success message
        printf("Record added successfully!\n");
    } else {
        // Print error message
        printf("Database is full!\n");
    }
}

// Function to search record in database by ID
void search_record(Database* db, int id) {
    // Initialize variables
    bool found = false;
    int pos = -1;
    // Loop through index to find ID
    for (int i = 0; i < db->num_index; i++) {
        if (db->index[i].id == id) {
            found = true;
            pos = db->index[i].pos;
            break;
        }
    }
    // Print record if found
    if (found) {
        printf("Record found:\n");
        printf("ID: %d\n", db->records[pos].id);
        printf("Name: %s\n", db->records[pos].name);
        printf("Age: %d\n", db->records[pos].age);
        printf("Salary: %.2f\n", db->records[pos].salary);
    } else {
        // Print error message
        printf("Record not found!\n");
    }
}

// Function to modify record in database by ID
void modify_record(Database* db, int id, char* name, int age, float salary) {
    // Initialize variables
    bool found = false;
    int pos = -1;
    // Loop through index to find ID
    for (int i = 0; i < db->num_index; i++) {
        if (db->index[i].id == id) {
            found = true;
            pos = db->index[i].pos;
            break;
        }
    }
    // Modify record if found
    if (found) {
        strcpy(db->records[pos].name, name);
        db->records[pos].age = age;
        db->records[pos].salary = salary;
        // Print success message
        printf("Record modified successfully!\n");
    } else {
        // Print error message
        printf("Record not found!\n");
    }
}

// Function to delete record from database by ID
void delete_record(Database* db, int id) {
    // Initialize variables
    bool found = false;
    int pos = -1;
    // Loop through index to find ID
    for (int i = 0; i < db->num_index; i++) {
        if (db->index[i].id == id) {
            found = true;
            pos = i;
            break;
        }
    }
    // Delete record if found
    if (found) {
        // Shift records down
        for (int i = pos; i < db->num_index - 1; i++) {
            db->records[db->index[i].pos] = db->records[db->index[i + 1].pos];
            db->index[i].id = db->index[i + 1].id;
            db->index[i].pos = db->index[i + 1].pos;
        }
        // Update number of records and index
        db->num_records--;
        db->num_index--;
        // Print success message
        printf("Record deleted successfully!\n");
    } else {
        // Print error message
        printf("Record not found!\n");
    }
}

// Function to print all records in database
void print_records(Database* db) {
    printf("ID | Name | Age | Salary\n");
    printf("----------------------------------\n");
    for (int i = 0; i < db->num_records; i++) {
        printf("%d | %s | %d | %.2f\n", db->records[i].id, db->records[i].name, db->records[i].age, db->records[i].salary);
    }
}

int main() {
    // Initialize database
    Database db;
    db.num_records = 0;
    db.num_index = 0;
    // Initialize variables
    int choice, id, age;
    char name[50];
    float salary;
    // Loop through menu until program is exited
    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                printf("Enter Salary: ");
                scanf("%f", &salary);
                add_record(&db, id, name, age, salary);
                break;
            case 2:
                printf("\nEnter ID: ");
                scanf("%d", &id);
                search_record(&db, id);
                break;
            case 3:
                printf("\nEnter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                printf("Enter Salary: ");
                scanf("%f", &salary);
                modify_record(&db, id, name, age, salary);
                break;
            case 4:
                printf("\nEnter ID: ");
                scanf("%d", &id);
                delete_record(&db, id);
                break;
            case 5:
                print_records(&db);
                break;
            case 6:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);
    return 0;
}