//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Database;

void init_database(Database *db) {
    db->count = 0;
}

void add_item(Database *db, int id, const char *name) {
    if (db->count < MAX_ITEMS) {
        db->items[db->count].id = id;
        strncpy(db->items[db->count].name, name, MAX_NAME_LENGTH);
        db->count++;
        printf("Item '%s' with ID %d added successfully!\n", name, id);
    } else {
        printf("Database full! Cannot add more items.\n");
    }
}

void search_item(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->items[i].id == id) {
            printf("Item found! ID: %d, Name: %s\n", db->items[i].id, db->items[i].name);
            return;
        }
    }
    printf("Item with ID %d not found!\n", id);
}

void delete_item(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->items[i].id == id) {
            printf("Deleting item with ID %d: %s\n", db->items[i].id, db->items[i].name);
            for (int j = i; j < db->count - 1; j++) {
                db->items[j] = db->items[j + 1];
            }
            db->count--;
            return;
        }
    }
    printf("Item with ID %d not found! Nothing to delete.\n", id);
}

void list_items(Database *db) {
    if (db->count == 0) {
        printf("No items in the database yet!\n");
        return;
    }
    printf("Listing all items:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s\n", db->items[i].id, db->items[i].name);
    }
}

void display_menu() {
    printf("\n--- Database Indexing System Menu ---\n");
    printf("1. Add Item\n");
    printf("2. Search Item\n");
    printf("3. Delete Item\n");
    printf("4. List Items\n");
    printf("5. Exit\n");
    printf("-------------------------------------\n");
}

int main() {
    Database db;
    init_database(&db);

    while (1) {
        display_menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int id;
            char name[MAX_NAME_LENGTH];
            printf("Enter item ID: ");
            scanf("%d", &id);
            printf("Enter item name: ");
            scanf("%s", name); // Note: assuming names do not contain spaces
            add_item(&db, id, name);
        } else if (choice == 2) {
            int id;
            printf("Enter item ID to search: ");
            scanf("%d", &id);
            search_item(&db, id);
        } else if (choice == 3) {
            int id;
            printf("Enter item ID to delete: ");
            scanf("%d", &id);
            delete_item(&db, id);
        } else if (choice == 4) {
            list_items(&db);
        } else if (choice == 5) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}