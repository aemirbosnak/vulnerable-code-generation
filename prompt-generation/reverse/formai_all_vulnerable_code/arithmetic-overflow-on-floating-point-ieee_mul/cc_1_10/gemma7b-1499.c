//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generateBill()
{
    char name[20];
    char address[50];
    char phoneNumber[20];
    int itemNo;
    char itemName[20];
    int quantity;
    float price;
    float totalAmount = 0.0f;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your address: ");
    scanf("%s", address);

    printf("Enter your phone number: ");
    scanf("%s", phoneNumber);

    printf("Enter the item number: ");
    scanf("%d", &itemNo);

    printf("Enter the item name: ");
    scanf("%s", itemName);

    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    printf("Enter the price: ");
    scanf("%f", &price);

    totalAmount = quantity * price;

    printf("---------------------------------------------------\n");
    printf("Name: %s\n", name);
    printf("Address: %s\n", address);
    printf("Phone Number: %s\n", phoneNumber);
    printf("Item No: %d\n", itemNo);
    printf("Item Name: %s\n", itemName);
    printf("Quantity: %d\n", quantity);
    printf("Price: %.2f\n", price);
    printf("Total Amount: %.2f\n", totalAmount);
    printf("---------------------------------------------------\n");

    FILE *fp = fopen("bill.txt", "w");
    fprintf(fp, "---------------------------------------------------\n");
    fprintf(fp, "Name: %s\n", name);
    fprintf(fp, "Address: %s\n", address);
    fprintf(fp, "Phone Number: %s\n", phoneNumber);
    fprintf(fp, "Item No: %d\n", itemNo);
    fprintf(fp, "Item Name: %s\n", itemName);
    fprintf(fp, "Quantity: %d\n", quantity);
    fprintf(fp, "Price: %.2f\n", price);
    fprintf(fp, "Total Amount: %.2f\n", totalAmount);
    fprintf(fp, "---------------------------------------------------\n");

    fclose(fp);
}

int main()
{
    generateBill();

    return 0;
}