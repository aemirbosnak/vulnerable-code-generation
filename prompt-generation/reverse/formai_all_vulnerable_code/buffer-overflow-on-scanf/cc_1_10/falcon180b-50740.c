//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 64
#define MAX_RECORD_LEN 1024
#define MAX_NUM_RECORDS 10000

typedef struct {
    char key[MAX_KEY_LEN];
    char record[MAX_RECORD_LEN];
} record_t;

void load_database(record_t *db, int num_records) {
    FILE *fp;
    char line[MAX_RECORD_LEN];
    int i = 0;

    fp = fopen("database.txt", "r");

    if (fp == NULL) {
        printf("Error: cannot open database file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        strcpy(db[i].key, line);
        i++;
    }

    fclose(fp);

    if (i!= num_records) {
        printf("Error: database file is corrupted\n");
        exit(1);
    }
}

void save_database(record_t *db, int num_records) {
    FILE *fp;
    int i;

    fp = fopen("database.txt", "w");

    if (fp == NULL) {
        printf("Error: cannot open database file\n");
        exit(1);
    }

    for (i = 0; i < num_records; i++) {
        fprintf(fp, "%s\n", db[i].key);
    }

    fclose(fp);
}

int search_database(record_t *db, int num_records, char *key) {
    int i;

    for (i = 0; i < num_records; i++) {
        if (strcmp(db[i].key, key) == 0) {
            printf("%s\n", db[i].record);
            return i;
        }
    }

    return -1;
}

int main() {
    int num_records;
    record_t db[MAX_NUM_RECORDS];

    printf("Enter the number of records: ");
    scanf("%d", &num_records);

    load_database(db, num_records);

    while (1) {
        printf("Enter a key to search: ");
        scanf("%s", db[num_records - 1].key);

        int index = search_database(db, num_records, db[num_records - 1].key);

        if (index == -1) {
            printf("Record not found\n");
        } else {
            printf("Record found at index %d\n", index);
        }

        printf("Do you want to save the changes? (y/n) ");
        char ch;
        scanf(" %c", &ch);

        if (ch == 'y' || ch == 'Y') {
            save_database(db, num_records);
            printf("Changes saved\n");
        }
    }

    return 0;
}