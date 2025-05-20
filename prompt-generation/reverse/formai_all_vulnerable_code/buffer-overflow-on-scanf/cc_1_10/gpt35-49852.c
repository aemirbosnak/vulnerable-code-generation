//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    int table;
    char name[50];
    int orderCount;
    char orderNames[10][50];
    int orderPrices[10];
};

struct Menu {
    char name[50];
    int price;
};

struct Menu menu[] = {
    {"Coffee", 50},
    {"Tea", 30},
    {"Sandwich", 80},
    {"Burger", 100},
    {"Pizza", 150}
};

int getMenuLength() {
    return sizeof(menu)/sizeof(menu[0]);
}

int getMenuIndexByName(char *itemName) {
    for(int i=0; i<getMenuLength(); i++) {
        if(strcmp(itemName, menu[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Customer customers[10];
    int customerCount = 0;

    while(1) {
        printf("\nNew order (y/n)? ");
        char ch;
        scanf(" %c", &ch);
        if(ch != 'y' && ch != 'Y') {
            break;
        }

        printf("\nEnter table number: ");
        scanf("%d", &customers[customerCount].table);

        printf("Enter customer name: ");
        scanf(" %[^\n]%*c", customers[customerCount].name);

        customers[customerCount].orderCount = 0;

        while(1) {
            printf("\nMenu: ");
            for(int i=0; i<getMenuLength(); i++) {
                printf("%s (%d) ", menu[i].name, menu[i].price);
            }

            printf("\nEnter order item name: ");
            char itemName[50];
            scanf(" %[^\n]%*c", itemName);
            int menuIndex = getMenuIndexByName(itemName);
            if(menuIndex == -1) {
                printf("\nInvalid menu item name. Please try again.");
                continue;
            }

            strcpy(customers[customerCount].orderNames[customers[customerCount].orderCount], itemName);
            customers[customerCount].orderPrices[customers[customerCount].orderCount] = menu[menuIndex].price;
            customers[customerCount].orderCount++;

            printf("Add another item (y/n)? ");
            scanf(" %c", &ch);
            if(ch != 'y' && ch != 'Y') {
                break;
            }
        }

        printf("\nOkay, order received for Table %d, Name: %s", customers[customerCount].table, customers[customerCount].name);
        printf("\nOrder Items:");
        for(int i=0; i<customers[customerCount].orderCount; i++) {
            printf("\n%s (%d)", customers[customerCount].orderNames[i], customers[customerCount].orderPrices[i]);
        }

        customerCount++;
    }

    printf("\n\nBilling Details: \n");
    for(int i=0; i<customerCount; i++) {
        printf("\nTable: %d, Name: %s", customers[i].table, customers[i].name);
        int total = 0;
        for(int j=0; j<customers[i].orderCount; j++) {
            total += customers[i].orderPrices[j];
        }
        printf("\nTotal Cost: %d\n", total);
    }

    return 0;
}