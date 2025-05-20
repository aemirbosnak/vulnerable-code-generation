//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LEN 50
#define AGE_LEN 3
#define CITY_LEN 50

typedef struct {
    char name[NAME_LEN];
    int age;
    char city[CITY_LEN];
} Person;

Person database[MAX_RECORDS];
int record_count = 0;

void add_record() {
    if (record_count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }
    
    Person p;
    printf("Enter name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter age: ");
    scanf("%d", &p.age);
    printf("Enter city: ");
    scanf(" %[^\n]", p.city);
    
    database[record_count++] = p;
    printf("Record added successfully!\n");
}

void display_records() {
    if (record_count == 0) {
        printf("No records to display.\n");
        return;
    }
    
    printf("\n--- Records ---\n");
    for (int i = 0; i < record_count; ++i) {
        printf("Record %d: Name: %s, Age: %d, City: %s\n", 
                i + 1, database[i].name, database[i].age, database[i].city);
    }
    printf("----------------\n");
}

void search_record() {
    char search_name[NAME_LEN];
    printf("Enter name to search: ");
    scanf(" %[^\n]", search_name);
    
    int found = 0;
    for (int i = 0; i < record_count; ++i) {
        if (strcmp(database[i].name, search_name) == 0) {
            printf("Record found: Name: %s, Age: %d, City: %s\n",
                    database[i].name, database[i].age, database[i].city);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Record not found!\n");
    }
}

void delete_record() {
    char delete_name[NAME_LEN];
    printf("Enter name to delete: ");
    scanf(" %[^\n]", delete_name);
    
    int found = -1;
    for (int i = 0; i < record_count; ++i) {
        if (strcmp(database[i].name, delete_name) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        for (int i = found; i < record_count - 1; ++i) {
            database[i] = database[i + 1];
        }
        record_count--;
        printf("Record deleted successfully!\n");
    } else {
        printf("Record not found!\n");
    }
}

void menu() {
    int choice;
    do {
        printf("\n--- Database Menu ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                search_record();
                break;
            case 4:
                delete_record();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Personal Database Simulation!\n");
    menu();
    return 0;
}