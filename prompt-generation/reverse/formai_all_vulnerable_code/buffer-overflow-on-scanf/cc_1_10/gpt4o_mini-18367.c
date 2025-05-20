//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: random
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

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Medicine storage is full!\n");
        return;
    }

    Medicine m;
    m.id = medicine_count + 1;
    printf("Enter medicine name: ");
    scanf("%s", m.name);
    printf("Enter medicine price: ");
    scanf("%f", &m.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &m.quantity);

    medicines[medicine_count] = m;
    medicine_count++;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    if (medicine_count == 0) {
        printf("No medicines available!\n");
        return;
    }
    
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

void updateMedicine() {
    int id;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);

    if (id <= 0 || id > medicine_count) {
        printf("Invalid medicine ID!\n");
        return;
    }

    Medicine *m = &medicines[id - 1]; // 0-based index
    printf("Updating medicine: %s\n", m->name);
    printf("Enter new name (or . to keep current): ");
    char new_name[NAME_LENGTH];
    scanf("%s", new_name);
    
    if (strcmp(new_name, ".") != 0) {
        strcpy(m->name, new_name);
    }
    
    printf("Enter new price (or -1 to keep current): ");
    float new_price;
    scanf("%f", &new_price);
    if (new_price >= 0) {
        m->price = new_price;
    }

    printf("Enter new quantity (or -1 to keep current): ");
    int new_quantity;
    scanf("%d", &new_quantity);
    if (new_quantity >= 0) {
        m->quantity = new_quantity;
    }

    printf("Medicine updated successfully!\n");
}

void deleteMedicine() {
    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > medicine_count) {
        printf("Invalid medicine ID!\n");
        return;
    }
    
    for (int i = id - 1; i < medicine_count - 1; i++) {
        medicines[i] = medicines[i + 1];
    }
    medicine_count--;
    printf("Medicine deleted successfully!\n");
}

void displayMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
    printf("---------------------------------------\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
                break;
            case 3:
                updateMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}