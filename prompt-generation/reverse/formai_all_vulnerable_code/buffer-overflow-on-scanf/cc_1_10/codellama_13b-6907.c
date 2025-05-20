//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: expert-level
// C Database Simulation Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_NAME_LEN 256
#define MAX_TABLE_SIZE 100
#define MAX_RECORDS 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char gender[10];
    char city[MAX_NAME_LEN];
    char country[MAX_NAME_LEN];
} record;

record table[MAX_TABLE_SIZE];

void print_table() {
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        printf("%s, %d, %s, %s, %s\n", table[i].name, table[i].age, table[i].gender, table[i].city, table[i].country);
    }
}

void add_record(record r) {
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        if (strcmp(table[i].name, r.name) == 0) {
            printf("Record already exists!\n");
            return;
        }
    }
    for (i = 0; i < MAX_RECORDS; i++) {
        if (table[i].name[0] == '\0') {
            table[i] = r;
            printf("Record added successfully!\n");
            return;
        }
    }
    printf("Database is full!\n");
}

void delete_record(char *name) {
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        if (strcmp(table[i].name, name) == 0) {
            table[i].name[0] = '\0';
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("Record not found!\n");
}

void update_record(char *name, int age, char *gender, char *city, char *country) {
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        if (strcmp(table[i].name, name) == 0) {
            table[i].age = age;
            strcpy(table[i].gender, gender);
            strcpy(table[i].city, city);
            strcpy(table[i].country, country);
            printf("Record updated successfully!\n");
            return;
        }
    }
    printf("Record not found!\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    int age;
    char gender[10];
    char city[MAX_NAME_LEN];
    char country[MAX_NAME_LEN];
    printf("Welcome to the Database Simulation Program!\n");
    printf("1. Add Record\n");
    printf("2. Delete Record\n");
    printf("3. Update Record\n");
    printf("4. Print Table\n");
    printf("5. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name, age, gender, city, country: ");
                scanf("%s %d %s %s %s", name, &age, gender, city, country);
                add_record((record) {name, age, gender, city, country});
                break;
            case 2:
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete_record(name);
                break;
            case 3:
                printf("Enter name, age, gender, city, country to update: ");
                scanf("%s %d %s %s %s", name, &age, gender, city, country);
                update_record(name, age, gender, city, country);
                break;
            case 4:
                print_table();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}