//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
} Product;

Product database[MAX_RECORDS];
int recordCount = 0;

void addProduct() {
    if (recordCount >= MAX_RECORDS) {
        printf("Database is full! Cannot add more products.\n");
        return;
    }
    
    Product p;
    p.id = recordCount + 1; // simple sequential id

    printf("Enter product name: ");
    scanf("%s", p.name); // input product name
    printf("Enter product price: ");
    scanf("%f", &p.price); // input product price
    
    database[recordCount] = p; // add the product to the database
    recordCount++; // increase the number of records
    printf("Product added successfully with ID %d\n", p.id);
}

void viewProducts() {
    if (recordCount == 0) {
        printf("No products in the database.\n");
        return;
    }
    
    printf("\nProducts in Database:\n");
    printf("ID\tName\t\tPrice\n");
    printf("-------------------------\n");
    for (int i = 0; i < recordCount; i++) {
        printf("%d\t%s\t\t%.2f\n", database[i].id, database[i].name, database[i].price);
    }
    printf("-------------------------\n");
}

void searchProduct() {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < recordCount; i++) {
        if (database[i].id == id) {
            printf("Product found:\n");
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Price: %.2f\n", database[i].price);
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < recordCount; i++) {
        if (database[i].id == id) {
            // Shift elements left
            for (int j = i; j < recordCount - 1; j++) {
                database[j] = database[j + 1];
            }
            recordCount--; // decrease the record count
            printf("Product with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Product with ID %d not found.\n", id);
}

void saveToFile() {
    FILE *file = fopen("database.txt", "w");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    
    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%d %s %.2f\n", database[i].id, database[i].name, database[i].price);
    }
    fclose(file);
    printf("Database saved to database.txt\n");
}

void loadFromFile() {
    FILE *file = fopen("database.txt", "r");
    if (!file) {
        printf("No saved database found. Starting fresh.\n");
        return;
    }
    
    while (fscanf(file, "%d %s %f", &database[recordCount].id, database[recordCount].name, 
                  &database[recordCount].price) != EOF) {
        recordCount++;
        if (recordCount >= MAX_RECORDS) {
            printf("Database is full, stopping the load.\n");
            break;
        }
    }
    fclose(file);
    printf("Database loaded successfully. Found %d products.\n", recordCount);
}

int main() {
    int choice;
    
    loadFromFile(); // Load the database from file at the start
    
    do {
        printf("\n--- Product Database ---\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Search Product\n");
        printf("4. Delete Product\n");
        printf("5. Save to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: searchProduct(); break;
            case 4: deleteProduct(); break;
            case 5: saveToFile(); break;
            case 6: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}