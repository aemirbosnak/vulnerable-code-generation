//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int id;
    float salary;
} Employee;

typedef struct {
    Employee* employees;
    int num_rows;
    int num_cols;
} Database;

Database* create_database(int num_rows, int num_cols) {
    Database* db = malloc(sizeof(Database));
    db->employees = malloc(num_rows * num_cols * sizeof(Employee));
    db->num_rows = num_rows;
    db->num_cols = num_cols;
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            db->employees[i * num_cols + j].id = i * num_cols + j;
            strcpy(db->employees[i * num_cols + j].name, "Employee ");
            db->employees[i * num_cols + j].salary = 0;
        }
    }
    return db;
}

void destroy_database(Database* db) {
    free(db->employees);
    free(db);
}

void print_database(Database* db) {
    for (int i = 0; i < db->num_rows; i++) {
        for (int j = 0; j < db->num_cols; j++) {
            printf("%d | %s | %.2f\n", db->employees[i * db->num_cols + j].id, db->employees[i * db->num_cols + j].name, db->employees[i * db->num_cols + j].salary);
        }
        printf("\n");
    }
}

int main() {
    Database* db = create_database(5, 3);
    print_database(db);
    destroy_database(db);
    return 0;
}