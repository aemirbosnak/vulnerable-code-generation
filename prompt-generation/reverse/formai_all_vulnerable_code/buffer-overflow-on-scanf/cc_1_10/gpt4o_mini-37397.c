//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LEN 50
#define INDEX_FILE "index.dat"
#define DATA_FILE "data.dat"

typedef struct {
    int id;
    char name[NAME_LEN];
} Record;

typedef struct {
    int id;
    long offset;
} Index;

void create_index(FILE *data_file);
void add_record(FILE *data_file, Record record);
void display_records(FILE *data_file);
void search_by_name(FILE *data_file, const char *name);
void load_index(Index *index_array, int *record_count);

int main() {
    int choice;
    Record record;
    FILE *data_file;

    data_file = fopen(DATA_FILE, "a+");
    if (data_file == NULL) {
        fprintf(stderr, "Could not open data file.\n");
        return EXIT_FAILURE;
    }

    do {
        printf("\nDatabase Menu:\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record by Name\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &record.id);
                printf("Enter Name: ");
                scanf("%s", record.name);
                add_record(data_file, record);
                create_index(data_file);
                break;
            case 2:
                display_records(data_file);
                break;
            case 3:
                printf("Enter Name to Search: ");
                char search_name[NAME_LEN];
                scanf("%s", search_name);
                search_by_name(data_file, search_name);
                break;
            case 4:
                fclose(data_file);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return EXIT_SUCCESS;
}

void add_record(FILE *data_file, Record record) {
    fseek(data_file, 0, SEEK_END);
    fwrite(&record, sizeof(Record), 1, data_file);
    printf("Record added successfully.\n");
}

void display_records(FILE *data_file) {
    Record record;
    rewind(data_file);
    
    printf("\nDisplaying Records:\n");
    while (fread(&record, sizeof(Record), 1, data_file) == 1) {
        printf("ID: %d, Name: %s\n", record.id, record.name);
    }
}

void search_by_name(FILE *data_file, const char *name) {
    Record record;
    rewind(data_file);
    int found = 0;

    printf("\nSearching for Record with Name: %s\n", name);
    while (fread(&record, sizeof(Record), 1, data_file) == 1) {
        if (strcmp(record.name, name) == 0) {
            printf("Found Record - ID: %d, Name: %s\n", record.id, record.name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No record found with the name \"%s\".\n", name);
    }
}

void create_index(FILE *data_file) {
    Index index_array[MAX_RECORDS];
    Record record;
    int count = 0;

    rewind(data_file);
    while (fread(&record, sizeof(Record), 1, data_file) == 1) {
        index_array[count].id = record.id;
        index_array[count].offset = ftell(data_file) - sizeof(Record);
        count++;
    }

    // Save index to the file
    FILE *index_file = fopen(INDEX_FILE, "wb");
    if (index_file == NULL) {
        fprintf(stderr, "Could not open index file.\n");
        return;
    }
    fwrite(index_array, sizeof(Index), count, index_file);
    fclose(index_file);
}