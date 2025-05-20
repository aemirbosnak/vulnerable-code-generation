//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void print_menu();
void calculate_total();

// global variables
int item_count = 0;
char items[50][25];
float prices[50];
float total = 0;

int main() {
    int option;
    do {
        printf("\nWelcome to our cafe. What would you like to do?\n");
        printf("1 - View menu\n");
        printf("2 - Add item\n");
        printf("3 - Calculate total\n");
        printf("4 - Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                print_menu();
                break;
            case 2:
                if(item_count >= 50) {
                    printf("\nSorry, you can only add up to 50 items.\n");
                    break;
                }
                char item_name[25];
                float item_price;
                printf("\nEnter item name: ");
                scanf("%s", item_name);
                printf("Enter item price: ");
                scanf("%f", &item_price);
                strcpy(items[item_count], item_name);
                prices[item_count] = item_price;
                item_count++;
                printf("\nItem added!\n");
                break;
            case 3:
                calculate_total();
                break;
            case 4:
                printf("\nThank you for visiting our cafe!\n");
                break;
            default:
                printf("\nInvalid option, please try again.\n");
        }
    } while(option != 4);

    return 0;
}

void print_menu() {
    printf("\nMenu:\n");
    printf("%-25s%-10s\n", "Item", "Price");
    printf("--------------------------------\n");
    printf("%-25s%-10s\n", "Coffee", "2.50");
    printf("%-25s%-10s\n", "Tea", "2.00");
    printf("%-25s%-10s\n", "Sandwich", "4.00");
    printf("%-25s%-10s\n", "Cake", "3.50");
    printf("%-25s%-10s\n", "Smoothie", "3.00");
}

void calculate_total() {
    printf("\nItems ordered:\n");
    printf("%-25s%-10s\n", "Item", "Price");
    printf("--------------------------------\n");
    for(int i = 0; i < item_count; i++) {
        printf("%-25s%-10.2f\n", items[i], prices[i]);
        total += prices[i];
    }
    printf("--------------------------------\n");
    printf("%-25s%-10.2f\n", "Total", total);
}