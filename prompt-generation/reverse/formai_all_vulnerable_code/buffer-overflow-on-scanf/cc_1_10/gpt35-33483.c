//FormAI DATASET v1.0 Category: Database Indexing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE_LENGTH 20
#define MAX_KEY_LENGTH 10
#define MAX_RECORDS 100

typedef struct Record {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct Index {
    char key[MAX_KEY_LENGTH];
    int offset;
    int count;
} Index;

void create_index_file(FILE *data_file, FILE *index_file) {
    int num_records, i, j;
    long int offset;
    char buffer[MAX_VALUE_LENGTH];
    Record record;
    Index index[MAX_RECORDS], temp_index;
    
    // Count the number of records in the data file
    fseek(data_file, 0, SEEK_END);
    num_records = ftell(data_file) / sizeof(Record);
    fseek(data_file, 0, SEEK_SET);
    
    // Read the records into memory and sort them by key
    for (i = 0; i < num_records; i++) {
        fread(&record, sizeof(Record), 1, data_file);
        strcpy(index[i].key, record.key);
        index[i].offset = ftell(data_file) - sizeof(Record);
    }
    for (i = 0; i < num_records - 1; i++) {
        for (j = i + 1; j < num_records; j++) {
            if (strcmp(index[i].key, index[j].key) > 0) {
                temp_index = index[i];
                index[i] = index[j];
                index[j] = temp_index;
            }
        }
    }
    
    // Write the sorted index to the index file
    for (i = 0; i < num_records; i++) {
        offset = index[i].offset;
        index[i].count = 1;
        while (fread(&record, sizeof(Record), 1, data_file)) {
            if (strcmp(index[i].key, record.key) != 0) {
                fseek(data_file, offset, SEEK_SET);
                break;
            }
            index[i].count++;
        }
        fseek(data_file, offset, SEEK_SET);
        fwrite(&record, sizeof(Record), 1, data_file);
        sprintf(buffer, "%s %d %d\n", index[i].key, index[i].offset, index[i].count);
        fwrite(buffer, strlen(buffer), 1, index_file);
    }
}

void search_index_file(FILE *index_file, FILE *data_file, char *search_key) {
    char buffer[MAX_KEY_LENGTH + MAX_VALUE_LENGTH + 10];
    char key[MAX_KEY_LENGTH];
    int offset, count, i, found = 0;
    Record record;
    
    while (fgets(buffer, MAX_KEY_LENGTH + MAX_VALUE_LENGTH + 10, index_file)) {
        sscanf(buffer, "%s %d %d", key, &offset, &count);
        if (strcmp(search_key, key) == 0) {
            found = 1;
            fseek(data_file, offset, SEEK_SET);
            for (i = 0; i < count; i++) {
                fread(&record, sizeof(Record), 1, data_file);
                printf("%s: %s\n", record.key, record.value);
            }
            break;
        }
    }
    if (!found) {
        printf("No records found with key %s\n", search_key);
    }
}

int main() {
    FILE *data_file, *index_file;
    char command[10], key[MAX_KEY_LENGTH];
    
    // Open the data file and index file
    data_file = fopen("data.dat", "rb+");
    index_file = fopen("index.txt", "w+");
    
    // Generate the index file if it doesn't exist
    if (fgetc(index_file) == EOF) {
        rewind(data_file);
        create_index_file(data_file, index_file);
    }
    
    // Read commands from user
    printf("Enter command (search, exit): ");
    scanf("%s", command);
    
    while (strcmp(command, "exit") != 0) {
        if (strcmp(command, "search") == 0) {
            printf("Enter key to search for: ");
            scanf("%s", key);
            search_index_file(index_file, data_file, key);
        } else {
            printf("Invalid command. Try again.\n");
        }
        printf("Enter command (search, exit): ");
        scanf("%s", command);
    }
    
    // Close files and exit
    fclose(data_file);
    fclose(index_file);
    return 0;
}