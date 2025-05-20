//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: irregular
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct Menu {
        char* name;
        float price;
    };

    struct Customer {
        char* name;
        float total_bill;
        int item_count;
        struct Menu* menu_items[10];
    };

    struct Billing {
        char* date;
        float total_bill;
        int item_count;
        struct Customer* customers[10];
    };

    void print_menu(struct Menu* menu) {
        printf("Name: %s\n", menu->name);
        printf("Price: %.2f\n", menu->price);
    }

    void print_customer(struct Customer* customer) {
        printf("Name: %s\n", customer->name);
        printf("Total Bill: %.2f\n", customer->total_bill);
        printf("Items: %d\n", customer->item_count);
        for (int i = 0; i < customer->item_count; i++) {
            printf("\t%s\n", customer->menu_items[i]->name);
        }
    }

    void print_billing(struct Billing* billing) {
        printf("Date: %s\n", billing->date);
        printf("Total Bill: %.2f\n", billing->total_bill);
        printf("Items: %d\n", billing->item_count);
        for (int i = 0; i < billing->item_count; i++) {
            printf("\t%s\n", billing->customers[i]->name);
        }
    }

    int main() {
        struct Menu* menu_items[10];
        struct Customer* customers[10];
        struct Billing* billing;

        menu_items[0] = (struct Menu*)malloc(sizeof(struct Menu));
        menu_items[0]->name = "Coffee";
        menu_items[0]->price = 3.00;

        menu_items[1] = (struct Menu*)malloc(sizeof(struct Menu));
        menu_items[1]->name = "Tea";
        menu_items[1]->price = 2.50;

        menu_items[2] = (struct Menu*)malloc(sizeof(struct Menu));
        menu_items[2]->name = "Cake";
        menu_items[2]->price = 5.00;

        customers[0] = (struct Customer*)malloc(sizeof(struct Customer));
        customers[0]->name = "John Doe";
        customers[0]->total_bill = 0.00;
        customers[0]->item_count = 0;

        customers[1] = (struct Customer*)malloc(sizeof(struct Customer));
        customers[1]->name = "Jane Doe";
        customers[1]->total_bill = 0.00;
        customers[1]->item_count = 0;

        billing = (struct Billing*)malloc(sizeof(struct Billing));
        billing->date = "12/12/2022";
        billing->total_bill = 0.00;
        billing->item_count = 0;

        for (int i = 0; i < 10; i++) {
            billing->customers[i] = customers[i];
        }

        for (int i = 0; i < 10; i++) {
            customers[i]->menu_items[i] = menu_items[i];
        }

        print_menu(menu_items[0]);
        print_menu(menu_items[1]);
        print_menu(menu_items[2]);

        print_customer(customers[0]);
        print_customer(customers[1]);

        print_billing(billing);

        return 0;
    }