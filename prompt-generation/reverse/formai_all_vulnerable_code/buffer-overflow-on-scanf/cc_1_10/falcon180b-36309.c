//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEXES 10
#define MAX_KEY_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    int value;
} Index;

typedef struct {
    Index indexes[MAX_INDEXES];
    int num_indexes;
} Database;

void create_index(Database *db, char *key) {
    Index index;
    strcpy(index.key, key);
    index.value = 0;

    for (int i = 0; i < db->num_indexes; i++) {
        if (strcmp(db->indexes[i].key, key) == 0) {
            return;
        }
    }

    db->indexes[db->num_indexes] = index;
    db->num_indexes++;
}

int find_index(Database *db, char *key) {
    for (int i = 0; i < db->num_indexes; i++) {
        if (strcmp(db->indexes[i].key, key) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    Database db;
    db.num_indexes = 0;

    create_index(&db, "name");
    create_index(&db, "age");

    int id = 1;
    char name[MAX_KEY_LENGTH];
    int age;

    while (1) {
        printf("Enter name: ");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter age: ");
        scanf("%d", &age);

        Index *index = find_index(&db, "name");
        if (index == NULL) {
            printf("Error: Name not found.\n");
            continue;
        }
        index->value = id;

        index = find_index(&db, "age");
        if (index == NULL) {
            printf("Error: Age not found.\n");
            continue;
        }
        index->value = age;

        id++;
    }

    return 0;
}