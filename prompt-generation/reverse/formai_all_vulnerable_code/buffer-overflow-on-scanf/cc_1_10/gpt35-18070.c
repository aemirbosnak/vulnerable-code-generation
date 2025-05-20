//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char item_name[100];
    float item_price;
    int quantity;
    float sub_total;
};

void header()
{
    printf("*** C CAFE BILLING SYSTEM ***\n");
    printf("--------------------------------\n\n");
}

float calculate_subtotal(int quantity, float item_price)
{
    float sub_total;
    sub_total = quantity * item_price;
    return sub_total;
}

void print_bill(struct node item[], int n, float total)
{
    int i;
    printf("\n\n---------------------------------");
    printf("\n     CAFE BILLING SYSTEM        \n");
    printf("---------------------------------\n");
    printf("S.No\tITEM\t\tPRICE\tQUANTITY\tSUB TOTAL\n");
    for(i = 0;i < n;i++)
    {
        printf("%d\t%s\t  %.2f\t\t%d\t\t%.2f\n", i+1, item[i].item_name, item[i].item_price, item[i].quantity, item[i].sub_total);
    }
    printf("\nTOTAL BILL AMOUNT: Rs. %.2f", total);
}

int main()
{
    int i,n;
    float total = 0.0;
    struct node item[50];
    char ans;
    header();
    do
    {
        printf("Enter number of items: ");
        scanf("%d", &n);
        for(i = 0;i < n;i++)
        {
            printf("\nEnter item name: ");
            scanf("%s", &item[i].item_name);
            printf("Enter item price: Rs. ");
            scanf("%f", &item[i].item_price);
            printf("Enter quantity: ");
            scanf("%d", &item[i].quantity);
            item[i].sub_total = calculate_subtotal(item[i].quantity, item[i].item_price);
            total += item[i].sub_total;
        }
        print_bill(item, n, total);
        printf("\n\nDo you want to continue? (y/n): ");
        scanf(" %c", &ans);
    }while(ans == 'y' || ans == 'Y');
    printf("\n______________________\n");
    printf("| HAPPY SHOPPING!!! |");
    printf("\n______________________\n");
    return 0;
}