//Falcon-180B DATASET v1.0 Category: Database querying ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50
#define MAX_AGE 120

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    int id;
} Person;

void create_table(FILE *db) {
    fprintf(db, "CREATE TABLE IF NOT EXISTS people (");
    fprintf(db, "id INTEGER PRIMARY KEY AUTOINCREMENT,");
    fprintf(db, "name TEXT NOT NULL,");
    fprintf(db, "age INTEGER NOT NULL);\n");
}

void insert_person(FILE *db, const char *name, int age) {
    Person p = { 0 };
    strncpy(p.name, name, MAX_NAME_LEN);
    p.age = age;

    fprintf(db, "INSERT INTO people (name, age) VALUES ('%s', %d);\n", name, age);
}

void query_people_by_age(FILE *db, int age) {
    fprintf(db, "SELECT * FROM people WHERE age = %d;\n", age);
}

void print_person(const Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("ID: %d\n", p->id);
}

int main() {
    FILE *db = fopen("test.db", "w");

    if (!db) {
        printf("Error opening database file.\n");
        return 1;
    }

    create_table(db);

    insert_person(db, "John Doe", 30);
    insert_person(db, "Jane Smith", 25);

    rewind(db);

    query_people_by_age(db, 30);

    fclose(db);

    db = fopen("test.db", "r");

    if (!db) {
        printf("Error opening database file.\n");
        return 1;
    }

    Person p = { 0 };

    while (fscanf(db, "SELECT * FROM people WHERE age = %d;", &p.age) == 1) {
        print_person(&p);
    }

    fclose(db);

    return 0;
}