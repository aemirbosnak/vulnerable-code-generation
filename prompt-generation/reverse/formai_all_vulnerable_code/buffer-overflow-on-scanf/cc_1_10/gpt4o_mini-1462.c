//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50
#define CODE_LENGTH 20

typedef struct {
    char code[CODE_LENGTH];
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicine_count = 0;

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Medicine list is full. Cannot add more medicines.\n");
        return;
    }

    Medicine new_medicine;
    printf("Enter medicine code: ");
    scanf("%s", new_medicine.code);
    printf("Enter medicine name: ");
    scanf(" %[^\n]%*c", new_medicine.name);
    printf("Enter quantity: ");
    scanf("%d", &new_medicine.quantity);
    printf("Enter price: ");
    scanf("%f", &new_medicine.price);

    medicines[medicine_count] = new_medicine;
    medicine_count++;
    printf("Medicine added successfully!\n");
}

void updateMedicine() {
    char code[CODE_LENGTH];
    printf("Enter medicine code to update: ");
    scanf("%s", code);
    
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(medicines[i].code, code) == 0) {
            printf("Updating medicine: %s\n", medicines[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine with code %s not found!\n", code);
}

void deleteMedicine() {
    char code[CODE_LENGTH];
    printf("Enter medicine code to delete: ");
    scanf("%s", code);
    
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(medicines[i].code, code) == 0) {
            for (int j = i; j < medicine_count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            medicine_count--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine with code %s not found!\n", code);
}

void viewMedicines() {
    if (medicine_count == 0) {
        printf("No medicines available in the store.\n");
        return;
    }

    printf("List of Medicines:\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("Code: %s, Name: %s, Quantity: %d, Price: %.2f\n",
               medicines[i].code, medicines[i].name,
               medicines[i].quantity, medicines[i].price);
    }
}

void showMenu() {
    printf("\nMedical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. Update Medicine\n");
    printf("3. Delete Medicine\n");
    printf("4. View Medicines\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                updateMedicine();
                break;
            case 3:
                deleteMedicine();
                break;
            case 4:
                viewMedicines();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}