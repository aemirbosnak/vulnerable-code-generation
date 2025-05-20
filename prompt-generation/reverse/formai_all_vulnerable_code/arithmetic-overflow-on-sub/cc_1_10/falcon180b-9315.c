//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float amount;
    int due_date;
    int paid;
} Bill;

int main() {
    int num_bills, i;
    Bill bills[50];

    // Get the number of bills from the user
    printf("Enter the number of bills: ");
    scanf("%d", &num_bills);

    // Get the details of each bill from the user
    for (i = 0; i < num_bills; i++) {
        printf("Enter the details of bill #%d:\n", i+1);
        printf("Name: ");
        scanf("%s", bills[i].name);
        printf("Amount: $");
        scanf("%f", &bills[i].amount);
        printf("Due date (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &bills[i].due_date, &bills[i].due_date+1, &bills[i].due_date+3);
        printf("Paid? (1 for yes, 0 for no): ");
        scanf("%d", &bills[i].paid);
    }

    // Print the bills
    printf("\nBills:\n");
    for (i = 0; i < num_bills; i++) {
        printf("Name: %s\nAmount: $%.2f\nDue date: %d/%d/%d\nPaid: %s\n", bills[i].name, bills[i].amount, bills[i].due_date/100, bills[i].due_date%100, bills[i].due_date%10000, bills[i].paid? "Yes" : "No");
    }

    // Sort the bills by due date
    for (i = 0; i < num_bills-1; i++) {
        for (int j = i+1; j < num_bills; j++) {
            if (bills[j].due_date < bills[i].due_date) {
                Bill temp = bills[i];
                bills[i] = bills[j];
                bills[j] = temp;
            }
        }
    }

    // Print the sorted bills
    printf("\nBills sorted by due date:\n");
    for (i = 0; i < num_bills; i++) {
        printf("Name: %s\nAmount: $%.2f\nDue date: %d/%d/%d\nPaid: %s\n", bills[i].name, bills[i].amount, bills[i].due_date/100, bills[i].due_date%100, bills[i].due_date%10000, bills[i].paid? "Yes" : "No");
    }

    return 0;
}