//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100000
#define MAX_ITEMS 1000

typedef struct {
    char name[MAX_SIZE];
    double price;
} item;

item items[MAX_ITEMS];
int num_items;

int main() {
    char input[MAX_SIZE];
    double total_spent = 0;
    int i;

    printf("Welcome to the Personal Finance Planner!\n");
    printf("This program will help you track your expenses and plan your budget.\n");
    printf("Please enter your name:\n");
    scanf("%s", input);
    strcpy(items[0].name, input);
    num_items = 1;

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Enter an expense\n");
        printf("2. View expenses\n");
        printf("3. Set a budget\n");
        printf("4. View budget\n");
        printf("5. Exit\n");
        scanf("%d", &i);

        switch(i) {
            case 1:
                printf("\nEnter the name of the item:\n");
                scanf("%s", input);
                strcpy(items[num_items].name, input);
                printf("Enter the price of the item:\n");
                scanf("%lf", &items[num_items].price);
                total_spent += items[num_items].price;
                num_items++;
                printf("\nItem added successfully!\n");
                break;
            case 2:
                printf("\nYour expenses:\n");
                for(i = 0; i < num_items; i++) {
                    printf("%s - $%.2lf\n", items[i].name, items[i].price);
                }
                break;
            case 3:
                printf("\nEnter your monthly budget:\n");
                scanf("%lf", &items[num_items].price);
                total_spent = 0;
                num_items++;
                printf("\nBudget set successfully!\n");
                break;
            case 4:
                printf("\nYour budget:\n");
                printf("Monthly budget: $%.2lf\n", items[num_items-1].price);
                printf("Total spent: $%.2lf\n", total_spent);
                break;
            case 5:
                printf("\nThank you for using the Personal Finance Planner!\n");
                return 0;
            default:
                printf("\nInvalid option selected.\n");
        }
    }

    return 0;
}