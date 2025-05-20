//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_LENGTH 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} database;

database *create_database(int num_rows, int num_cols) {
    database *db = malloc(sizeof(database));
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    db->data = calloc(num_rows, sizeof(char*));
    for (int i = 0; i < num_rows; i++) {
        db->data[i] = calloc(num_cols, sizeof(char));
    }
    return db;
}

void destroy_database(database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        free(db->data[i]);
    }
    free(db->data);
    free(db);
}

void print_database(database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%c", db->data[i][j]);
        }
        printf("\n");
    }
}

int get_random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char get_random_char() {
    return rand() % 26 + 'a';
}

void generate_random_data(database *db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            db->data[i][j] = get_random_char();
        }
    }
}

int main() {
    srand(time(NULL));
    int num_rows, num_cols;
    printf("Enter number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter number of columns: ");
    scanf("%d", &num_cols);
    database *db = create_database(num_rows, num_cols);
    generate_random_data(db);
    printf("Random data:\n");
    print_database(db);
    destroy_database(db);
    return 0;
}