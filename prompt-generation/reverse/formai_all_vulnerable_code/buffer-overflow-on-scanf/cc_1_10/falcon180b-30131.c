//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Record;

Record database[100];
int numRecords = 0;

void addRecord(char* name, char* value) {
    if (numRecords >= 100) {
        printf("Error: Database is full.\n");
        return;
    }

    strcpy(database[numRecords].name, name);
    strcpy(database[numRecords].value, value);
    numRecords++;
}

void deleteRecord(char* name) {
    int i;
    for (i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, name) == 0) {
            memset(&database[i], 0, sizeof(Record));
            numRecords--;
            return;
        }
    }
    printf("Error: Record not found.\n");
}

void updateRecord(char* name, char* value) {
    int i;
    for (i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, name) == 0) {
            strcpy(database[i].value, value);
            return;
        }
    }
    printf("Error: Record not found.\n");
}

void searchRecord(char* name) {
    int i;
    for (i = 0; i < numRecords; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("Name: %s\nValue: %s\n", database[i].name, database[i].value);
            return;
        }
    }
    printf("Error: Record not found.\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];

    do {
        printf("1. Add Record\n2. Delete Record\n3. Update Record\n4. Search Record\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Value: ");
            scanf("%s", value);
            addRecord(name, value);
            break;
        case 2:
            printf("Enter Name: ");
            scanf("%s", name);
            deleteRecord(name);
            break;
        case 3:
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter New Value: ");
            scanf("%s", value);
            updateRecord(name, value);
            break;
        case 4:
            printf("Enter Name: ");
            scanf("%s", name);
            searchRecord(name);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}