//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    time_t date;
} item;

void add_item(item *items, int count) {
    printf("Enter item name: ");
    scanf("%s", items[count].name);
    printf("Enter item price: ");
    scanf("%f", &items[count].price);
    printf("Enter item date (YYYY-MM-DD): ");
    scanf("%s", items[count].date);
    items[count].date = mktime(items[count].date);
}

void display_items(item *items, int count) {
    printf("\nExpense Tracker\n");
    printf("=====================\n");
    printf("Item Name\tPrice\tDate\n");
    for(int i=0; i<count; i++) {
        printf("%s\t%.2f\t%s\n", items[i].name, items[i].price, ctime(&items[i].date));
    }
}

int main() {
    item items[MAX_ITEMS];
    int count = 0;
    char choice;
    do {
        printf("\nWelcome to Expense Tracker!\n");
        printf("===========================\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                if(count < MAX_ITEMS) {
                    add_item(items, count);
                    count++;
                } else {
                    printf("Expense limit reached!\n");
                }
                break;
            case '2':
                if(count > 0) {
                    display_items(items, count);
                } else {
                    printf("No expenses added yet!\n");
                }
                break;
            case '3':
                printf("Thank you for using Expense Tracker!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= '3');
    return 0;
}