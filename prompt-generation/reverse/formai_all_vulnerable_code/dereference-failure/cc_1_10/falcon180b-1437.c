//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 500

typedef struct {
    char **data;
    int rows;
    int cols;
} Database;

Database* create_database() {
    Database *db = (Database*) malloc(sizeof(Database));
    db->data = (char**) malloc(MAX_ROWS * sizeof(char*));
    db->rows = 0;
    db->cols = 0;
    return db;
}

void add_row(Database *db, char *data) {
    int i;
    db->data[db->rows] = (char*) malloc(strlen(data) + 1);
    strcpy(db->data[db->rows], data);
    for(i = 0; i < strlen(data); i++) {
        if(data[i] == ',') {
            db->cols++;
        }
    }
    db->rows++;
}

void print_database(Database *db) {
    int i, j;
    for(i = 0; i < db->rows; i++) {
        for(j = 0; j < db->cols; j++) {
            printf("%s ", db->data[i]);
        }
        printf("\n");
    }
}

void free_database(Database *db) {
    int i;
    for(i = 0; i < db->rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

int main() {
    Database *db = create_database();
    char input[MAX_DATA_SIZE];

    while(1) {
        printf("Enter data (or 'q' to quit): ");
        fgets(input, MAX_DATA_SIZE, stdin);
        if(strcmp(input, "q") == 0) {
            break;
        }
        add_row(db, input);
    }

    print_database(db);

    free_database(db);

    return 0;
}