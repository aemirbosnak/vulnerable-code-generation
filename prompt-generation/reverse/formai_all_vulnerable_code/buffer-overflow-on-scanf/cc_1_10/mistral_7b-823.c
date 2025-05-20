//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_TRANSACTIONS 100
#define FILE_NAME "personal_finance.txt"

typedef struct Transaction {
    char description[50];
    float amount;
    struct Transaction *next;
} Transaction;

Transaction *transactions = NULL;
int num_transactions = 0;

void add_transaction(char *description, float amount) {
    Transaction *new_transaction = (Transaction *)malloc(sizeof(Transaction));

    strcpy(new_transaction->description, description);
    new_transaction->amount = amount;
    new_transaction->next = transactions;

    transactions = new_transaction;
    num_transactions++;
}

void display_balance() {
    float balance = 0.0;

    Transaction *current = transactions;
    while (current != NULL) {
        balance += current->amount;
        current = current->next;
    }

    printf("Your current account balance is: $%.2f\n", balance);
}

void save_data() {
    int file_fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (file_fd < 0) {
        perror("Error opening file for writing.");
        exit(EXIT_FAILURE);
    }

    Transaction *current = transactions;

    while (current != NULL) {
        char data[100];
        snprintf(data, sizeof(data), "%s,%.2f\n", current->description, current->amount);

        if (write(file_fd, data, strlen(data)) < 0) {
            perror("Error writing to file.");
            exit(EXIT_FAILURE);
        }

        current = current->next;
    }

    close(file_fd);
    printf("Data saved successfully.\n");
}

int main() {
    char input_description[50];
    float input_amount;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add transaction\n");
        printf("2. Display balance\n");
        printf("3. Save data and exit\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter transaction description: ");
                scanf("%s", input_description);
                printf("Enter transaction amount: ");
                scanf("%f", &input_amount);

                add_transaction(input_description, input_amount);
                break;

            case 2:
                display_balance();
                break;

            case 3:
                save_data();
                exit(EXIT_SUCCESS);

            case 4:
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return EXIT_SUCCESS;
}