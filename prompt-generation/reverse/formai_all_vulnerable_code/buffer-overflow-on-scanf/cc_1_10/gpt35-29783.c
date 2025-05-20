//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
};

void displayMedicine(struct Medicine med);
void addMedicine(struct Medicine *medicines, int *count);
void sellMedicine(struct Medicine *medicines, int count);

int main()
{
    struct Medicine medicines[100];
    int count = 0;
    int choice;

    printf("Welcome to the Medical Store Management System\n");

    while(1) {
        printf("\n1.Add Medicine\n2.Sell Medicine\n3.View Medicine\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                sellMedicine(medicines, count);
                break;
            case 3:
                printf("\n-----------------------------------\n");
                printf("Name\tManufacturer\tQuantity\tPrice\n");
                printf("-----------------------------------\n");
                for(int i=0; i<count; i++) {
                    displayMedicine(medicines[i]);
                }
                break;
            case 4:
                printf("\nThank you for using the Medical Store Management System\n");
                exit(0);
            default:
                printf("\nInvalid choice, please retry...\n");
                break;
        }
    }

    return 0;
}

void displayMedicine(struct Medicine med) {
    printf("%s\t%s\t\t%d\t\t%.2f\n", med.name, med.manufacturer, med.quantity, med.price);
}

void addMedicine(struct Medicine *medicines, int *count) {
    printf("\nEnter the medicine name: ");
    scanf("%s", medicines[*count].name);
    printf("Enter the manufacturer name: ");
    scanf("%s", medicines[*count].manufacturer);
    printf("Enter the quantity: ");
    scanf("%d", &medicines[*count].quantity);
    printf("Enter the price: ");
    scanf("%f", &medicines[*count].price);

    (*count)++;
}

void sellMedicine(struct Medicine *medicines, int count) {
    char name[50];
    int quantity;

    printf("\nEnter the medicine name to sell: ");
    scanf("%s", name);

    for(int i=0; i<count; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            printf("Enter the quantity to sell: ");
            scanf("%d", &quantity);

            if(medicines[i].quantity >= quantity) {
                medicines[i].quantity -= quantity;
                printf("Medicine sold!\n");
                return;
            } else {
                printf("Insufficient quantity, available: %d\n", medicines[i].quantity);
                return;
            }
        }
    }

    printf("Medicine not found!\n");
}