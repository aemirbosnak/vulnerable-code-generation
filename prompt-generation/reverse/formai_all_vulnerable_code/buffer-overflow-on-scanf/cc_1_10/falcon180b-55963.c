//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_CUSTOMER_NAME_LENGTH 50
#define MAX_FORTUNE_LENGTH 200

typedef struct {
    char name[MAX_CUSTOMER_NAME_LENGTH];
    int customer_id;
    char fortune[MAX_FORTUNE_LENGTH];
} Customer;

void generate_random_fortune(char* fortune) {
    char* fortunes[] = {
        "You will have a great day today!",
        "Good things are coming your way!",
        "You will meet someone special soon!",
        "Your hard work will pay off!",
        "You will receive a surprise gift!",
        "You will be successful in your endeavors!",
        "You will find happiness in unexpected places!",
        "Your dreams will come true!",
        "You will have a lucky streak!",
        "You will have a peaceful and relaxing day!"
    };
    int num_fortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    srand(time(NULL));
    int index = rand() % num_fortunes;
    strcpy(fortune, fortunes[index]);
}

int main() {
    Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;
    char input[MAX_CUSTOMER_NAME_LENGTH];
    int customer_id = 1;

    printf("Welcome to the Fortune Teller!\n");

    while (num_customers < MAX_CUSTOMERS) {
        printf("Enter your name (or type 'quit' to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        strcpy(customers[num_customers].name, input);
        customers[num_customers].customer_id = customer_id;
        generate_random_fortune(customers[num_customers].fortune);
        num_customers++;
        customer_id++;
    }

    printf("\n");
    for (int i = 0; i < num_customers; i++) {
        printf("Customer %d: %s\n", customers[i].customer_id, customers[i].name);
        printf("Fortune: %s\n", customers[i].fortune);
        printf("\n");
    }

    return 0;
}