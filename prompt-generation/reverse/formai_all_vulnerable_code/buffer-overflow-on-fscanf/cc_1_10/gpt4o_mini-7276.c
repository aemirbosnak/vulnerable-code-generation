//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char manufacturer[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicine_count = 0;

void add_medicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Inventory is full! Cannot add more medicines.\n");
        return;
    }
    Medicine new_medicine;
    new_medicine.id = medicine_count + 1;

    printf("Enter medicine name: ");
    scanf(" %[^\n]", new_medicine.name);
    printf("Enter manufacturer name: ");
    scanf(" %[^\n]", new_medicine.manufacturer);
    printf("Enter price: ");
    scanf("%f", &new_medicine.price);
    printf("Enter quantity: ");
    scanf("%d", &new_medicine.quantity);

    inventory[medicine_count] = new_medicine;
    medicine_count++;
    printf("Medicine added successfully!\n");
}

void display_medicines() {
    if (medicine_count == 0) {
        printf("No medicines in inventory!\n");
        return;
    }
    printf("\n--- Medicine Inventory ---\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("ID: %d, Name: %s, Manufacturer: %s, Price: %.2f, Quantity: %d\n",
               inventory[i].id, inventory[i].name, inventory[i].manufacturer,
               inventory[i].price, inventory[i].quantity);
    }
}

void update_medicine() {
    int id;
    printf("Enter the ID of the medicine to update: ");
    scanf("%d", &id);

    if (id < 1 || id > medicine_count) {
        printf("Invalid medicine ID!\n");
        return;
    }

    Medicine *med = &inventory[id - 1];
    printf("Update details for %s (Current Price: %.2f, Current Quantity: %d)\n",
           med->name, med->price, med->quantity);

    printf("Enter new name (or '-' to skip): ");
    char temp_name[MAX_NAME_LENGTH];
    scanf(" %[^\n]", temp_name);
    if (strcmp(temp_name, "-") != 0) {
        strcpy(med->name, temp_name);
    }
    printf("Enter new manufacturer (or '-' to skip): ");
    char temp_manufacturer[MAX_NAME_LENGTH];
    scanf(" %[^\n]", temp_manufacturer);
    if (strcmp(temp_manufacturer, "-") != 0) {
        strcpy(med->manufacturer, temp_manufacturer);
    }
    
    printf("Enter new price (or -1 to skip): ");
    float new_price;
    scanf("%f", &new_price);
    if (new_price >= 0) {
        med->price = new_price;
    }
    
    printf("Enter new quantity (or -1 to skip): ");
    int new_quantity;
    scanf("%d", &new_quantity);
    if (new_quantity >= 0) {
        med->quantity = new_quantity;
    }

    printf("Medicine updated successfully!\n");
}

void delete_medicine() {
    int id;
    printf("Enter the ID of the medicine to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > medicine_count) {
        printf("Invalid medicine ID!\n");
        return;
    }

    for (int i = id - 1; i < medicine_count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    medicine_count--;
    printf("Medicine deleted successfully!\n");
}

void save_inventory() {
    FILE *file = fopen("inventory.txt", "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < medicine_count; i++) {
        fprintf(file, "%d %s %s %.2f %d\n", inventory[i].id, inventory[i].name,
                inventory[i].manufacturer, inventory[i].price, inventory[i].quantity);
    }
    fclose(file);
    printf("Inventory saved to inventory.txt\n");
}

void load_inventory() {
    FILE *file = fopen("inventory.txt", "r");
    if (!file) {
        printf("Could not open file for reading. Starting with empty inventory.\n");
        return;
    }
    while (fscanf(file, "%d %s %s %f %d", 
                  &inventory[medicine_count].id, 
                  inventory[medicine_count].name, 
                  inventory[medicine_count].manufacturer,
                  &inventory[medicine_count].price, 
                  &inventory[medicine_count].quantity) != EOF) {
        medicine_count++;
    }
    fclose(file);
    printf("Inventory loaded from inventory.txt\n");
}

int main() {
    load_inventory();
    int choice;
    
    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Save Inventory\n");
        printf("6. Exit\n");
        printf("Choose an action: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_medicines();
                break;
            case 3:
                update_medicine();
                break;
            case 4:
                delete_medicine();
                break;
            case 5:
                save_inventory();
                break;
            case 6:
                save_inventory();
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}