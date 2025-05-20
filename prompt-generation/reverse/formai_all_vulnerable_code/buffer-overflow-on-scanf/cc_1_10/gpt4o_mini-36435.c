//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

void print_book_details(int id, const char *title, const char *author, const char *year) {
    printf("\n---------------------------------\n");
    printf("ID: %d\n", id);
    printf("Title: %s\n", title);
    printf("Author: %s\n", author);
    printf("Year: %s\n", year);
    printf("---------------------------------\n");
}

int callback(void *data, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        if (argv[i]) {
            printf("%s = %s\n", azColName[i], argv[i]);
        } else {
            printf("%s = NULL\n", azColName[i]);
        }
    }
    return 0;
}

void query_books(sqlite3 *db, const char *query) {
    char *error_message = 0;
    int exit = sqlite3_exec(db, query, callback, 0, &error_message);

    if (exit != SQLITE_OK) {
        fprintf(stderr, "SQLite Error: %s\n", error_message);
        sqlite3_free(error_message);
    }
}

void create_table(sqlite3 *db) {
    const char *sql_create_table = "CREATE TABLE IF NOT EXISTS Books("
                                    "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                                    "Title TEXT NOT NULL,"
                                    "Author TEXT NOT NULL,"
                                    "Year TEXT NOT NULL);";
    char *error_message = 0;
    int exit = sqlite3_exec(db, sql_create_table, NULL, 0, &error_message);
    if (exit != SQLITE_OK) {
        fprintf(stderr, "Error creating table: %s\n", error_message);
        sqlite3_free(error_message);
    } 
}

void add_book(sqlite3 *db, const char *title, const char *author, const char *year) {
    char sql_insert[256];
    snprintf(sql_insert, sizeof(sql_insert), "INSERT INTO Books (Title, Author, Year) VALUES ('%s', '%s', '%s');", title, author, year);
    query_books(db, sql_insert);
}

void menu() {
    printf("\n1. Add new book\n");
    printf("2. Query all books\n");
    printf("3. Find a book by title\n");
    printf("4. Exit\n");
}

int main(int argc, char* argv[]) {
    sqlite3 *db;
    int exit = sqlite3_open("library.db", &db);
    
    if (exit) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return EXIT_FAILURE;
    } else {
        fprintf(stdout, "Opened database successfully!\n");
    }

    create_table(db);
    
    char title[100], author[100], year[10];
    int choice;

    while(1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book title: ");
                scanf(" %[^\n]%*c", title);
                printf("Enter book author: ");
                scanf(" %[^\n]%*c", author);
                printf("Enter book publication year: ");
                scanf(" %[^\n]%*c", year);
                add_book(db, title, author, year);
                printf("Book added successfully!\n");
                break;

            case 2: {
                const char *sql_query_all = "SELECT * FROM Books;";
                query_books(db, sql_query_all);
                break;
            }

            case 3:
                printf("Enter the title to search: ");
                scanf(" %[^\n]%*c", title);
                char sql_search[128];
                snprintf(sql_search, sizeof(sql_search), "SELECT * FROM Books WHERE Title LIKE '%%%s%%';", title);
                query_books(db, sql_search);
                break;

            case 4:
                printf("Exiting the library system. Farewell!\n");
                sqlite3_close(db);
                return EXIT_SUCCESS;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    sqlite3_close(db);
    return 0;
}