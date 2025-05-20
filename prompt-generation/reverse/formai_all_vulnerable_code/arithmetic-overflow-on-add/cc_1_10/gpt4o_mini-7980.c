//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_WORD_LENGTH 20

struct Record {
    char name[MAX_NAME_LENGTH];
    int age;
    float salary;
};

struct DataBase {
    struct Record records[MAX_RECORDS];
    int count;
};

// Function prototypes
void initDatabase(struct DataBase *db);
void addRecord(struct DataBase *db);
void displayRecords(const struct DataBase *db);
void searchRecord(const struct DataBase *db, const char *name);
void sortRecords(struct DataBase *db);
void topNSalaries(const struct DataBase *db, int n);

int main() {
    struct DataBase db;
    initDatabase(&db);
    
    int choice;
    
    printf("Welcome to the Exciting Data Mining Program!\n");
    do {
        printf("\nChoose an option:\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Sort Records by Salary\n");
        printf("5. Top N Salaries\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(&db);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3: {
                char name[MAX_NAME_LENGTH];
                printf("Enter name to search: ");
                scanf("%s", name);
                searchRecord(&db, name);
                break;
            }
            case 4:
                sortRecords(&db);
                printf("Records sorted by salary!\n");
                break;
            case 5: {
                int n;
                printf("How many top salaries do you want to see? ");
                scanf("%d", &n);
                topNSalaries(&db, n);
                break;
            }
            case 0:
                printf("Exiting the program! Stay curious!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void initDatabase(struct DataBase *db) {
    db->count = 0;
}

void addRecord(struct DataBase *db) {
    if (db->count < MAX_RECORDS) {
        printf("Enter name: ");
        scanf("%s", db->records[db->count].name);
        printf("Enter age: ");
        scanf("%d", &db->records[db->count].age);
        printf("Enter salary: ");
        scanf("%f", &db->records[db->count].salary);
        db->count++;
        printf("Record added successfully!\n");
    } else {
        printf("Database is full! Cannot add more records.\n");
    }
}

void displayRecords(const struct DataBase *db) {
    if (db->count == 0) {
        printf("No records to display!\n");
        return;
    }
    
    printf("\nRecords:\n");
    for (int i = 0; i < db->count; ++i) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", 
                db->records[i].name, 
                db->records[i].age, 
                db->records[i].salary);
    }
}

void searchRecord(const struct DataBase *db, const char *name) {
    for (int i = 0; i < db->count; ++i) {
        if (strcmp(db->records[i].name, name) == 0) {
            printf("Record Found! Name: %s, Age: %d, Salary: %.2f\n", 
                   db->records[i].name, 
                   db->records[i].age, 
                   db->records[i].salary);
            return;
        }
    }
    printf("Record with name '%s' not found!\n", name);
}

void sortRecords(struct DataBase *db) {
    for (int i = 0; i < db->count - 1; ++i) {
        for (int j = i + 1; j < db->count; ++j) {
            if (db->records[i].salary < db->records[j].salary) {
                struct Record temp = db->records[i];
                db->records[i] = db->records[j];
                db->records[j] = temp;
            }
        }
    }
}

void topNSalaries(const struct DataBase *db, int n) {
    if (n > db->count) {
        printf("There are only %d records in the database!\n", db->count);
        return;
    }
    
    printf("\nTop %d Salaries:\n", n);
    for (int i = 0; i < n; ++i) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", 
               db->records[i].name, 
               db->records[i].age, 
               db->records[i].salary);
    }
}