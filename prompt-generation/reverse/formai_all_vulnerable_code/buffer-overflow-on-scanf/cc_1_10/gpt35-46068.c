//FormAI DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 50

// define a struct for the data record
typedef struct {
    char name[20];
    int id;
    float score;
} Record;

// define a struct for the index record
typedef struct {
    int id;
    int offset;
} IndexRecord;

// function to create an index file
void createIndex(char *filename) {
    char indexFilename[MAXSIZE];
    strcpy(indexFilename, filename);

    // append .idx to create index file name
    strcat(indexFilename, ".idx");

    FILE *fp, *indexfp;
    Record record;
    IndexRecord index;
    int offset = 0;

    // open the data file for reading
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Unable to open file!\n");
        return;
    }

    // create the index file for writing
    indexfp = fopen(indexFilename, "wb");
    if (indexfp == NULL) {
        printf("Unable to create index file!\n");
        return;
    }

    // read the data file record by record
    while(fread(&record, sizeof(Record), 1, fp)) {
        // set the values for the index record
        index.id = record.id;
        index.offset = offset;

        // write the index record to the index file
        fwrite(&index, sizeof(IndexRecord), 1, indexfp);

        // update the offset after writing each record
        offset = ftell(fp);
    }

    // close both files
    fclose(fp);
    fclose(indexfp);

    printf("Index file created successfully!\n");
}

// function to search for a record by id
void searchById(char *filename, int id) {
    char indexFilename[MAXSIZE];
    strcpy(indexFilename, filename);

    // append .idx to the file name to get index file name
    strcat(indexFilename, ".idx");

    FILE *fp, *indexfp;
    Record record;
    IndexRecord index;
    int found = 0;

    // open the index file for reading
    indexfp = fopen(indexFilename, "rb");
    if (indexfp == NULL) {
        printf("Unable to open index file!\n");
        return;
    }

    // read the index file record by record
    while(fread(&index, sizeof(IndexRecord), 1, indexfp)) {
        // if the id matches, move to the corresponding offset in the data file
        if (index.id == id) {
            fp = fopen(filename, "rb");
            if (fp == NULL) {
                printf("Unable to open file!\n");
                return;
            }

            fseek(fp, index.offset, SEEK_SET);
            fread(&record, sizeof(Record), 1, fp);

            printf("Record found:\n");
            printf("Name: %s\n", record.name);
            printf("Id: %d\n", record.id);
            printf("Score: %.2f\n", record.score);

            found = 1;

            fclose(fp);

            break;
        }
    }

    if (!found) {
        printf("Record with id %d not found!\n", id);
    }

    fclose(indexfp);
}

int main() {
    char filename[MAXSIZE];
    int choice, id;
    printf("Enter the name of the data file: ");
    scanf("%s", filename);

    while(1) {
        printf("\n1. Create index file\n");
        printf("2. Search for a record by id\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createIndex(filename);
                break;
            case 2:
                printf("Enter the id to search for: ");
                scanf("%d", &id);
                searchById(filename, id);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}