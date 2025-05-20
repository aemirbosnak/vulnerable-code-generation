//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50
#define DELIMITER ','

typedef struct {
    char *data[MAX_FIELD_SIZE];
    int num_fields;
} Record;

Record *database = NULL;
int num_records = 0;

void init_database() {
    database = (Record *)malloc(MAX_RECORDS * sizeof(Record));
    memset(database, 0, MAX_RECORDS * sizeof(Record));
    num_records = 0;
}

void add_record(char *record_str) {
    char *token = strtok(record_str, DELIMITER);
    int i = 0;

    while (token!= NULL && i < MAX_FIELD_SIZE) {
        database[num_records].data[i] = strdup(token);
        i++;
        token = strtok(NULL, DELIMITER);
    }

    database[num_records].num_fields = i;
    num_records++;
}

void print_record(int record_num) {
    printf("Record %d:\n", record_num);
    for (int i = 0; i < database[record_num].num_fields; i++) {
        printf("%s\t", database[record_num].data[i]);
    }
    printf("\n");
}

void search_database(char *search_str) {
    int found = 0;

    for (int i = 0; i < num_records; i++) {
        for (int j = 0; j < database[i].num_fields; j++) {
            if (strcmp(database[i].data[j], search_str) == 0) {
                print_record(i);
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        printf("No records found.\n");
    }
}

int main() {
    init_database();

    add_record("John Doe,25,Male");
    add_record("Jane Smith,30,Female");
    add_record("Bob Johnson,40,Male");

    printf("Database:\n");
    for (int i = 0; i < num_records; i++) {
        print_record(i);
    }

    search_database("Male");

    return 0;
}