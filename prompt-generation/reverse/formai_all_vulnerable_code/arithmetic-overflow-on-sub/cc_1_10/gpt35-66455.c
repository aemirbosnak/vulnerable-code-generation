//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct items{
    char name[25];
    float price;
    int qty;
    float total;
};

typedef struct items ITEM;

int main(){
    ITEM item[20];
    int n,i,option;
    float grand_total = 0;

    printf("\t\t------------ Welcome to Cafe Billing System! ------------\n");
    printf("\nPlease enter the number of items you want to order: ");
    scanf("%d",&n);

    for(i=0; i<n; i++){
        printf("\nEnter details for item %d below:\n", (i+1));
        printf("\nEnter name of item: ");
        getchar();
        fgets(item[i].name, 25, stdin);
        printf("Enter price of item (in INR): ");
        scanf("%f",&item[i].price);
        printf("Enter quantity of item: ");
        scanf("%d",&item[i].qty);
        item[i].total = item[i].price * item[i].qty;
        grand_total += item[i].total;
    }

    printf("\n---------------------------------------------------------\n");
    printf("\n\t\t\t  Cafe Items\n\n");
    printf("---------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s | %-10s |\n", "Name", "Price", "Quantity", "Total");
    printf("---------------------------------------------------------\n");

    for(i=0; i<n; i++){
        printf("| %-20s | %-10.2f | %-10d | %-10.2f |\n", item[i].name, item[i].price, item[i].qty, item[i].total);
    }

    printf("---------------------------------------------------------\n");
    printf("| %-50s | %-10.2f |\n", "Grand Total", grand_total);
    printf("---------------------------------------------------------\n");

    printf("\nDo you want to delete any item from the list? (Press 1 for YES and 2 for NO): ");
    scanf("%d",&option);

    if(option == 1){
        int item_num;
        printf("Enter the item number you want to delete: ");
        scanf("%d",&item_num);

        if(item_num > n){
            printf("Invalid item number. Please try again later.\n");
            exit(0);
        }

        for(i=item_num-1; i<n-1; i++){
            item[i] = item[i+1];
        }

        n--;
        grand_total -= item[item_num-1].total;

        printf("\n---------------------------------------------------------\n");
        printf("\n\t\t\t  Cafe Items\n\n");
        printf("---------------------------------------------------------\n");
        printf("| %-20s | %-10s | %-10s | %-10s |\n", "Name", "Price", "Quantity", "Total");
        printf("---------------------------------------------------------\n");

        for(i=0; i<n; i++){
            printf("| %-20s | %-10.2f | %-10d | %-10.2f |\n", item[i].name, item[i].price, item[i].qty, item[i].total);
        }

        printf("---------------------------------------------------------\n");
        printf("| %-50s | %-10.2f |\n", "Grand Total", grand_total);
        printf("---------------------------------------------------------\n");

    }

    return 0;
}