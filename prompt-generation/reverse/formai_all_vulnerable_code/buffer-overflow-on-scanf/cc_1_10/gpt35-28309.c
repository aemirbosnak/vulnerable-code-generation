//FormAI DATASET v1.0 Category: Database Indexing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

/* Struct for storing data in the database */
struct Record {
    int id;
    char name[MAX_SIZE];
    float salary;
};

/* Struct for storing the index */
struct Index {
    int id;
    int offset;
};

/* Function for creating the database */
void create_database() {
    FILE *fptr;
    fptr = fopen("database.txt", "w+");
    if (fptr == NULL) {
        printf("Error creating database!");
        exit(1);
    }
    fclose(fptr);
    printf("Database created successfully!\n");
}

/* Function for inserting data into the database */
void insert_data(int id, char *name, float salary) {
    FILE *fptr;
    fptr = fopen("database.txt", "a+");
    if (fptr == NULL) {
        printf("Error opening database!");
        exit(1);
    }
    fprintf(fptr, "%d\t%s\t%.2f\n", id, name, salary);
    fclose(fptr);
}

/* Function for creating the index */
void create_index() {
    FILE *fptr_database, *fptr_index;
    struct Record record;
    struct Index index;
    int offset = 0;
    fptr_database = fopen("database.txt", "r");
    fptr_index = fopen("index.txt", "w+");
    if (fptr_database == NULL || fptr_index == NULL) {
        printf("Error opening files!");
        exit(1);
    }
    while (fscanf(fptr_database, "%d %s %f", &record.id, record.name, &record.salary) != EOF) {
        index.id = record.id;
        index.offset = offset;
        fwrite(&index, sizeof(struct Index), 1, fptr_index);
        offset = ftell(fptr_database);
    }
    fclose(fptr_database);
    fclose(fptr_index);
    printf("Index created successfully!\n");
}

/* Function for searching data from the database using the index */
void search_data(int id) {
    FILE *fptr_database, *fptr_index;
    struct Record record;
    struct Index index;
    int found = 0, offset = 0;
    fptr_index = fopen("index.txt", "r");
    if (fptr_index == NULL) {
        printf("Index not found!");
        exit(1);
    }
    while (fread(&index, sizeof(struct Index), 1, fptr_index)) {
        if (index.id == id) {
            found = 1;
            offset = index.offset;
            break;
        }
    }
    fclose(fptr_index);
    if (found) {
        fptr_database = fopen("database.txt", "r");
        if (fptr_database == NULL) {
            printf("Database not found!");
            exit(1);
        }
        fseek(fptr_database, offset, SEEK_SET);
        fscanf(fptr_database, "%d %s %f", &record.id, record.name, &record.salary);
        printf("Record found!\nID: %d\nName: %s\nSalary: %.2f\n", record.id, record.name, record.salary);
        fclose(fptr_database);
    } else {
        printf("Record not found!");
    }
}

int main() {
    int choice, id;
    char name[MAX_SIZE];
    float salary;
    while (1) {
        printf("1. Create database\n");
        printf("2. Insert data into database\n");
        printf("3. Create index\n");
        printf("4. Search data in database using index\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_database();
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter salary: ");
                scanf("%f", &salary);
                insert_data(id, name, salary);
                break;
            case 3:
                create_index();
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                search_data(id);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}