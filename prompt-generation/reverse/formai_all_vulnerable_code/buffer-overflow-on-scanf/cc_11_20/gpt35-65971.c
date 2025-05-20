//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

/* defining a structure for the items to be stored in the warehouse */
struct item {
    int id; /* unique identifier for the item */
    char name[50]; /* name of the item */
    float price; /* price of the item */
    int quantity; /* quantity of the item available */
}items[100];

int main()
{
    int choice, n=0, id, index, qty;
    char ch;

    /* menu-driven program */
    do {
        printf("\nWarehouse Management System Menu:\n");
        printf("\n1. Add item\n2. Display all items\n3. Search for an item\n4. Update item quantity\n5. Delete an item\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: /* adding an item */
                printf("\nEnter item details:\n");
                printf("ID: ");
                scanf("%d", &items[n].id);
                printf("Name: ");
                scanf("%s", items[n].name);
                printf("Price: ");
                scanf("%f", &items[n].price);
                printf("Quantity: ");
                scanf("%d", &items[n].quantity);
                n++;
                break;

            case 2: /* displaying all items */
                printf("\nID\tName\tPrice\tQuantity\n");
                for(int i=0; i<n; i++) {
                    printf("%d\t%s\t%.2f\t%d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);
                }
                break;

            case 3: /* searching for an item */
                printf("\nEnter item ID: ");
                scanf("%d", &id);
                for(int i=0; i<n; i++) {
                    if(items[i].id == id) {
                        printf("\nID\tName\tPrice\tQuantity\n");
                        printf("%d\t%s\t%.2f\t%d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);
                        break;
                    }
                }
                break;

            case 4: /* updating item quantity */
                printf("\nEnter item ID: ");
                scanf("%d", &id);
                for(int i=0; i<n; i++) {
                    if(items[i].id == id) {
                        printf("\nID\tName\tPrice\tQuantity\n");
                        printf("%d\t%s\t%.2f\t%d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);
                        printf("\nEnter new quantity: ");
                        scanf("%d", &qty);
                        items[i].quantity = qty;
                        printf("\nItem quantity updated.\n");
                        break;
                    }
                }
                break;

            case 5: /* deleting an item */
                printf("\nEnter item ID: ");
                scanf("%d", &id);
                for(int i=0; i<n; i++) {
                    if(items[i].id == id) {
                        index = i;
                        break;
                    }
                }
                for(int i=index; i<n-1; i++) {
                    items[i] = items[i+1];
                }
                printf("\nItem deleted.\n");
                n--;
                break;

            case 6: /* exit */
                exit(0);

            default: /* invalid choice */
                printf("\nInvalid choice.\n");
        }

        printf("\nDo you want to continue (Y/N)? ");
        scanf("%s", &ch);

    } while(ch == 'y' || ch == 'Y');

    return 0;
}