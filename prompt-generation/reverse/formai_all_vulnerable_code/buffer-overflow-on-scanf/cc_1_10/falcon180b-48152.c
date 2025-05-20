//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure of a record
struct Record {
    int id;
    char name[50];
    char address[100];
    int phone;
};

// Function to compare two records based on their IDs
int compare(const void* a, const void* b) {
    struct Record* record1 = (struct Record*)a;
    struct Record* record2 = (struct Record*)b;

    if(record1->id < record2->id)
        return -1;
    else if(record1->id > record2->id)
        return 1;
    else
        return 0;
}

// Function to display the records in the database
void displayRecords(struct Record* records, int numRecords) {
    printf("ID\tName\tAddress\tPhone\n");
    for(int i=0; i<numRecords; i++) {
        printf("%d\t%s\t%s\t%d\n", records[i].id, records[i].name, records[i].address, records[i].phone);
    }
}

// Function to search for a record in the database
int searchRecord(struct Record* records, int numRecords, int id) {
    struct Record* result = bsearch(&id, records, numRecords, sizeof(struct Record), compare);
    if(result!= NULL)
        return 1;
    else
        return 0;
}

// Function to add a record to the database
void addRecord(struct Record* records, int* numRecords) {
    printf("Enter ID: ");
    scanf("%d", &records[*numRecords].id);
    printf("Enter Name: ");
    scanf("%s", records[*numRecords].name);
    printf("Enter Address: ");
    scanf("%s", records[*numRecords].address);
    printf("Enter Phone: ");
    scanf("%d", &records[*numRecords].phone);

    (*numRecords)++;
}

// Function to delete a record from the database
void deleteRecord(struct Record* records, int* numRecords) {
    printf("Enter ID of record to delete: ");
    int id;
    scanf("%d", &id);

    int index = searchRecord(records, *numRecords, id);
    if(index!= 0) {
        for(int i=index; i<*numRecords-1; i++) {
            records[i] = records[i+1];
        }
        (*numRecords)--;
    }
    else
        printf("Record not found.\n");
}

int main() {
    int numRecords = 0;
    struct Record records[100];

    addRecord(records, &numRecords);
    addRecord(records, &numRecords);
    addRecord(records, &numRecords);

    displayRecords(records, numRecords);

    deleteRecord(records, &numRecords);

    displayRecords(records, numRecords);

    return 0;
}