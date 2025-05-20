//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 256
#define MAX_TOKEN 100
#define MAX_ACCOUNT 50

typedef struct {
    char name[MAX_TOKEN];
    float balance;
    int type; // 0: checking, 1: savings, 2: credit
} Account;

Account accounts[MAX_ACCOUNT];
int num_accounts = 0;

void error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void tokenize(const char *line, char *tokens[]) {
    int i = 0, j = 0;
    char *token;

    while (*line != '\0') {
        token = strtok(line, " \t\n\r,");
        if (token != NULL) {
            strcpy(tokens[i], token);
            i++;
        }
        line = strtok(NULL, " \t\n\r,");
    }
    tokens[i] = "\0";
}

void parse_line(const char *line) {
    char tokens[MAX_TOKEN][MAX_TOKEN];
    int i;

    tokenize(line, tokens);

    if (strcmp(tokens[0], "ADD") == 0) {
        if (num_accounts >= MAX_ACCOUNT) error("Too many accounts.");
        strcpy(accounts[num_accounts].name, tokens[1]);
        accounts[num_accounts].type = atoi(tokens[2]);
        accounts[num_accounts].balance = atof(tokens[3]);
        num_accounts++;
    } else if (strcmp(tokens[0], "DEPOSIT") == 0) {
        int index = -1;
        for (i = 0; i < num_accounts; i++) {
            if (strcmp(accounts[i].name, tokens[1]) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1) error("Account not found.");
        accounts[index].balance += atof(tokens[2]);
    } else if (strcmp(tokens[0], "WITHDRAW") == 0) {
        int index = -1;
        for (i = 0; i < num_accounts; i++) {
            if (strcmp(accounts[i].name, tokens[1]) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1) error("Account not found.");
        if (accounts[index].type == 2 && accounts[index].balance < -atof(tokens[2])) {
            error("Insufficient credit.");
        }
        accounts[index].balance -= atof(tokens[2]);
    } else if (strcmp(tokens[0], "BALANCE") == 0) {
        int index = -1;
        for (i = 0; i < num_accounts; i++) {
            if (strcmp(accounts[i].name, tokens[1]) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1) error("Account not found.");
        printf("%s: %.2f\n", accounts[index].name, accounts[index].balance);
    } else {
        error("Unknown command.");
    }
}

int main() {
    char line[MAX_LINE];
    int i;

    while (1) {
        printf("> ");
        fgets(line, sizeof(line), stdin);
        line[strlen(line) - 1] = '\0'; // remove newline character
        parse_line(line);
    }

    return 0;
}