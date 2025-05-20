//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cafe {
    char item[20];
    int quantity;
    double price;
};

void clear_screen() {
    system("clear||cls");
}

void add_to_bill(struct cafe *bill, int *num_items){
    printf("Enter the item name (max 20 characters): ");
    scanf("%s", bill[*num_items].item);
    printf("Enter the quantity: ");
    scanf("%d", &bill[*num_items].quantity);
    printf("Enter the price: ");
    scanf("%lf", &bill[*num_items].price);
    (*num_items)++;
}

void print_bill(struct cafe *bill, int num_items){
    printf("Item\tQuantity\tPrice\n");
    double total = 0;
    for(int i=0; i<num_items; i++) {
        printf("%s\t%d\t\t%.2lf\n", bill[i].item, bill[i].quantity, bill[i].price);
        total += bill[i].price * bill[i].quantity;
    }
    printf("\nTotal: %.2lf\n", total);
}

int main() {
    int choice;
    int num_items = 0;
    struct cafe bill[100]; // maximum of 100 items in a bill

    while(1){
        clear_screen();
        printf("\tC CAFE\n");
        printf("1. Add item to bill\n");
        printf("2. Print bill\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_to_bill(bill, &num_items);
                    break;
            case 2: print_bill(bill, num_items);
                    break;
            case 3: printf("Thank you for visiting C CAFE!\n");
                    exit(0);
            default: printf("Invalid choice!\n");
        }
        printf("Press any key to continue...");
        getchar();
        getchar();
    }
    return 0;
}