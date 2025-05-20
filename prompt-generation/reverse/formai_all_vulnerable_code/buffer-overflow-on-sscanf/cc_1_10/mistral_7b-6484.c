//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define RECORD_SIZE 100

typedef struct {
    char name[50];
    int account_number;
    float balance;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void error_msg(char *msg) {
    printf("\n%s\n", msg);
    exit(1);
}

void parse_record(char *line) {
    Record *r = &records[num_records++];
    char name[50];
    int account_number;
    float balance;
    sscanf(line, "%s %d %f", name, &account_number, &balance);
    strcpy(r->name, name);
    r->account_number = account_number;
    r->balance = balance;
}

void display_menu() {
    printf("\nBanking Record System\n");
    printf("----------------------\n");
    printf("1. Add a new record\n");
    printf("2. Search by account number\n");
    printf("3. Display all records\n");
    printf("4. Exit\n");
}

int main() {
    char line[RECORD_SIZE];
    FILE *file = fopen("bank_records.txt", "r");

    if (file == NULL) {
        error_msg("Could not open file\n");
    }

    while (fgets(line, sizeof(line), file)) {
        parse_record(line);
    }

    fclose(file);

    display_menu();

    int choice;
    while (scanf("%d", &choice) != 1 || (choice < 1 || choice > 4)) {
        printf("Invalid choice. Please try again.\n");
        display_menu();
    }

    switch (choice) {
        case 1:
            // Add new record code here
            break;
        case 2:
            // Search by account number code here
            break;
        case 3:
            // Display all records code here
            break;
        case 4:
            exit(0);
            break;
    }

    return 0;
}