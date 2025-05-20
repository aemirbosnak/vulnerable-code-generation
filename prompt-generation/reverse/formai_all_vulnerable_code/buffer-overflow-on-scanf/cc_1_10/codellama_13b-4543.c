//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char address[50];
    int age;
    float balance;
} Customer;

void print_menu(void) {
    printf("----------------------------------------------\n");
    printf("|   ITEM NAME     | PRICE      | DESCRIPTION   |\n");
    printf("----------------------------------------------\n");
    printf("|   Coffee        | 10.99      | Hot coffee    |\n");
    printf("|   Tea           | 9.99       | Tea           |\n");
    printf("|   Soda          | 12.99      | Soda          |\n");
    printf("|   Sandwich      | 14.99      | Sandwich      |\n");
    printf("|   Chips         | 5.99       | Chips         |\n");
    printf("|   Drink         | 3.99       | Drink         |\n");
    printf("----------------------------------------------\n");
}

void print_bill(Customer *customer, float total_cost) {
    printf("----------------------------------------------\n");
    printf("|   CUSTOMER INFO                            |\n");
    printf("----------------------------------------------\n");
    printf("|   Name: %s\n", customer->name);
    printf("|   Address: %s\n", customer->address);
    printf("|   Age: %d\n", customer->age);
    printf("|   Balance: %.2f\n", customer->balance);
    printf("----------------------------------------------\n");
    printf("|   ITEM PRICE                               |\n");
    printf("----------------------------------------------\n");
    printf("|   Total Cost: %.2f\n", total_cost);
    printf("----------------------------------------------\n");
}

void calculate_bill(Customer *customer, float *total_cost) {
    float subtotal = 0;
    int num_items = 0;

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    for (int i = 0; i < num_items; i++) {
        char item_name[50];
        float item_price;

        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", item_name);
        printf("Enter the price of item %s: ", item_name);
        scanf("%f", &item_price);

        subtotal += item_price;
    }

    *total_cost = subtotal;
}

int main() {
    Customer customer;
    float total_cost;

    printf("Welcome to the Cafe Billing System!\n");

    printf("Enter your name: ");
    scanf("%s", customer.name);
    printf("Enter your address: ");
    scanf("%s", customer.address);
    printf("Enter your age: ");
    scanf("%d", &customer.age);
    printf("Enter your balance: ");
    scanf("%f", &customer.balance);

    print_menu();

    calculate_bill(&customer, &total_cost);

    print_bill(&customer, total_cost);

    return 0;
}