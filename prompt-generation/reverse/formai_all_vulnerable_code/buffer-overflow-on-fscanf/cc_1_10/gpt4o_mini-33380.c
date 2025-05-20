//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max entries in the database
#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100

// Struct to represent an individual entry in the database
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
} Entry;

// Function prototypes
void initializeDatabase(Entry *db, int *count);
void addEntry(Entry *db, int *count);
void displayEntries(const Entry *db, int count);
void searchEntry(const Entry *db, int count);
void deleteEntry(Entry *db, int *count);
void saveToFile(const Entry *db, int count);
void loadFromFile(Entry *db, int *count);
void displayMenu();

int main() {
    Entry database[MAX_ENTRIES];
    int count = 0;
    loadFromFile(database, &count);
    
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEntry(database, &count);
                break;
            case 2:
                displayEntries(database, count);
                break;
            case 3:
                searchEntry(database, count);
                break;
            case 4:
                deleteEntry(database, &count);
                break;
            case 5:
                saveToFile(database, count);
                break;
            case 6:
                printf("Exiting the database program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 6);
    
    return 0;
}

void initializeDatabase(Entry *db, int *count) {
    *count = 0; // Start with zero entries
}

void addEntry(Entry *db, int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Database is full! Cannot add more entries.\n");
        return;
    }
    
    Entry newEntry;
    newEntry.id = *count + 1; // Assign an ID based on current count
    printf("Enter name: ");
    getchar(); // clear the newline character left in buffer
    fgets(newEntry.name, MAX_NAME_LEN, stdin);
    newEntry.name[strcspn(newEntry.name, "\n")] = 0; // Remove newline
        
    printf("Enter description: ");
    fgets(newEntry.description, MAX_DESCRIPTION_LEN, stdin);
    newEntry.description[strcspn(newEntry.description, "\n")] = 0; // Remove newline
    
    db[*count] = newEntry; // Add new entry to the database
    (*count)++;
    printf("Entry added successfully! ID is %d\n", newEntry.id);
}

void displayEntries(const Entry *db, int count) {
    if (count == 0) {
        printf("No entries in the database.\n");
        return;
    }
    printf("\nDatabase Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Description: %s\n", db[i].id, db[i].name, db[i].description);
    }
}

void searchEntry(const Entry *db, int count) {
    if (count == 0) {
        printf("No entries to search!\n");
        return;
    }
    
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    
    if (id < 1 || id > count) {
        printf("Entry with ID %d not found.\n", id);
    } else {
        printf("Found Entry - ID: %d, Name: %s, Description: %s\n", db[id - 1].id, db[id - 1].name, db[id - 1].description);
    }
}

void deleteEntry(Entry *db, int *count) {
    if (*count == 0) {
        printf("No entries to delete!\n");
        return;
    }
    
    int id;
    printf("Enter ID of the entry to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > *count) {
        printf("Entry with ID %d not found.\n", id);
    } else {
        for (int i = id - 1; i < *count - 1; i++) {
            db[i] = db[i + 1]; // Shift entries to fill the gap
        }
        (*count)--;
        printf("Entry with ID %d deleted successfully.\n", id);
    }
}

void saveToFile(const Entry *db, int count) {
    FILE *file = fopen("database.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d;%s;%s\n", db[i].id, db[i].name, db[i].description);
    }
    
    fclose(file);
    printf("Database saved successfully to 'database.txt'.\n");
}

void loadFromFile(Entry *db, int *count) {
    FILE *file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("No existing database found. Starting fresh!\n");
        return;
    }

    while (fscanf(file, "%d;%49[^;];%99[^\n]\n", &db[*count].id, db[*count].name, db[*count].description) == 3) {
        (*count)++;
    }

    fclose(file);
    printf("Database loaded successfully with %d entries.\n", *count);
}

void displayMenu() {
    printf("\n=== Simple Database Menu ===\n");
    printf("1. Add Entry\n");
    printf("2. Display All Entries\n");
    printf("3. Search Entry by ID\n");
    printf("4. Delete Entry\n");
    printf("5. Save Database to File\n");
    printf("6. Exit\n");
}