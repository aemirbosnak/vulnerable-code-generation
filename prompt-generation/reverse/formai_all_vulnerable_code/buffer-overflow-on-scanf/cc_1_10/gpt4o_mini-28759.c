//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a structure to represent a medicine
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Medicine;

// Function prototypes
void addMedicine(Medicine *meds, int *count);
void displayMedicines(Medicine *meds, int count);
void searchMedicine(Medicine *meds, int count);
void updateMedicine(Medicine *meds, int count);
void deleteMedicine(Medicine *meds, int *count);
void saveToFile(Medicine *meds, int count);
void loadFromFile(Medicine *meds, int *count);

int main() {
    Medicine *meds = malloc(100 * sizeof(Medicine)); // Dynamic allocation for 100 medicines
    int count = 0;
    int choice;

    loadFromFile(meds, &count); // Load existing entries

    while(1) {
        printf("\n=== Medical Store Management System ===\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(meds, &count);
                break;
            case 2:
                displayMedicines(meds, count);
                break;
            case 3:
                searchMedicine(meds, count);
                break;
            case 4:
                updateMedicine(meds, count);
                break;
            case 5:
                deleteMedicine(meds, &count);
                break;
            case 6:
                saveToFile(meds, count);
                free(meds);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addMedicine(Medicine *meds, int *count) {
    printf("Enter Medicine ID: ");
    scanf("%d", &meds[*count].id);
    printf("Enter Medicine Name: ");
    scanf("%s", meds[*count].name);
    printf("Enter Quantity: ");
    scanf("%d", &meds[*count].quantity);
    printf("Enter Price: ");
    scanf("%f", &meds[*count].price);
    (*count)++;
    printf("Medicine added successfully!\n");
}

void displayMedicines(Medicine *meds, int count) {
    printf("\nMedicine List:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for(int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", meds[i].id, meds[i].name, meds[i].quantity, meds[i].price);
    }
}

void searchMedicine(Medicine *meds, int count) {
    int id;
    printf("Enter Medicine ID to search: ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++) {
        if(meds[i].id == id) {
            printf("Medicine found: %s, Quantity: %d, Price: %.2f\n", meds[i].name, meds[i].quantity, meds[i].price);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void updateMedicine(Medicine *meds, int count) {
    int id;
    printf("Enter Medicine ID to update: ");
    scanf("%d", &id);
    for(int i = 0; i < count; i++) {
        if(meds[i].id == id) {
            printf("Updating Medicine: %s\n", meds[i].name);
            printf("Enter new Quantity: ");
            scanf("%d", &meds[i].quantity);
            printf("Enter new Price: ");
            scanf("%f", &meds[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine(Medicine *meds, int *count) {
    int id;
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);
    for(int i = 0; i < *count; i++) {
        if(meds[i].id == id) {
            for(int j = i; j < *count - 1; j++) {
                meds[j] = meds[j + 1]; // Shift medicines left
            }
            (*count)--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void saveToFile(Medicine *meds, int count) {
    FILE *file = fopen("medicines.dat", "wb");
    fwrite(meds, sizeof(Medicine), count, file);
    fclose(file);
    printf("Data saved successfully!\n");
}

void loadFromFile(Medicine *meds, int *count) {
    FILE *file = fopen("medicines.dat", "rb");
    if (file != NULL) {
        *count = fread(meds, sizeof(Medicine), 100, file);
        fclose(file);
        printf("Data loaded successfully!\n");
    }
}