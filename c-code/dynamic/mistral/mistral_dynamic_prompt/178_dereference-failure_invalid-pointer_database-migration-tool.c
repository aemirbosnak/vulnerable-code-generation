#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    char name[100];
    char database[100];
} Account;

void migrate_data(Account *accounts, int size) {
    FILE *fp = fopen("new_database.db", "w");

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%s %s\n", accounts[i].name, accounts[i].database);
    }

    fclose(fp);
}

void load_accounts(Account *accounts, int *num_accounts) {
    FILE *fp = fopen("old_database.db", "r");

    char buffer[BUFFER_SIZE];
    int i = 0;

    while (fgets(buffer, BUFFER_SIZE, fp)) {
        strcpy(accounts[i].name, strtok(buffer, " "));
        strcpy(accounts[i].database, strtok(NULL, " "));
        i++;
    }

    *num_accounts = i;
    fclose(fp);
}

int main() {
    Account *accounts = (Account *)malloc(100 * sizeof(Account));
    int num_accounts;

    load_accounts(accounts, &num_accounts);
    migrate_data(accounts + num_accounts, 100); // DEREFERENCE FAILURE VULNERABILITY HERE

    free(accounts);

    return 0;
}
