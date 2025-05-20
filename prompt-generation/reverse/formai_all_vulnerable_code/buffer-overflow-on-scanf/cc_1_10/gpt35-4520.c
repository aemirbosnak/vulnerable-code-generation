//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    char med_name[20];
    int med_qty;
    float med_price;
} Medicine;

int main() {
    int choice, med_qty;
    float payment;
    Medicine med[10];
    strcpy(med[0].med_name, "Paracetamol");
    med[0].med_qty = 100;
    med[0].med_price = 1.5;

    strcpy(med[1].med_name, "Aspirin");
    med[1].med_qty = 50;
    med[1].med_price = 2.5;

    strcpy(med[2].med_name, "Ibuprofen");
    med[2].med_qty = 75;
    med[2].med_price = 3.0;

    printf("1. Display Medicines\n");
    printf("2. Purchase Medicines\n");
    printf("3. Add new Medicine\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nMedicine Name\tQuantity\tPrice\n");
            for(int i=0; i<3; i++) {
                printf("%s\t\t%d\t\t%.2f\n", med[i].med_name, med[i].med_qty, med[i].med_price);
            }
            break;
        case 2:
            printf("Enter Medicine Name: ");
            char med_name[20];
            scanf("%s", med_name);
            int found = 0;
            for(int i=0; i<3; i++) {
                if(strcmp(med[i].med_name, med_name) == 0) {
                    printf("Enter Quantity: ");
                    scanf("%d", &med_qty);
                    if(med_qty > med[i].med_qty) {
                        printf("Sorry, required quantity is not available.\n");
                        break;
                    }
                    payment = med_qty * med[i].med_price;
                    printf("Total Payment: %.2f\n", payment);
                    med[i].med_qty -= med_qty;
                    found = 1;
                    break;
                }
            }
            if(!found) {
                printf("Sorry, medicine not found.\n");
            }
            break;
        case 3:
            printf("Enter Medicine Name: ");
            char new_med_name[20];
            float new_med_price;
            scanf("%s", new_med_name);
            printf("Enter Quantity: ");
            scanf("%d", &med_qty);
            printf("Enter Price: ");
            scanf("%f", &new_med_price);
            strcpy(med[3].med_name, new_med_name);
            med[3].med_qty = med_qty;
            med[3].med_price = new_med_price;
            printf("\nNew Medicine Added.\n");
            break;
        default:
            printf("Invalid Choice.\n");
            break;
    }

    return 0;
}