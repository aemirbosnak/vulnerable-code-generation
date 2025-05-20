//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: future-proof
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
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating table\n");
        exit(1);
    }
    fprintf(fp, "ID\tName\tAge\tGender\n");
    fclose(fp);
}

void insert_record(char *filename, char *id, char *name, int age, char *gender) {
    FILE *fp;
    Record record;
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error inserting record\n");
        exit(1);
    }
    record.num_fields = 4;
    strcpy(record.fields[0], id);
    strcpy(record.fields[1], name);
    sprintf(record.fields[2], "%d", age);
    strcpy(record.fields[3], gender);
    fwrite(&record, sizeof(Record), 1, fp);
    fclose(fp);
}

void display_record(Record record) {
    int i;
    for (i = 0; i < record.num_fields; i++) {
        printf("%s\t", record.fields[i]);
    }
    printf("\n");
}

void search_record(char *filename, char *id) {
    FILE *fp;
    Record record;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error searching record\n");
        exit(1);
    }
    while (fread(&record, sizeof(Record), 1, fp)!= 0) {
        if (strcmp(record.fields[0], id) == 0) {
            display_record(record);
        }
    }
    fclose(fp);
}

int main() {
    char filename[20] = "database.txt";
    create_table(filename);
    insert_record(filename, "1", "John", 25, "Male");
    insert_record(filename, "2", "Jane", 30, "Female");
    insert_record(filename, "3", "Bob", 45, "Male");
    search_record(filename, "2");
    return 0;
}