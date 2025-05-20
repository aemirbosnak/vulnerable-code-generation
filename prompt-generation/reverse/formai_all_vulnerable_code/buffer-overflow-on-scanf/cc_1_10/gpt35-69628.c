//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

float total = 0;

void menu() {
    printf("Menu:\n");
    printf("1. Espresso     - $2.50\n");
    printf("2. Latte        - $3.00\n");
    printf("3. Cappuccino   - $3.25\n");
    printf("4. Mocha        - $3.50\n");
    printf("5. Frappuccino  - $4.00\n\n");
    printf("Enter your choice (1-5):");
}

float bill(float amount, float price) {
    total += price * amount;
    return price * amount;
}

int main() {
    int choice, amount;
    char ans;
    printf("Welcome to Cafe Billing System!\n");
    do {
        menu();
        scanf("%d", &choice);
        while(choice < 1 || choice > 5) {
            printf("Invalid choice! Please choose a number between 1 and 5:");
            scanf("%d", &choice);
        }
        printf("Enter the amount of drinks you want to purchase:");
        scanf("%d", &amount);
        while(amount < 1) {
            printf("Invalid amount! Please enter a positive integer:");
            scanf("%d", &amount);
        }
        switch(choice) {
            case 1:
                printf("You have ordered %d Espresso(s).\n", amount);
                printf("Total amount due: $%.2f\n", bill(amount, 2.50));
                break;
            case 2:
                printf("You have ordered %d Latte(s).\n", amount);
                printf("Total amount due: $%.2f\n", bill(amount, 3.00));
                break;
            case 3:
                printf("You have ordered %d Cappuccino(s).\n", amount);
                printf("Total amount due: $%.2f\n", bill(amount, 3.25));
                break;
            case 4:
                printf("You have ordered %d Mocha(s).\n", amount);
                printf("Total amount due: $%.2f\n", bill(amount, 3.50));
                break;
            case 5:
                printf("You have ordered %d Frappuccino(s).\n", amount);
                printf("Total amount due: $%.2f\n", bill(amount, 4.00));
                break;
            default:
                break;
        }
        printf("Do you want to order again? (y/n):");
        scanf("%s", &ans);
        while(tolower(ans) != 'y' && tolower(ans) != 'n') {
            printf("Invalid response! Please enter either 'y' or 'n':");
            scanf("%s", &ans);
        }
    } while(tolower(ans) != 'n');
    printf("Thank you for using Cafe Billing System!\n");
    printf("Total amount due: $%.2f\n", total);
    return 0;
}