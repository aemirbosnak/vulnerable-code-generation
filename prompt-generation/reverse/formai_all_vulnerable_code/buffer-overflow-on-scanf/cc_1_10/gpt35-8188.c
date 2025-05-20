//FormAI DATASET v1.0 Category: Database Indexing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* defining a structure for the database */
struct Database {
    int id;
    char name[50];
    int age;
};

/* defining a structure for the index */
struct Index {
    int id;
    int offset;
};

/* function to add data to the database */
int addData(FILE *dbFile) {
    struct Database record;
    printf("\nEnter ID: ");
    scanf("%d", &record.id);
    printf("Enter Name: ");
    scanf("%s", record.name);
    printf("Enter Age: ");
    scanf("%d", &record.age);
    fseek(dbFile, 0, SEEK_END);
    fwrite(&record, sizeof(struct Database), 1, dbFile);
}

/* function to search for a record in the database */
int searchRecord(FILE *dbFile, int id) {
    struct Database record;
    int found = 0;
    fseek(dbFile, 0, SEEK_SET);
    while (fread(&record, sizeof(struct Database), 1, dbFile)) {
        if (record.id == id) {
            found = 1;
            printf("Record found:\n");
            printf("ID: %d\n", record.id);
            printf("Name: %s\n", record.name);
            printf("Age: %d\n", record.age);
        }
    }
    if (!found) {
        printf("Record not found.\n");
    }
}

/* function to create the index */
int createIndex(FILE *dbFile, FILE *indexFile) {
    struct Database record;
    struct Index indexRecord;
    int offset;
    fseek(dbFile, 0, SEEK_SET);
    while (fread(&record, sizeof(struct Database), 1, dbFile)) {
        indexRecord.id = record.id;
        offset = ftell(dbFile) - sizeof(struct Database);
        indexRecord.offset = offset;
        fwrite(&indexRecord, sizeof(struct Index), 1, indexFile);
    }
}

/* function to search using the index */
int searchUsingIndex(FILE *dbFile, FILE *indexFile, int id) {
    struct Index indexRecord;
    struct Database record;
    int found = 0;
    fseek(indexFile, 0, SEEK_SET);
    while (fread(&indexRecord, sizeof(struct Index), 1, indexFile)) {
        if (indexRecord.id == id) {
            found = 1;
            fseek(dbFile, indexRecord.offset, SEEK_SET);
            fread(&record, sizeof(struct Database), 1, dbFile);
            printf("Record found:\n");
            printf("ID: %d\n", record.id);
            printf("Name: %s\n", record.name);
            printf("Age: %d\n", record.age);
            break;
        }
    }
    if (!found) {
        printf("Record not found.\n");
    }
}

/* main function */
int main() {
    FILE *dbFile, *indexFile;
    char *dbFileName = "database.txt";
    char *indexFileName = "index.txt";
    int choice, id;
    dbFile = fopen(dbFileName, "a+");
    if (dbFile == NULL) {
        printf("Error opening database file.\n");
        exit(1);
    }
    indexFile = fopen(indexFileName, "a+");
    if (indexFile == NULL) {
        printf("Error opening index file.\n");
        exit(1);
    }
    while (1) {
        printf("\nMenu\n");
        printf("1. Add Data to database\n");
        printf("2. Search Record\n");
        printf("3. Create Index\n");
        printf("4. Search using Index\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addData(dbFile);
                break;
            case 2:
                printf("\nEnter ID to search: ");
                scanf("%d", &id);
                searchRecord(dbFile, id);
                break;
            case 3:
                createIndex(dbFile, indexFile);
                break;
            case 4:
                printf("\nEnter ID to search: ");
                scanf("%d", &id);
                searchUsingIndex(dbFile, indexFile, id);
                break;
            case 5:
                printf("Exiting...\n");
                fclose(dbFile);
                fclose(indexFile);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}