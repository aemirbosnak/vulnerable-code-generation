//FormAI DATASET v1.0 Category: Database simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct student {
    int id;
    char name[MAX];
    int age;
};

struct database {
    struct student records[MAX];
    int count;
};

void add_record(struct database *db, int id, char name[], int age) {
    if(db->count == MAX) {
        printf("Database full!\n");
        return;
    }
    db->records[db->count].id = id;
    strcpy(db->records[db->count].name, name);
    db->records[db->count].age = age;
    db->count++;
}

void delete_record(struct database *db, int id) {
    int i;
    for(i = 0; i < db->count; i++) {
        if(db->records[i].id == id) {
            db->count--;
            for(; i < db->count; i++) {
                db->records[i] = db->records[i + 1];
            }
            printf("Record deleted.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

void print_records(struct database *db) {
    int i;
    printf("ID\tName\t\tAge\n");
    for(i = 0; i < db->count; i++) {
        printf("%d\t%s\t\t%d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
}

int main() {
    struct database db;
    db.count = 0;
    int choice, id, age;
    char name[MAX];
    do {
        printf("1. Add record\n");
        printf("2. Delete record\n");
        printf("3. Print all records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                add_record(&db, id, name, age);
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                delete_record(&db, id);
                break;
            case 3:
                print_records(&db);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 4);
    return 0;
}