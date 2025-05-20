//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>

int main(){
    float salary, rent, groceries, utilities;
    float savings, expenses, balance;
    int choice;

    printf("WELCOME TO PERSONAL FINANCE PLANNER\n");

    printf("Enter your monthly salary: ");
    scanf("%f", &salary);

    printf("Enter your monthly rent: ");
    scanf("%f", &rent);

    printf("Enter your monthly groceries expense: ");
    scanf("%f", &groceries);

    printf("Enter your monthly utilities expense: ");
    scanf("%f", &utilities);

    expenses = rent + groceries + utilities;
    savings = salary - expenses;
    balance = salary - expenses;

    printf("Choose an option: \n");
    printf("1-Add an expense\n");
    printf("2-View your expenses\n");
    printf("3-View your savings\n");
    printf("4-View your balance\n");
    printf("5-Exit\n");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the amount: ");
                float amount;
                scanf("%f", &amount);
                printf("\nWhat type of expense is this? (1 - Rent, 2 - Groceries, 3 - Utilities)");
                int exp_choice;
                scanf("%d", &exp_choice);

                switch(exp_choice){
                    case 1:
                        rent += amount;
                        printf("\nRent expense updated!\n");
                        break;
                    case 2:
                        groceries += amount;
                        printf("\nGroceries expense updated!\n");
                        break;
                    case 3:
                        utilities += amount;
                        printf("\nUtilities expense updated!\n");
                        break;
                    default:
                        printf("\nInvalid option!\n");
                        break;
                }

                expenses = rent + groceries + utilities;
                balance = salary - expenses;
                savings = salary - expenses;
                break;

            case 2:
                printf("\nYour current expenses:\n");
                printf("Rent: %.2f\nGroceries: %.2f\nUtilities: %.2f\n", rent, groceries, utilities);
                break;

            case 3:
                printf("\nYour current savings: %.2f\n", savings);
                break;

            case 4:
                printf("\nYour current balance: %.2f\n", balance);
                break;

            case 5:
                printf("\nTHANK YOU FOR USING PERSONAL FINANCE PLANNER!\n");
                return 0;

            default:
                printf("\nInvalid option!\n");
                break;
        }
    }
}