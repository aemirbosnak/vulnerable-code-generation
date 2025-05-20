//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define structure representing the indexed record
struct Record {
    int key;
    char name[20];
    char address[50];
};

//Define structure representing the index record
struct IndexRecord {
    int key;
    int offset;
};

//Constants
const int RECORD_SIZE = sizeof(struct Record);
const int INDEX_SIZE = sizeof(struct IndexRecord);
const int MAX_RECORDS = 100;
const int MAX_INDEX = 50;

//Global file pointer variables
FILE *dataFile;
FILE *indexFile;

//Function declarations
void insertRecord(struct Record, int);
void updateRecord(int);
void deleteRecord(int);
void displayRecord(int);
void displayAll();
void indexFileCreation();
void indexRecordInsert(struct IndexRecord);
int getIndexRecord(int);

//Main function
int main() {
    //Open data file
    dataFile = fopen("data.txt", "rb+");
    if (dataFile == NULL) {
        dataFile = fopen("data.txt", "wb+");
    }

    //Open index file
    indexFile = fopen("index.txt", "rb+");
    if (indexFile == NULL) {
        indexFile = fopen("index.txt", "wb+");
        indexFileCreation();
    }

    //Display menu and get user input
    int option, key;
    struct Record record;
    printf("\nDATABASE INDEXING SYSTEM\n");
    while (1) {
        printf("\nSELECT AN OPTION:\n");
        printf("1 - INSERT RECORD\n");
        printf("2 - UPDATE RECORD\n");
        printf("3 - DELETE RECORD\n");
        printf("4 - DISPLAY RECORD\n");
        printf("5 - DISPLAY ALL RECORDS\n");
        printf("6 - EXIT\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nINSERT RECORD\n");
                printf("KEY: ");
                scanf("%d", &record.key);
                printf("NAME: ");
                scanf("%s", record.name);
                printf("ADDRESS: ");
                scanf("%s", record.address);
                insertRecord(record, 0);
                break;

            case 2:
                printf("\nUPDATE RECORD\n");
                printf("KEY: ");
                scanf("%d", &key);
                updateRecord(key);
                break;

            case 3:
                printf("\nDELETE RECORD\n");
                printf("KEY: ");
                scanf("%d", &key);
                deleteRecord(key);
                break;

            case 4:
                printf("\nDISPLAY RECORD\n");
                printf("KEY: ");
                scanf("%d", &key);
                displayRecord(key);
                break;

            case 5:
                printf("\nDISPLAY ALL RECORDS\n");
                displayAll();
                break;

            case 6:
                fclose(dataFile);
                fclose(indexFile);
                exit(0);

            default:
                printf("\nINVALID OPTION\n");
                break;
        }
    }
}

//Insert record into data file and index file
void insertRecord(struct Record record, int offset) {
    fseek(dataFile, 0, SEEK_END);
    fwrite(&record, RECORD_SIZE, 1, dataFile);
    indexRecordInsert((struct IndexRecord){record.key, ftell(dataFile) - RECORD_SIZE});
}

//Update record in data file based on key
void updateRecord(int key) {
    int offset = getIndexRecord(key);
    if (offset == -1) {
        printf("\nRECORD NOT FOUND\n");
        return;
    }

    struct Record record;
    fseek(dataFile, offset, SEEK_SET);
    fread(&record, RECORD_SIZE, 1, dataFile);

    printf("NAME: %s", record.name);
    scanf("%s", record.name);
    printf("ADDRESS: %s", record.address);
    scanf("%s", record.address);

    fseek(dataFile, offset, SEEK_SET);
    fwrite(&record, RECORD_SIZE, 1, dataFile);
}

//Delete record from data file and index file based on key
void deleteRecord(int key) {
    int offset = getIndexRecord(key);
    if (offset == -1) {
        printf("\nRECORD NOT FOUND\n");
        return;
    }

    struct Record record;
    fseek(dataFile, offset, SEEK_SET);
    fread(&record, RECORD_SIZE, 1, dataFile);

    int index = getIndexRecord(key);
    fseek(indexFile, index * INDEX_SIZE, SEEK_SET);
    fwrite(-1, INDEX_SIZE, 1, indexFile);

    printf("\nDELETE SUCCESSFUL\n");
}

//Display record based on key
void displayRecord(int key) {
    int offset = getIndexRecord(key);
    if (offset == -1) {
        printf("\nRECORD NOT FOUND\n");
        return;
    }

    struct Record record;
    fseek(dataFile, offset, SEEK_SET);
    fread(&record, RECORD_SIZE, 1, dataFile);

    printf("\nKEY: %d\n", record.key);
    printf("NAME: %s\n", record.name);
    printf("ADDRESS: %s\n", record.address);
}

//Display all records in data file
void displayAll() {
    int count = 0;
    struct Record record;
    fseek(dataFile, 0, SEEK_SET);
    while (fread(&record, RECORD_SIZE, 1, dataFile)) {
        if (record.key != -1) {
            printf("\nKEY: %d\n", record.key);
            printf("NAME: %s\n", record.name);
            printf("ADDRESS: %s\n", record.address);
            count++;
        }
    }

    if (count == 0) {
        printf("\nNO RECORDS FOUND\n");
    }
}

//Create index file
void indexFileCreation() {
    struct IndexRecord nullIndexRecord = {-1, -1};
    for (int i = 0; i < MAX_INDEX; i++) {
        fwrite(&nullIndexRecord, INDEX_SIZE, 1, indexFile);
    }
}

//Insert record into index file
void indexRecordInsert(struct IndexRecord indexRecord) {
    int index = indexRecord.key % MAX_INDEX;
    fseek(indexFile, index * INDEX_SIZE, SEEK_SET);
    struct IndexRecord currentRecord;
    for (int i = 0; i < MAX_INDEX; i++) {
        fread(&currentRecord, INDEX_SIZE, 1, indexFile);
        if (currentRecord.key == -1 || currentRecord.key == indexRecord.key) {
            fseek(indexFile, index * INDEX_SIZE, SEEK_SET);
            fwrite(&indexRecord, INDEX_SIZE, 1, indexFile);
            printf("\nINSERT SUCCESSFUL\n");
            return;
        }
        index = (index + 1) % MAX_INDEX;
        fseek(indexFile, index * INDEX_SIZE, SEEK_SET);
    }
    printf("\nINDEX FILE IS FULL\n");
}

//Get offset of record in data file based on key from index file
int getIndexRecord(int key) {
    int index = key % MAX_INDEX;
    fseek(indexFile, index * INDEX_SIZE, SEEK_SET);
    struct IndexRecord currentRecord;
    for (int i = 0; i < MAX_INDEX; i++) {
        fread(&currentRecord, INDEX_SIZE, 1, indexFile);
        if (currentRecord.key == key) {
            return currentRecord.offset;
        }
        else if (currentRecord.key == -1) {
            return -1;
        }
        index = (index + 1) % MAX_INDEX;
        fseek(indexFile, index * INDEX_SIZE, SEEK_SET);
    }
    return -1;
}