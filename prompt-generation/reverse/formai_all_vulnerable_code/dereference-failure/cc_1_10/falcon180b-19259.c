//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>

struct person {
    char name[50];
    int age;
};

void print_person(struct person *p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

int main() {
    MYSQL *conn = NULL;
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    struct person people[100];
    int num_rows = 0;

    // Connect to the MySQL server
    if (!mysql_init(conn)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    if (!mysql_real_connect(conn, "localhost", "username", "password", "database", 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    // Query the database and retrieve the results
    if (!mysql_query(conn, "SELECT * FROM people")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    result = mysql_store_result(conn);

    while ((row = mysql_fetch_row(result))!= NULL) {
        strcpy(people[num_rows].name, row[0]);
        people[num_rows].age = atoi(row[1]);
        num_rows++;
    }

    // Print the results
    for (int i = 0; i < num_rows; i++) {
        print_person(&people[i]);
    }

    // Close the database connection
    mysql_close(conn);

    return 0;
}