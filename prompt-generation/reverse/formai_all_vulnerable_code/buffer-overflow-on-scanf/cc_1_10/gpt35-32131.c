//FormAI DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define maximum database size
#define MAX_DB_SIZE 100

// Define database struct
struct Database {
    int id[MAX_DB_SIZE];
    char name[MAX_DB_SIZE][50];
    float price[MAX_DB_SIZE];
    int quantity[MAX_DB_SIZE];
    int size;
};

// Function prototypes
void addProduct(struct Database *db);
void editProduct(struct Database *db);
void deleteProduct(struct Database *db);
void printDatabase(struct Database db);
void printMainMenu();

// Main function
int main() {
    struct Database db;
    db.size = 0;

    int choice;

    do {
        printMainMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(&db);
                break;
            case 2:
                editProduct(&db);
                break;
            case 3:
                deleteProduct(&db);
                break;
            case 4:
                printDatabase(db);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Add product function
void addProduct(struct Database *db) {
    if (db->size == MAX_DB_SIZE) {
        printf("Database is full, cannot add more products!\n");
        return;
    }

    printf("Enter product ID: ");
    scanf("%d", &db->id[db->size]);

    printf("Enter product name: ");
    scanf("%s", db->name[db->size]);

    printf("Enter product price: ");
    scanf("%f", &db->price[db->size]);

    printf("Enter product quantity: ");
    scanf("%d", &db->quantity[db->size]);

    db->size++;

    printf("Product added successfully!\n");
}

// Edit product function
void editProduct(struct Database *db) {
    if (db->size == 0) {
        printf("Database is empty, cannot edit products!\n");
        return;
    }

    int id;
    printf("Enter ID of product to edit: ");
    scanf("%d", &id);

    int index = -1;

    for (int i = 0; i < db->size; i++) {
        if (db->id[i] == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Product with ID %d not found!\n", id);
        return;
    }

    printf("Enter new name (leave blank to keep current): ");
    char name[50];
    scanf("%s", name);
    if (name[0] != '\0') {
        strcpy(db->name[index], name);
    }

    printf("Enter new price (0 to keep current): ");
    float price;
    scanf("%f", &price);
    if (price != 0) {
        db->price[index] = price;
    }

    printf("Enter new quantity (0 to keep current): ");
    int quantity;
    scanf("%d", &quantity);
    if (quantity != 0) {
        db->quantity[index] = quantity;
    }

    printf("Product with ID %d edited successfully!\n", id);
}

// Delete product function
void deleteProduct(struct Database *db) {
    if (db->size == 0) {
        printf("Database is empty, cannot delete products!\n");
        return;
    }

    int id;
    printf("Enter ID of product to delete: ");
    scanf("%d", &id);

    int index = -1;

    for (int i = 0; i < db->size; i++) {
        if (db->id[i] == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Product with ID %d not found!\n", id);
        return;
    }

    for (int i = index; i < db->size - 1; i++) {
        db->id[i] = db->id[i+1];
        strcpy(db->name[i], db->name[i+1]);
        db->price[i] = db->price[i+1];
        db->quantity[i] = db->quantity[i+1];
    }

    db->size--;

    printf("Product with ID %d deleted successfully!\n", id);
}

// Print database function
void printDatabase(struct Database db) {
    if (db.size == 0) {
        printf("Database is empty!\n");
        return;
    }

    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < db.size; i++) {
        printf("%d\t%s\t%.2f\t%d\n", db.id[i], db.name[i], db.price[i], db.quantity[i]);
    }
}

// Print main menu function
void printMainMenu() {
    printf("***** SIMULATION OF A DATABASE *****\n");
    printf("1. Add product\n");
    printf("2. Edit product\n");
    printf("3. Delete product\n");
    printf("4. Print database\n");
    printf("5. Exit\n");
    printf("Enter choice (1-5): ");
}