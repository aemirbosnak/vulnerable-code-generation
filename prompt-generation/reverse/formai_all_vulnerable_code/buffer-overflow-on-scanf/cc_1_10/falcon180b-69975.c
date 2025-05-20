//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_CUSTOMERS 100
#define MAX_FORTUNE_LENGTH 100

typedef struct {
    char name[50];
    char fortune[MAX_FORTUNE_LENGTH];
} Customer;

void generate_fortune(Customer *customer) {
    const char *fortunes[] = {
        "You will meet a tall, dark stranger.",
        "A great opportunity awaits you.",
        "Your lucky numbers are 7, 13, 29, 43, and 57.",
        "Beware of the Ides of March.",
        "You will receive a message from an old friend.",
        "A pleasant surprise is in store for you.",
        "You will find true love within the week.",
        "A financial windfall is headed your way.",
        "Your health will improve dramatically.",
        "You will be promoted at work."
    };

    srand(time(NULL));
    int index = rand() % sizeof(fortunes) / sizeof(fortunes[0]);
    strcpy(customer->fortune, fortunes[index]);
}

void greet_customer(Customer *customer) {
    printf("Welcome, %s! I have a special fortune for you:\n", customer->name);
    printf("-------------------------------------------------\n");
    printf("%s\n", customer->fortune);
    printf("-------------------------------------------------\n");
}

int main() {
    Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;

    while (num_customers < MAX_CUSTOMERS) {
        printf("Enter your name (or type 'quit' to exit): ");
        char name[50];
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        strcpy(customers[num_customers].name, name);
        generate_fortune(&customers[num_customers]);
        num_customers++;
    }

    printf("Thank you for visiting the Automated Fortune Teller!\n");
    for (int i = 0; i < num_customers; i++) {
        greet_customer(&customers[i]);
    }

    return 0;
}