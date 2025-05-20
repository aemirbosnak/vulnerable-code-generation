//FormAI DATASET v1.0 Category: Database Indexing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 1000

typedef struct {
    int id;
    char name[50];
    char email[50];
} Record;

typedef struct {
    int key;
    int index;
} Index;

int next_id = 1;
Record database[MAX_RECORDS];
Index index_table[MAX_RECORDS];

int insert(Record record);
void index_records();

int main() {
    int option;
    int id;
    char name[50];
    char email[50];
    int index;
    bool running = true;

    while (running) {
        printf("1. Insert record\n");
        printf("2. Find record by ID\n");
        printf("3. Find record by name\n");
        printf("4. Find record by email\n");
        printf("5. Quit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                insert((Record) { next_id++, name, email });
                index_records();
                printf("Record inserted.\n");
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                index = index_table[id - 1].index;
                if (index != -1) {
                    Record record = database[index];
                    printf("Record found: ID=%d, Name=%s, Email=%s\n", record.id, record.name, record.email);
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                for (int i = 0; i < MAX_RECORDS; i++) {
                    if (index_table[i].key != -1 && strcmp(database[index_table[i].index].name, name) == 0) {
                        Record record = database[index_table[i].index];
                        printf("Record found: ID=%d, Name=%s, Email=%s\n", record.id, record.name, record.email);
                    }
                }
                break;
            case 4:
                printf("Enter email: ");
                scanf("%s", email);
                for (int i = 0; i < MAX_RECORDS; i++) {
                    if (index_table[i].key != -1 && strcmp(database[index_table[i].index].email, email) == 0) {
                        Record record = database[index_table[i].index];
                        printf("Record found: ID=%d, Name=%s, Email=%s\n", record.id, record.name, record.email);
                    }
                }
                break;
            case 5:
                running = false;
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}

int insert(Record record) {
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (database[i].id == 0) {
            database[i] = record;
            return i;
        }
    }
    return -1;
}

void index_records() {
    for (int i = 0; i < MAX_RECORDS; i++) {
        index_table[i].key = -1;
        index_table[i].index = -1;
    }
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (database[i].id != 0) {
            index_table[database[i].id - 1].key = database[i].id;
            index_table[database[i].id - 1].index = i;
        }
    }
}