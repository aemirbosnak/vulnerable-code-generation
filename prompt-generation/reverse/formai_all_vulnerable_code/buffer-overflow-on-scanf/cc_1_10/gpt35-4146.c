//FormAI DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

typedef struct {
    char name[25];
    int age;
    char address[50];
} Record;

int num_records = 0;
Record records[MAX_RECORDS];

void add_record();
void view_records();
void delete_record();

int main() {
    char choice;
    do {
        printf("1. Add record\n");
        printf("2. View records\n");
        printf("3. Delete record\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                add_record();
                break;

            case '2':
                view_records();
                break;

            case '3':
                delete_record();
                break;

            case '4':
                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }

    } while (choice != '4');

    return 0;
}

void add_record() {
    if (num_records == MAX_RECORDS) {
        printf("Database full, cannot add more records\n");
        return;
    }

    Record new_record;
    printf("Enter name: ");
    scanf("%s", new_record.name);
    printf("Enter age: ");
    scanf("%d", &new_record.age);
    printf("Enter address: ");
    scanf("%s", new_record.address);

    records[num_records++] = new_record;

    printf("Record added successfully\n");
}

void view_records() {
    if (num_records == 0) {
        printf("Database empty, no records to display\n");
        return;
    }

    printf("Name\tAge\tAddress\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s\t%d\t%s\n", records[i].name, records[i].age, records[i].address);
    }
}

void delete_record() {
    if (num_records == 0) {
        printf("Database empty, no records to delete\n");
        return;
    }

    char name[25];
    printf("Enter name to delete: ");
    scanf("%s", name);

    int found_index = -1;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(name, records[i].name) == 0) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("Record not found\n");
        return;
    }

    for (int i = found_index; i < num_records - 1; i++) {
        records[i] = records[i+1];
    }

    num_records--;

    printf("Record deleted successfully\n");
}