//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 100
#define MAX_KEY_LEN 50
#define MAX_RECORDS 1000

typedef struct {
    char key[MAX_KEY_LEN];
    int record_id;
} IndexEntry;

typedef struct {
    int num_records;
    int num_indices;
    IndexEntry* index;
} Database;

void init_database(Database* db) {
    db->num_records = 0;
    db->num_indices = 0;
    db->index = (IndexEntry*)malloc(MAX_KEYS * sizeof(IndexEntry));
    memset(db->index, 0, MAX_KEYS * sizeof(IndexEntry));
}

void free_database(Database* db) {
    free(db->index);
}

int add_record(Database* db, char* key, int record_id) {
    IndexEntry* entry;
    int i;

    for (i = 0; i < db->num_indices; i++) {
        if (strcmp(db->index[i].key, key) == 0) {
            return -1; // key already exists
        }
    }

    if (db->num_indices >= MAX_KEYS) {
        printf("Error: Maximum number of keys reached\n");
        return -1;
    }

    entry = &db->index[db->num_indices];
    strcpy(entry->key, key);
    entry->record_id = record_id;
    db->num_indices++;

    return 0;
}

int search_record(Database* db, char* key, int* record_id) {
    IndexEntry* entry;
    int i;

    for (i = 0; i < db->num_indices; i++) {
        if (strcmp(db->index[i].key, key) == 0) {
            *record_id = db->index[i].record_id;
            return 0;
        }
    }

    return -1;
}

int main() {
    Database db;
    init_database(&db);

    int choice;
    while (1) {
        printf("1. Add Record\n2. Search Record\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char key[MAX_KEY_LEN];
            int record_id;
            printf("Enter Key: ");
            scanf("%s", key);
            printf("Enter Record ID: ");
            scanf("%d", &record_id);

            if (add_record(&db, key, record_id) == 0) {
                printf("Record added successfully\n");
            }
            break;
        }
        case 2: {
            char key[MAX_KEY_LEN];
            int record_id;
            printf("Enter Key: ");
            scanf("%s", key);

            if (search_record(&db, key, &record_id) == 0) {
                printf("Record ID: %d\n", record_id);
            } else {
                printf("Record not found\n");
            }
            break;
        }
        case 3:
            free_database(&db);
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}