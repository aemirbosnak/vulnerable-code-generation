//Falcon-180B DATASET v1.0 Category: Database querying ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_SIZE 1000
#define MAX_COLUMNS 100
#define MAX_ROWS 1000
#define MAX_FIELD_SIZE 100

struct query {
    char query_string[MAX_QUERY_SIZE];
    int num_columns;
    char columns[MAX_COLUMNS][MAX_FIELD_SIZE];
    int num_rows;
    int rows[MAX_ROWS];
};

void print_query(struct query* q) {
    printf("Query: %s\n", q->query_string);
    printf("Number of columns: %d\n", q->num_columns);
    for (int i = 0; i < q->num_columns; ++i) {
        printf("Column %d: %s\n", i+1, q->columns[i]);
    }
    printf("Number of rows: %d\n", q->num_rows);
    for (int i = 0; i < q->num_rows; ++i) {
        printf("Row %d: ", i+1);
        for (int j = 0; j < q->num_columns; ++j) {
            printf("%d ", q->rows[i*q->num_columns + j]);
        }
        printf("\n");
    }
}

int main() {
    struct query q;
    char input[MAX_QUERY_SIZE];
    int pos = 0;

    printf("Enter a SQL query:\n");
    fgets(input, MAX_QUERY_SIZE, stdin);

    q.query_string[0] = '\0';
    strcat(q.query_string, input);

    char* token = strtok(input, " ");
    while (token!= NULL) {
        if (pos >= MAX_COLUMNS) {
            printf("Error: Too many columns in query.\n");
            exit(1);
        }
        strcpy(q.columns[pos], token);
        ++pos;
        token = strtok(NULL, " ");
    }
    q.num_columns = pos;

    int num_rows = 0;
    while (fgets(input, MAX_QUERY_SIZE, stdin)!= NULL) {
        if (num_rows >= MAX_ROWS) {
            printf("Error: Too many rows in query.\n");
            exit(1);
        }
        int val;
        sscanf(input, "%d", &val);
        q.rows[num_rows*q.num_columns + 0] = val;
        ++num_rows;
    }
    q.num_rows = num_rows;

    print_query(&q);

    return 0;
}