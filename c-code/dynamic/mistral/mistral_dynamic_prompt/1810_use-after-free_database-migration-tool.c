#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Database {
    char *name;
    char *data;
    struct Database *next;
} Database;

void add_database(Database **head, char *name, char *data) {
    Database *new_db = (Database *)malloc(sizeof(Database));
    new_db->name = strdup(name);
    new_db->data = strdup(data);
    new_db->next = *head;
    *head = new_db;
}

void migrate(Database **head) {
    Database *current = *head;
    while (current != NULL) {
        printf("Migrating database: %s\n", current->name);
        process_data(current->data); // Use after free vulnerability occurs here
        current = current->next;
        free(current->name);
        free(current->data);
        free(current);
    }
    *head = NULL;
}

void process_data(char *data) { // Vulnerable function
    if (strstr(data, "secret_data")) {
        printf("Sensitive data found!\n");
    }
}

int main() {
    Database *db_list = NULL;

    add_database(&db_list, "db1", "data1");
    add_database(&db_list, "db2", "data2");
    add_database(&db_list, "db3", "secret_data"); // This database triggers the use-after-free vulnerability

    migrate(&db_list);

    return 0;
}
