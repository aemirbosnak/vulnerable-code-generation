//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item{
    char name[50];
    int quantity;
    float price;
};

int main(){
    int choice, i=0, num_items=0;
    float subtotal=0, total=0, tax, tip, grand_total;
    struct item items[10];

    printf("\n===== Cafe Billing System =====\n\n");

    while(1){
        printf("Enter 1 to add an item\n");
        printf("Enter 2 to generate bill\n");
        printf("Enter 3 to exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1){
            printf("\nEnter item name: ");
            scanf("%s", items[i].name);

            printf("Enter item quantity: ");
            scanf("%d", &items[i].quantity);

            printf("Enter item price: ");
            scanf("%f", &items[i].price);

            printf("\nItem added successfully!\n\n");

            subtotal += (items[i].quantity * items[i].price);

            i++;
            num_items++;
        }

        else if(choice == 2){
            if(num_items == 0){
                printf("\nNo items added to the bill yet!\n\n");
            }
            else{
                tax = 0.05 * subtotal;
                printf("\nEnter tip percentage: ");
                scanf("%f", &tip);

                total = subtotal + tax + (tip/100) * subtotal;

                printf("\n===== BILL =====\n\n");

                for(int j=0; j<num_items; j++){
                    printf("%d. %s - Quantity: %d, Price: $%0.2f\n", j+1, items[j].name, items[j].quantity, items[j].price);
                }

                printf("\nSubtotal: $%0.2f\n", subtotal);
                printf("Tax (5%%): $%0.2f\n", tax);
                printf("Tip: $%0.2f\n", (tip/100)*subtotal);
                printf("Total: $%0.2f\n\n", total);

                break;
            }
        }

        else if(choice == 3){
            exit(0);
        }

        else{
            printf("\nInvalid choice, try again.\n\n");
        }
    }

    return 0;
}