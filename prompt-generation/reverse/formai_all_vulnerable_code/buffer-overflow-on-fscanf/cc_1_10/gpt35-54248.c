//FormAI DATASET v1.0 Category: Database simulation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECORDS 100

struct Record{
    int id;
    char name[20];
    int age;
};

int main(){
    FILE *filePointer;
    struct Record database[MAX_RECORDS];
    int numRecords = 0;

    // Read from file and populate the database array
    filePointer = fopen("data.txt", "r");
    if (filePointer == NULL){
        printf("File could not be opened.\n");
        exit(1);
    }
    while(!feof(filePointer)){
        fscanf(filePointer, "%d %s %d", &database[numRecords].id, database[numRecords].name, &database[numRecords].age);
        numRecords++;
    }
    fclose(filePointer);

    // Add records to the database
    struct Record newRecord;
    printf("Enter ID, name, and age of the new record: ");
    scanf("%d %s %d", &newRecord.id, newRecord.name, &newRecord.age);

    database[numRecords] = newRecord;
    numRecords++;

    // Write the updated database to file
    filePointer = fopen("data.txt", "w");
    if (filePointer == NULL){
        printf("File could not be opened.\n");
        exit(1);
    }
    for (int i = 0; i < numRecords; i++){
        fprintf(filePointer, "%d %s %d\n", database[i].id, database[i].name, database[i].age);
    }
    fclose(filePointer);

    // Display all records in the database
    printf("ID    Name    Age\n");
    for (int i = 0; i < numRecords; i++){
        printf("%d    %s    %d\n", database[i].id, database[i].name, database[i].age);
    }

    return 0;
}