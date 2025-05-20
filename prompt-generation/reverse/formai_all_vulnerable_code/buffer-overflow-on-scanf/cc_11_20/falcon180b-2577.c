//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_AMOUNT 1000

struct item {
    char name[100];
    char category[50];
    double amount;
};

int main() {
    char choice;
    int num_categories = 0, num_items = 0;
    struct item categories[MAX_CATEGORIES], items[MAX_ITEMS];
    double total_expense = 0.0;

    do {
        system("clear");
        printf("Expense Tracker\n");
        printf("Enter 1 to add a category\n");
        printf("Enter 2 to add an item\n");
        printf("Enter 3 to view categories\n");
        printf("Enter 4 to view items\n");
        printf("Enter 5 to view total expense\n");
        printf("Enter 6 to exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(num_categories >= MAX_CATEGORIES) {
                    printf("Maximum categories reached\n");
                } else {
                    printf("Enter category name: ");
                    scanf("%s", categories[num_categories].category);
                    num_categories++;
                }
                break;

            case '2':
                if(num_items >= MAX_ITEMS) {
                    printf("Maximum items reached\n");
                } else {
                    printf("Enter item name: ");
                    scanf("%s", items[num_items].name);
                    printf("Enter category: ");
                    scanf("%s", items[num_items].category);
                    printf("Enter amount: ");
                    scanf("%lf", &items[num_items].amount);
                    num_items++;
                }
                break;

            case '3':
                printf("Categories:\n");
                for(int i=0; i<num_categories; i++) {
                    printf("%s\n", categories[i].category);
                }
                break;

            case '4':
                printf("Items:\n");
                for(int i=0; i<num_items; i++) {
                    printf("%s - %s - $%lf\n", items[i].name, items[i].category, items[i].amount);
                }
                break;

            case '5':
                for(int i=0; i<num_items; i++) {
                    total_expense += items[i].amount;
                }
                printf("Total expense: $%lf\n", total_expense);
                break;

            case '6':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while(choice!= '6');

    return 0;
}