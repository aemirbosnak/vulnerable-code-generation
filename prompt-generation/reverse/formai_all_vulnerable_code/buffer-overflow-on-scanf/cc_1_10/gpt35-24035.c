//FormAI DATASET v1.0 Category: Database Indexing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LEN 30

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
} Record;

typedef struct {
    int id;
    int index;
} Index;

Index index_array[MAX_RECORDS];
int index_count = 0;

// function to add record to database and index to index array
void add_record(Record record) {
    FILE *db_file = fopen("database.txt", "a");
    fprintf(db_file, "%d %s\n", record.id, record.name);
    fclose(db_file);

    Index new_index;
    new_index.id = record.id;
    new_index.index = index_count;

    index_array[index_count] = new_index;
    index_count++;
}

// linear search function to find index of record with given id
int find_index(int id) {
    for (int i = 0; i < index_count; i++) {
        if (index_array[i].id == id) {
            return index_array[i].index;
        }
    }
    return -1;
}

// function to display record given its index in the file
void display_record(int index) {
    FILE *db_file = fopen("database.txt", "r");

    // move file pointer to the given line
    for (int i = 0; i < index; i++) {
        char buffer[MAX_NAME_LEN + 10];
        fgets(buffer, MAX_NAME_LEN + 10, db_file);
    }

    // read and display record at the given line
    int id;
    char name[MAX_NAME_LEN];
    fscanf(db_file, "%d %s", &id, name);
    printf("ID: %d   Name: %s\n", id, name);

    fclose(db_file);
}

// function to display all records in the database
void display_all_records() {
    FILE *db_file = fopen("database.txt", "r");

    int id;
    char name[MAX_NAME_LEN];

    while (fscanf(db_file, "%d %s", &id, name) != EOF) {
        printf("ID: %d   Name: %s\n", id, name);
    }

    fclose(db_file);
}

int main() {
    int choice;
    Record new_record;

    do {
        printf("\n1. Add new record\n");
        printf("2. Search for record\n");
        printf("3. Display all records\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter ID: ");
                scanf("%d", &new_record.id);
                printf("Enter name: ");
                scanf("%s", new_record.name);
                add_record(new_record);
                printf("\nRecord added successfully!\n");
                break;
            case 2:
                printf("\nEnter ID of record to search: ");
                int id;
                scanf("%d", &id);
                int index = find_index(id);
                if (index == -1) {
                    printf("\nRecord not found\n");
                } else {
                    printf("\nRecord found:\n");
                    display_record(index);
                }
                break;
            case 3:
                printf("\nAll records:\n");
                display_all_records();
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while (choice != 4);

    return 0;
}