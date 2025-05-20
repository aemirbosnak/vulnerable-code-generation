//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *zErrMsg = 0;

    int rc;

    // Create a database connection
    rc = sqlite3_open("spaceships.db", &db);
    if (rc) {
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // Create the spaceships table
    const char *sql = "CREATE TABLE spaceships (name TEXT PRIMARY KEY, manufacturer TEXT, model TEXT, maxSpeed INTEGER, maxRange INTEGER)";
    rc = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);
    if (rc) {
        printf("Can't create table: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 1;
    }

    // Insert some sample data into the table
    sql = "INSERT INTO spaceships (name, manufacturer, model, maxSpeed, maxRange) VALUES ('Millennium Falcon', 'YT-1300', 'Falcon', 150, 1000)";
    rc = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);
    if (rc) {
        printf("Can't insert data: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return 1;
    }

    // Close the database connection
    sqlite3_close(db);

    printf("Database created successfully!\n");

    // Command-line interface
    while (1) {
        printf("\nEnter command: ");
        char command[100];
        scanf("%s", command);

        // View data in the table
        if (strcmp(command, "view") == 0) {
            sqlite3 *db2;
            rc = sqlite3_open("spaceships.db", &db2);
            if (rc) {
                printf("Can't open database: %s\n", sqlite3_errmsg(db));
                return 1;
            }

            char query[100];
            sprintf(query, "SELECT name, manufacturer, model, maxSpeed, maxRange FROM spaceships");
            stmt = sqlite3_prepare(db2, query, -1, &zErrMsg, NULL);
            if (zErrMsg) {
                printf("Can't prepare query: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
                return 1;
            }

            while (1) {
                rc = sqlite3_step(stmt);
                if (rc == SQLITE_ROW) {
                    printf("Name: %s, Manufacturer: %s, Model: %s, MaxSpeed: %d, MaxRange: %d\n",
                            sqlite3_column_text(stmt, 0), sqlite3_column_text(stmt, 1),
                            sqlite3_column_text(stmt, 2), sqlite3_column_int(stmt, 3),
                            sqlite3_column_int(stmt, 4));
                } else {
                    break;
                }
            }

            sqlite3_finalize(stmt);
            sqlite3_close(db2);
            break;
        }

        // Add a new spaceship to the table
        else if (strcmp(command, "add") == 0) {
            printf("Enter name, manufacturer, model, maxSpeed, maxRange: ");
            char name[100], manufacturer[100], model[100], maxSpeed[100], maxRange[100];
            scanf("%s %s %s %s %s", name, manufacturer, model, maxSpeed, maxRange);

            sqlite3 *db2;
            rc = sqlite3_open("spaceships.db", &db2);
            if (rc) {
                printf("Can't open database: %s\n", sqlite3_errmsg(db));
                return 1;
            }

            char query[100];
            sprintf(query, "INSERT INTO spaceships (name, manufacturer, model, maxSpeed, maxRange) VALUES ('%s', '%s', '%s', %d, %d)",
                    name, manufacturer, model, atoi(maxSpeed), atoi(maxRange));
            stmt = sqlite3_prepare(db2, query, -1, &zErrMsg, NULL);
            if (zErrMsg) {
                printf("Can't prepare query: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
                return 1;
            }

            rc = sqlite3_step(stmt);
            if (rc == SQLITE_DONE) {
                printf("Spaceship added successfully!\n");
            } else {
                printf("Can't add spaceship: %s\n", sqlite3_errmsg(db));
                sqlite3_free(zErrMsg);
                return 1;
            }

            sqlite3_finalize(stmt);
            sqlite3_close(db2);
            break;
        }

        // Update an existing spaceship in the table
        else if (strcmp(command, "update") == 0) {
            printf("Enter name, manufacturer, model, maxSpeed, maxRange: ");
            char name[100], manufacturer[100], model[100], maxSpeed[100], maxRange[100];
            scanf("%s %s %s %s %s", name, manufacturer, model, maxSpeed, maxRange);

            sqlite3 *db2;
            rc = sqlite3_open("spaceships.db", &db2);
            if (rc) {
                printf("Can't open database: %s\n", sqlite3_errmsg(db));
                return 1;
            }

            char query[100];
            sprintf(query, "UPDATE spaceships SET name='%s', manufacturer='%s', model='%s', maxSpeed=%d, maxRange=%d WHERE name='%s'",
                    name, manufacturer, model, atoi(maxSpeed), atoi(maxRange), name);
            stmt = sqlite3_prepare(db2, query, -1, &zErrMsg, NULL);
            if (zErrMsg) {
                printf("Can't prepare query: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
                return 1;
            }

            rc = sqlite3_step(stmt);
            if (rc == SQLITE_DONE) {
                printf("Spaceship updated successfully!\n");
            } else {
                printf("Can't update spaceship: %s\n", sqlite3_errmsg(db));
                sqlite3_free(zErrMsg);
                return 1;
            }

            sqlite3_finalize(stmt);
            sqlite3_close(db2);
            break;
        }

        // Delete a spaceship from the table
        else if (strcmp(command, "delete") == 0) {
            printf("Enter name: ");
            char name[100];
            scanf("%s", name);

            sqlite3 *db2;
            rc = sqlite3_open("spaceships.db", &db2);
            if (rc) {
                printf("Can't open database: %s\n", sqlite3_errmsg(db));
                return 1;
            }

            char query[100];
            sprintf(query, "DELETE FROM spaceships WHERE name='%s'", name);
            stmt = sqlite3_prepare(db2, query, -1, &zErrMsg, NULL);
            if (zErrMsg) {
                printf("Can't prepare query: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
                return 1;
            }

            rc = sqlite3_step(stmt);
            if (rc == SQLITE_DONE) {
                printf("Spaceship deleted successfully!\n");
            } else {
                printf("Can't delete spaceship: %s\n", sqlite3_errmsg(db));
                sqlite3_free(zErrMsg);
                return 1;
            }

            sqlite3_finalize(stmt);
            sqlite3_close(db2);
            break;
        }

        // Invalid command
        else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}