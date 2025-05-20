//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

void add_medicine(struct medicine *medicines, int *num_medicines) {
    printf("Enter the medicine name: ");
    scanf("%s", medicines[*num_medicines].name);
    printf("Enter the medicine quantity: ");
    scanf("%d", &medicines[*num_medicines].quantity);
    printf("Enter the medicine price: ");
    scanf("%f", &medicines[*num_medicines].price);
    (*num_medicines)++;
    printf("Medicine added successfully!\n");
}

void search_medicine(struct medicine *medicines, int num_medicines, char *name) {
    int i;
    for(i = 0; i < num_medicines; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            printf("Medicine found!\n");
            printf("Name: %s\nQuantity: %d\nPrice: %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void sell_medicine(struct medicine *medicines, int num_medicines, char *name, int quantity) {
    int i;
    for(i = 0; i < num_medicines; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            if(medicines[i].quantity >= quantity) {
                medicines[i].quantity -= quantity;
                printf("Medicine sold successfully!\n");
            } else {
                printf("Insufficient medicine quantity!\n");
            }
            return;
        }
    }
    printf("Medicine not found!\n");
}

void display_medicines(struct medicine *medicines, int num_medicines) {
    int i;
    for(i = 0; i < num_medicines; i++) {
        printf("Medicine %d:\n", i+1);
        printf("Name: %s\nQuantity: %d\nPrice: %.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

int main() {
    struct medicine medicines[100];
    int num_medicines = 0;
    while(1) {
        printf("\n********** Medical Store Management System **********\n");
        printf("1. Add Medicine\n2. Search Medicine\n3. Sell Medicine\n4. Display Medicines\n5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_medicine(medicines, &num_medicines);
                break;
            case 2:
                printf("Enter the medicine name: ");
                char name[50];
                scanf("%s", name);
                search_medicine(medicines, num_medicines, name);
                break;
            case 3:
                printf("Enter the medicine name: ");
                char sell_name[50];
                scanf("%s", sell_name);
                printf("Enter the medicine quantity: ");
                int quantity;
                scanf("%d", &quantity);
                sell_medicine(medicines, num_medicines, sell_name, quantity);
                break;
            case 4:
                display_medicines(medicines, num_medicines);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}