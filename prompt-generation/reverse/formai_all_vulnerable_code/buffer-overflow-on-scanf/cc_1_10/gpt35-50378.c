//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: real-life
#include <stdio.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

void addMedicine(struct medicine *med, int *count) {
    printf("Enter medicine name: ");
    scanf("%s", med[*count].name);
    printf("Enter quantity: ");
    scanf("%d", &med[*count].quantity);
    printf("Enter price: ");
    scanf("%f", &med[*count].price);
    *count += 1;
}

void updateMedicine(struct medicine *med, int count) {
    char name[50];
    printf("Enter name of medicine to update: ");
    scanf("%s", name);
    for(int i=0; i<count; i++) {
        if(strcmp(med[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &med[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &med[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void sellMedicine(struct medicine *med, int count) {
    char name[50];
    printf("Enter name of medicine to sell: ");
    scanf("%s", name);
    for(int i=0; i<count; i++) {
        if(strcmp(med[i].name, name) == 0) {
            printf("Enter quantity to sell: ");
            int sellQuantity;
            scanf("%d", &sellQuantity);
            if(sellQuantity > med[i].quantity) {
                printf("Insufficient quantity!\n");
                return;
            }
            med[i].quantity -= sellQuantity;
            printf("Total cost: %.2f\n", sellQuantity * med[i].price);
            printf("Medicine sold successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void displayMedicines(struct medicine* med, int count) {
    printf("%-20s%-10s%s\n", "Name", "Quantity", "Price");
    for(int i=0; i<count; i++) {
        printf("%-20s%-10d%.2f\n", med[i].name, med[i].quantity, med[i].price);
    }
}

int main() {
    struct medicine meds[50];
    int count = 0;
    while(1) {
        printf("\nEnter 1 to add medicine, 2 to update medicine, 3 to sell medicine, 4 to display medicines or 5 to exit: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1: addMedicine(meds, &count); break;
            case 2: updateMedicine(meds, count); break;
            case 3: sellMedicine(meds, count); break;
            case 4: displayMedicines(meds, count); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}