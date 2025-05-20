//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#define MAX_QUERY_LENGTH 512

static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void create_table(sqlite3 *db) {
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS PERSONNEL("
                      "ID INT PRIMARY KEY NOT NULL,"
                      "NAME TEXT NOT NULL,"
                      "AGE INT NOT NULL);";

    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } 
}

void insert_person(sqlite3 *db, int id, const char *name, int age) {
    char sql[MAX_QUERY_LENGTH];
    char *errMsg = 0;

    snprintf(sql, sizeof(sql), "INSERT INTO PERSONNEL (ID, NAME, AGE) VALUES (%d, '%s', %d);",
             id, name, age);
    
    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        printf("Inserted: %d, %s, %d\n", id, name, age);
    }
}

void fetch_person(sqlite3 *db, int id) {
    char sql[MAX_QUERY_LENGTH];
    char *errMsg = 0;

    snprintf(sql, sizeof(sql), "SELECT * FROM PERSONNEL WHERE ID = %d;", id);
    
    if (sqlite3_exec(db, sql, callback, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

void print_menu() {
    printf("List of Actions:\n");
    printf("1. Insert Person\n");
    printf("2. Fetch Person\n");
    printf("3. Exit\n");
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("personnel.db", &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    create_table(db);

    while (1) {
        print_menu();
        int choice;
        printf("Choose an action (1-3): ");
        scanf("%d", &choice);
        
        if (choice == 3) {
            break;
        }

        switch (choice) {
            case 1: {
                int id;
                char name[100];
                int age;
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                insert_person(db, id, name, age);
                break;
            }
            case 2: {
                int id;
                printf("Enter ID to fetch: ");
                scanf("%d", &id);
                fetch_person(db, id);
                break;
            }
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    sqlite3_close(db);
    return 0;
}