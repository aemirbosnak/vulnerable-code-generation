#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DB {
    char name[20];
    char data[1024];
} DB;

DB* createDB(const char* name, const char* data) {
    DB* db = (DB*) malloc(sizeof(DB));
    strcpy(db->name, name);
    strcpy(db->data, data);
    return db;
}

void printDB(DB* db) {
    printf("Database Name: %s\n", db->name);
    printf("Database Data: %s\n", db->data);
}

int main() {
    DB* db1 = createDB("test1", "some data");
    DB* db2 = createDB("test2", "other data");

    // Some arbitrary database operations...

    // Memory leak, dereferencing dangling pointer 'db1'
    printDB(db1);

    // Keep adding more databases to the list and perform operations...

    return 0;
}
