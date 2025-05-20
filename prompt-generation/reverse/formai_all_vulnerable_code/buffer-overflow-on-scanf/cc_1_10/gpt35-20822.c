//FormAI DATASET v1.0 Category: Database simulation ; Style: complete
// C program to simulate a database using arrays

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char name[20];
    char email[30];
};

struct Database {
    struct Record records[MAX_RECORDS];
    int count;
};

void addRecord(struct Database *db, struct Record record);
void deleteRecord(struct Database *db, int id);
void viewRecord(struct Database db);
void searchRecord(struct Database db, int id);
void saveToFile(struct Database db, char *fileName);

int main() {
    struct Database db = { .count = 0 };

    int choice;
    do {
        printf("1. Add a record\n");
        printf("2. Delete a record\n");
        printf("3. View all records\n");
        printf("4. Search a record\n");
        printf("5. Save to file\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                struct Record record;
                printf("Enter id: ");
                scanf("%d", &record.id);
                printf("Enter name: ");
                scanf("%s", record.name);
                printf("Enter email: ");
                scanf("%s", record.email);
                addRecord(&db, record);
                break;
            }

            case 2: {
                int id;
                printf("Enter id of record to delete: ");
                scanf("%d", &id);
                deleteRecord(&db, id);
                break;
            }

            case 3: {
                viewRecord(db);
                break;
            }

            case 4: {
                int id;
                printf("Enter id to search for: ");
                scanf("%d", &id);
                searchRecord(db, id);
                break;
            }

            case 5: {
                char fileName[30];
                printf("Enter file name to save to: ");
                scanf("%s", fileName);
                saveToFile(db, fileName);
                break;
            }

            case 6: {
                printf("Exiting...\n");
                break;
            }

            default: {
                printf("Invalid option, please try again.\n");
                break;
            }
        }
    } while(choice != 6);

    return 0;
}

void addRecord(struct Database *db, struct Record record) {
    if(db->count == MAX_RECORDS) {
        printf("Cannot add any more records, database is full.\n");
        return;
    }

    for(int i=0; i<db->count; i++) {
        if(db->records[i].id == record.id) {
            printf("Record with the given ID already exists.\n");
            return;
        }
    }

    db->records[db->count++] = record;
    printf("Record added successfully.\n");
}

void deleteRecord(struct Database *db, int id) {
    int i=0;
    for(; i<db->count; i++) {
        if(db->records[i].id == id) {
            break;
        }
    }

    if(i == db->count) {
        printf("Record with the given ID was not found.\n");
        return;
    }

    for(; i<db->count-1; i++) {
        db->records[i] = db->records[i+1];
    }
    
    db->count--;
    printf("Record deleted successfully.\n");
}

void viewRecord(struct Database db) {
    if(db.count == 0) {
        printf("Database is empty.\n");
        return;
    }

    printf("ID\tName\t\t\tEmail\n");
    for(int i=0; i<db.count; i++) {
        printf("%d\t%-20s\t%-30s\n", db.records[i].id, db.records[i].name, db.records[i].email);
    }
}

void searchRecord(struct Database db, int id) {
    int i=0;
    for(; i<db.count; i++) {
        if(db.records[i].id == id) {
            break;
        }
    }

    if(i == db.count) {
        printf("Record with the given ID was not found.\n");
        return;
    }

    printf("ID\tName\t\t\tEmail\n");
    printf("%d\t%-20s\t%-30s\n", db.records[i].id, db.records[i].name, db.records[i].email);
}

void saveToFile(struct Database db, char *fileName) {
    FILE *fp = fopen(fileName, "w");
    if(fp == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }

    fprintf(fp, "ID\tName\t\t\tEmail\n");
    for(int i=0; i<db.count; i++) {
        fprintf(fp, "%d\t%-20s\t%-30s\n", db.records[i].id, db.records[i].name, db.records[i].email);
    }

    fclose(fp);
    printf("Data saved to file successfully.\n");
}