//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Stock {
    char name[50];
    float current_price;
    float purchase_price;
    float change_percentage;
    struct Stock *next;
} Stock;

Stock *head = NULL;

void display_stocks(void) {
    printf("\nCurrent Stocks:\n");
    Stock *current = head;
    int index = 1;
    while (current != NULL) {
        printf("%d. %s\tCurrent Price: %.2f\tPurchase Price: %.2f\tChange Percentage: %.2f%%\n", index, current->name, current->current_price, current->purchase_price, current->change_percentage);
        index++;
        current = current->next;
    }
}

void add_stock(void) {
    Stock *new_stock = (Stock *)malloc(sizeof(Stock));
    printf("\nEnter Stock Name: ");
    fgets(new_stock->name, sizeof(new_stock->name), stdin);
    new_stock->name[strcspn(new_stock->name, "\n")] = '\0';
    printf("Enter Current Price: ");
    scanf("%f", &new_stock->current_price);
    printf("Enter Purchase Price: ");
    scanf("%f", &new_stock->purchase_price);
    new_stock->change_percentage = ((new_stock->current_price - new_stock->purchase_price) / new_stock->purchase_price) * 100;
    new_stock->next = head;
    head = new_stock;
}

void remove_stock(void) {
    Stock *current = head;
    Stock *previous = NULL;
    int index = 1;
    char name[50];
    printf("\nEnter Stock Name to Remove: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("\nStock '%s' removed successfully.\n", name);
            return;
        }
        previous = current;
        current = current->next;
        index++;
    }
    printf("\nStock '%s' not found.\n", name);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Display Stocks\n2. Add Stock\n3. Remove Stock\n4. Quit\nEnter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_stocks();
                break;
            case 2:
                add_stock();
                break;
            case 3:
                remove_stock();
                break;
            case 4:
                printf("Exiting Program...\n");
                exit(0);
                break;
            default:
                printf("Invalid Choice. Please Try Again.\n");
        }
    }
    return 0;
}