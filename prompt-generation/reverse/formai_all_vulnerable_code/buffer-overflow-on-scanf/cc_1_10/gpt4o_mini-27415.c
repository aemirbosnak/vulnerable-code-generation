//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: detailed
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
int medicineCount = 0;

// Function Prototypes
void addMedicine();
void displayMedicines();
void updateStock();
void searchMedicine();
void displayMenu();
void saveData();
void loadData();

int main() {
    loadData();
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addMedicine(); break;
            case 2: displayMedicines(); break;
            case 3: updateStock(); break;
            case 4: searchMedicine(); break;
            case 5: saveData(); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void displayMenu() {
    printf("\n=== Medical Store Management System ===\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Update Stock\n");
    printf("4. Search Medicine\n");
    printf("5. Exit\n");
    printf("========================================\n");
}

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Maximum limit reached.\n");
        return;
    }
    
    Medicine newMedicine;
    newMedicine.id = medicineCount + 1; // Simplistic way to assign ID
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter manufacturer: ");
    scanf("%s", newMedicine.manufacturer);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    
    medicines[medicineCount++] = newMedicine;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available.\n");
        return;
    }

    printf("\n=== List of Medicines ===\n");
    printf("ID\tName\tManufacturer\tPrice\tQuantity\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%d\t%s\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, 
               medicines[i].manufacturer, medicines[i].price, medicines[i].quantity);
    }
}

void updateStock() {
    int id, quantity;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);
    
    if (id < 1 || id > medicineCount) {
        printf("Invalid medicine ID.\n");
        return;
    }
    
    printf("Enter quantity to add: ");
    scanf("%d", &quantity);
    medicines[id - 1].quantity += quantity;
    printf("Stock updated successfully! New quantity: %d\n", medicines[id - 1].quantity);
}

void searchMedicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    
    int found = 0;
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine found! ID: %d, Manufacturer: %s, Price: %.2f, Quantity: %d\n", 
                   medicines[i].id, medicines[i].manufacturer, medicines[i].price, medicines[i].quantity);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Medicine not found.\n");
    }
}

void saveData() {
    FILE *file = fopen("medicines.dat", "wb");
    if (file == NULL) {
        printf("Error saving data!\n");
        return;
    }
    
    fwrite(medicines, sizeof(Medicine), medicineCount, file);
    fclose(file);
    printf("Data saved successfully!\n");
}

void loadData() {
    FILE *file = fopen("medicines.dat", "rb");
    if (file == NULL) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }
    
    medicineCount = fread(medicines, sizeof(Medicine), MAX_MEDICINES, file);
    fclose(file);
    printf("Data loaded successfully!\n");
}