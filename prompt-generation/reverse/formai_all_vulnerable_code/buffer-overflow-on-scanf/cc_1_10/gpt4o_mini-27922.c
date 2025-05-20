//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_LENGTH 50

typedef struct {
    int id;
    char name[MAX_LENGTH];
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Database;

typedef struct {
    int id;
    int index;
} IndexEntry;

typedef struct {
    IndexEntry entries[MAX_ITEMS];
    int count;
} Index;

// Function prototypes
void initDatabase(Database *db);
void addItem(Database *db, int id, const char *name);
void displayDatabase(const Database *db);
void createIndex(const Database *db, Index *index);
void displayIndex(const Index *index);
int searchItemById(const Index *index, const Database *db, int id);

int main() {
    Database db;
    Index index;
    int id, menuChoice;
    char name[MAX_LENGTH];

    initDatabase(&db);
    
    do {
        printf("\nDatabase Indexing System\n");
        printf("1. Add Item\n");
        printf("2. Display Database\n");
        printf("3. Create/Update Index\n");
        printf("4. Display Index\n");
        printf("5. Search Item by ID\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                addItem(&db, id, name);
                break;
            case 2:
                displayDatabase(&db);
                break;
            case 3:
                createIndex(&db, &index);
                printf("Index created/updated successfully!\n");
                break;
            case 4:
                displayIndex(&index);
                break;
            case 5:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                int foundIndex = searchItemById(&index, &db, id);
                if (foundIndex != -1) {
                    printf("Item Found: ID = %d, Name = %s\n", db.items[foundIndex].id, db.items[foundIndex].name);
                } else {
                    printf("Item with ID %d not found.\n", id);
                }
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (menuChoice != 6);

    return 0;
}

void initDatabase(Database *db) {
    db->count = 0;
}

void addItem(Database *db, int id, const char *name) {
    if (db->count < MAX_ITEMS) {
        db->items[db->count].id = id;
        strncpy(db->items[db->count].name, name, MAX_LENGTH);
        db->count++;
        printf("Item added successfully!\n");
    } else {
        printf("Database is full, cannot add more items.\n");
    }
}

void displayDatabase(const Database *db) {
    printf("\n--- Database Contents ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s\n", db->items[i].id, db->items[i].name);
    }
}

void createIndex(const Database *db, Index *index) {
    index->count = 0;
    for (int i = 0; i < db->count; i++) {
        index->entries[i].id = db->items[i].id;
        index->entries[i].index = i; // Store index of the item in the Database
        index->count++;
    }
}

void displayIndex(const Index *index) {
    printf("\n--- Index Contents ---\n");
    for (int i = 0; i < index->count; i++) {
        printf("ID: %d, Index: %d\n", index->entries[i].id, index->entries[i].index);
    }
}

int searchItemById(const Index *index, const Database *db, int id) {
    for (int i = 0; i < index->count; i++) {
        if (index->entries[i].id == id) {
            return index->entries[i].index; // Return the index of the found item
        }
    }
    return -1; // Item not found
}