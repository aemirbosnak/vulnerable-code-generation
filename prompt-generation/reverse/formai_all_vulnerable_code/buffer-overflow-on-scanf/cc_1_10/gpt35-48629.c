//FormAI DATASET v1.0 Category: Database simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>

#define MAX_RECORDS 100

struct Record {
    char name[20];
    int age;
    char address[50];
};

struct Database {
    struct Record records[MAX_RECORDS];
    int num_records;
};

void print_menu() {
    printf("\n================= MENU =================\n");
    printf("1. Add a record\n");
    printf("2. Edit a record\n");
    printf("3. Delete a record\n");
    printf("4. View all records\n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
}

void add_record(struct Database *db) {
    if (db->num_records >= MAX_RECORDS) {
        printf("Error: Database full!\n");
        return;
    }
    struct Record r;
    printf("\nEnter name: ");
    scanf("%s", r.name);
    printf("Enter age: ");
    scanf("%d", &r.age);
    printf("Enter address: ");
    scanf("%s", r.address);
    db->records[db->num_records++] = r;
    printf("\nRecord added successfully!\n");
}

void edit_record(struct Database *db) {
    int id;
    printf("\nEnter record ID to edit: ");
    scanf("%d", &id);
    if (id < 1 || id > db->num_records) {
        printf("\nError: Invalid ID!\n");
        return;
    }
    struct Record r = db->records[id-1];
    printf("\nCurrent record:\n");
    printf("Name: %s\n", r.name);
    printf("Age: %d\n", r.age);
    printf("Address: %s\n", r.address);
    printf("\nEnter new data:\n");
    printf("Enter name: ");
    scanf("%s", r.name);
    printf("Enter age: ");
    scanf("%d", &r.age);
    printf("Enter address: ");
    scanf("%s", r.address);
    db->records[id-1] = r;
    printf("\nRecord updated successfully!\n");
}

void delete_record(struct Database *db) {
    int id;
    printf("\nEnter record ID to delete: ");
    scanf("%d", &id);
    if (id < 1 || id > db->num_records) {
        printf("\nError: Invalid ID!\n");
        return;
    }
    for (int i=id-1; i<db->num_records-1; i++) {
        db->records[i] = db->records[i+1];
    }
    db->num_records--;
    printf("\nRecord deleted successfully!\n");
}

void view_records(struct Database *db) {
    if (db->num_records == 0) {
        printf("\nDatabase is empty!\n");
        return;
    }
    printf("\n================= RECORDS =================\n");
    for (int i=0; i<db->num_records; i++) {
        printf("ID: %d\n", i+1);
        printf("Name: %s\n", db->records[i].name);
        printf("Age: %d\n", db->records[i].age);
        printf("Address: %s\n", db->records[i].address);
        printf("\n");
    }
}

int main() {
    struct Database db = { .num_records = 0 };
    int choice;
    while (true) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_record(&db); break;
            case 2: edit_record(&db); break;
            case 3: delete_record(&db); break;
            case 4: view_records(&db); break;
            case 5: return 0;
            default: printf("\nError: Invalid choice!\n");
        }
    }
    return 0;
}