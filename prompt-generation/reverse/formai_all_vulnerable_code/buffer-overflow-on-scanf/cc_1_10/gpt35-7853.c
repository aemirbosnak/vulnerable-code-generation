//FormAI DATASET v1.0 Category: Database simulation ; Style: content
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct database {
    int id;
    char name[20];
} database;

void display_menu() {
    printf("\n-----Database Simulation-----\n");
    printf("1. Add a record\n");
    printf("2. Display all records\n");
    printf("3. Search records by name\n");
    printf("4. Delete a record by id\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void add_record(database *db, int *count) {
    printf("\nEnter name: ");
    scanf("%s", db[*count].name);
    printf("Enter id: ");
    scanf("%d", &db[*count].id);
    (*count)++;
    printf("\nRecord added successfully!\n");
}

void display_records(database *db, int count) {
    printf("\nId\tName\n");
    for(int i=0; i<count; i++) {
        printf("%d\t%s\n", db[i].id, db[i].name);
    }
}

void search_record(database *db, int count) {
    char name[20];
    printf("\nEnter name to search: ");
    scanf("%s", name);
    int found = 0; // flag variable to check if record is found or not
    printf("\nId\tName\n");
    for(int i=0; i<count; i++) {
        if(strcmp(db[i].name, name) == 0) {
            printf("%d\t%s\n", db[i].id, db[i].name);
            found = 1;
        }
    }
    if(!found) {
        printf("Record not found!\n");
    }
}

void delete_record(database *db, int *count) {
    int id, found = 0; // flag variable to check if record is found or not
    printf("\nEnter id to delete: ");
    scanf("%d", &id);
    for(int i=0; i<*count; i++) {
        if(db[i].id == id) {
            found = 1;
            for(int j=i; j<(*count)-1; j++) {
                db[j] = db[j+1];
            }
            (*count)--;
            printf("\nRecord deleted successfully!\n");
            break;
        }
    }
    if(!found) {
        printf("\nRecord not found!\n");
    }
}

int main() {
    database db[100]; // database can hold maximum 100 records
    int choice, count=0;
    do{
        display_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_record(db, &count);
                break;
            case 2:
                display_records(db, count);
                break;
            case 3:
                search_record(db, count);
                break;
            case 4: 
                delete_record(db, &count);
                break;
            case 5:
                printf("\nExiting program...Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again!\n");
        }
    } while(1);
    return 0;
}