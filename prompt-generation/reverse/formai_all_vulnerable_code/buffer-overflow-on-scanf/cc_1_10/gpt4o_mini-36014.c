//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    float price;
    int quantity;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicine_count = 0;

void add_medicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Error: Inventory full. Cannot add more medicines.\n");
        return;
    }
    
    Medicine new_medicine;
    new_medicine.id = medicine_count + 1;

    printf("Enter medicine name: ");
    scanf(" %[^\n]%*c", new_medicine.name);
    
    printf("Enter price of medicine: ");
    scanf("%f", &new_medicine.price);
    
    printf("Enter quantity of medicine: ");
    scanf("%d", &new_medicine.quantity);
    
    inventory[medicine_count] = new_medicine;
    medicine_count++;
    
    printf("Medicine '%s' added successfully!\n", new_medicine.name);
}

void list_medicines() {
    if (medicine_count == 0) {
        printf("No medicines in the inventory.\n");
        return;
    }

    printf("\nMedicine Inventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", 
               inventory[i].id, 
               inventory[i].name, 
               inventory[i].price, 
               inventory[i].quantity);
    }
    printf("-----------------------------------------\n");
}

void update_medicine() {
    int id;
    printf("Enter the ID of the medicine to update: ");
    scanf("%d", &id);

    if (id < 1 || id > medicine_count) {
        printf("Error: Medicine with ID %d not found.\n", id);
        return;
    }
    
    Medicine *med = &inventory[id - 1];
    printf("Current details - Name: %s, Price: %.2f, Quantity: %d\n", 
           med->name, med->price, med->quantity);

    printf("Enter new name (leave blank to keep unchanged): ");
    char new_name[MAX_NAME_LENGTH];
    scanf(" %[^\n]%*c", new_name);
    if (strlen(new_name) > 0) {
        strcpy(med->name, new_name);
    }

    printf("Enter new price (negative value to keep unchanged): ");
    float new_price;
    scanf("%f", &new_price);
    if (new_price >= 0) {
        med->price = new_price;
    }

    printf("Enter new quantity (negative value to keep unchanged): ");
    int new_quantity;
    scanf("%d", &new_quantity);
    if (new_quantity >= 0) {
        med->quantity = new_quantity;
    }

    printf("Medicine details updated successfully!\n");
}

void delete_medicine() {
    int id;
    printf("Enter the ID of the medicine to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > medicine_count) {
        printf("Error: Medicine with ID %d not found.\n", id);
        return;
    }
    
    for (int i = id - 1; i < medicine_count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    medicine_count--;

    printf("Medicine with ID %d deleted successfully!\n", id);
}

void search_medicine() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the medicine to search: ");
    scanf(" %[^\n]%*c", name);

    int found = 0;
    for (int i = 0; i < medicine_count; i++) {
        if (strstr(inventory[i].name, name) != NULL) {
            found = 1;
            printf("Found - ID: %d, Name: %s, Price: %.2f, Quantity: %d\n",
                   inventory[i].id, 
                   inventory[i].name, 
                   inventory[i].price, 
                   inventory[i].quantity);
        }
    }

    if (!found) {
        printf("No medicines found with name '%s'.\n", name);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. List Medicines\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Search Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                list_medicines();
                break;
            case 3:
                update_medicine();
                break;
            case 4:
                delete_medicine();
                break;
            case 5:
                search_medicine();
                break;
            case 6:
                printf("Exiting system...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}