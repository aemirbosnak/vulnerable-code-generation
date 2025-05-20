//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 50
#define MAX_AGE 120

typedef struct person {
    char name[MAX_NAME_LEN];
    int age;
} person_t;

person_t *database = NULL;
int num_records = 0;

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void print_database() {
    if (num_records == 0) {
        printf("Database is empty.\n");
        return;
    }

    printf("Name\tAge\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s\t%d\n", database[i].name, database[i].age);
    }
}

int main() {
    database = malloc(MAX_RECORDS * sizeof(person_t));
    if (database == NULL) {
        printf("Error: Failed to allocate memory for database.\n");
        return 1;
    }

    num_records = 0;

    while (num_records < MAX_RECORDS) {
        printf("Enter name (or type 'quit' to exit): ");
        char name[MAX_NAME_LEN];
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        printf("Enter age: ");
        int age;
        scanf("%d", &age);

        if (age < 0 || age > MAX_AGE) {
            printf("Error: Age must be between 0 and %d.\n", MAX_AGE);
            continue;
        }

        person_t *new_record = realloc(database, (num_records + 1) * sizeof(person_t));
        if (new_record == NULL) {
            printf("Error: Failed to allocate memory for new record.\n");
            return 1;
        }

        database = new_record;

        strcpy(database[num_records].name, name);
        database[num_records].age = age;
        num_records++;
    }

    print_database();

    return 0;
}