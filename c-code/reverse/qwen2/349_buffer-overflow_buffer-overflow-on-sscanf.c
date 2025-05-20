#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define KEY_SIZE 50
#define VALUE_SIZE 200

typedef struct {
    char key[KEY_SIZE];
    char value[VALUE_SIZE];
} Record;

Record database[MAX_RECORDS];
int record_count = 0;

void add_record(const char *key, const char *value) {
    if (record_count >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }
    strcpy(database[record_count].key, key);
    strcpy(database[record_count].value, value);
    record_count++;
}

char* search_record(const char *key) {
    for (int i = 0; i < record_count; i++) {
        if (strcmp(database[i].key, key) == 0) {
            return database[i].value;
        }
    }
    return NULL;
}

int main() {
    add_record("name", "Alice");
    add_record("age", "30");
    add_record("city", "New York");

    char query[KEY_SIZE];
    while (1) {
        printf("Enter key to search (or 'exit' to quit): ");
        scanf("%s", query);
        if (strcmp(query, "exit") == 0) {
            break;
        }
        char *result = search_record(query);
        if (result != NULL) {
            printf("Value: %s\n", result);
        } else {
            printf("Key not found.\n");
        }
    }

    return 0;
}
