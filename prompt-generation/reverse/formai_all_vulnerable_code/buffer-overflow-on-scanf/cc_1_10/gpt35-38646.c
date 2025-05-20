//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: curious
#include<stdio.h>
#include<stdlib.h>

int main(){
    char menu[3][20] = {
        "Coffee", "Tea", "Sandwich"
    };
    int price[3] = {40, 30, 50};
    int quantity[3] = {0, 0, 0};

    printf("Welcome to the C Cafe!\n");

    while(1){
        printf("\nMENU\n");
        printf("-------\n");
        for(int i = 0; i < 3; i++){
            printf("%d. %s - Rs.%d\n", i+1, menu[i], price[i]);
        }
        printf("\n");
        printf("Enter your choice(1-3): ");
        int choice;
        scanf("%d", &choice);
        if(choice < 1 || choice > 3){
            printf("Invalid choice!\n");
            continue;
        }
        printf("Enter quantity: ");
        int qty;
        scanf("%d", &qty);
        if(qty < 0){
            printf("Invalid quantity!\n");
            continue;
        }

        quantity[choice-1] += qty;

        printf("\nAdded %d %s to your order.\n", qty, menu[choice-1]);

        printf("Do you want to add more items?(y/n): ");
        char ch;
        scanf(" %c", &ch);
        if(!(ch == 'y' || ch == 'Y')){
            break;
        }
    }

    printf("\nORDER SUMMARY\n");
    printf("---------------\n");
    int total = 0;
    for(int i = 0; i < 3; i++){
        if(quantity[i] > 0){
            printf("%s x %d - Rs.%d\n", menu[i], quantity[i], price[i]*quantity[i]);
            total += price[i] * quantity[i];
        }
    }
    printf("\nTOTAL: Rs.%d", total);
    printf("\n---------------\n");
    printf("\nThank you for visiting the C Cafe. Have a nice day!\n");

    return 0;
}