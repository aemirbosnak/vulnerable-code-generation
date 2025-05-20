//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining the structure for medicine details
struct Medicine {
    char name[50];
    char type[50];
    float price;
    int quantity;
};

// Function to add medicine in the store
void addMedicine(struct Medicine *medicines, int *count) {
    printf("\n-----Add Medicine-----\n");
    printf("Enter name of the medicine: ");
    scanf(" %[^\n]s", medicines[*count].name);
    printf("Enter type of the medicine: ");
    scanf(" %[^\n]s", medicines[*count].type);
    printf("Enter price of the medicine: ");
    scanf("%f", &medicines[*count].price);
    printf("Enter quantity of the medicine: ");
    scanf("%d", &medicines[*count].quantity);
    (*count)++;
    printf("\nMedicine added successfully!\n");
}

// Function to display all medicines in the store
void displayAllMedicines(struct Medicine *medicines, int count) {
    printf("\n-----Medicines in Store-----\n");
    if(count == 0) {
        printf("No medicines in store.\n");
    }
    else {
        printf("NAME\tTYPE\tPRICE\tQUANTITY\n");
        printf("--------------------------------------------\n");
        for(int i=0; i<count; i++) {
            printf("%s\t%s\t%.2f\t%d\n", medicines[i].name, medicines[i].type, medicines[i].price, medicines[i].quantity);
        }
    }
}

// Function to search for a medicine by name and display its details
void searchMedicine(struct Medicine *medicines, int count) {
    char searchName[50];
    printf("\n-----Search Medicine-----\n");
    printf("Enter name of the medicine to search: ");
    scanf(" %[^\n]s", searchName);
    for(int i=0; i<count; i++) {
        if(strcmp(medicines[i].name, searchName) == 0) {
            printf("NAME\tTYPE\tPRICE\tQUANTITY\n");
            printf("--------------------------------------------\n");
            printf("%s\t%s\t%.2f\t%d\n\n", medicines[i].name, medicines[i].type, medicines[i].price, medicines[i].quantity);
            return;
        }
    }
    printf("Medicine not found.\n");
}

// Function to update the quantity of medicine in the store
void updateMedicineQuantity(struct Medicine *medicines, int count) {
    char updateName[50];
    int updateQuantity, foundMedicine=0;
    printf("\n-----Update Medicine Quantity-----\n");
    printf("Enter name of the medicine to update: ");
    scanf(" %[^\n]s", updateName);
    for(int i=0; i<count; i++) {
        if(strcmp(medicines[i].name, updateName) == 0) {
            printf("Current quantity of %s is %d.\n", medicines[i].name, medicines[i].quantity);
            printf("Enter updated quantity: ");
            scanf("%d", &updateQuantity);
            medicines[i].quantity = updateQuantity;
            printf("\nQuantity updated successfully!\n");
            foundMedicine = 1;
            break;
        }
    }
    if(!foundMedicine) {
        printf("Medicine not found.\n");
    }
}

int main() {
    struct Medicine medicines[100];
    int choice, count=0;
    do {
        // Displaying Menu
        printf("\n-----Medical Store Management System-----\n");
        printf("1. Add Medicine\n");
        printf("2. Display All Medicines\n");
        printf("3. Search Medicine by Name\n");
        printf("4. Update Medicine Quantity\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: // Adding Medicine
                addMedicine(medicines, &count);
                break;
            case 2: // Displaying All Medicines
                displayAllMedicines(medicines, count);
                break;
            case 3: // Searching for a Medicine by Name
                searchMedicine(medicines, count);
                break;
            case 4: // Updating Medicine Quantity
                updateMedicineQuantity(medicines, count);
                break;
            case 5: // Exiting the Program
                printf("\nExiting program... Thank You!\n");
                break;
            default: // Invalid Choice
                printf("\nInvalid Choice! Please try again.\n");
        }
    } while(choice != 5);
    return 0;
}