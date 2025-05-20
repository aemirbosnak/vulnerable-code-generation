//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a struct for the database
typedef struct {
    int id;
    char name[100];
    int age;
} Record;

// Function prototypes
void menu();
void addRecord(Record db[], int *size);
void viewRecord(Record db[], int size);
void deleteRecord(Record db[], int *size, int id);
void searchRecord(Record db[], int size, char name[]);
void saveToFile(Record db[], int size);
int loadFromFile(Record db[]);

// Main function
int main() {
    // Declare variables
    Record db[100];
    int size = 0;
    char choice;

    // Load database from file
    size = loadFromFile(db);

    // Display menu
    do {
        menu();
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addRecord(db, &size);
                break;
            case '2':
                viewRecord(db, size);
                break;
            case '3':
                printf("Enter ID to delete: ");
                int id;
                scanf("%d", &id);
                deleteRecord(db, &size, id);
                break;
            case '4':
                printf("Enter name to search: ");
                char name[100];
                scanf("%s", name);
                searchRecord(db, size, name);
                break;
            case '5':
                saveToFile(db, size);
                printf("Database saved to file.\n");
                break;
            case 'q':
            case 'Q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 'q' && choice != 'Q');

    // Exit program
    return 0;
}

// Display menu options
void menu() {
    printf("\n--- Database Menu ---\n");
    printf("1. Add record\n");
    printf("2. View records\n");
    printf("3. Delete record\n");
    printf("4. Search record\n");
    printf("5. Save to file\n");
    printf("Q. Quit\n");
    printf("Enter choice: ");
}

// Add a new record to the database
void addRecord(Record db[], int *size) {
    printf("\n--- Add Record ---\n");

    // Get record details from user
    printf("Enter ID: ");
    scanf("%d", &db[*size].id);
    printf("Enter name: ");
    scanf("%s", db[*size].name);
    printf("Enter age: ");
    scanf("%d", &db[*size].age);

    // Increment size of database
    (*size)++;
}

// View all records in the database
void viewRecord(Record db[], int size) {
    printf("\n--- View Records ---\n");

    if (size == 0) {
        printf("Database is empty.\n");
    } else {
        // Display all records
        for (int i = 0; i < size; i++) {
            printf("%d\t%s\t%d\n", db[i].id, db[i].name, db[i].age);
        }
    }
}

// Delete a record from the database
void deleteRecord(Record db[], int *size, int id) {
    printf("\n--- Delete Record ---\n");

    // Search for record with matching ID
    bool found = false;
    for (int i = 0; i < *size; i++) {
        if (db[i].id == id) {
            // Shift all records after deleted record down one index
            for (int j = i; j < (*size) - 1; j++) {
                db[j] = db[j+1];
            }
            // Decrement size of database
            (*size)--;
            found = true;
            break;
        }
    }

    // Display result
    if (found) {
        printf("Record deleted.\n");
    } else {
        printf("Record not found.\n");
    }
}

// Search for a record by name in the database
void searchRecord(Record db[], int size, char name[]) {
    printf("\n--- Search Record ---\n");
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (strcmp(db[i].name, name) == 0) {
            printf("%d\t%s\t%d\n", db[i].id, db[i].name, db[i].age);
            found = true;
        }
    }

    // Display result
    if (!found) {
        printf("Record not found.\n");
    }
}

// Save the current database to a file
void saveToFile(Record db[], int size) {
    // Open file for writing
    FILE *file = fopen("database.txt", "w");

    // Write each record to file
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\t%s\t%d\n", db[i].id, db[i].name, db[i].age);
    }

    // Close file
    fclose(file);
}

// Load the database from file and return the size
int loadFromFile(Record db[]) {
    // Open file for reading
    FILE *file = fopen("database.txt", "r");

    // Read each record from file
    int size = 0;
    while (!feof(file)) {
        fscanf(file, "%d\t%s\t%d\n", &db[size].id, db[size].name, &db[size].age);
        size++;
    }

    // Close file
    fclose(file);

    // Decrement size to account for final empty record
    size--;

    return size;
}