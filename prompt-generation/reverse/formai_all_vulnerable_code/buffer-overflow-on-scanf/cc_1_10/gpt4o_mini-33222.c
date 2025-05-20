//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} UserRecord;

typedef struct {
    UserRecord records[MAX_RECORDS];
    int count;
} UserDatabase;

typedef struct {
    int index;
    char name[NAME_LENGTH];
} NameIndexEntry;

typedef struct {
    NameIndexEntry entries[MAX_RECORDS];
    int count;
} NameIndex;

void init_database(UserDatabase *db) {
    db->count = 0;
}

void init_index(NameIndex *index) {
    index->count = 0;
}

void add_record(UserDatabase *db, NameIndex *index, const char *name, const char *email) {
    if (db->count < MAX_RECORDS) {
        strncpy(db->records[db->count].name, name, NAME_LENGTH);
        strncpy(db->records[db->count].email, email, EMAIL_LENGTH);
        
        index->entries[index->count].index = db->count;
        strncpy(index->entries[index->count].name, name, NAME_LENGTH);
        index->count++;

        db->count++;
    } else {
        printf("Database is full!\n");
    }
}

void sort_index(NameIndex *index) {
    for (int i = 0; i < index->count - 1; i++) {
        for (int j = i + 1; j < index->count; j++) {
            if (strcmp(index->entries[i].name, index->entries[j].name) > 0) {
                NameIndexEntry temp = index->entries[i];
                index->entries[i] = index->entries[j];
                index->entries[j] = temp;
            }
        }
    }
}

int binary_search_index(NameIndex *index, const char *name) {
    int left = 0;
    int right = index->count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(name, index->entries[mid].name);

        if (cmp == 0) {
            return index->entries[mid].index;
        } 
        else if (cmp < 0) {
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }
    return -1; // Not found
}

void display_record(const UserRecord *record) {
    printf("Name: %s\n", record->name);
    printf("Email: %s\n", record->email);
}

void search_record(UserDatabase *db, NameIndex *index, const char *name) {
    int index_pos = binary_search_index(index, name);
    if (index_pos != -1) {
        display_record(&db->records[index_pos]);
    } else {
        printf("Record not found for Name: %s\n", name);
    }
}

void display_all_records(UserDatabase *db) {
    for (int i = 0; i < db->count; i++) {
        display_record(&db->records[i]);
        printf("\n");
    }
}

int main() {
    UserDatabase db;
    NameIndex index;
    
    init_database(&db);
    init_index(&index);

    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
    
    int choice;
    do {
        printf("1. Add Record\n");
        printf("2. Search Record by Name\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter email: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                add_record(&db, &index, name, email);
                sort_index(&index);
                break;
            case 2:
                printf("Enter name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                search_record(&db, &index, name);
                break;
            case 3:
                display_all_records(&db);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 4);
    
    return 0;
}