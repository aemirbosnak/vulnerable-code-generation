//Falcon-180B DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a record
typedef struct {
    char name[50];
    int age;
    float salary;
} Record;

// Function to read records from a file
void readRecords(FILE *fp, Record *records, int numRecords) {
    int i = 0;
    while (i < numRecords && fscanf(fp, "%s %d %f", records[i].name, &records[i].age, &records[i].salary) == 3) {
        i++;
    }
}

// Function to write records to a file
void writeRecords(FILE *fp, Record *records, int numRecords) {
    int i;
    for (i = 0; i < numRecords; i++) {
        fprintf(fp, "%s %d %f\n", records[i].name, records[i].age, records[i].salary);
    }
}

// Function to sort records by name
void sortRecords(Record *records, int numRecords) {
    int i, j;
    char tempName[50];
    Record tempRecord;
    for (i = 0; i < numRecords - 1; i++) {
        for (j = i + 1; j < numRecords; j++) {
            if (strcmp(records[i].name, records[j].name) > 0) {
                strcpy(tempName, records[i].name);
                strcpy(records[i].name, records[j].name);
                strcpy(records[j].name, tempName);
                tempRecord = records[i];
                records[i] = records[j];
                records[j] = tempRecord;
            }
        }
    }
}

int main() {
    FILE *fp;
    char filename[50];
    int choice, numRecords;
    Record records[100];

    // Prompt user for file name
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    // Read records from the file
    readRecords(fp, records, 100);
    numRecords = 0;
    while (records[numRecords].name[0]!= '\0') {
        numRecords++;
    }
    fclose(fp);

    // Prompt user for a choice
    printf("Enter your choice:\n");
    printf("1. Sort records by name\n");
    printf("2. Write records to a new file\n");
    scanf("%d", &choice);

    // Perform the chosen operation
    switch (choice) {
        case 1:
            sortRecords(records, numRecords);
            printf("Records sorted by name:\n");
            writeRecords(stdout, records, numRecords);
            break;
        case 2:
            printf("Enter the name of the new file: ");
            scanf("%s", filename);
            fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("Error: File not found.\n");
                exit(1);
            }
            writeRecords(fp, records, numRecords);
            fclose(fp);
            printf("Records written to file.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}