//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float income;
} Record;

void loadData(Record records[], int *recordCount);
void displayData(const Record records[], int recordCount);
void findAgeMean(const Record records[], int recordCount);
void findIncomeMean(const Record records[], int recordCount);
void saveFilteredData(const Record records[], int recordCount, float incomeThreshold);

int main() {
    Record records[MAX_RECORDS];
    int recordCount = 0;
    int choice;

    loadData(records, &recordCount);

    while (1) {
        printf("\nData Mining Program\n");
        printf("1. Display Records\n");
        printf("2. Calculate Mean Age\n");
        printf("3. Calculate Mean Income\n");
        printf("4. Filter by Income\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayData(records, recordCount);
                break;
            case 2:
                findAgeMean(records, recordCount);
                break;
            case 3:
                findIncomeMean(records, recordCount);
                break;
            case 4: {
                float incomeThreshold;
                printf("Enter income threshold: ");
                scanf("%f", &incomeThreshold);
                saveFilteredData(records, recordCount, incomeThreshold);
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }
    return 0;
}

void loadData(Record records[], int *recordCount) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("Failed to open data file");
        exit(1);
    }

    while (*recordCount < MAX_RECORDS && fscanf(file, "%s %d %f", records[*recordCount].name, &records[*recordCount].age, &records[*recordCount].income) == 3) {
        (*recordCount)++;
    }

    fclose(file);
}

void displayData(const Record records[], int recordCount) {
    printf("\n%-20s %-5s %-10s\n", "Name", "Age", "Income");
    printf("-------------------------------------\n");
    
    for (int i = 0; i < recordCount; i++) {
        printf("%-20s %-5d %-10.2f\n", records[i].name, records[i].age, records[i].income);
    }
}

void findAgeMean(const Record records[], int recordCount) {
    if (recordCount == 0) {
        printf("No records to calculate mean age.\n");
        return;
    }

    float sum = 0;
    for (int i = 0; i < recordCount; i++) {
        sum += records[i].age;
    }
    float meanAge = sum / recordCount;
    printf("Mean Age: %.2f\n", meanAge);
}

void findIncomeMean(const Record records[], int recordCount) {
    if (recordCount == 0) {
        printf("No records to calculate mean income.\n");
        return;
    }

    float sum = 0;
    for (int i = 0; i < recordCount; i++) {
        sum += records[i].income;
    }
    float meanIncome = sum / recordCount;
    printf("Mean Income: %.2f\n", meanIncome);
}

void saveFilteredData(const Record records[], int recordCount, float incomeThreshold) {
    FILE *file = fopen("filtered_data.txt", "w");
    if (file == NULL) {
        perror("Failed to create output file");
        return;
    }

    int count = 0;
    for (int i = 0; i < recordCount; i++) {
        if (records[i].income > incomeThreshold) {
            fprintf(file, "%s %d %.2f\n", records[i].name, records[i].age, records[i].income);
            count++;
        }
    }

    if (count > 0) {
        printf("Filtered data saved to 'filtered_data.txt'.\n");
    } else {
        printf("No records exceeding the income threshold of %.2f.\n", incomeThreshold);
    }

    fclose(file);
}