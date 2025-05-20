//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: intelligent
/*
 * Data mining example program in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_ATTRIBUTES 10

struct Record {
    char name[20];
    int age;
    char gender;
    char occupation[20];
    float income;
};

void printRecord(struct Record record) {
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
    printf("Gender: %c\n", record.gender);
    printf("Occupation: %s\n", record.occupation);
    printf("Income: %f\n", record.income);
}

void sortRecords(struct Record records[], int numRecords) {
    int i, j;
    struct Record temp;

    for (i = 0; i < numRecords - 1; i++) {
        for (j = 0; j < numRecords - i - 1; j++) {
            if (records[j].age > records[j + 1].age) {
                temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Record records[MAX_RECORDS];
    int numRecords = 0;

    // Read in the records from a file
    FILE *fp = fopen("records.txt", "r");
    while (fscanf(fp, "%s %d %c %s %f", &records[numRecords].name, &records[numRecords].age, &records[numRecords].gender, &records[numRecords].occupation, &records[numRecords].income) == 5) {
        numRecords++;
    }
    fclose(fp);

    // Sort the records by age
    sortRecords(records, numRecords);

    // Print the sorted records
    for (int i = 0; i < numRecords; i++) {
        printRecord(records[i]);
    }

    return 0;
}