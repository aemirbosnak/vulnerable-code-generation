//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 50

typedef struct {
    char name[50];
    float balance;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void add_record(const char *name, float amount) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }

    strcpy(records[num_records].name, name);
    records[num_records].balance += amount;
    num_records++;
}

void view_records() {
    if (!num_records) {
        printf("No records found.\n");
        return;
    }

    printf("\n%-15s %-15s\n", "Name", "Balance");
    for (int i = 0; i < num_records; i++) {
        printf("%-15s %10.2f\n", records[i].name, records[i].balance);
    }
}

void delete_record(const char *name) {
    int index = -1;

    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Record not found.\n");
        return;
    }

    for (int i = index; i < num_records - 1; i++) {
        records[i] = records[i + 1];
    }

    num_records--;
}

int main() {
    char cmd[10];
    char name[50];
    float amount;

    while (1) {
        printf("\n1. Add record\n2. View records\n3. Delete record\n4. Exit\nEnter command: ");
        scanf("%s", cmd);

        switch (cmd[0]) {
            case '1':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter amount: ");
                scanf("%f", &amount);
                add_record(name, amount);
                break;
            case '2':
                view_records();
                break;
            case '3':
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete_record(name);
                break;
            case '4':
                exit(0);
                break;
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}