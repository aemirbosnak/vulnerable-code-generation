#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Database {
    char *name;
    char *connection_string;
    struct Database *next;
} Database;

Database *head = NULL;

void add_database(char *name, char *connection_string) {
    Database *new_db = (Database *) malloc(sizeof(Database));
    new_db->name = name;
    new_db->connection_string = connection_string;
    new_db->next = head;
    head = new_db;
}

void print_databases() {
    Database *current = head;
    while (current != NULL) {
        printf("Database: %s\nConnection String: %s\n", current->name, current->connection_string);
        current = current->next;
    }
}

void free_databases() {
    Database *current = head;
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current->name);
        free(current->connection_string);
        free(current);
    }
    head = NULL;
}

int main() {
    add_database("TestDB", "test_connection_string");
    Database *db = (Database *) malloc(sizeof(Database));
    db->name = NULL;
    db->connection_string = "invalid_connection_string";
    db->next = head;
    head = db;
    print_databases();
    free_databases();
    return 0;
}
