//FormAI DATASET v1.0 Category: Expense Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char date[11];
    char item[20];
    double amount;
};

int main() {
    int choice, count = 0, i;
    double total = 0;
    struct Expense expense[100];

    printf("Welcome to Expense Tracker App\n");

    while(1) {
        printf("\n1. Add Expense\n2. View Expense\n3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1 :
                printf("\nEnter Expense details\n");
                printf("Date [DD/MM/YYYY] : ");
                scanf("%s", &expense[count].date);
                printf("Item : ");
                scanf("%s", &expense[count].item);
                printf("Amount : ");
                scanf("%lf", &expense[count].amount);

                total += expense[count].amount;
                count++;
                printf("Expense added successfully!\n");
                break;

            case 2 :
                if(count == 0) {
                    printf("No expenses added yet!\n");
                }
                else {
                    printf("\nExpense List\n");
                    printf("Date\t\tItem\t\tAmount\n");
                    for(i=0;i<count;i++) {
                        printf("%s\t%s\t%lf\n", expense[i].date, expense[i].item, expense[i].amount);
                    }
                    printf("\nTotal expenses : %lf\n", total);
                }
                break;

            case 3 :
                printf("\nThank you for using Expense Tracker App!\n");
                exit(0);
                break;

            default :
                printf("\nInvalid choice!\n");
        }
    }
}