//FormAI DATASET v1.0 Category: Expense Tracker ; Style: secure
#include<stdio.h>
#include<string.h>
#define MAX_ENTRIES 50
#define PASSWORD "1234"   // replace with your own secure password

struct Expense {
    char category[20];
    float amount;
};

int main() {
    int num_entries = 0, option, pin_attempts = 3, i;
    float total_spent = 0;
    char pin[10];
    struct Expense expenses[MAX_ENTRIES];

    // ask for pin
    printf("Enter password to access expense tracker: ");
    scanf("%s", pin);

    // validate pin
    while (pin_attempts > 0 && strcmp(pin, PASSWORD) != 0) {
        printf("Incorrect password. %d attempts remaining. Enter password: ", pin_attempts);
        scanf("%s", pin);
        pin_attempts--;
    }

    if (strcmp(pin, PASSWORD) != 0) {
        printf("Access denied. Too many failed attempts.");
        return 0;
    }

    // menu
    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add new expense\n");
        printf("2. View recent expenses\n");
        printf("3. View total spent\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (num_entries == MAX_ENTRIES) {
                    printf("Error: Maximum number of entries reached. Delete old entries before adding new ones.");
                } else {
                    printf("\nEnter expense category: ");
                    scanf("%s", expenses[num_entries].category);
                    printf("Enter expense amount: ");
                    scanf("%f", &expenses[num_entries].amount);
                    total_spent += expenses[num_entries].amount;
                    num_entries++;
                    printf("\nExpense added successfully!\n");
                }
                break;
            case 2:
                printf("\nRecent Expenses:\n");
                for (i = num_entries - 1; i >= 0 && i >= num_entries - 5; i--) {
                    printf("%s: $%.2f\n", expenses[i].category, expenses[i].amount);
                }
                break;
            case 3:
                printf("\nTotal spent: $%.2f\n", total_spent);
                break;
            case 4:
                printf("\nHave a nice day!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while (option != 4);

    return 0;
}