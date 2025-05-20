//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char country[50];
    int id;
} Record;

int main() {
    FILE* db = fopen("records.bin", "wb+");
    if (!db) {
        printf("Error creating the database file!");
        return 1;
    }

    printf("Welcome to the Database Simulator!\n");

    int option = 0;
    while (option != 4) {
        printf("\nWhat would you like to do?\n1. Add record\n2. View records\n3. Delete record\n4. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                {
                    Record newRecord;
                    printf("\nEnter the name of the person: ");
                    scanf("%s", newRecord.name);
                    printf("Enter the age of the person: ");
                    scanf("%d", &newRecord.age);
                    printf("Enter the country of the person: ");
                    scanf("%s", newRecord.country);
                    printf("Enter the ID of the person: ");
                    scanf("%d", &newRecord.id);
                    fseek(db, 0, SEEK_END);
                    fwrite(&newRecord, sizeof(Record), 1, db);
                    printf("\nRecord added successfully!");
                    break;
                }
            case 2:
                {
                    fseek(db, 0, SEEK_SET);
                    Record currentRecord;
                    int recordCount = 0;
                    while (fread(&currentRecord, sizeof(Record), 1, db) == 1) {
                        printf("\nName: %s\n", currentRecord.name);
                        printf("Age: %d\n", currentRecord.age);
                        printf("Country: %s\n", currentRecord.country);
                        printf("ID: %d\n", currentRecord.id);
                        recordCount++;
                    }
                    if (recordCount == 0) {
                        printf("\nNo records found.");
                    }
                    break;
                }
            case 3:
                {
                    int recordID;
                    printf("\nEnter the ID of the record to delete: ");
                    scanf("%d", &recordID);
                    fseek(db, 0, SEEK_SET);
                    int recordFound = 0;
                    Record currentRecord;
                    while (fread(&currentRecord, sizeof(Record), 1, db) == 1) {
                        if (currentRecord.id == recordID) {
                            recordFound = 1;
                            break;
                        }
                    }
                    if (recordFound) {
                        fseek(db, -sizeof(Record), SEEK_CUR);
                        Record blankRecord = {"", 0, "", 0};
                        fwrite(&blankRecord, sizeof(Record), 1, db);
                        printf("\nRecord deleted successfully!");
                    } else {
                        printf("\nRecord not found.");
                    }
                    break;
                }
            case 4:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid option. Please try again.");
                break;
        }
    }

    fclose(db);
    return 0;
}