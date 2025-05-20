//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

int calculateTotal(int quantity[], int price[], int count){
    int sum = 0;
    int i;
    for(i = 0; i < count; i++){
        sum += quantity[i] * price[i];
    }
    return sum;
}

int main(){

    int quantity[10];
    int price[10];
    char name[10][20];
    int count = 0;

    while(1){
        printf("Enter item %d: ( 0 to end entry)\n", count+1);
        scanf("%s", name[count]);
        if(name[count][0] == '0'){
            break;
        }
        printf("Enter price: \n");
        scanf("%d", &price[count]);
        printf("Enter quantity: \n");
        scanf("%d", &quantity[count]);
        count++;
    }

    printf("\n\n");
    printf("-------------------------------------------------------\n");
    printf("                         BILLING SYSTEM                 \n");
    printf("-------------------------------------------------------\n");
    printf("Item Name              Quantity                Price   \n");
    printf("-------------------------------------------------------\n");

    int i;

    for(i = 0; i < count; i++){
        printf("%-20s %-20d %-20d\n", name[i], quantity[i], price[i]);
    }

    printf("-------------------------------------------------------\n");
    printf("Total                                             %d\n", calculateTotal(quantity, price, count));
    printf("-------------------------------------------------------\n");

    return 0;
}