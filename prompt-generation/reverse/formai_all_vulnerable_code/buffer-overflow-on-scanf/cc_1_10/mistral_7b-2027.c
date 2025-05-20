//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define RECORD_SIZE 100

typedef struct {
    char name[50];
    float balance;
} Record;

Record records[MAX_RECORDS];
int currentRecord = 0;

void saveRecord(const char *name, float amount) {
    strcpy(records[currentRecord].name, name);
    records[currentRecord].balance += amount;
    currentRecord++;
}

float getBalance(const char *name) {
    for (int i = 0; i < currentRecord; i++) {
        if (strcmp(records[i].name, name) == 0) {
            return records[i].balance;
        }
    }
    return -1;
}

int main() {
    char command[10];
    char name[50];
    float amount;

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "deposit") == 0) {
            scanf("%s %f", name, &amount);
            saveRecord(name, amount);
        } else if (strcmp(command, "withdraw") == 0) {
            scanf("%s %f", name, &amount);
            float balance = getBalance(name);
            if (balance >= amount) {
                saveRecord(name, -amount);
                printf("Successfully withdrew %.2f\n", amount);
            } else {
                printf("Insufficient funds\n");
            }
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command\n");
        }
    }

    return 0;
}