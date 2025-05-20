//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char occupation[MAX_NAME_LENGTH];
    float salary;
} Record;

void addRecord(Record records[], int *recordCount) {
    if (*recordCount >= MAX_RECORDS) {
        printf("Record limit reached. Cannot add more records.\n");
        return;
    }
    
    Record newRecord;
    printf("Enter name: ");
    scanf("%s", newRecord.name);
    printf("Enter age: ");
    scanf("%d", &newRecord.age);
    printf("Enter occupation: ");
    scanf("%s", newRecord.occupation);
    printf("Enter salary: ");
    scanf("%f", &newRecord.salary);
    
    records[*recordCount] = newRecord;
    (*recordCount)++;
    printf("Record added successfully!\n");
}

void displayRecords(Record records[], int recordCount) {
    if (recordCount == 0) {
        printf("No records to display.\n");
        return;
    }
    
    printf("\n-------------------------------------\n");
    printf("Name\t\tAge\tOccupation\tSalary\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < recordCount; i++) {
        printf("%s\t\t%d\t%s\t\t%.2f\n", records[i].name, records[i].age, records[i].occupation, records[i].salary);
    }
    printf("-------------------------------------\n");
}

void searchRecord(Record records[], int recordCount) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of the record to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < recordCount; i++) {
        if (strcmp(records[i].name, name) == 0) {
            printf("Record Found: %s, Age: %d, Occupation: %s, Salary: %.2f\n",
                   records[i].name, records[i].age, records[i].occupation, records[i].salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record with name %s not found.\n", name);
    }
}

void deleteRecord(Record records[], int *recordCount) {
    char name[MAX_NAME_LENGTH];
    printf("Enter name of the record to delete: ");
    scanf("%s", name);

    for (int i = 0; i < *recordCount; i++) {
        if (strcmp(records[i].name, name) == 0) {
            for (int j = i; j < *recordCount - 1; j++) {
                records[j] = records[j + 1];
            }
            (*recordCount)--;
            printf("Record with name %s deleted successfully.\n", name);
            return;
        }
    }
    printf("Record with name %s not found.\n", name);
}

void analyzeData(Record records[], int recordCount) {
    if (recordCount == 0) {
        printf("No records to analyze.\n");
        return;
    }

    float totalSalary = 0.0;
    int ageCount = 0;
    for (int i = 0; i < recordCount; i++) {
        totalSalary += records[i].salary;
        ageCount += records[i].age;
    }
    
    float avgSalary = totalSalary / recordCount;
    float avgAge = (float)ageCount / recordCount;

    printf("\nAverage Salary: %.2f\n", avgSalary);
    printf("Average Age: %.2f\n", avgAge);
}

int main() {
    Record records[MAX_RECORDS];
    int recordCount = 0;
    int choice;

    do {
        printf("\nData Mining Application Menu:\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Analyze Data\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(records, &recordCount);
                break;
            case 2:
                displayRecords(records, recordCount);
                break;
            case 3:
                searchRecord(records, recordCount);
                break;
            case 4:
                deleteRecord(records, &recordCount);
                break;
            case 5:
                analyzeData(records, recordCount);
                break;
            case 6:
                printf("Exiting the application.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}