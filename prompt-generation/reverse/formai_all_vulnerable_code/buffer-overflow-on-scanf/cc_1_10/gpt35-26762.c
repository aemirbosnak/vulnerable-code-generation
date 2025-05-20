//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stock {
   char med_name[30];
   int med_id;
   float med_price;
   int med_quantity;
}med[50];

int n;

void add_med()
{
    printf("Enter Medicine name, ID, Price and Quantity separated by commas: \n");
    scanf("%s %d %f %d", med[n].med_name, &med[n].med_id, &med[n].med_price, &med[n].med_quantity);
    n++;
    printf("Medicine added successfully!\n");
}

void search_med()
{
    int id, i;
    printf("Enter Medicine ID to search: ");
    scanf("%d", &id);
    for (i=0; i<n; i++) 
    {
        if (med[i].med_id == id) 
        {
            printf("Medicine Found!\nName: %s\nID: %d\nPrice: %.2f\nQuantity: %d\n", med[i].med_name, med[i].med_id, med[i].med_price, med[i].med_quantity);
            return;
        }
    }
    printf("Sorry, Medicine not found...\n");
}

void update_med()
{
    int id, qty, i;
    printf("Enter Medicine ID to update quantity: ");
    scanf("%d", &id);
    for (i=0; i<n; i++) 
    {
        if (med[i].med_id == id) 
        {
            printf("Enter new Quantity: ");
            scanf("%d", &qty);
            med[i].med_quantity = qty;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Sorry, Medicine not found...\n");
}

void display_med()
{
    int i;
    printf("Name\t\tID\tPrice\tQuantity\n");
    for (i=0; i<n; i++) 
    {
        printf("%s\t\t%d\t%.2f\t%d\n", med[i].med_name, med[i].med_id, med[i].med_price, med[i].med_quantity);
    }
}

int main()
{
    int choice;
    n = 0; //initialize number of medicines as 0
    do {
        printf("\n\n----- Medical Store Management System Menu -----\n");
        printf("1. Add Medicine\n2. Search Medicine\n3. Update Quantity\n4. Display Inventory\n0. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 0:
                printf("Thank you for using the Medical Store Management System!\n");
                break;
            case 1:
                add_med();
                break;
            case 2:
                search_med();
                break;
            case 3:
                update_med();
                break;
            case 4:
                display_med();
                break;
            default: //wrong choice
                printf("Invalid choice! Try again...\n");
        }
    } while(choice != 0);
    
    return 0;
}