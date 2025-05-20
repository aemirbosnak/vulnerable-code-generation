//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

struct Item
{
    int itemCode;
    char itemName[50];
    int quantity;
    float price;
};

void addItem(struct Item *ptr, int n)
{
    printf("\n ================================");
    printf("\n ADD ITEMS TO WAREHOUSE INVENTORY");
    printf("\n ================================");
    for(int i=0; i<n; i++)
    {
        printf("\nEnter Item %d Details: \n", i+1);
        printf("Item Code: ");
        scanf("%d", &(ptr+i)->itemCode);
        printf("Item Name: ");
        scanf("%s", &(ptr+i)->itemName);
        printf("Item Quantity: ");
        scanf("%d", &(ptr+i)->quantity);
        printf("Item Price: ");
        scanf("%f", &(ptr+i)->price);
    }
}

void displayItem(struct Item *ptr, int n)
{
    printf("\n ================================");
    printf("\n WAREHOUSE INVENTORY");
    printf("\n ================================");
    printf("\nItem Code\tItem Name\tQuantity\tPrice");
    for(int i=0; i<n; i++)
        printf("\n%d\t\t%s\t\t%d\t\t%.2f", (ptr+i)->itemCode, (ptr+i)->itemName, (ptr+i)->quantity, (ptr+i)->price);
}

void searchItem(struct Item *ptr, int n)
{
    int code, found=0;
    printf("\nEnter Item Code to Search: ");
    scanf("%d", &code);
    for(int i=0; i<n; i++)
    {
        if((ptr+i)->itemCode == code){
            printf("\nItem Found!");
            printf("\nItem Name: %s", (ptr+i)->itemName);
            printf("\nItem Quantity: %d", (ptr+i)->quantity);
            printf("\nItem Price: %.2f", (ptr+i)->price);
            found=1;
            break;
        }
    }
    if(!found)
        printf("\nItem not Found!");
}

void removeItem(struct Item *ptr, int *n)
{
    int code, found=0, index;
    printf("\nEnter Item Code to Remove: ");
    scanf("%d", &code);
    for(int i=0; i<*n; i++)
    {
        if((ptr+i)->itemCode == code){
            found=1;
            index=i;
            break;
        }
    }
    if(found)
    {
        for(int i=index; i<(*n)-1; i++)
            *(ptr+i) = *(ptr+i+1);
        (*n)--;
        printf("\nItem Successfully Removed!");
    }
    else
        printf("\nItem not Found!");
}

int main()
{
    int n, choice;
    printf("Welcome to WMS - Warehouse Management System");
    printf("\nEnter the number of Items to Add: ");
    scanf("%d", &n);
    struct Item *items = (struct Item*) malloc(n * sizeof(struct Item));

    do{
        printf("\n\n===MENU===\n");
        printf("1. Add Items\n");
        printf("2. Display Items\n");
        printf("3. Search Item\n");
        printf("4. Remove Item\n");
        printf("5. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addItem(items, n);
                break;
            case 2:
                displayItem(items, n);
                break;
            case 3:
                searchItem(items, n);
                break;
            case 4:
                removeItem(items, &n);
                break;
            case 5:
                printf("\nThank You! Exiting Program...");
                break;
            default:
                printf("\nInvalid Choice! Try Again...");
        }
    }while(choice!=5);

    return 0;
}