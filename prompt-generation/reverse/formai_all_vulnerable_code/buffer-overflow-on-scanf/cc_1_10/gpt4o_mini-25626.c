//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Function to print the subcategories recursively
void printSubCategories(sqlite3 *db, int parentId, int level) {
    sqlite3_stmt *stmt;
    char *errMsg;

    // Prepare the SQL statement to select subcategories of the given parent category
    const char *sql = "SELECT id, name FROM categories WHERE parent_id = ?";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    // Bind the parent ID to the statement
    sqlite3_bind_int(stmt, 1, parentId);

    // Execute the statement and fetch results
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        
        // Print the category name with indentation based on level
        for (int i = 0; i < level; i++) {
            printf("  ");
        }
        printf("Category: %s (ID: %d)\n", name, id);

        // Recursive call to print subcategories of the current category
        printSubCategories(db, id, level + 1);
    }

    // Finalize the prepared statement
    sqlite3_finalize(stmt);
}

int main() {
    sqlite3 *db;
    char *errMsg = 0;

    // Open the SQLite database
    if (sqlite3_open("categories.db", &db)) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }

    // User input for a parent category ID
    int parentId;
    printf("Enter the parent category ID to view its subcategories: ");
    scanf("%d", &parentId);

    // Start fetching and printing subcategories
    printf("Subcategories of category ID %d:\n", parentId);
    printSubCategories(db, parentId, 0);

    // Close the database
    sqlite3_close(db);
    return 0;
}