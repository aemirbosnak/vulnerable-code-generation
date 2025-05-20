//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num_rows;

void createTable() {
    int i;
    printf("Creating table\n");
    printf("Enter number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter column names separated by spaces: ");
    fflush(stdin);
    char col_names[num_rows][100];
    fgets(col_names[0], sizeof(col_names[0]), stdin);
    for (i = 1; i < num_rows; i++) {
        fgets(col_names[i], sizeof(col_names[i]), stdin);
    }
    printf("Enter column data separated by spaces: ");
    fflush(stdin);
    char data[num_rows][100];
    for (i = 0; i < num_rows; i++) {
        fgets(data[i], sizeof(data[i]), stdin);
    }
    printf("Table created with %d rows\n", num_rows);
}

void insertData() {
    int i;
    printf("Inserting data\n");
    printf("Enter column names separated by spaces: ");
    fflush(stdin);
    char col_names[num_rows][100];
    fgets(col_names[0], sizeof(col_names[0]), stdin);
    for (i = 1; i < num_rows; i++) {
        fgets(col_names[i], sizeof(col_names[i]), stdin);
    }
    printf("Enter column data separated by spaces: ");
    fflush(stdin);
    char data[num_rows][100];
    for (i = 0; i < num_rows; i++) {
        fgets(data[i], sizeof(data[i]), stdin);
    }
    printf("Data inserted\n");
}

void deleteTable() {
    printf("Deleting table\n");
    printf("Enter number of rows: ");
    scanf("%d", &num_rows);
    printf("Table deleted with %d rows\n", num_rows);
}

int main() {
    createTable();
    insertData();
    deleteTable();
    return 0;
}