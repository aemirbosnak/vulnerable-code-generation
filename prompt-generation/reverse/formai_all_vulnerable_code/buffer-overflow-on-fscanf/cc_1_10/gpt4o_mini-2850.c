//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Storage full!\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);

    medicines[medicineCount] = newMedicine;
    medicineCount++;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available!\n");
        return;
    }

    printf("List of Medicines:\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%d. Name: %s, Quantity: %d, Price: %.2f\n",
               i + 1, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void updateMedicine() {
    int index;
    printf("Enter the number of the medicine to update: ");
    scanf("%d", &index);
    
    if (index < 1 || index > medicineCount) {
        printf("Invalid medicine number!\n");
        return;
    }

    index--; // Adjust for zero-based index
    printf("Updating medicine: %s\n", medicines[index].name);
    printf("Enter new quantity: ");
    scanf("%d", &medicines[index].quantity);
    printf("Enter new price: ");
    scanf("%f", &medicines[index].price);
    
    printf("Medicine updated successfully!\n");
}

void deleteMedicine() {
    int index;
    printf("Enter the number of the medicine to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > medicineCount) {
        printf("Invalid medicine number!\n");
        return;
    }

    index--; // Adjust for zero-based index
    for (int i = index; i < medicineCount - 1; i++) {
        medicines[i] = medicines[i + 1];
    }
    medicineCount--;
    printf("Medicine deleted successfully!\n");
}

void saveToFile() {
    FILE *file = fopen("medicines.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    for (int i = 0; i < medicineCount; i++) {
        fprintf(file, "%s %d %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
    fclose(file);
    printf("Medicines saved to file successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("medicines.txt", "r");
    if (file == NULL) {
        printf("No saved medicines found, starting fresh!\n");
        return;
    }
    medicineCount = 0;
    while (fscanf(file, "%s %d %f", medicines[medicineCount].name, 
           &medicines[medicineCount].quantity, 
           &medicines[medicineCount].price) == 3) {
        medicineCount++;
    }
    fclose(file);
    printf("Medicines loaded from file successfully!\n");
}

void displayMenu() {
    printf("\n");
    printf("===== Medical Store Management System =====\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Save Medicines to File\n");
    printf("6. Load Medicines from File\n");
    printf("7. Exit\n");
    printf("============================================\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    loadFromFile();

    while (1) {
        displayMenu();
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
                saveToFile();
                break;
            case 6:
                loadFromFile();
                break;
            case 7:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}