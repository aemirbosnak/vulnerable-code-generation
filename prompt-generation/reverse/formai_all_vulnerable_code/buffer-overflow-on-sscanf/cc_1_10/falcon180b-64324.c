//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *fields[MAX_FIELD_SIZE];
    int num_fields;
} Record;

void create_table(char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating table.\n");
        exit(1);
    }

    Record record;
    strcpy(record.fields[0], "ID");
    strcpy(record.fields[1], "Name");
    strcpy(record.fields[2], "Age");

    fprintf(fp, "%s\t%s\t%s\n", record.fields[0], record.fields[1], record.fields[2]);

    fclose(fp);
}

void insert_record(char *filename, char *id, char *name, int age) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error inserting record.\n");
        exit(1);
    }

    Record record;
    strcpy(record.fields[0], id);
    strcpy(record.fields[1], name);
    sprintf(record.fields[2], "%d", age);

    fprintf(fp, "%s\t%s\t%s\n", record.fields[0], record.fields[1], record.fields[2]);

    fclose(fp);
}

void search_record(char *filename, char *id) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error searching record.\n");
        exit(1);
    }

    Record record;
    char line[MAX_FIELD_SIZE * MAX_FIELD_SIZE];

    while (fgets(line, sizeof(line), fp)!= NULL) {
        sscanf(line, "%s\t%s\t%s", record.fields[0], record.fields[1], record.fields[2]);

        if (strcmp(record.fields[0], id) == 0) {
            printf("Record found:\n");
            printf("ID: %s\n", record.fields[0]);
            printf("Name: %s\n", record.fields[1]);
            printf("Age: %s\n", record.fields[2]);

            break;
        }
    }

    fclose(fp);
}

int main() {
    create_table("database.txt");
    insert_record("database.txt", "1", "John", 25);
    insert_record("database.txt", "2", "Jane", 30);

    search_record("database.txt", "1");

    return 0;
}