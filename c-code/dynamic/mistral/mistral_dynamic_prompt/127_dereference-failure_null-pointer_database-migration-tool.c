#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Database {
    char *name;
    int size;
    char **data;
} Database;

Database *init_database(const char *db_name, int size) {
    Database *db = malloc(sizeof(Database));
    db->name = strdup(db_name);
    db->size = size;
    db->data = calloc(db->size, sizeof(char *));
    return db;
}

void free_database(Database *db) {
    for (int i = 0; i < db->size; ++i) {
        free(db->data[i]);
    }
    free(db->data);
    free(db->name);
    free(db);
}

void insert_data(Database *db, const char *data, int index) {
    db->data[index] = strdup(data);
}

int main() {
    Database *db = init_database("TestDB", 5);

    // Random index usage without bounds checking
    insert_data(db, "Secret SQL injection vulnerability!", 10);

    // Null pointer dereference for fun
    printf("%s\n", db->data[-1]);

    free_database(db);
    return 0;
}
