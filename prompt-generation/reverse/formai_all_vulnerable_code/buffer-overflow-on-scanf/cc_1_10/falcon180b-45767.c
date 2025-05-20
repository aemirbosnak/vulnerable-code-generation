//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of records
#define MAX_RECORDS 100

// Define the structure of a record
typedef struct {
    int id;
    char name[50];
    float score;
} Record;

// Open the database file
FILE *open_database(char *filename) {
    FILE *db;
    
    db = fopen(filename, "rb");
    
    if (db == NULL) {
        printf("Error: Unable to open database file.\n");
        exit(1);
    }
    
    return db;
}

// Close the database file
void close_database(FILE *db) {
    fclose(db);
}

// Read a record from the database file
Record read_record(FILE *db) {
    Record record;
    
    fread(&record, sizeof(Record), 1, db);
    
    return record;
}

// Write a record to the database file
void write_record(FILE *db, Record record) {
    fwrite(&record, sizeof(Record), 1, db);
}

// Sort the records in ascending order based on their IDs
void sort_records(Record records[], int num_records) {
    int i, j;
    Record temp;
    
    for (i = 0; i < num_records - 1; i++) {
        for (j = i + 1; j < num_records; j++) {
            if (records[i].id > records[j].id) {
                temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }
}

// Print the records in the database file
void print_records(Record records[], int num_records) {
    int i;
    
    for (i = 0; i < num_records; i++) {
        printf("%d %s %.2f\n", records[i].id, records[i].name, records[i].score);
    }
}

int main() {
    char filename[50];
    FILE *db;
    Record records[MAX_RECORDS];
    int num_records = 0;
    
    // Prompt the user for the database file name
    printf("Enter the database file name: ");
    scanf("%s", filename);
    
    // Open the database file
    db = open_database(filename);
    
    // Read the records from the database file
    while (num_records < MAX_RECORDS && fread(&records[num_records], sizeof(Record), 1, db) == 1) {
        num_records++;
    }
    
    // Close the database file
    close_database(db);
    
    // Sort the records in ascending order based on their IDs
    sort_records(records, num_records);
    
    // Print the records in the database file
    printf("The records in the database file are:\n");
    print_records(records, num_records);
    
    return 0;
}