//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void create_table(sqlite3 *db) {
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS EMPLOYEE("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "NAME TEXT NOT NULL,"
                      "AGE INT NOT NULL);";
    
    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
}

void insert_employee(sqlite3 *db, const char *name, int age) {
    char *errMsg = 0;
    char sql[256];
    
    snprintf(sql, sizeof(sql), "INSERT INTO EMPLOYEE (NAME, AGE) VALUES ('%s', %d);", name, age);
    
    if (sqlite3_exec(db, sql, 0, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Inserted data successfully\n");
    }
}

void query_employee(sqlite3 *db, const char *name) {
    char *errMsg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "SELECT * FROM EMPLOYEE WHERE NAME='%s';", name);
    
    if (sqlite3_exec(db, sql, callback, 0, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
}

int main(int argc, char* argv[]) {
    sqlite3 *db;
    int exit = 0;
    
    exit = sqlite3_open("employee.db", &db);
    
    if (exit) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    create_table(db);

    char command[100];
    while (1) {
        printf("Enter 'add' to insert employee, 'query' to query employee, or 'exit' to quit: ");
        fgets(command, sizeof(command), stdin);
        if (strncmp(command, "exit", 4) == 0) {
            break;
        } else if (strncmp(command, "add", 3) == 0) {
            char name[50];
            int age;
            printf("Enter employee name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0; // Remove newline
            printf("Enter employee age: ");
            scanf("%d", &age);
            insert_employee(db, name, age);
            while (getchar() != '\n'); // Clear input buffer
        } else if (strncmp(command, "query", 5) == 0) {
            char name[50];
            printf("Enter employee name to query: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0; // Remove newline
            query_employee(db, name);
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }

    sqlite3_close(db);
    
    return 0;
}