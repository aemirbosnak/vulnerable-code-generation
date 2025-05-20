//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char name[MAX_DATA_SIZE];
    int age;
} Person;

typedef struct {
    Person data[MAX_ROWS][MAX_COLS];
    int numRows;
    int numCols;
} Database;

Database* createDatabase() {
    Database* db = (Database*) malloc(sizeof(Database));
    db->numRows = 0;
    db->numCols = 0;
    return db;
}

void destroyDatabase(Database* db) {
    free(db);
}

void addRow(Database* db) {
    db->numRows++;
}

void addCol(Database* db) {
    db->numCols++;
}

void setData(Database* db, int row, int col, const char* name, int age) {
    strcpy(db->data[row][col].name, name);
    db->data[row][col].age = age;
}

void printData(const Database* db) {
    for (int i = 0; i < db->numRows; i++) {
        for (int j = 0; j < db->numCols; j++) {
            printf("Name: %s, Age: %d\n", db->data[i][j].name, db->data[i][j].age);
        }
    }
}

int main() {
    Database* db = createDatabase();
    addRow(db);
    addRow(db);
    addCol(db);
    addCol(db);
    setData(db, 0, 0, "Alice", 25);
    setData(db, 0, 1, "Bob", 30);
    setData(db, 1, 0, "Charlie", 20);
    setData(db, 1, 1, "David", 40);
    printData(db);
    destroyDatabase(db);
    return 0;
}