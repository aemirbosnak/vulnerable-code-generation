//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Define the database file name
#define DB_FILE "scientific_database.db"

// Define the main function
int main() {
    // Open the database file
    sqlite3 *db;
    int rc = sqlite3_open(DB_FILE, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Prepare the SQL statement to query the database
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM experiments WHERE parameter = ? AND value > ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Bind the parameters to the SQL statement
    double parameter_value;
    printf("Enter the parameter value: ");
    scanf("%lf", &parameter_value);
    sqlite3_bind_double(stmt, 1, parameter_value);

    double value_threshold;
    printf("Enter the value threshold: ");
    scanf("%lf", &value_threshold);
    sqlite3_bind_double(stmt, 2, value_threshold);

    // Execute the SQL statement
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        // Retrieve the experiment data from the result row
        int experiment_id = sqlite3_column_int(stmt, 0);
        const char *experiment_name = (const char *) sqlite3_column_text(stmt, 1);
        double experiment_value = sqlite3_column_double(stmt, 2);

        // Print the experiment data
        printf("Experiment ID: %d\n", experiment_id);
        printf("Experiment Name: %s\n", experiment_name);
        printf("Experiment Value: %f\n", experiment_value);
        printf("\n");
    }

    // Finalize the SQL statement
    sqlite3_finalize(stmt);

    // Close the database file
    sqlite3_close(db);

    return 0;
}