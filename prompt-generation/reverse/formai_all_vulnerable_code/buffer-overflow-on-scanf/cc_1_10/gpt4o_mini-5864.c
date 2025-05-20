//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char manufacturer[50];
    int expiryYear;
    int stock;
    float price;
} Medicine;

void addMedicine(Medicine medicines[], int *count) {
    if (*count >= MAX_MEDICINES) {
        printf("Whoa! No more space to add medicines!\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter manufacturer: ");
    scanf("%s", newMedicine.manufacturer);
    printf("Enter expiry year: ");
    scanf("%d", &newMedicine.expiryYear);
    printf("Enter stock: ");
    scanf("%d", &newMedicine.stock);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);

    medicines[*count] = newMedicine;
    (*count)++;
    
    printf("Medicine added successfully! It's like a magic spell in the world of pharmacy!\n");
}

void displayMedicines(Medicine medicines[], int count) {
    if (count == 0) {
        printf("Oh no! No medicines to display!\n");
        return;
    }

    printf("Listing all medicines:\n");
    for (int i = 0; i < count; i++) {
        printf("Medicine #%d:\n", i + 1);
        printf("Name: %s\n", medicines[i].name);
        printf("Manufacturer: %s\n", medicines[i].manufacturer);
        printf("Expiry Year: %d\n", medicines[i].expiryYear);
        printf("Stock: %d\n", medicines[i].stock);
        printf("Price: %.2f\n", medicines[i].price);
        printf("---------------------\n");
    }
}

void updateStock(Medicine medicines[], int count) {
    char name[50];
    printf("Enter the name of the medicine to update stock: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            int newStock;
            printf("Current stock is %d. Enter new stock: ", medicines[i].stock);
            scanf("%d", &newStock);
            medicines[i].stock = newStock;
            printf("Stock updated! It's like a breath of fresh air!\n");
            return;
        }
    }
    printf("Medicine not found! How could this happen?!\n");
}

void deleteMedicine(Medicine medicines[], int *count) {
    char name[50];
    printf("Enter the name of the medicine to delete: ");
    scanf("%s", name);
    for (int i = 0; i < *count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            (*count)--;
            printf("Medicine deleted! Like it vanished into thin air!\n");
            return;
        }
    }
    printf("Medicine not found! What a tragic twist of fate!\n");
}

int main() {
    Medicine medicines[MAX_MEDICINES];
    int count = 0;
    int choice;

    printf("Welcome to the Medicine Management System! What a ride it is!\n");

    while (1) {
        printf("\n1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Update Stock\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                displayMedicines(medicines, count);
                break;
            case 3:
                updateStock(medicines, count);
                break;
            case 4:
                deleteMedicine(medicines, &count);
                break;
            case 5:
                printf("Exiting program. Goodbye! It's been a wild ride!\n");
                exit(0);
            default:
                printf("Oh no! Invalid choice! Choose wisely next time!\n");
        }
    }

    return 0;
}