//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_AGE 120

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void insert_record(char* name, int age) {
    if (num_records == MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }
    strcpy(database[num_records].name, name);
    database[num_records].age = age;
    num_records++;
}

void delete_record(char* name) {
    for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            for (int j = i; j < num_records - 1; j++) {
                strcpy(database[j].name, database[j+1].name);
                database[j].age = database[j+1].age;
            }
            num_records--;
            printf("Record for %s has been deleted!\n", name);
            return;
        }
    }
    printf("Record for %s not found!\n", name);
}

void update_record(char* name, int age) {
    for (int i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            database[i].age = age;
            printf("Record for %s has been updated!\n", name);
            return;
        }
    }
    printf("Record for %s not found!\n", name);
}

void print_database() {
    printf("Name    Age\n");
    for (int i = 0; i < num_records; i++) {
        printf("%-7s %d\n", database[i].name, database[i].age);
    }
}

void run_simulation() {
    printf("Welcome to the Database Simulation!\n\n");
    while (1) {
        printf("Please choose an option:\n");
        printf("1. Insert record\n");
        printf("2. Delete record\n");
        printf("3. Update record\n");
        printf("4. Print database\n");
        printf("5. Quit\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Please enter the person's name and age:\n");
                char name[MAX_NAME_LENGTH];
                int age;
                scanf("%s %d", name, &age);
                insert_record(name, age);
                break;
            case 2:
                printf("Please enter the name of the person to delete:\n");
                char name_to_delete[MAX_NAME_LENGTH];
                scanf("%s", name_to_delete);
                delete_record(name_to_delete);
                break;
            case 3:
                printf("Please enter the name and new age:\n");
                char name_to_update[MAX_NAME_LENGTH];
                int new_age;
                scanf("%s %d", name_to_update, &new_age);
                update_record(name_to_update, new_age);
                break;
            case 4:
                print_database();
                break;
            case 5:
                printf("Goodbye!\n");
                return;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
}

int main() {
    run_simulation();
    return 0;
}