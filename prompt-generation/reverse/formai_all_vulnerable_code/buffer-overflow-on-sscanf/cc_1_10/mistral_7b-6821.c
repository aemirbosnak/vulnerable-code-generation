//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    float price;
    int quantity;
} MenuItem;

typedef struct {
    char customerName[50];
    MenuItem items[10];
    int numItems;
    float total;
} Bill;

void printMenu() {
    printf("-----------------------------------------\n");
    printf("| Welcome to C Cafe Billing System!       |\n");
    printf("|----------------------------------------|\n");
    printf("| 1. Sandwich                            |\n");
    printf("| 2. Burger                              |\n");
    printf("| 3. Pizza                               |\n");
    printf("| 4. Drinks                              |\n");
    printf("| 5. Exit                                |\n");
    printf("-----------------------------------------\n");
}

void addItemToBill(Bill *bill, MenuItem item) {
    bill->items[bill->numItems] = item;
    bill->numItems++;
    bill->total += item.price * item.quantity;
}

MenuItem parseMenuItem(char *line) {
    MenuItem menuItem;
    sscanf(line, "%s %f %d", menuItem.name, &menuItem.price, &menuItem.quantity);
    return menuItem;
}

int main() {
    Bill bill = {""};
    printMenu();
    char line[100];

    while (1) {
        fgets(line, sizeof(line), stdin);
        line[strlen(line) - 1] = '\0'; // remove newline character

        if (strcmp(line, "5") == 0) {
            break;
        }

        MenuItem menuItem = parseMenuItem(line);
        addItemToBill(&bill, menuItem);
    }

    printf("Customer Name: %s\n", bill.customerName);
    printf("-----------------------------------------\n");
    printf("| Bill Details                          |\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < bill.numItems; i++) {
        printf("| %-20s | %5.2f | %5d |\n", bill.items[i].name, bill.items[i].price, bill.items[i].quantity);
    }
    printf("-----------------------------------------\n");
    printf("| Total: %5.2f                          |\n", bill.total);
    printf("-----------------------------------------\n");

    return 0;
}