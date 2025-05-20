//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    int id;
    char name[50];
    char manufacturer[50];
    double price;
    int quantity;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int medicine_count = 0;

void add_medicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Inventory is full! Cannot add more medicines.\n");
        return;
    }

    Medicine med;
    med.id = medicine_count + 1;

    printf("Enter medicine name: ");
    scanf("%s", med.name);
    
    printf("Enter manufacturer: ");
    scanf("%s", med.manufacturer);
    
    printf("Enter price: ");
    scanf("%lf", &med.price);
    
    printf("Enter quantity: ");
    scanf("%d", &med.quantity);

    inventory[medicine_count] = med;
    medicine_count++;

    printf("Medicine added successfully!\n");
}

void view_medicines() {
    if (medicine_count == 0) {
        printf("No medicines available in the inventory.\n");
        return;
    }

    printf("\nMedicines in Inventory:\n");
    printf("ID\tName\t\tManufacturer\tPrice\tQuantity\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t%s\t%s\t%.2lf\t%d\n", 
                inventory[i].id, 
                inventory[i].name, 
                inventory[i].manufacturer, 
                inventory[i].price, 
                inventory[i].quantity);
    }
}

void sell_medicine() {
    int id, quantity;

    printf("Enter the ID of the medicine to sell: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > medicine_count) {
        printf("Invalid medicine ID!\n");
        return;
    }

    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    
    if (quantity > inventory[id - 1].quantity) {
        printf("Insufficient quantity in stock!\n");
        return;
    }

    inventory[id - 1].quantity -= quantity;
    
    printf("Sold %d units of %s. Remaining stock: %d\n", 
            quantity, 
            inventory[id - 1].name, 
            inventory[id - 1].quantity);
}

void search_medicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < medicine_count; i++) {
        if (strcasecmp(inventory[i].name, name) == 0) {
            printf("ID: %d, Name: %s, Manufacturer: %s, Price: %.2lf, Quantity: %d\n", 
                    inventory[i].id,
                    inventory[i].name,
                    inventory[i].manufacturer,
                    inventory[i].price,
                    inventory[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found in the inventory.\n");
    }
}

void update_medicine() {
    int id;
    printf("Enter the ID of the medicine to update: ");
    scanf("%d", &id);

    if (id <= 0 || id > medicine_count) {
        printf("Invalid medicine ID!\n");
        return;
    }

    printf("Updating details for %s:\n", inventory[id - 1].name);
    
    printf("Enter new name: ");
    scanf("%s", inventory[id - 1].name);
    
    printf("Enter new manufacturer: ");
    scanf("%s", inventory[id - 1].manufacturer);
    
    printf("Enter new price: ");
    scanf("%lf", &inventory[id - 1].price);
    
    printf("Enter new quantity: ");
    scanf("%d", &inventory[id - 1].quantity);

    printf("Medicine updated successfully!\n");
}

void menu() {
    int choice;
    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Sell Medicine\n");
        printf("4. Search Medicine\n");
        printf("5. Update Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                view_medicines();
                break;
            case 3:
                sell_medicine();
                break;
            case 4:
                search_medicine();
                break;
            case 5:
                update_medicine();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}