//FormAI DATASET v1.0 Category: Database simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10

typedef struct {
    int id;
    char name[20];
    float balance;
} Record;

Record db[MAX_RECORDS];
int num_records = 0;

void add_record() {
    if (num_records == MAX_RECORDS) {
        printf("Database full!\n");
        return;
    }

    Record new_record;
    printf("Enter id: ");
    scanf("%d", &new_record.id);
    printf("Enter name: ");
    scanf("%s", new_record.name);
    printf("Enter balance: ");
    scanf("%f", &new_record.balance);

    db[num_records++] = new_record;
}

void list_records() {
    if (num_records == 0) {
        printf("No records found!\n");
        return;
    }

    printf("ID\tName\tBalance\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%.2f\n", db[i].id, db[i].name, db[i].balance);
    }
}

void find_record() {
    int id;
    printf("Enter id to find: ");
    scanf("%d", &id);

    for (int i = 0; i < num_records; i++) {
        if (db[i].id == id) {
            printf("ID\tName\tBalance\n");
            printf("%d\t%s\t%.2f\n", db[i].id, db[i].name, db[i].balance);
            return;
        }
    }

    printf("Record not found!\n");
}

void delete_record() {
    int id;
    printf("Enter id to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < num_records; i++) {
        if (db[i].id == id) {
            for (int j = i; j < num_records-1; j++) {
                db[j] = db[j+1];
            }
            num_records--;
            printf("Record deleted!\n");
            return;
        }
    }

    printf("Record not found!\n");
}

void update_record() {
    int id;
    printf("Enter id to update: ");
    scanf("%d", &id);

    for (int i = 0; i < num_records; i++) {
        if (db[i].id == id) {
            printf("Enter name: ");
            scanf("%s", db[i].name);
            printf("Enter balance: ");
            scanf("%f", &db[i].balance);
            printf("Record updated!\n");
            return;
        }
    }

    printf("Record not found!\n");
}

void menu() {
    printf("\n");
    printf("1) Add record\n");
    printf("2) List records\n");
    printf("3) Find record\n");
    printf("4) Delete record\n");
    printf("5) Update record\n");
    printf("6) Exit\n");
}

int main() {
    int option = 0;
    while (option != 6) {
        menu();
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: add_record(); break;
            case 2: list_records(); break;
            case 3: find_record(); break;
            case 4: delete_record(); break;
            case 5: update_record(); break;
            case 6: break;
            default: printf("Invalid option!\n"); break;
        }
    }

    return 0;
}