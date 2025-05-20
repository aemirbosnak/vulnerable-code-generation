//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

int calculateBill(int count){
    int choice, quantity, item_price, item_count, item_total, total = 0;

    printf("\nEnter the item choice (1-5, 0 to exit): ");
    scanf("%d", &choice);

    switch(choice){
        case 0:
            return total;
        case 1:
            item_price = 50;
            break;
        case 2:
            item_price = 75;
            break;
        case 3:
            item_price = 60;
            break;
        case 4:
            item_price = 110;
            break;
        case 5:
            item_price = 90;
            break;
        default:
            printf("\nInvalid Choice!");
            break;
    }

    if(choice != 0){
        printf("\nEnter the quantity: ");
        scanf("%d", &quantity);

        item_total = item_price * quantity;

        printf("\nCost of one item is: %d", item_price);
        printf("\nTotal Cost of item %d: %d", choice, item_total);

        total += item_total;
        count++;

        printf("\nDo you want to add more items? 1 for Yes and 2 for No: ");
        scanf("%d", &item_count);

        if(item_count == 1){
            calculateBill(count);
        }
        else if(item_count == 2){
            printf("\nTotal number of items purchased: %d", count);
            printf("\nTotal Amount: %d", total);
            return total;
        }
        else{
            printf("\nInvalid Choice!");
            return calculateBill(count);
        }
    }

    return total;
}

int main(){
    int total = calculateBill(0);

    printf("\nThe final amount to be paid is: %d", total);
    return 0;
}