//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define KEY_LENGTH 50
#define DATA_LENGTH 100

typedef struct {
    char key[KEY_LENGTH];
    char data[DATA_LENGTH];
} Record;

typedef struct {
    Record* records[MAX_RECORDS];
    int count;
} Index;

Index *create_index() {
    Index *index = (Index *)malloc(sizeof(Index));
    index->count = 0;
    return index;
}

void free_index(Index *index) {
    for (int i = 0; i < index->count; i++) {
        free(index->records[i]);
    }
    free(index);
}

int insert_record(Index *index, const char *key, const char *data) {
    if (index->count >= MAX_RECORDS) {
        return -1; // Index full
    }
    Record *record = (Record *)malloc(sizeof(Record));
    strncpy(record->key, key, KEY_LENGTH);
    strncpy(record->data, data, DATA_LENGTH);
    index->records[index->count++] = record;
    return 0; // Success
}

Record* search_record(Index *index, const char *key) {
    for (int i = 0; i < index->count; i++) {
        if (strcmp(index->records[i]->key, key) == 0) {
            return index->records[i];
        }
    }
    return NULL; // Not found
}

void display_index(Index *index) {
    printf("\n--- Index Records ---\n");
    for (int i = 0; i < index->count; i++) {
        printf("Key: %s, Data: %s\n", index->records[i]->key, index->records[i]->data);
    }
    printf("----------------------\n");
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Index *index = create_index();
    char key[KEY_LENGTH], data[DATA_LENGTH];
    int choice;

    while (1) {
        printf("\n1. Insert Record\n2. Search Record\n3. Display Index\n4. Exit\nChoose an option: ");
        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            printf("Invalid input! Please choose a valid option.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter Key: ");
                clear_input_buffer();
                fgets(key, KEY_LENGTH, stdin);
                key[strcspn(key, "\n")] = 0; // Removing newline character
                printf("Enter Data: ");
                fgets(data, DATA_LENGTH, stdin);
                data[strcspn(data, "\n")] = 0; // Removing newline character
                if (insert_record(index, key, data) == -1) {
                    printf("Error: Index full, cannot insert new record.\n");
                } else {
                    printf("Record inserted successfully.\n");
                }
                break;
            case 2:
                printf("Enter Key to Search: ");
                clear_input_buffer();
                fgets(key, KEY_LENGTH, stdin);
                key[strcspn(key, "\n")] = 0; // Removing newline character
                Record *result = search_record(index, key);
                if (result) {
                    printf("Record Found: Key: %s, Data: %s\n", result->key, result->data);
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 3:
                display_index(index);
                break;
            case 4:
                free_index(index);
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}