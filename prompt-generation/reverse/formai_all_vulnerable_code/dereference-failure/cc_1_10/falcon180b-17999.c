//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LEN 1024
#define MAX_TOKENS 256

typedef struct {
    char *name;
    double amount;
} Transaction;

Transaction *transactions = NULL;
int num_transactions = 0;

void add_transaction(Transaction *t) {
    transactions = realloc(transactions, sizeof(Transaction) * ++num_transactions);
    memcpy(&transactions[num_transactions - 1], t, sizeof(Transaction));
}

void print_transactions() {
    for (int i = 0; i < num_transactions; i++) {
        printf("%s: $%.2f\n", transactions[i].name, transactions[i].amount);
    }
}

Transaction *find_transaction(char *name) {
    for (int i = 0; i < num_transactions; i++) {
        if (strcmp(transactions[i].name, name) == 0) {
            return &transactions[i];
        }
    }
    return NULL;
}

double calculate_total_expenses() {
    double total = 0;
    for (int i = 0; i < num_transactions; i++) {
        total += transactions[i].amount;
    }
    return total;
}

double calculate_average_expenses() {
    double total = calculate_total_expenses();
    return total / num_transactions;
}

int main() {
    char line[MAX_LINE_LEN];
    char *token;
    FILE *fp;
    int line_num = 0;

    fp = fopen("transactions.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open transactions file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        line_num++;
        token = strtok(line, ":");
        if (token == NULL) {
            printf("Error: Invalid line format in transactions file (line %d).\n", line_num);
            return 1;
        }
        Transaction t;
        t.name = strdup(token);
        t.amount = atof(strtok(NULL, ":"));
        add_transaction(&t);
    }

    fclose(fp);

    print_transactions();

    printf("Total expenses: $%.2f\n", calculate_total_expenses());
    printf("Average expenses: $%.2f\n", calculate_average_expenses());

    return 0;
}