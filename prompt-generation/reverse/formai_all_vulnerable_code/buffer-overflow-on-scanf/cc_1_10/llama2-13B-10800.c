//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 255
#define MAX_AGE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} record_t;

record_t records[MAX_RECORDS];
int record_count = 0;

void init_database(void);
void add_record(char *name, int age);
void print_all_records(void);
void search_record(char *name);

int main(void) {
    srand(time(NULL));

    init_database();

    printf("Welcome to the database demo\n");

    while (1) {
        printf("Add a new record (y/n)? ");
        char input = getchar();

        if (input == 'y') {
            char name[MAX_NAME_LENGTH];
            int age;

            printf("Enter name: ");
            fgets(name, MAX_NAME_LENGTH, stdin);
            printf("Enter age: ");
            scanf("%d", &age);

            add_record(name, age);
        } else if (input == 'n') {
            break;
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }

    print_all_records();

    return 0;
}

void init_database(void) {
    record_count = 0;
    memset(records, 0, sizeof(records));
}

void add_record(char *name, int age) {
    record_t *new_record = (record_t *) malloc(sizeof(record_t));
    strcpy(new_record->name, name);
    new_record->age = age;

    if (record_count >= MAX_RECORDS) {
        printf("Error: Database is full. Please delete some records before adding new ones.\n");
        return;
    }

    records[record_count++] = *new_record;
}

void print_all_records(void) {
    printf("All records:\n");

    for (int i = 0; i < record_count; i++) {
        printf("%d. %s (%d years old)\n", i + 1, records[i].name, records[i].age);
    }
}

void search_record(char *name) {
    int found = 0;

    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].name, name) == 0) {
            found = 1;
            printf("%d. %s (%d years old)\n", i + 1, records[i].name, records[i].age);
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }
}