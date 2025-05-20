//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct order{
    char name[20];
    int qty;
    float price;
};

void generateBill(struct order*, int);

int main(){
    int n, i;
    struct order *oList;

    printf("Enter the number of items in the order: ");
    scanf("%d", &n);

    oList = (struct order*)malloc(n*sizeof(struct order));

    for(i = 0; i<n; i++){
        printf("\nEnter the name of the item #%d: ", i+1);
        getchar();
        fgets(oList[i].name, 20, stdin);

        printf("Enter the quantity of item #%d: ", i+1);
        scanf("%d", &oList[i].qty);

        printf("Enter the price of item #%d: ", i+1);
        scanf("%f", &oList[i].price);
    }

    generateBill(oList, n);

    free(oList);
    return 0;
}

void generateBill(struct order *list, int n){
    float total = 0;
    int i;

    printf("\n\n*************** CAFE BILLING SYSTEM **********************\n");
    printf("-----------------------------------------------------------\n");
    printf("S.No \t Item \t\t Quantity \t Price \t Total\n");
    printf("-----------------------------------------------------------\n");

    for(i = 0; i<n; i++){
        printf("%d \t %s \t %d \t\t %.2f \t %.2f\n", i+1, list[i].name, list[i].qty, list[i].price, list[i].qty*list[i].price);
        total = total + list[i].qty*list[i].price;
    }

    printf("\n-----------------------------------------------------------\n");
    printf("\t\t\t\t Grand Total: %.2f", total);
    printf("\n-----------------------------------------------------------\n");
}