//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

struct column {
    char name[50];
    int type;
    int size;
};

struct row {
    int id;
    struct column columns[MAX_COLS];
};

struct table {
    char name[50];
    int num_rows;
    int num_cols;
    struct row rows[MAX_ROWS];
};

int main() {
    struct table my_table = {"my_table", 0, 0, {{0, {{"id", 4, 4}, {"name", 50, 1}}}}};

    printf("Enter number of columns for table'my_table': ");
    scanf("%d", &my_table.num_cols);

    for (int i = 0; i < my_table.num_cols; i++) {
        printf("Enter column name for column %d: ", i+1);
        scanf("%s", my_table.rows[0].columns[i].name);
        printf("Enter column type for column %s (1 for INT, 2 for VARCHAR): ", my_table.rows[0].columns[i].name);
        scanf("%d", &my_table.rows[0].columns[i].type);
        if (my_table.rows[0].columns[i].type == 2) {
            printf("Enter column size for column %s: ", my_table.rows[0].columns[i].name);
            scanf("%d", &my_table.rows[0].columns[i].size);
        }
    }

    printf("Enter number of rows for table'my_table': ");
    scanf("%d", &my_table.num_rows);

    for (int i = 0; i < my_table.num_rows; i++) {
        printf("Enter row ID for row %d: ", i+1);
        scanf("%d", &my_table.rows[i].id);
    }

    return 0;
}