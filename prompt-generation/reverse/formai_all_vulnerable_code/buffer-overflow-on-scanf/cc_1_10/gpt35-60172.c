//FormAI DATASET v1.0 Category: Database querying ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql/mysql.h>

int main(void) {
    MYSQL *conn = mysql_init(NULL);
    MYSQL_RES *result;
    MYSQL_ROW row;

    int month, year;
    char query[150]; // query string buffer

    // Connect to the database
    if (!mysql_real_connect(conn, "localhost", "user", "password", "sales_db", 0, NULL, 0)) {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        exit(1);
    }

    // Prompt user for input
    printf("Enter month and year (MM YY): ");
    scanf("%d %d", &month, &year);

    // Build the query
    sprintf(query, "SELECT product_name, SUM(quantity) as total_quantity FROM sales \
                    WHERE MONTH(sale_date)=%d AND YEAR(sale_date)=%d \
                    GROUP BY product_name ORDER BY total_quantity DESC LIMIT 5", month, year);

    // Execute the query
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error: %s\n", mysql_error(conn));
        exit(1);
    }

    // Get the result set
    result = mysql_store_result(conn);

    // Print the results
    printf("\nBest-selling products for %d-%d:\n", month, year);
    printf("---------------------------------------\n");
    while ((row = mysql_fetch_row(result))) {
        printf("%s: %s units\n", row[0], row[1]);
    }

    // Clean up
    mysql_free_result(result);
    mysql_close(conn);

    return 0;
}