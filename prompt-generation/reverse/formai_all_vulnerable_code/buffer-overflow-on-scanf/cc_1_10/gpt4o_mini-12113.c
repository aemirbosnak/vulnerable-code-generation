//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_NAME_LENGTH 100
#define MAX_TYPE_LENGTH 50

// A creature struct to hold individual creature information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char type[MAX_TYPE_LENGTH];
    int age;
} Creature;

// Callback function to display query results
static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

// Function to create a new database and a creatures table
void create_database() {
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("mythical_creatures.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    const char *sql = "CREATE TABLE IF NOT EXISTS Creatures(Id INTEGER PRIMARY KEY, Name TEXT, Type TEXT, Age INTEGER);";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL Error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    sqlite3_close(db);
}

// Function to insert a new creature into the database
void insert_creature(Creature creature) {
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("mythical_creatures.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO Creatures(Name, Type, Age) VALUES('%s', '%s', %d);", creature.name, creature.type, creature.age);

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL Error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
    else {
        printf("Creature added: %s\n", creature.name);
    }

    sqlite3_close(db);
}

// Function to query and display all creatures from the database
void query_creatures() {
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open("mythical_creatures.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    const char *sql = "SELECT * FROM Creatures;";

    rc = sqlite3_exec(db, sql, callback, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL Error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    sqlite3_close(db);
}

// Function to read creature details from user input
void read_creature(Creature *creature) {
    printf("Enter creature name: ");
    fgets(creature->name, MAX_NAME_LENGTH, stdin);
    creature->name[strcspn(creature->name, "\n")] = 0; // Remove newline

    printf("Enter creature type: ");
    fgets(creature->type, MAX_TYPE_LENGTH, stdin);
    creature->type[strcspn(creature->type, "\n")] = 0; // Remove newline

    printf("Enter creature age: ");
    scanf("%d", &creature->age);
    getchar(); // to consume newline after entering age
}

// Main function to run the program
int main() {
    create_database();

    char option;
    Creature creature;

    while (1) {
        printf("==== Mythical Creatures Database ====\n");
        printf("1. Add Creature\n");
        printf("2. List Creatures\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        option = getchar();
        getchar(); // Consume newline

        switch (option) {
            case '1':
                read_creature(&creature);
                insert_creature(creature);
                break;
            case '2':
                query_creatures();
                break;
            case '3':
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}