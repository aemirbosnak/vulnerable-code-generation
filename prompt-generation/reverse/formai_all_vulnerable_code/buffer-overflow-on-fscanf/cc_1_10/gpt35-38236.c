//FormAI DATASET v1.0 Category: Database querying ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declare struct for holding database records
typedef struct record{
    int id;
    char name[20];
    int age;
    char address[50];
} Record;

//Declare function prototype for querying database
void queryDb(char* name);

int main(){
    char nameToSearch[20];

    printf("Welcome to the Puzzling Database Query Program!\n");
    printf("Please enter the name of the person you are searching for:\n");
    scanf("%s", nameToSearch);

    //Call the queryDb function, passing the name to search as an argument
    queryDb(nameToSearch);

    return 0;
}

void queryDb(char* name){
    //Open the database file for reading
    FILE* dbFile = fopen("database.txt", "r");
    if(dbFile == NULL){
        printf("ERROR: Cannot open database file.\n");
        exit(1);
    }

    //Get the number of records in the database file
    int numOfRecords;
    fscanf(dbFile, "%d", &numOfRecords);

    //Allocate memory to hold the records
    Record* records = (Record*)malloc(numOfRecords * sizeof(Record));

    //Read each record from the database file
    int i;
    for(i = 0; i < numOfRecords; i++){
        fscanf(dbFile, "%d %s %d %s", &(records[i].id), records[i].name, &(records[i].age), records[i].address);
    }

    //Close the database file
    fclose(dbFile);

    //Search for the record with the matching name
    for(i = 0; i < numOfRecords; i++){
        if(strcmp(records[i].name, name) == 0){
            //If a match is found, print the record details
            printf("Record found!\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Address: %s\n", records[i].address);
            return;
        }
    }

    //If no match is found, print an error message
    printf("ERROR: Record not found.\n");

    //Free the memory allocated to the records array
    free(records);
}