//FormAI DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char location[50];
} Record;

Record* db;

int num_records = 0;
int max_records = 10;

void add_record(int id, char* name, char* location) {
    if (num_records >= max_records) {
        printf("Database is full!\n");
        return;
    }
    db[num_records].id = id;
    strncpy(db[num_records].name, name, 50);
    strncpy(db[num_records].location, location, 50);
    num_records++;
    printf("Record added successfully!\n");
}

void delete_record(int id) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (db[i].id == id) {
            break;
        }
    }
    if (i == num_records) {
        printf("Record not found!\n");
        return;
    }
    for (; i < num_records - 1; i++) {
        db[i] = db[i+1];
    }
    num_records--;
    printf("Record deleted successfully!\n");
}

void print_record(int id) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (db[i].id == id) {
            printf("ID: %d\n", db[i].id);
            printf("Name: %s\n", db[i].name);
            printf("Location: %s\n", db[i].location);
            return;
        }
    }
    printf("Record not found!\n");
}

void list_records() {
    int i;
    for (i = 0; i < num_records; i++) {
        print_record(db[i].id);
    }
}

int main() {
    db = (Record*) malloc(max_records * sizeof(Record));
    char command[50];
    int id;
    char name[50];
    char location[50];
    printf("Welcome to the database simulation!\n");
    printf("Enter 'add id name location' to add a record.\n");
    printf("Enter 'delete id' to delete a record.\n");
    printf("Enter 'print id' to print a record.\n");
    printf("Enter 'list' to list all records.\n");
    printf("Enter 'exit' to exit the program.\n");
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            scanf("%d %s %s", &id, name, location);
            add_record(id, name, location);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%d", &id);
            delete_record(id);
        } else if (strcmp(command, "print") == 0) {
            scanf("%d", &id);
            print_record(id);
        } else if (strcmp(command, "list") == 0) {
            list_records();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }
    free(db);
    printf("Thank you for using the database simulation!\n");
    return 0;
}