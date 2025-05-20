//FormAI DATASET v1.0 Category: Database simulation ; Style: automated
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records that can be stored

struct Record {
    int ID;
    char name[20];
    int age;
    char address[50];
};

struct Database {
    struct Record records[MAX_RECORDS];
    int num_records;
};

// Function to display menu
void display_menu() {
    printf("Welcome to the Database Management System\n");
    printf("----------------------------------------\n");
    printf("1. Add new record\n");
    printf("2. Edit existing record\n");
    printf("3. Delete record\n");
    printf("4. Search record\n");
    printf("5. Display all records\n");
    printf("6. Exit\n");
}

// Function to add a new record to the database
void add_record(struct Database *db) {
    if (db->num_records == MAX_RECORDS) {
        printf("Error: Database is full\n");
        return;
    }
    struct Record new_record;
    printf("Enter ID: ");
    scanf("%d", &new_record.ID);
    printf("Enter name: ");
    scanf("%s", new_record.name);
    printf("Enter age: ");
    scanf("%d", &new_record.age);
    printf("Enter address: ");
    scanf("%s", new_record.address);
    db->records[db->num_records++] = new_record;
    printf("Record added successfully\n");
}

// Function to edit an existing record in the database
void edit_record(struct Database *db) {
    int ID;
    printf("Enter ID of record to edit: ");
    scanf("%d", &ID);
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (db->records[i].ID == ID) {
            struct Record new_record;
            printf("Enter new name: ");
            scanf("%s", new_record.name);
            printf("Enter new age: ");
            scanf("%d", &new_record.age);
            printf("Enter new address: ");
            scanf("%s", new_record.address);
            db->records[i] = new_record;
            printf("Record edited successfully\n");
            return;
        }
    }
    printf("Error: Record not found\n");
}

// Function to delete a record from the database
void delete_record(struct Database *db) {
    int ID;
    printf("Enter ID of record to delete: ");
    scanf("%d", &ID);
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (db->records[i].ID == ID) {
            int j;
            for (j = i; j < db->num_records - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->num_records--;
            printf("Record deleted successfully\n");
            return;
        }
    }
    printf("Error: Record not found\n");
}

// Function to search for a record in the database by name
void search_record(struct Database *db) {
    char name[20];
    printf("Enter name to search for: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            printf("Record found:\n");
            printf("ID: %d\n", db->records[i].ID);
            printf("Name: %s\n", db->records[i].name);
            printf("Age: %d\n", db->records[i].age);
            printf("Address: %s\n", db->records[i].address);
            return;
        }
    }
    printf("Error: Record not found\n");
}

// Function to display all records in the database
void display_all_records(struct Database *db) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("ID: %d\n", db->records[i].ID);
        printf("Name: %s\n", db->records[i].name);
        printf("Age: %d\n", db->records[i].age);
        printf("Address: %s\n", db->records[i].address);
    }
    printf("End of records\n");
}

int main() {
    struct Database db = { .num_records = 0 };
    int choice;
    do {
        display_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
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
                search_record(&db);
                break;
            case 5:
                display_all_records(&db);
                break;
            case 6:
                printf("Exiting program\n");
                break;
            default:
                printf("Error: Invalid choice\n");
                break;
        }
    } while (choice != 6);
    return 0;
}