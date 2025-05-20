//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicine_count = 0;

void add_medicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Maximum capacity reached.\n");
        return;
    }

    Medicine new_medicine;
    new_medicine.id = medicine_count + 1;

    printf("Enter medicine name: ");
    fgets(new_medicine.name, NAME_LENGTH, stdin);
    new_medicine.name[strcspn(new_medicine.name, "\n")] = 0; // Remove newline

    printf("Enter medicine price: ");
    scanf("%f", &new_medicine.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &new_medicine.quantity);
    getchar(); // Clear the newline character from input buffer

    medicines[medicine_count] = new_medicine;
    medicine_count++;
    printf("Medicine added successfully!\n");
}

void update_medicine() {
    int id;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);
    getchar(); // Clear the newline character from input buffer

    if (id < 1 || id > medicine_count) {
        printf("Invalid medicine ID.\n");
        return;
    }

    Medicine *med = &medicines[id - 1];
    printf("Updating medicine - %s\n", med->name);
    
    printf("Enter new medicine name: ");
    fgets(med->name, NAME_LENGTH, stdin);
    med->name[strcspn(med->name, "\n")] = 0; // Remove newline

    printf("Enter new medicine price: ");
    scanf("%f", &med->price);
    printf("Enter new medicine quantity: ");
    scanf("%d", &med->quantity);
    getchar(); // Clear the newline character from input buffer
    
    printf("Medicine updated successfully!\n");
}

void delete_medicine() {
    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);
    getchar(); // Clear the newline character from input buffer

    if (id < 1 || id > medicine_count) {
        printf("Invalid medicine ID.\n");
        return;
    }

    for (int i = id - 1; i < medicine_count - 1; i++) {
        medicines[i] = medicines[i + 1];  // Shift medicines left
    }
    medicine_count--;
    printf("Medicine deleted successfully!\n");
}

void view_medicines() {
    if (medicine_count == 0) {
        printf("No medicines available.\n");
        return;
    }

    printf("\nID\tName\t\tPrice\tQuantity\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
    printf("-----------------------------------------\n");
}

void display_menu() {
    printf("\nMedical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. Update Medicine\n");
    printf("3. Delete Medicine\n");
    printf("4. View Medicines\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                update_medicine();
                break;
            case 3:
                delete_medicine();
                break;
            case 4:
                view_medicines();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
    return 0;
}