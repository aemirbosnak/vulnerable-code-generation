//FormAI DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct student {
    int id;
    char name[20];
    char major[20];
    float gpa;
};

struct database {
    struct student records[MAX_RECORDS];
    int count;
};

void menu() {
    printf("=====================\n");
    printf("1. Add Record\n");
    printf("2. Edit Record\n");
    printf("3. Delete Record\n");
    printf("4. View Records\n");
    printf("5. Exit\n");
    printf("=====================\n");
}

void add_record(struct database *db) {
    if (db->count == MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &db->records[db->count].id);
    printf("Enter Student Name: ");
    scanf("%s", db->records[db->count].name);
    printf("Enter Student Major: ");
    scanf("%s", db->records[db->count].major);
    printf("Enter Student GPA: ");
    scanf("%f", &db->records[db->count].gpa);

    db->count++;
    printf("Record added successfully!\n");
}

void edit_record(struct database *db) {
    int id, i;
    printf("Enter Student ID to Edit Record: ");
    scanf("%d", &id);

    for (i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Enter Student Name: ");
            scanf("%s", db->records[i].name);
            printf("Enter Student Major: ");
            scanf("%s", db->records[i].major);
            printf("Enter Student GPA: ");
            scanf("%f", &db->records[i].gpa);
            printf("Record edited successfully!\n");
            return;
        }
    }

    printf("Record not found!\n");
}

void delete_record(struct database *db) {
    int id, i, j;
    printf("Enter Student ID to Delete Record: ");
    scanf("%d", &id);

    for (i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            for (j = i + 1; j < db->count; j++) {
                db->records[j-1] = db->records[j];
            }
            db->count--;
            printf("Record deleted successfully!\n");
            return;
        }
    }

    printf("Record not found!\n");
}

void view_records(struct database *db) {
    int i;
    printf("ID\tName\tMajor\tGPA\n");
    for (i = 0; i < db->count; i++) {
        printf("%d\t%s\t%s\t%.2f\n", db->records[i].id, db->records[i].name, db->records[i].major, db->records[i].gpa);
    }
}

int main() {
    struct database db = {0};
    int choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_record(&db);
                break;
            case 2:
                edit_record(&db);
                break;
            case 3:
                delete_record(&db);
                break;
            case 4:
                view_records(&db);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}