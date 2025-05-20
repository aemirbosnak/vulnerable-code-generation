//FormAI DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _bank_record {
    char name[50];
    char account_number[20];
    double balance;
} BankRecord;

void add_record(BankRecord* records, int* num_records) {
    printf("Enter name: ");
    scanf("%s", records[*num_records].name);
    printf("Enter account number: ");
    scanf("%s", records[*num_records].account_number);
    printf("Enter balance: ");
    scanf("%lf", &(records[*num_records].balance));

    *num_records += 1;
}

void display_records(BankRecord* records, int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Account Number: %s\n", records[i].account_number);
        printf("Balance: $%.2f\n", records[i].balance);
    }
}

void save_records(BankRecord* records, int num_records, const char* file_path) {
    FILE* file = fopen(file_path, "w");

    if (file == NULL) {
        printf("Failed to open file for writing\n");
        return;
    }

    fwrite(&num_records, sizeof(int), 1, file);

    for (int i = 0; i < num_records; i++) {
        fwrite(records[i].name, sizeof(char), 50, file);
        fwrite(records[i].account_number, sizeof(char), 20, file);
        fwrite(&(records[i].balance), sizeof(double), 1, file);
    }

    fclose(file);
}

int load_records(BankRecord* records, int* num_records, const char* file_path) {
    FILE* file = fopen(file_path, "r");

    if (file == NULL) {
        printf("Failed to open file for reading\n");
        return 0;
    }

    fread(num_records, sizeof(int), 1, file);

    for (int i = 0; i < *num_records; i++) {
        fread(records[i].name, sizeof(char), 50, file);
        fread(records[i].account_number, sizeof(char), 20, file);
        fread(&(records[i].balance), sizeof(double), 1, file);
    }

    fclose(file);
    return 1;
}

int main() {
    char command[10];
    BankRecord* records = malloc(100 * sizeof(BankRecord));
    int num_records = 0;

    printf("Welcome to the Banking Record System!\n");

    while (1) {
        printf("Enter command (add, display, save, load, quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            add_record(records, &num_records);
        } else if (strcmp(command, "display") == 0) {
            display_records(records, num_records);
        } else if (strcmp(command, "save") == 0) {
            char file_path[100];
            printf("Enter file path: ");
            scanf("%s", file_path);
            save_records(records, num_records, file_path);
            printf("Records saved to file\n");
        } else if (strcmp(command, "load") == 0) {
            char file_path[100];
            printf("Enter file path: ");
            scanf("%s", file_path);
            int result = load_records(records, &num_records, file_path);
            if (result) {
                printf("Records loaded from file\n");
            }
        } else if (strcmp(command, "quit") == 0) {
            free(records);
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}