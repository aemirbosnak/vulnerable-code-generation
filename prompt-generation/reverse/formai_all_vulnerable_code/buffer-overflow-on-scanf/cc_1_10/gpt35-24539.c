//FormAI DATASET v1.0 Category: Database simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_RECORDS 1000

typedef struct Record {
    int id;
    char name[50];
    char address[100];
    int age;
} Record;

Record database[MAX_RECORDS];
int dbSize = 0;

typedef struct Operation {
    char type[10];
    Record record;
} Operation;

Operation operationsQueue[MAX_RECORDS];
int opIndex = 0;

void addOperation(char type[], Record record) {
    strcpy(operationsQueue[opIndex].type, type);
    operationsQueue[opIndex].record = record;
    opIndex++;
}

bool isOperationQueueEmpty() {
    return (opIndex == 0);
}

void processOperation() {
    if(isOperationQueueEmpty()) return;
    Operation operation = operationsQueue[0];
    if(strcmp(operation.type, "ADD") == 0) {
        database[dbSize++] = operation.record;
        printf("Record added successfully\n");
    } else if(strcmp(operation.type, "DELETE") == 0) {
        int recordIndex = -1;
        for(int i = 0; i < dbSize; i++) {
            if(database[i].id == operation.record.id) {
                recordIndex = i;
                break;
            }
        }
        if(recordIndex != -1) {
            for(int i = recordIndex; i < dbSize-1; i++) {
                database[i] = database[i+1];
            }
            dbSize--;
            printf("Record deleted successfully\n");
        } else {
            printf("Record not found\n");
        }
    }
    for(int i = 0; i < opIndex-1; i++) {
        operationsQueue[i] = operationsQueue[i+1];
    }
    opIndex--;
}

int main() {
    int choice;
    bool quit = false;
    srand(time(NULL));
    while(!quit) {
        printf("1. Add record\n");
        printf("2. Delete record\n");
        printf("3. Process operations\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Record record;
                record.id = rand() % 1000 + 1;
                printf("Enter name: ");
                scanf("%s", &record.name);
                printf("Enter address: ");
                scanf("%s", &record.address);
                printf("Enter age: ");
                scanf("%d", &record.age);
                addOperation("ADD", record);
                break;
            }
            case 2: {
                Record record;
                printf("Enter id: ");
                scanf("%d", &record.id);
                addOperation("DELETE", record);
                break;
            }
            case 3: {
                while(!isOperationQueueEmpty()) {
                    processOperation();
                }
                break;
            }
            case 4: {
                quit = true;
                break;
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }
    return 0;
}