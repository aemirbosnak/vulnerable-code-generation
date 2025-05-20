//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine;

void addMedicine(medicine *med, int size) {
    printf("Enter medicine name:\n");
    scanf("%s",med[size].name);
    printf("Enter quantity:\n");
    scanf("%d",&med[size].quantity);
    printf("Enter price:\n");
    scanf("%f",&med[size].price);
}

void sellMedicine(medicine *med, int size) {
    char name[50];
    printf("Enter medicine name to sell:\n");
    scanf("%s",name);
    for (int i = 0; i < size; i++) {
        if (strcmp(med[i].name, name) == 0) {
            if (med[i].quantity > 0) {
                med[i].quantity--;
                printf("Sold medicine %s, Remaining Quantity: %d, Price: %.2f\n", med[i].name, med[i].quantity, med[i].price);
            } else {
                printf("Medicine out of stock!\n");
            }
            return;
        }
    }
    printf("Medicine not found!\n");
}

void showInventory(medicine *med, int size) {
    printf("Current inventory:\n");
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t\t%.2f\n", med[i].name, med[i].quantity, med[i].price);
    }
}

int main() {
    medicine *med;
    int size = 0;
    int choice = 0;
    med = (medicine*) malloc(sizeof(medicine));
    while (choice != 4) {
        printf("1. Add medicine\n");
        printf("2. Sell medicine\n");
        printf("3. Show inventory\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                size++;
                med = (medicine*) realloc(med, size * sizeof(medicine));
                addMedicine(med, size - 1);
                break;
            case 2:
                sellMedicine(med, size);
                break;
            case 3:
                showInventory(med, size);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    free(med);
    return 0;
}