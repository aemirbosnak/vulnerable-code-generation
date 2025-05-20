#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct Database {
    char *name;
    char *data;
    struct Database *next;
} Database;

Database *head = NULL;

void create_database(char *name, char *data) {
    Database *new_db = (Database *)malloc(sizeof(Database));
    new_db->name = name;
    new_db->data = data;
    new_db->next = head;
    head = new_db;
}

void print_databases() {
    Database *current = head;
    while (current != NULL) {
        printf("Database: %s\nData: %s\n", current->name, current->data);
        current = current->next;
    }
}

int main() {
    char *db_names[] = {"Database1", "Database2", "Database3"};
    char *db_data[] = {"secret1", "secret2", "secret3"};

    for (int i = 0; i < 3; i++) {
        create_database(db_names[i], db_data[i]);
    }

    print_databases();

    create_database("Database4", NULL);

    print_databases();

    return 0;
}
