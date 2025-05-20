//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100
#define MAX_DATA_SIZE 100

typedef struct {
    char index[MAX_INDEX_SIZE];
    char data[MAX_DATA_SIZE];
} record;

void add_record(record *db, int size, char *index, char *data) {
    record new_record;
    strcpy(new_record.index, index);
    strcpy(new_record.data, data);
    db[size] = new_record;
}

void display_records(record *db, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s : %s\n", db[i].index, db[i].data);
    }
}

void search_record(record *db, int size, char *index) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(db[i].index, index) == 0) {
            printf("Data: %s\n", db[i].data);
            return;
        }
    }
    printf("Record not found.\n");
}

void delete_record(record *db, int size, char *index) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(db[i].index, index) == 0) {
            memset(db[i].index, 0, MAX_INDEX_SIZE);
            memset(db[i].data, 0, MAX_DATA_SIZE);
            return;
        }
    }
    printf("Record not found.\n");
}

void main() {
    record db[MAX_DATA_SIZE];
    int size = 0;
    char index[MAX_INDEX_SIZE];
    char data[MAX_DATA_SIZE];

    while (1) {
        printf("\nEnter 1 to add record\n2 to display records\n3 to search record\n4 to delete record\n5 to exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter index: ");
                scanf("%s", index);
                printf("Enter data: ");
                scanf("%s", data);
                add_record(db, size, index, data);
                size++;
                break;
            case 2:
                display_records(db, size);
                break;
            case 3:
                printf("Enter index: ");
                scanf("%s", index);
                search_record(db, size, index);
                break;
            case 4:
                printf("Enter index: ");
                scanf("%s", index);
                delete_record(db, size, index);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}