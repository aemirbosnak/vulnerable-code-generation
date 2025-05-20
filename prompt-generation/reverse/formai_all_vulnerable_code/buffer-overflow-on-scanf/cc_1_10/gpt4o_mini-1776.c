//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

void addMedicine(Medicine *, int *);
void displayMedicines(Medicine *, int);
void searchMedicine(Medicine *, int);

int main() {
    Medicine medicines[MAX_MEDICINES];
    int choice;
    int totalMedicines = 0;

    printf("🎉 Welcome to the Medical Store Management System! 🎉\n");

    while (1) {
        printf("\n1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Exit\n");
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMedicine(medicines, &totalMedicines);
                break;
            case 2:
                displayMedicines(medicines, totalMedicines);
                break;
            case 3:
                searchMedicine(medicines, totalMedicines);
                break;
            case 4:
                printf("Thank you for using the system! Have a great day! 🌞\n");
                exit(0);
            default:
                printf("🚫 Invalid choice! Please try again. 🚫\n");
        }
    }
    return 0;
}

void addMedicine(Medicine *medicines, int *totalMedicines) {
    if (*totalMedicines >= MAX_MEDICINES) {
        printf("😢 Sorry, we can't add more medicines! Max limit reached! 😢\n");
        return;
    }
    printf("Enter medicine name: ");
    scanf("%s", medicines[*totalMedicines].name);
    printf("Enter quantity: ");
    scanf("%d", &medicines[*totalMedicines].quantity);
    printf("Enter price: ");
    scanf("%f", &medicines[*totalMedicines].price);
    (*totalMedicines)++;
    printf("🎉 Medicine added successfully! 🎉\n");
}

void displayMedicines(Medicine *medicines, int totalMedicines) {
    if (totalMedicines == 0) {
        printf("😮 No medicines available! Please add some first! 😮\n");
        return;
    }
    printf("\n📋 List of Medicines 📋\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Medicine Name", "Quantity", "Price");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < totalMedicines; i++) {
        printf("%-20s %-10d %-10.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
    printf("--------------------------------------------------\n");
}

void searchMedicine(Medicine *medicines, int totalMedicines) {
    char searchName[50];
    printf("Enter the medicine name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < totalMedicines; i++) {
        if (strcmp(medicines[i].name, searchName) == 0) {
            printf("🎯 Medicine found! 🎯\n");
            printf("Name: %s\n", medicines[i].name);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %.2f\n", medicines[i].price);
            return;
        }
    }
    printf("😢 Medicine not found! Try again! 😢\n");
}