//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLUMNS 5

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person data[MAX_ROWS];
    int row_index;
} DB;

void print_db(DB *db) {
    int i;
    printf("Name\tAge\n");
    for (i = 0; i < db->row_index; i++) {
        printf("%s\t%d\n", db->data[i].name, db->data[i].age);
    }
}

int main() {
    DB db;
    db.row_index = 0;

    int choice;
    do {
        printf("\n1. Add a new person to the database\n2. Print the database\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(db.data[db.row_index].name, sizeof(db.data[db.row_index].name), stdin);
                printf("Enter age: ");
                scanf("%d", &db.data[db.row_index].age);
                db.row_index++;
                break;

            case 2:
                print_db(&db);
                break;

            case 3:
                exit(0);
        }
    } while (choice!= 3);

    return 0;
}