//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECORDS 50
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100
#define MAX_AMOUNT 100000.0

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    float amount;
} Transaction;

void print_menu();
Transaction transactions[MAX_RECORDS];
int num_records = 0;

int main() {
    char choice;
    int index;
    float input_amount;

    do {
        print_menu();
        scanf("%c", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 'A':
                if (num_records < MAX_RECORDS) {
                    printf("Enter transaction name: ");
                    fgets(transactions[num_records].name, MAX_NAME_LEN, stdin);
                    transactions[num_records].name[strcspn(transactions[num_records].name, "\n")] = '\0';
                    printf("Enter transaction description: ");
                    fgets(transactions[num_records].description, MAX_DESC_LEN, stdin);
                    transactions[num_records].description[strcspn(transactions[num_records].description, "\n")] = '\0';
                    printf("Enter transaction amount: ");
                    scanf("%f", &input_amount);

                    if (input_amount > 0 && input_amount <= MAX_AMOUNT) {
                        transactions[num_records].amount = input_amount;
                        num_records++;
                        printf("Transaction recorded successfully!\n");
                    } else {
                        printf("Invalid transaction amount. Please enter a valid amount.\n");
                    }
                } else {
                    printf("Maximum number of transactions reached.\n");
                }
                break;

            case 'B':
                if (num_records > 0) {
                    printf("Enter the transaction number to be deleted: ");
                    scanf("%d", &index);

                    if (index >= 0 && index < num_records) {
                        for (int i = index; i < num_records - 1; i++) {
                            transactions[i] = transactions[i+1];
                        }
                        num_records--;
                        printf("Transaction deleted successfully!\n");
                    } else {
                        printf("Invalid transaction number.\n");
                    }
                } else {
                    printf("No transactions to delete.\n");
                }
                break;

            case 'C':
                if (num_records > 0) {
                    printf("Transaction records:\n");
                    for (int i = 0; i < num_records; i++) {
                        printf("%d. %s %s %+.2f\n", i+1, transactions[i].name, transactions[i].description, transactions[i].amount);
                    }
                } else {
                    printf("No transactions recorded.\n");
                }
                break;

            case 'D':
                printf("Exiting MoneyMate...\n");
                break;

            default:
                printf("Invalid option. Please choose a valid option.\n");
        }
    } while (choice != 'D');

    return 0;
}

void print_menu() {
    printf("\nMoneyMate Menu:\n");
    printf("A) Add a transaction\n");
    printf("B) Delete a transaction\n");
    printf("C) Display transaction records\n");
    printf("D) Exit MoneyMate\n");
}