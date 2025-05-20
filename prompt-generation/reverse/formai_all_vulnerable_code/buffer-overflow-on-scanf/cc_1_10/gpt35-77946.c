//FormAI DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
    int age;
} Record;

int num_records = 0;
Record records[MAX_RECORDS];

void add_record() {
    Record rec;
    printf("Enter record ID: ");
    scanf("%d", &rec.id);
    printf("Enter record name: ");
    scanf("%s", &rec.name);
    printf("Enter record age: ");
    scanf("%d", &rec.age);
    records[num_records++] = rec;
}

void print_all_records() {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%d\n", records[i].id, records[i].name, records[i].age);
    }
}

void search_record() {
    int id;
    printf("Enter record ID to search: ");
    scanf("%d", &id);
    printf("ID\tName\tAge\n");
    for (int i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            printf("%d\t%s\t%d\n", records[i].id, records[i].name, records[i].age);
            return;
        }
    }
    printf("Record not found.\n");
}

void delete_record() {
    int id;
    printf("Enter record ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            for (int j = i + 1; j < num_records; j++) {
                records[j - 1] = records[j];
            }
            num_records--;
            printf("Record deleted!\n");
            return;
        }
    }
    printf("Record not found.\n");
}

int main() {
    int option;

    while (1) {
        printf("\n1. Add Record\n2. Print All Records\n3. Search Record\n4. Delete Record\n5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_record();
                break;
            case 2:
                print_all_records();
                break;
            case 3:
                search_record();
                break;
            case 4:
                delete_record();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid option!\n");
                break;
        }
    }

    return 0;
}