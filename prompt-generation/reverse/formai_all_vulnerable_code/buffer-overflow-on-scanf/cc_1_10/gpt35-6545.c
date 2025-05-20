//FormAI DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char name[20];
    int age;
    char gender[7];
};

struct RecordDB {
    struct Record records[MAX_RECORDS];
    int size;
};

void addRecord(struct RecordDB* db, struct Record record) {
    if (db->size >= MAX_RECORDS) {
        printf("ERROR: Database is full!\n");
        return;
    }
    db->records[db->size++] = record;
    printf("Record added succesfully!\n");
}

void deleteRecord(struct RecordDB* db, int id) {
    int index = -1;
    for (int i = 0; i < db->size; i++) {
        if (db->records[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("ERROR: Record not found!\n");
        return;
    }
    for (int i = index; i < db->size - 1; i++) {
        db->records[i] = db->records[i+1];
    }
    db->size--;
    printf("Record deleted succesfully!\n");
}

void displayRecord(struct RecordDB* db, int id) {
    for (int i = 0; i < db->size; i++) {
        if (db->records[i].id == id) {
            printf("ID: %d\n", db->records[i].id);
            printf("Name: %s\n", db->records[i].name);
            printf("Age: %d\n", db->records[i].age);
            printf("Gender: %s\n", db->records[i].gender);
            return;
        }
    }
    printf("ERROR: Record not found!\n");
}

void listRecords(struct RecordDB* db) {
    if (db->size == 0) {
        printf("Database is empty!\n");
        return;
    }
    printf("ID\tName\tAge\tGender\n");
    for (int i = 0; i < db->size; i++) {
        printf("%d\t%s\t%d\t%s\n", db->records[i].id, db->records[i].name, db->records[i].age, db->records[i].gender);
    }
}

int main() {
    struct RecordDB db = {0};
    int choice, id, age;
    char name[20], gender[7];
    struct Record record;

    while (1) {
        printf("\nMENU\n");
        printf("----\n");
        printf("1. Add Record\n");
        printf("2. Delete Record\n");
        printf("3. Display Record\n");
        printf("4. List Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                printf("Enter Gender: ");
                scanf("%s", gender);
                record.id = id;
                strcpy(record.name, name);
                record.age = age;
                strcpy(record.gender, gender);
                addRecord(&db, record);
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                deleteRecord(&db, id);
                break;
            case 3:
                printf("Enter ID: ");
                scanf("%d", &id);
                displayRecord(&db, id);
                break;
            case 4:
                listRecords(&db);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}