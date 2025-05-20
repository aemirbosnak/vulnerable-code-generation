//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_customers, num_items, i, j, choice;
    float total_bill, bill_amount, tip_amount;
    char item[10][20], customer_name[20];
    struct tm time_info;
    time_t now;

    srand(time(NULL));
    now = time(NULL);
    localtime_r(&now, &time_info);

    printf("Welcome to the C Cafe Billing System!\n");
    printf("Today's date: %d-%02d-%02d\n", time_info.tm_year+1900, time_info.tm_mon+1, time_info.tm_mday);
    printf("Please enter the number of customers: ");
    scanf("%d", &num_customers);

    for (i = 0; i < num_customers; i++) {
        printf("Customer %d name: ", i+1);
        scanf("%s", customer_name);

        printf("Please enter the number of items for %s: ", customer_name);
        scanf("%d", &num_items);

        for (j = 0; j < num_items; j++) {
            printf("Item %d name: ", j+1);
            scanf("%s", item[j]);

            bill_amount = rand() % 100;
            printf("Bill amount for %s: $%.2f\n", item[j], bill_amount);
            total_bill += bill_amount;
        }

        printf("Total bill for %s: $%.2f\n", customer_name, total_bill);
        printf("Would you like to add a tip (y/n)? ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            printf("Please enter the tip amount: ");
            scanf("%f", &tip_amount);
            total_bill += tip_amount;
        }

        printf("\n");
    }

    return 0;
}