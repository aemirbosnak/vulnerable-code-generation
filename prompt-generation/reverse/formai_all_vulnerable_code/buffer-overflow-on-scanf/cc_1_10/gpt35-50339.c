//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FOOD_ITEMS 10

const char *menu[MAX_FOOD_ITEMS] = {"Coffee", "Tea", "Muffin", "Croissant", "Sandwich", "Salad", "Cake", "Smoothie", "Juice", "Water"};
const float prices[MAX_FOOD_ITEMS] = {2.50, 2.00, 1.50, 1.75, 4.00, 5.00, 3.00, 6.00, 4.00, 1.00};

typedef struct {
    char name[30];
    char order[30];
    int quantity;
    float price;
} Customer;

int main() {
    printf("Welcome to C Cafe Billing System\n");
    printf("------------------------------\n\n");

    //Initializing variables
    int num_customers;
    printf("Enter number of customers: ");
    scanf("%d", &num_customers);
    printf("\n");

    Customer *customers = (Customer *) malloc(num_customers * sizeof(Customer));

    //Prompting user for customer details and order
    for(int i=0; i<num_customers; i++) {
        printf("Enter name for customer %d: ", i+1);
        scanf("%s", customers[i].name);
        printf("Enter order for customer %d: ", i+1);

        //Taking the order in a string and parsing the item and quantity from it
        char order[30];
        scanf(" %[^\n]s", order);
        char *token = strtok(order, ",");
        customers[i].price = 0;
        while(token != NULL) {
            int item = atoi(token) - 1;
            customers[i].price += prices[item];
            customers[i].quantity += 1;
            if(customers[i].order[0] == '\0') {
                sprintf(customers[i].order, "%s (x1)", menu[item]);
            }
            else {
                char *pos = strstr(customers[i].order, menu[item]);
                if(pos != NULL) {
                    int quantity = customers[i].order[pos - customers[i].order + strlen(menu[item]) + 3] - '0';
                    sprintf(pos+strlen(menu[item])+3, "%d", quantity+1);
                }
                else {
                    sprintf(customers[i].order+strlen(customers[i].order), ", %s (x1)", menu[item]);
                }
            }
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    //Printing the bill for each customer
    for(int i=0; i<num_customers; i++) {
        printf("Name: %s\n", customers[i].name);
        printf("Order: %s\n", customers[i].order);
        printf("Quantity: %d\n", customers[i].quantity);
        printf("Total Price: $%0.2f\n\n", customers[i].price);
    }

    free(customers);
    return 0;
}