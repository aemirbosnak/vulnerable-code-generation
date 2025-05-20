//FormAI DATASET v1.0 Category: Database Indexing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 100

struct Record {
    char name[50];
    int age;
    char address[100];
    long phone_number;
};

struct Index {
    char name[50];
    int index;
};

struct Database {
    struct Record records[MAX_RECORDS];
    struct Index index[MAX_RECORDS];
    int record_count;
};

int add_record(struct Database* db, struct Record record);
int remove_record(struct Database* db, int index);
void print_record(struct Record record);
void print_database(struct Database db);
void print_menu();
void print_error_message();
int search_record(struct Database db, char* name);

int main() {
    struct Database db;
    db.record_count = 0;
    int choice, index, result;
    char name[50];
    struct Record record;
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", record.name);
                printf("Enter age: ");
                scanf("%d", &record.age);
                printf("Enter address: ");
                scanf("%s", record.address);
                printf("Enter phone number: ");
                scanf("%ld", &record.phone_number);
                result = add_record(&db, record);
                if (result == -1) {
                    print_error_message();
                }
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                result = remove_record(&db, index);
                if (result == -1) {
                    print_error_message();
                }
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                result = search_record(db, name);
                if (result == -1) {
                    print_error_message();
                }
                break;
            case 4:
                print_database(db);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

int add_record(struct Database* db, struct Record record) {
    if (db->record_count >= MAX_RECORDS) {
        return -1;
    }
    int i;
    for (i = 0; i < db->record_count; i++) {
        if (strcmp(db->index[i].name, record.name) > 0) {
            break;
        }
    }
    int j;
    for (j = db->record_count; j > i; j--) {
        db->records[j] = db->records[j-1];
        db->index[j] = db->index[j-1];
    }
    db->records[i] = record;
    strcpy(db->index[i].name, record.name);
    db->index[i].index = i;
    db->record_count++;
    return 0;
}

int remove_record(struct Database* db, int index) {
    if (index < 0 || index >= db->record_count) {
        return -1;
    }
    int i;
    for (i = index; i < db->record_count-1; i++) {
        db->records[i] = db->records[i+1];
        db->index[i] = db->index[i+1];
    }
    db->record_count--;
    return 0;
}

void print_record(struct Record record) {
    printf("%s, age: %d, address: %s, phone number: %ld\n", record.name, record.age, record.address, record.phone_number);
}

void print_database(struct Database db) {
    int i;
    for (i = 0; i < db.record_count; i++) {
        printf("Record %d: ", i+1);
        print_record(db.records[i]);
    }
}

void print_menu() {
    printf("1. Add record\n");
    printf("2. Remove record\n");
    printf("3. Search record by name\n");
    printf("4. Display all records\n");
}

void print_error_message() {
    printf("Error: invalid input\n");
}

int search_record(struct Database db, char* name) {
    int i;
    for (i = 0; i < db.record_count; i++) {
        if (strcmp(db.records[i].name, name) == 0) {
            printf("Record %d: ", i+1);
            print_record(db.records[i]);
            return i;
        }
    }
    return -1;
}