//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50
#define CODE_LENGTH 20

// Structure to hold medicine information
typedef struct {
    char name[NAME_LENGTH];
    char code[CODE_LENGTH];
    int quantity;
    float price;
} Medicine;

// Function prototypes
void addMedicine(Medicine *medicines, int *count);
void viewMedicines(Medicine *medicines, int count);
void searchMedicine(Medicine *medicines, int count);
void deleteMedicine(Medicine *medicines, int *count);
void saveData(Medicine *medicines, int count);
void loadData(Medicine *medicines, int *count);

int main() {
    Medicine medicines[MAX_MEDICINES];
    int count = 0;
    int choice;

    loadData(medicines, &count);

    do {
        printf("\n===== Medical Store Management System =====\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addMedicine(medicines, &count); break;
            case 2: viewMedicines(medicines, count); break;
            case 3: searchMedicine(medicines, count); break;
            case 4: deleteMedicine(medicines, &count); break;
            case 5: saveData(medicines, count); printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addMedicine(Medicine *medicines, int *count) {
    if (*count >= MAX_MEDICINES) {
        printf("Medicine inventory is full!\n");
        return;
    }
    printf("Enter medicine name: ");
    scanf("%s", medicines[*count].name);
    printf("Enter medicine code: ");
    scanf("%s", medicines[*count].code);
    printf("Enter quantity: ");
    scanf("%d", &medicines[*count].quantity);
    printf("Enter price: ");
    scanf("%f", &medicines[*count].price);
    (*count)++;
    printf("Medicine added successfully!\n");
}

void viewMedicines(Medicine *medicines, int count) {
    if (count == 0) {
        printf("No medicines in inventory.\n");
        return;
    }
    printf("\nAvailable Medicines:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (Code: %s) | Quantity: %d | Price: %.2f\n", 
                i + 1, medicines[i].name, medicines[i].code, 
                medicines[i].quantity, medicines[i].price);
    }
}

void searchMedicine(Medicine *medicines, int count) {
    char searchCode[CODE_LENGTH];
    printf("Enter medicine code to search: ");
    scanf("%s", searchCode);
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].code, searchCode) == 0) {
            printf("Search Result: %s | Quantity: %d | Price: %.2f\n",
                    medicines[i].name, medicines[i].quantity, medicines[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void deleteMedicine(Medicine *medicines, int *count) {
    char deleteCode[CODE_LENGTH];
    printf("Enter medicine code to delete: ");
    scanf("%s", deleteCode);
    int found = 0;

    for (int i = 0; i < *count; i++) {
        if (strcmp(medicines[i].code, deleteCode) == 0) {
            for (int j = i; j < *count - 1; j++) {
                medicines[j] = medicines[j + 1]; // Shift elements to left
            }
            (*count)--;
            found = 1;
            printf("Medicine deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Medicine not found for deletion!\n");
    }
}

void saveData(Medicine *medicines, int count) {
    FILE *file = fopen("medicines.dat", "wb");
    if (file == NULL) {
        printf("Error saving data!\n");
        return;
    }
    fwrite(medicines, sizeof(Medicine), count, file);
    fclose(file);
    printf("Data saved successfully!\n");
}

void loadData(Medicine *medicines, int *count) {
    FILE *file = fopen("medicines.dat", "rb");
    if (file != NULL) {
        *count = fread(medicines, sizeof(Medicine), MAX_MEDICINES, file);
        fclose(file);
        printf("Data loaded successfully!\n");
    }
}