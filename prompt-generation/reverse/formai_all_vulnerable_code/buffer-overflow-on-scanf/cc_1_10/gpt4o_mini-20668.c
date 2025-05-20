//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char category[30];
    float price;
    int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicineCount = 0;

// Function prototypes
void addMedicine();
void displayMedicines();
void searchMedicine();

int main() {
    int choice;

    while (1) {
        printf("\n*** Medical Store Management System ***\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Exit\n");
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
                printf("Exiting the system.\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Medicines storage is full!\n");
        return;
    }
    
    Medicine newMedicine;
    
    printf("Enter medicine name: ");
    getchar(); // consume newline character
    fgets(newMedicine.name, sizeof(newMedicine.name), stdin);
    newMedicine.name[strcspn(newMedicine.name, "\n")] = '\0'; // Remove newline
    
    printf("Enter medicine category: ");
    fgets(newMedicine.category, sizeof(newMedicine.category), stdin);
    newMedicine.category[strcspn(newMedicine.category, "\n")] = '\0'; // Remove newline

    printf("Enter medicine price: ");
    scanf("%f", &newMedicine.price);

    printf("Enter medicine quantity: ");
    scanf("%d", &newMedicine.quantity);

    medicines[medicineCount] = newMedicine;
    medicineCount++;
    
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available in the system.\n");
        return;
    }

    printf("\nList of Medicines:\n");
    printf("%-20s %-20s %-10s %-10s\n", "Name", "Category", "Price", "Quantity");
    for (int i = 0; i < medicineCount; i++) {
        printf("%-20s %-20s %-10.2f %-10d\n", medicines[i].name, medicines[i].category, medicines[i].price, medicines[i].quantity);
    }
}

void searchMedicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    getchar(); // consume newline character
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    int found = 0;
    for (int i = 0; i < medicineCount; i++) {
        if (strcasecmp(medicines[i].name, name) == 0) {
            printf("\nMedicine found:\n");
            printf("Name: %s\n", medicines[i].name);
            printf("Category: %s\n", medicines[i].category);
            printf("Price: %.2f\n", medicines[i].price);
            printf("Quantity: %d\n", medicines[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found in the system.\n");
    }
}