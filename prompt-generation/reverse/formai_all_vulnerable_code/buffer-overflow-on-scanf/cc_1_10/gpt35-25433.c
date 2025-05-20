//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int stock;
    float price;
};

void addMedicine(struct medicine [], int *);
void deleteMedicine(struct medicine [], int *);
void displayMedicine(struct medicine [], int);
void searchMedicine(struct medicine [], int);
void updatePrice(struct medicine [], int);

int main() {
    int choice, count = 0;
    struct medicine inventory[100];
    do {
        printf("\n------------Medical Store Management System------------\n");
        printf("\n1. Add Medicine");
        printf("\n2. Delete Medicine");
        printf("\n3. Display Medicine");
        printf("\n4. Search Medicine");
        printf("\n5. Update Medicine Price");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addMedicine(inventory, &count);
                break;
            case 2:
                deleteMedicine(inventory, &count);
                break;
            case 3:
                displayMedicine(inventory, count);
                break;
            case 4:
                searchMedicine(inventory, count);
                break;
            case 5:
                updatePrice(inventory, count);
                break;
            case 6:
                printf("Thank you for using Medical Store Management System!");
                break;
            default:
                printf("Invalid choice! Please try again.");
                break;
        }
    } while (choice != 6);
    return 0;
}

void addMedicine(struct medicine inventory[], int *count) {
    printf("\n------------Add Medicine------------\n");
    printf("Enter medicine name: ");
    scanf("%s", inventory[*count].name);
    printf("Enter medicine stock: ");
    scanf("%d", &inventory[*count].stock);
    printf("Enter medicine price: ");
    scanf("%f", &inventory[*count].price);
    *count = *count + 1;
    printf("\nMedicine added successfully!\n");
}

void deleteMedicine(struct medicine inventory[], int *count) {
    int i, j;
    char name[50];
    printf("\n------------Delete Medicine------------\n");
    printf("Enter medicine name: ");
    scanf("%s", name);
    for (i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (j = i; j < *count; j++) {
                strcpy(inventory[j].name, inventory[j+1].name);
                inventory[j].stock = inventory[j+1].stock;
                inventory[j].price = inventory[j+1].price;
            }
            *count = *count - 1;
            printf("\nMedicine deleted successfully!\n");
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

void displayMedicine(struct medicine inventory[], int count) {
    int i;
    printf("\n------------Display Medicine------------\n");
    printf("Name\t\tStock\tPrice\n");
    for (i = 0; i < count; i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].stock, inventory[i].price);
    }
}

void searchMedicine(struct medicine inventory[], int count) {
    int i;
    char name[50];
    printf("\n------------Search Medicine------------\n");
    printf("Enter medicine name: ");
    scanf("%s", name);
    for (i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("\nMedicine found!\n");
            printf("Name\t\tStock\tPrice\n");
            printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].stock, inventory[i].price);
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

void updatePrice(struct medicine inventory[], int count) {
    int i;
    char name[50];
    float newPrice;
    printf("\n------------Update Medicine Price------------\n");
    printf("Enter medicine name: ");
    scanf("%s", name);
    for (i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("\nEnter new price: ");
            scanf("%f", &newPrice);
            inventory[i].price = newPrice;
            printf("\nMedicine price updated successfully!\n");
            return;
        }
    }
    printf("\nMedicine not found!\n");
}