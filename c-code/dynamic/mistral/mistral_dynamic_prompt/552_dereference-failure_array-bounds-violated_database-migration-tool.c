#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_DB_NAME_LEN 50
#define MAX_TABLE_NAME_LEN 100
#define MAX_COLUMN_NAME_LEN 50
#define MAX_ROWS_IN_TABLE 1000

typedef struct Table {
    char name[MAX_TABLE_NAME_LEN];
    int num_cols;
    char **columns;
    int **data;
} Table;

Table database[MAX_DB_NAME_LEN];

void load_db() {
    strcpy(database[0].name, "example_db");
    database[0].num_cols = 3;
    database[0].columns = (char **)malloc(database[0].num_cols * sizeof(char *));
    database[0].data = (int **)malloc(database[0].num_cols * MAX_ROWS_IN_TABLE * sizeof(int *));

    database[0].columns[0] = "id";
    database[0].columns[1] = "name";
    database[0].columns[2] = "age";

    // Violating array bounds, assuming there are 1000 rows in the table
    for (int i = 0; i < MAX_ROWS_IN_TABLE; ++i) {
        database[0].data[0][i] = i; // Assigning to an invalid memory location of data array
        database[0].data[1][i] = i * 100; // Assigning to an invalid memory location of data array
        database[0].data[2][i] = i * 10000; // Assigning to an invalid memory location of data array
    }
}

int main() {
    load_db();

    // Accessing data out of bounds, assuming there are 1001 rows in the table
    printf("%d\n", database[0].data[0][1000]);

    return 0;
}
