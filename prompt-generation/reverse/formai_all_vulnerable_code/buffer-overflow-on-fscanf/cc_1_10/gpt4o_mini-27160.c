//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50
#define CODE_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char code[CODE_LENGTH];
    float price;
    int quantity;
} Medicine;

void addMedicine();
void displayMedicines();
void searchMedicine();
void deleteMedicine();
void saveMedicines();
void loadMedicines();
void showMenu();

Medicine medicines[MAX_MEDICINES];
int medicineCount = 0;

int main() {
    loadMedicines();
    int choice;
    
    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                saveMedicines();
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void showMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
}

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Medicine inventory is full!\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter the medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter the medicine code: ");
    scanf("%s", newMedicine.code);
    printf("Enter the medicine price: ");
    scanf("%f", &newMedicine.price);
    printf("Enter the quantity available: ");
    scanf("%d", &newMedicine.quantity);

    medicines[medicineCount] = newMedicine;
    medicineCount++;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available in the inventory.\n");
        return;
    }

    printf("\n--- List of Medicines ---\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("Name: %s, Code: %s, Price: %.2f, Quantity: %d\n", medicines[i].name, medicines[i].code, medicines[i].price, medicines[i].quantity);
    }
}

void searchMedicine() {
    char code[CODE_LENGTH];
    printf("Enter the medicine code to search: ");
    scanf("%s", code);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].code, code) == 0) {
            printf("Medicine found! Name: %s, Code: %s, Price: %.2f, Quantity: %d\n", medicines[i].name, medicines[i].code, medicines[i].price, medicines[i].quantity);
            return;
        }
    }
    printf("Medicine with code %s not found!\n", code);
}

void deleteMedicine() {
    char code[CODE_LENGTH];
    printf("Enter the medicine code to delete: ");
    scanf("%s", code);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].code, code) == 0) {
            for (int j = i; j < medicineCount - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            medicineCount--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine with code %s not found!\n", code);
}

void saveMedicines() {
    FILE *file = fopen("medicines.txt", "w");
    if (file == NULL) {
        printf("Error saving medicines to file!\n");
        return;
    }
    
    for (int i = 0; i < medicineCount; i++) {
        fprintf(file, "%s %s %.2f %d\n", medicines[i].name, medicines[i].code, medicines[i].price, medicines[i].quantity);
    }
    fclose(file);
    printf("Medicines saved successfully!\n");
}

void loadMedicines() {
    FILE *file = fopen("medicines.txt", "r");
    if (file == NULL) {
        printf("No existing medicines found, starting fresh inventory.\n");
        return;
    }

    while (fscanf(file, "%s %s %f %d", medicines[medicineCount].name, medicines[medicineCount].code, &medicines[medicineCount].price, &medicines[medicineCount].quantity) != EOF) {
        medicineCount++;
    }
    fclose(file);
    printf("Medicines loaded successfully!\n");
}