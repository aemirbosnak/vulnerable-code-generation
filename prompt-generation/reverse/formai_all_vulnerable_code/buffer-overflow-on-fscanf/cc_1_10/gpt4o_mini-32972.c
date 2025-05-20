//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define AGE_LENGTH 3

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Student;

Student database[MAX_RECORDS];
int recordCount = 0;

void addRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }

    Student newStudent;
    newStudent.id = recordCount + 1; // Assign ID based on record count

    printf("Enter Name: ");
    scanf("%s", newStudent.name);
    printf("Enter Age: ");
    scanf("%d", &newStudent.age);

    database[recordCount] = newStudent;
    recordCount++;
    printf("Record added successfully!\n");
}

void displayRecords() {
    if (recordCount == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n=== Student Records ===\n");
    for (int i = 0; i < recordCount; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", 
               database[i].id, database[i].name, database[i].age);
    }
    printf("=======================\n");
}

void searchRecord() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    if (id < 1 || id > recordCount) {
        printf("Record not found!\n");
        return;
    }

    Student student = database[id - 1];
    printf("Record Found: ID: %d, Name: %s, Age: %d\n", 
           student.id, student.name, student.age);
}

void deleteRecord() {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > recordCount) {
        printf("Record not found!\n");
        return;
    }

    // Shift records to fill the gap
    for (int i = id - 1; i < recordCount - 1; i++) {
        database[i] = database[i + 1];
    }
    recordCount--;
    printf("Record deleted successfully!\n");
}

void saveToFile() {
    FILE *file = fopen("database.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%d %s %d\n", 
                database[i].id, database[i].name, database[i].age);
    }
    fclose(file);
    printf("Database saved to file.\n");
}

void loadFromFile() {
    FILE *file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fscanf(file, "%d %s %d", 
                  &database[recordCount].id, database[recordCount].name, 
                  &database[recordCount].age) == 3) {
        recordCount++;
        if (recordCount >= MAX_RECORDS) {
            printf("Database is full, cannot load more records.\n");
            break;
        }
    }
    fclose(file);
    printf("Database loaded from file.\n");
}

void showMenu() {
    printf("\n=== Student Database Menu ===\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Search Record by ID\n");
    printf("4. Delete Record by ID\n");
    printf("5. Save to File\n");
    printf("6. Load from File\n");
    printf("7. Exit\n");
    printf("==============================\n");
}

int main() {
    int choice;
    loadFromFile();

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                saveToFile();
                break;
            case 6:
                loadFromFile();
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}