//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicine_count = 0;

void add_medicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Storage is full.\n");
        return;
    }
    Medicine new_medicine;
    new_medicine.id = medicine_count + 1;

    printf("Enter medicine name: ");
    getchar();  // To consume newline character left by previous input
    fgets(new_medicine.name, sizeof(new_medicine.name), stdin);
    new_medicine.name[strcspn(new_medicine.name, "\n")] = 0; // Remove newline

    printf("Enter manufacturer: ");
    fgets(new_medicine.manufacturer, sizeof(new_medicine.manufacturer), stdin);
    new_medicine.manufacturer[strcspn(new_medicine.manufacturer, "\n")] = 0; // Remove newline

    printf("Enter price: ");
    scanf("%f", &new_medicine.price);
    printf("Enter quantity: ");
    scanf("%d", &new_medicine.quantity);

    medicines[medicine_count] = new_medicine;
    medicine_count++;
    printf("Medicine added successfully! ID: %d\n", new_medicine.id);
}

void display_medicines() {
    if (medicine_count == 0) {
        printf("No medicines available.\n");
        return;
    }
    printf("\nAvailable Medicines:\n");
    printf("ID\tName\t\tManufacturer\tPrice\tQuantity\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t%s\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].manufacturer, medicines[i].price, medicines[i].quantity);
    }
}

void search_medicine() {
    int id;
    printf("Enter medicine ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < medicine_count; i++) {
        if (medicines[i].id == id) {
            printf("\nMedicine Found:\n");
            printf("ID: %d\n", medicines[i].id);
            printf("Name: %s\n", medicines[i].name);
            printf("Manufacturer: %s\n", medicines[i].manufacturer);
            printf("Price: %.2f\n", medicines[i].price);
            printf("Quantity: %d\n", medicines[i].quantity);
            return;
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

void delete_medicine() {
    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < medicine_count; i++) {
        if (medicines[i].id == id) {
            for (int j = i; j < medicine_count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            medicine_count--;
            printf("Medicine with ID %d deleted successfully!\n", id);
            return;
        }
    }
    printf("Medicine with ID %d not found.\n", id);
}

void menu() {
    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: add_medicine(); break;
            case 2: display_medicines(); break;
            case 3: search_medicine(); break;
            case 4: delete_medicine(); break;
            case 5: exit(0); break;
            default: printf("Invalid choice, please try again.\n"); 
        }
    }
}

int main() {
    menu();
    return 0;
}