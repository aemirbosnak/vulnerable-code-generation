//FormAI DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 40
#define MAX_ADDRESS_LEN 100
#define MAX_PHONE_LEN 15

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    char phone[MAX_PHONE_LEN];
} customer;

int main() {
    int option, count = 0, i;
    customer *data = NULL;

    while (1) {
        printf("\n-----CUSTOMER DATABASE-----\n");
        printf("1. Add customer\n");
        printf("2. Display all customers\n");
        printf("3. Search for customer by name\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                // Add new customer
                printf("\n-----ADD CUSTOMER-----\n");

                data = (customer *)realloc(data, (count + 1) * sizeof(customer));

                printf("Enter customer name: ");
                scanf("%s", data[count].name);

                printf("Enter customer address: ");
                scanf("%s", data[count].address);

                printf("Enter customer phone number: ");
                scanf("%s", data[count].phone);

                data[count].id = count + 1;

                printf("\nCustomer added successfully!\n");
                count++;

                break;
            }

            case 2: {
                // Display all customers
                printf("\n-----ALL CUSTOMERS-----\n");

                if (count == 0) {
                    printf("No customers in the database\n");
                } else {
                    for (i = 0; i < count; i++) {
                        printf("ID: %d, Name: %s, Address: %s, Phone: %s\n",
                            data[i].id, data[i].name, data[i].address, data[i].phone);
                    }
                }

                break;
            }

            case 3: {
                // Search for customer by name
                char search_name[MAX_NAME_LEN];
                int found = 0;

                printf("\n-----SEARCH CUSTOMER-----\n");
                printf("Enter customer name: ");
                scanf("%s", search_name);

                for (i = 0; i < count; i++) {
                    if (strcmp(search_name, data[i].name) == 0) {
                        printf("Customer Found!\n");
                        printf("ID: %d, Name: %s, Address: %s, Phone: %s\n",
                            data[i].id, data[i].name, data[i].address, data[i].phone);
                        found = 1;
                    }
                }

                if (!found) {
                    printf("Customer not found\n");
                }

                break;
            }

            case 4: {
                // Exit the program
                printf("\nExiting program. Goodbye!\n");
                free(data);
                return 0;
            }

            default:
                printf("\nInvalid option, please try again\n");
        }
    }
}