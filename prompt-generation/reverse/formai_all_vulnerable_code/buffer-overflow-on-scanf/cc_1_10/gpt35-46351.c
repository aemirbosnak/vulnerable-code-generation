//FormAI DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RECORD_SIZE 50
#define BUFFER_SIZE 1024

struct record {
    int id;
    char name[20];
    char address[30];
};

struct index {
    int id;
    int offset;
};

// function prototypes
int create_index(FILE *db_file, FILE *index_file);
void add_record(FILE *db_file, FILE *index_file, struct record *rec);
void search_record(FILE *db_file, FILE *index_file, int id);

int main() {
    FILE *db_file, *index_file;
    struct record rec;
    char choice;
    int id;

    // open files in append mode
    db_file = fopen("data.dat", "a+b");
    index_file = fopen("index.dat", "a+b");

    if(db_file == NULL || index_file == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    // create index from database
    if(create_index(db_file, index_file) == -1) {
        printf("Error creating index.\n");
        exit(1);
    }

    while(1) {
        printf("\nEnter choice (a to add, s to search, q to quit): ");
        scanf(" %c", &choice);

        if(choice == 'q')
            break;

        switch(choice) {
            case 'a':
                // add record to database
                add_record(db_file, index_file, &rec);
                break;

            case 's':
                // search record in database
                printf("Enter ID to search: ");
                scanf("%d", &id);
                search_record(db_file, index_file, id);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    fclose(db_file);
    fclose(index_file);

    return 0;
}

// function to create index from database
int create_index(FILE *db_file, FILE *index_file) {
    struct record rec;
    struct index idx;
    int offset = 0;
    rewind(db_file);

    while(fread(&rec, RECORD_SIZE, 1, db_file) == 1) {
        idx.id = rec.id;
        idx.offset = offset;

        if(fwrite(&idx, sizeof(struct index), 1, index_file) != 1)
            return -1; // error writing index to file

        offset += RECORD_SIZE;
    }

    return 0;
}

// function to add record to database
void add_record(FILE *db_file, FILE *index_file, struct record *rec) {
    struct index idx;
    int offset;

    // get new record data
    printf("Enter ID: ");
    scanf("%d", &rec->id);
    printf("Enter name: ");
    scanf("%s", rec->name);
    printf("Enter address: ");
    scanf("%s", rec->address);

    // write record to database
    fseek(db_file, 0, SEEK_END);
    fwrite(rec, RECORD_SIZE, 1, db_file);

    // update index with new record
    idx.id = rec->id;
    offset = ftell(db_file) - RECORD_SIZE;
    idx.offset = offset;

    fwrite(&idx, sizeof(struct index), 1, index_file);

    printf("Record added.\n");
}

// function to search record in database
void search_record(FILE *db_file, FILE *index_file, int id) {
    struct record rec;
    struct index idx;
    int found = 0;

    rewind(index_file);

    while(fread(&idx, sizeof(struct index), 1, index_file) == 1) {
        if(idx.id == id) {
            fseek(db_file, idx.offset, SEEK_SET);
            fread(&rec, RECORD_SIZE, 1, db_file);
            printf("Record found:\n");
            printf("ID: %d\nName: %s\nAddress: %s\n", rec.id, rec.name, rec.address);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Record not found.\n");
}