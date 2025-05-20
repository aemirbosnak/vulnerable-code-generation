//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 100

typedef struct {
    char *field[MAX_FIELD_SIZE];
    int num_fields;
} Record;

void create_table(void) {
    char table_name[MAX_FIELD_SIZE];
    char field_name[MAX_FIELD_SIZE];
    int field_type;
    int field_size;
    int num_fields = 0;

    printf("Enter table name: ");
    scanf("%s", table_name);

    printf("Enter number of fields: ");
    scanf("%d", &num_fields);

    printf("Enter field names and types:\n");
    for (int i = 0; i < num_fields; i++) {
        printf("Field %d name: ", i+1);
        scanf("%s", field_name);
        printf("Field %d type (1 = integer, 2 = string): ", i+1);
        scanf("%d", &field_type);
        if (field_type == 1) {
            field_size = sizeof(int);
        } else {
            field_size = MAX_FIELD_SIZE;
        }
        printf("Field %d size: %d\n", i+1, field_size);
    }

    printf("Table created successfully.\n");
}

void insert_record(void) {
    char table_name[MAX_FIELD_SIZE];
    Record record;
    int num_fields;

    printf("Enter table name: ");
    scanf("%s", table_name);

    printf("Enter number of fields: ");
    scanf("%d", &num_fields);

    record.num_fields = num_fields;
    for (int i = 0; i < num_fields; i++) {
        record.field[i] = malloc(MAX_FIELD_SIZE);
        printf("Enter field %d value: ", i+1);
        scanf("%s", record.field[i]);
    }

    printf("Record inserted successfully.\n");
}

void select_record(void) {
    char table_name[MAX_FIELD_SIZE];
    char field_name[MAX_FIELD_SIZE];
    int field_index;
    Record record;

    printf("Enter table name: ");
    scanf("%s", table_name);

    printf("Enter field name to search: ");
    scanf("%s", field_name);

    printf("Enter field index (1-%d): ", record.num_fields);
    scanf("%d", &field_index);

    record.num_fields = 1;
    record.field[0] = malloc(MAX_FIELD_SIZE);
    strcpy(record.field[0], field_name);

    printf("Selected record:\n");
    for (int i = 0; i < record.num_fields; i++) {
        printf("Field %d: %s\n", i+1, record.field[i]);
    }
}

int main(void) {
    int choice;

    do {
        printf("1. Create table\n");
        printf("2. Insert record\n");
        printf("3. Select record\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_table();
                break;
            case 2:
                insert_record();
                break;
            case 3:
                select_record();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}