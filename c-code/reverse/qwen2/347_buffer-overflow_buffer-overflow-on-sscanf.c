#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

Record database[MAX_RECORDS];
int record_count = 0;

void add_record(int id, const char* name) {
    if (record_count >= MAX_RECORDS) return;
    database[record_count].id = id;
    strncpy(database[record_count].name, name, MAX_NAME_LENGTH - 1);
    database[record_count].name[MAX_NAME_LENGTH - 1] = '\0';
    record_count++;
}

void search_records(const char* query) {
    for (int i = 0; i < record_count; i++) {
        if (strstr(database[i].name, query)) {
            printf("ID: %d, Name: %s\n", database[i].id, database[i].name);
        }
    }
}

int main() {
    add_record(1, "Alice");
    add_record(2, "Bob");
    add_record(3, "Charlie");

    search_records("li"); // Should find Alice
    search_records("ar"); // Should find Charlie

    return 0;
}
