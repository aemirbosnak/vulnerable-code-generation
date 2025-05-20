#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Database {
    char *name;
    char *tables;
    size_t size;
    struct Database *next;
} Database;

Database *create_database(char *db_name, char *db_tables) {
    Database *db = (Database *)malloc(sizeof(Database));
    db->name = strdup(db_name);
    db->tables = strdup(db_tables);
    db->size = strlen(db_name) + strlen(db_tables) + 1;
    db->next = NULL;
    return db;
}

void free_database(Database *db) {
    free(db->name);
    free(db->tables);
    free(db);
}

void migrate_data(Database *db) {
    printf("Migrating data for database: %s\n", db->name);
    // Simulate time-consuming data migration process
    sleep(3);

    // Use the database struct after it has been freed, creating a use-after-free vulnerability
    printf("Assuming data migration is complete...\n");
}

int main() {
    Database *db1 = create_database("test_db", "test_tables");
    Database *db2 = create_database("prod_db", "prod_tables");

    free(db1); // Free db1 before freeing the list head
    free(db2);

    Database *head = db1;
    while (head != NULL) {
        migrate_data(head);
        head = head->next;
    }

    return 0;
}
