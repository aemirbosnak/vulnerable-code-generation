//Falcon-180B DATASET v1.0 Category: Database querying ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mysql/mysql.h>

typedef struct {
    char *name;
    char *address;
    int age;
} Person;

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Address: %s\n", person->address);
    printf("Age: %d\n", person->age);
}

int main() {
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    Person *persons;
    int num_persons = 0;
    char query[100];

    // Connect to the database
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
        fprintf(stderr, "Error connecting to the database: %s\n", mysql_error(conn));
        exit(1);
    }

    // Retrieve all records from the "persons" table
    sprintf(query, "SELECT * FROM persons");
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Error querying the database: %s\n", mysql_error(conn));
        exit(1);
    }
    result = mysql_store_result(conn);

    // Allocate memory for the retrieved records
    persons = (Person*)malloc(sizeof(Person) * mysql_num_rows(result));
    if (!persons) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }

    // Fill the retrieved records with data
    while ((row = mysql_fetch_row(result))) {
        persons[num_persons].name = strdup(row[0]);
        persons[num_persons].address = strdup(row[1]);
        persons[num_persons].age = atoi(row[2]);
        num_persons++;
    }

    // Print the retrieved records
    for (int i = 0; i < num_persons; i++) {
        print_person(&persons[i]);
    }

    // Free the memory allocated for the retrieved records
    for (int i = 0; i < num_persons; i++) {
        free(persons[i].name);
        free(persons[i].address);
    }
    free(persons);

    // Close the database connection
    mysql_close(conn);

    return 0;
}