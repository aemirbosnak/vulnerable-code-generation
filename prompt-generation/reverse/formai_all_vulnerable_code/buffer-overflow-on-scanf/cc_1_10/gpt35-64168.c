//FormAI DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Record;

void addRecord(Record records[], int* numRecords);
void deleteRecord(Record records[], int* numRecords);
void searchRecord(Record records[], int numRecords);
void printAllRecords(Record records[], int numRecords);

int main() {
    Record records[MAX_RECORDS];
    int numRecords = 0;

    while (1) {
        printf("###################################################################\n");
        printf("###                 WELCOME TO C DATABASE SIMULATION            ###\n");
        printf("###            PLEASE SELECT AN OPTION FROM THE MENU:            ###\n");
        printf("###################################################################\n");
        printf("###          1. ADD NEW RECORD                                   ###\n");
        printf("###          2. DELETE A RECORD                                  ###\n");
        printf("###          3. SEARCH FOR A RECORD                              ###\n");
        printf("###          4. PRINT ALL RECORDS                                 ###\n");
        printf("###          5. EXIT                                             ###\n");
        printf("###################################################################\n");

        int choice;
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addRecord(records, &numRecords);
                break;

            case 2:
                deleteRecord(records, &numRecords);
                break;

            case 3:
                searchRecord(records, numRecords);
                break;

            case 4:
                printAllRecords(records, numRecords);
                break;

            case 5:
                printf("Exiting database...");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n\n");
                break;
        }
    }

    return 0;
}

void addRecord(Record records[], int* numRecords) {
    printf("\nADDING A NEW RECORD...\n");

    if (*numRecords == MAX_RECORDS) {
        printf("ERROR: Maximum number of records reached!\n\n");
        return;
    }

    Record newRecord;
    printf("ENTER ID: ");
    scanf("%d", &newRecord.id);

    for (int i = 0; i < *numRecords; i++) {
        if (newRecord.id == records[i].id) {
            printf("ERROR: ID already exists!\n\n");
            return;
        }
    }

    printf("ENTER NAME: ");
    scanf("%s", newRecord.name);
    printf("ENTER AGE: ");
    scanf("%d", &newRecord.age);
    printf("ENTER SALARY: ");
    scanf("%f", &newRecord.salary);

    records[*numRecords] = newRecord;
    (*numRecords)++;
    printf("RECORD ADDED SUCCESSFULLY!\n\n");
}

void deleteRecord(Record records[], int* numRecords) {
    printf("\nDELETING A RECORD...\n");

    if (*numRecords == 0) {
        printf("ERROR: Database is empty!\n\n");
        return;
    }

    int id;
    printf("ENTER ID: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < *numRecords; i++) {
        if (id == records[i].id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("ERROR: ID not found!\n\n");
        return;
    }

    for (int i = index; i < *numRecords - 1; i++) {
        records[i] = records[i + 1];
    }

    (*numRecords)--;
    printf("RECORD DELETED SUCCESSFULLY!\n\n");
}

void searchRecord(Record records[], int numRecords) {
    printf("\nSEARCHING FOR A RECORD...\n");

    if (numRecords == 0) {
        printf("ERROR: Database is empty!\n\n");
        return;
    }

    int id;
    printf("ENTER ID: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < numRecords; i++) {
        if (id == records[i].id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("ERROR: ID not found!\n\n");
        return;
    }

    printf("RECORD FOUND!\n\n");
    printf("ID: %d\n", records[index].id);
    printf("NAME: %s\n", records[index].name);
    printf("AGE: %d\n", records[index].age);
    printf("SALARY: %.2f\n\n", records[index].salary);
}

void printAllRecords(Record records[], int numRecords) {
    printf("\nPRINTING ALL RECORDS...\n");

    if (numRecords == 0) {
        printf("ERROR: Database is empty!\n\n");
        return;
    }

    printf("ID\tNAME\tAGE\tSALARY\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%d\t%s\t%d\t%.2f\n", records[i].id, records[i].name, records[i].age, records[i].salary);
    }
    printf("\n");
}