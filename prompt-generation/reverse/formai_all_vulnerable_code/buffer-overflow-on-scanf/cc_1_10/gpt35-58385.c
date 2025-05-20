//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to display main menu
void displayMenu() {
    printf("\n-------------Medical Store Management System---------------\n\n");
    printf("1. Add Medicine\n");
    printf("2. Remove Medicine\n");
    printf("3. Search Medicine\n");
    printf("4. Display All Medicines\n");
    printf("5. Sell Medicine\n");
    printf("6. Exit\n");
}

//Medicine structure
struct Medicine {
    char name[50];
    int quantity;
    float price;
    int id;
};

//Array of Medicines
struct Medicine medicineList[100];

//Count of Medicines in List
int count = 0;

//Function to Add Medicine in List
void addMedicine() {
    struct Medicine medicine;

    printf("Enter Medicine ID: ");
    scanf("%d", &medicine.id);

    printf("Enter Medicine Name: ");
    scanf("%s", medicine.name);

    printf("Enter Medicine Quantity: ");
    scanf("%d", &medicine.quantity);

    printf("Enter Medicine Price: ");
    scanf("%f", &medicine.price);

    medicineList[count++] = medicine;
    printf("\nMedicine Added Successfully!\n");
}

//Function to Remove Medicine from List
void removeMedicine() {
    int id, index = -1;
    printf("Enter Medicine ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (medicineList[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nMedicine with ID %d not found!\n", id);
        return;
    }
    for (int i = index; i < count - 1; i++) {
        medicineList[i] = medicineList[i+1];
    }
    count--;
    printf("\nMedicine Removed Successfully!\n");
}

//Function to Search Medicine from List by Name
void searchMedicine() {
    char name[50];
    printf("Enter Medicine Name to Search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(medicineList[i].name, name) == 0) {
            printf("\nFound Medicine: \n");
            printf("ID: %d\tName: %s\tQuantity: %d\tPrice: %.2f\n", medicineList[i].id, medicineList[i].name, medicineList[i].quantity, medicineList[i].price);
            return;
        }
    }
    printf("\nMedicine with Name '%s' not found!\n", name);
}

//Function to Display All Medicines from List
void displayAllMedicines() {
    printf("\nTotal Medicines Available: %d\n", count);
    if (count == 0) {
        printf("Sorry, No Medicines Available!\n");
        return;
    }

    printf("\n\nID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%.2f\n", medicineList[i].id, medicineList[i].name, medicineList[i].quantity, medicineList[i].price);
    }
}

//Function to Sell Medicine
void sellMedicine() {
    int id, index = -1, quantity;
    printf("Enter Medicine ID to Sell: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (medicineList[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nMedicine with ID %d not found!\n", id);
        return;
    }
    printf("Enter Selling Quantity: ");
    scanf("%d", &quantity);
    if (quantity <= 0 || quantity > medicineList[index].quantity) {
        printf("\nInvalid Quantity!\n");
        return;
    }
    medicineList[index].quantity -= quantity;
    printf("\nTotal Amount: %.2f\n", medicineList[index].price * quantity);
    printf("\nMedicine Sold Successfully!\nRemaining Quantity: %d\n", medicineList[index].quantity);
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                removeMedicine();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                displayAllMedicines();
                break;
            case 5:
                sellMedicine();
                break;
            case 6:
                printf("\nThank you for using Medical Store Management System!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid Choice, Try Again!\n");
                break;
        }
    }
    return 0;
}