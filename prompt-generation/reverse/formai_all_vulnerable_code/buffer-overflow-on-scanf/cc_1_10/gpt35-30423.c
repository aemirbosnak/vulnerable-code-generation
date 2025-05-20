//FormAI DATASET v1.0 Category: Database simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 10

// Define a struct for each record
typedef struct {
    int id;
    char name[50];
    char email[50];
} Record;

// Define the main database struct
typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

// Define database functions
void initialize_db(Database *db) {
    db->num_records = 0;
}

void add_record(Database *db, Record new_record) {
    if (db->num_records < MAX_RECORDS) {
        db->records[db->num_records++] = new_record;
    } else {
        printf("Error: database is full!\n");
    }
}

void delete_record(Database *db, int id_to_delete) {
    bool found_record = false;
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id_to_delete) {
            found_record = true;
            for (int j = i; j < db->num_records - 1; j++) {
                db->records[j] = db->records[j+1];
            }
            db->num_records--;
            printf("Deleted record with id %d.\n", id_to_delete);
            break;
        }
    }
    if (!found_record) {
        printf("Error: no record with id %d!\n", id_to_delete);
    }
}

void list_records(Database *db) {
    printf("ID\tName\t\tEmail\n");
    for (int i = 0; i < db->num_records; i++) {
        printf("%d\t%s\t\t%s\n", db->records[i].id, db->records[i].name, db->records[i].email);
    }
}

int main() {
    Database my_db;
    initialize_db(&my_db);
    
    // Add some initial records
    Record r1 = {1, "Alice", "alice@example.com"};
    add_record(&my_db, r1);
    Record r2 = {2, "Bob", "bob@example.com"};
    add_record(&my_db, r2);
    Record r3 = {3, "Charlie", "charlie@example.com"};
    add_record(&my_db, r3);
    
    printf("Welcome to the Mind-Bending Database Simulator!\n");
    printf("(Type 'help' for a list of commands.)\n");
    
    while (true) {
        // Read user input
        printf("> ");
        char input[50];
        scanf("%s", input);
        
        if (strcmp(input, "help") == 0) {
            printf("Available commands:\n");
            printf("  add <id> <name> <email>\n");
            printf("  delete <id>\n");
            printf("  list\n");
            printf("  help\n");
            printf("  exit\n");
        } else if (strcmp(input, "add") == 0) {
            // Read record info from user
            int id;
            char name[50];
            char email[50];
            scanf("%d %s %s", &id, name, email);
            Record new_record = {id, name, email};
            add_record(&my_db, new_record);
            printf("Added record with id %d.\n", id);
        } else if (strcmp(input, "delete") == 0) {
            // Read id to delete from user
            int id;
            scanf("%d", &id);
            delete_record(&my_db, id);
        } else if (strcmp(input, "list") == 0) {
            list_records(&my_db);
        } else if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Error: unknown command '%s'!\n", input);
        }
    }
    
    return 0;
}