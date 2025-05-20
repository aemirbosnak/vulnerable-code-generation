//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

#define DB_NAME "post_apocalypse.db"

typedef struct Survivor {
    int id;
    char name[50];
    int age;
    char equipment[50];
    char location[50];
} Survivor;

void create_database() {
    sqlite3 *db;
    char *err_msg = 0;

    int rc = sqlite3_open(DB_NAME, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    const char *sql = "CREATE TABLE IF NOT EXISTS Survivors (" \
                      "Id INTEGER PRIMARY KEY AUTOINCREMENT," \
                      "Name TEXT NOT NULL," \
                      "Age INTEGER NOT NULL," \
                      "Equipment TEXT NOT NULL," \
                      "Location TEXT NOT NULL);";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }

    sqlite3_close(db);
}

void add_survivor() {
    sqlite3 *db;
    char *err_msg = 0;
    Survivor survivor;

    printf("Enter Survivor Details:\n");
    printf("Name: ");
    fgets(survivor.name, sizeof(survivor.name), stdin);
    survivor.name[strcspn(survivor.name, "\n")] = 0; // Remove newline

    printf("Age: ");
    scanf("%d", &survivor.age);
    getchar(); // Consume the newline character

    printf("Equipment: ");
    fgets(survivor.equipment, sizeof(survivor.equipment), stdin);
    survivor.equipment[strcspn(survivor.equipment, "\n")] = 0;

    printf("Location: ");
    fgets(survivor.location, sizeof(survivor.location), stdin);
    survivor.location[strcspn(survivor.location, "\n")] = 0;

    int rc = sqlite3_open(DB_NAME, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char sql[256];
    snprintf(sql, sizeof(sql), "INSERT INTO Survivors (Name, Age, Equipment, Location) VALUES ('%s', %d, '%s', '%s');", 
             survivor.name, survivor.age, survivor.equipment, survivor.location);

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Survivor added successfully!\n");
    }

    sqlite3_close(db);
}

void list_survivors() {
    sqlite3 *db;
    sqlite3_stmt *stmt;

    int rc = sqlite3_open(DB_NAME, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    const char *sql = "SELECT * FROM Survivors;";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    printf("\nList of Survivors:\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        const unsigned char *equipment = sqlite3_column_text(stmt, 3);
        const unsigned char *location = sqlite3_column_text(stmt, 4);

        printf("ID: %d, Name: %s, Age: %d, Equipment: %s, Location: %s\n",
               id, name, age, equipment, location);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void survivor_menu() {
    int choice;

    do {
        printf("\nPost-Apocalyptic Survivor Database\n");
        printf("1. Add Survivor\n");
        printf("2. List Survivors\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                add_survivor();
                break;
            case 2:
                list_survivors();
                break;
            case 3:
                printf("Survivors will carry on...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);
}

int main() {
    create_database();
    survivor_menu();
    return 0;
}