//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_ACCOUNTS 10
#define NUM_COLUMNS 3

typedef struct {
    char name[MAX_LINE_LENGTH];
    char account_number[MAX_LINE_LENGTH];
    char balance[MAX_LINE_LENGTH];
} account_t;

int main() {
    account_t accounts[MAX_NUM_ACCOUNTS];
    int num_accounts = 0;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char *token;
    FILE *fp;

    printf("Enter the name of the file containing account information: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (num_accounts >= MAX_NUM_ACCOUNTS) {
            printf("Error: too many accounts in file.\n");
            exit(1);
        }
        token = strtok(line, ",");
        strcpy(accounts[num_accounts].name, token);
        token = strtok(NULL, ",");
        strcpy(accounts[num_accounts].account_number, token);
        token = strtok(NULL, ",");
        strcpy(accounts[num_accounts].balance, token);
        num_accounts++;
    }

    fclose(fp);

    printf("\n");
    printf("Account Name\tAccount Number\tBalance\n");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < num_accounts; i++) {
        printf("%-30s%-30s$%s\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
    }

    return 0;
}