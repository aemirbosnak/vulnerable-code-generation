//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char *name;
    int age;
    float salary;
} Record;

typedef struct {
    Record *data;
    int num_rows;
    int num_cols;
} Database;

void init_database(Database *db) {
    db->data = malloc(MAX_ROWS * sizeof(Record));
    db->num_rows = 0;
    db->num_cols = 3;
}

void destroy_database(Database *db) {
    free(db->data);
}

int add_record(Database *db, char *name, int age, float salary) {
    Record *rec = malloc(sizeof(Record));
    rec->name = strdup(name);
    rec->age = age;
    rec->salary = salary;

    if (db->num_rows >= MAX_ROWS) {
        printf("Error: Database is full.\n");
        free(rec);
        return -1;
    }

    db->data[db->num_rows] = *rec;
    db->num_rows++;

    return 0;
}

int search_record(Database *db, char *name) {
    for (int i = 0; i < db->num_rows; i++) {
        if (strcmp(db->data[i].name, name) == 0) {
            printf("Name: %s\nAge: %d\nSalary: %.2f\n", db->data[i].name, db->data[i].age, db->data[i].salary);
            return 0;
        }
    }

    printf("Record not found.\n");
    return -1;
}

int main() {
    srand(time(NULL));

    Database db;
    init_database(&db);

    int choice;
    do {
        printf("1. Add record\n2. Search record\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            {
                char name[20];
                int age;
                float salary;

                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter age: ");
                scanf("%d", &age);

                printf("Enter salary: ");
                scanf("%f", &salary);

                add_record(&db, name, age, salary);
                break;
            }
        case 2:
            {
                char name[20];

                printf("Enter name to search: ");
                scanf("%s", name);

                search_record(&db, name);
                break;
            }
        case 3:
            destroy_database(&db);
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}