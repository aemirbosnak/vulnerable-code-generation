//FormAI DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

typedef struct {
    int id;
    char name[20];
    int age;
    char email[50];
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void add_record() {
    if (num_records == MAX_RECORDS) {
        printf("Database is full.\n");
        return;
    }

    Record r;
    r.id = num_records + 1;

    printf("Enter name: ");
    scanf("%s", r.name);
    printf("Enter age: ");
    scanf("%d", &r.age);
    printf("Enter email: ");
    scanf("%s", r.email);

    database[num_records] = r;
    num_records++;
}

void print_database() {
    printf("ID\tName\tAge\tEmail\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%d\t%s\n", database[i].id, database[i].name, database[i].age, database[i].email);
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add record\n");
        printf("2. Print database\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                print_database();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    }

    return 0;
}