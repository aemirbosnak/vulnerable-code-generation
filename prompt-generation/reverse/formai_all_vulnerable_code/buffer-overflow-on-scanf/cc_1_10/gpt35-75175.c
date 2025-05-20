//FormAI DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 1000

typedef struct record {
    char id[10];
    char name[20];
    char address[30];
    char phone[15];
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void add_record(char id[], char name[], char address[], char phone[]);
void delete_record(char id[]);
int search_record(char id[]);
void print_records();
void clear_database();

int main() {
    char command[20];
    char id[10], name[20], address[30], phone[15];

    printf("Welcome to the database simulator.\n\n");

    while(1) {
        printf("Enter a command: ");
        scanf("%s", command);

        if(strcmp(command, "add") == 0) {
            printf("Enter ID, name, address, and phone number: ");
            scanf("%s %s %s %s", id, name, address, phone);
            add_record(id, name, address, phone);
            printf("Record added successfully.\n\n");
        }
        else if(strcmp(command, "delete") == 0) {
            printf("Enter ID to delete: ");
            scanf("%s", id);
            delete_record(id);
        }
        else if(strcmp(command, "search") == 0) {
            printf("Enter ID to search: ");
            scanf("%s", id);
            int index = search_record(id);
            if(index == -1) {
                printf("Record not found.\n\n");
            }
            else {
                printf("Record found:\nID: %s\nName: %s\nAddress: %s\nPhone: %s\n\n", 
                database[index].id, database[index].name, database[index].address, database[index].phone);
            }
        }
        else if(strcmp(command, "print") == 0) {
            print_records();
        }
        else if(strcmp(command, "clear") == 0) {
            clear_database();
            printf("Database cleared.\n\n");
        }
        else if(strcmp(command, "quit") == 0) {
            printf("Exiting program...\n");
            exit(0);
        }
        else {
            printf("Invalid command. Please try again.\n\n");
        }
    }
}

void add_record(char id[], char name[], char address[], char phone[]) {
    strcpy(database[num_records].id, id);
    strcpy(database[num_records].name, name);
    strcpy(database[num_records].address, address);
    strcpy(database[num_records].phone, phone);
    num_records++;
}

void delete_record(char id[]) {
    int index = search_record(id);

    if(index == -1) {
        printf("Record not found.\n\n");
    }
    else {
        for(int i = index; i < num_records - 1; i++) {
            database[i] = database[i + 1];
        }
        num_records--;
        printf("Record deleted successfully.\n\n");
    }
}

int search_record(char id[]) {
    for(int i = 0; i < num_records; i++) {
        if(strcmp(database[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

void print_records() {
    if(num_records == 0) {
        printf("Database is empty.\n\n");
    }
    else {
        printf("List of records:\n");
        for(int i = 0; i < num_records; i++) {
            printf("ID: %s\nName: %s\nAddress: %s\nPhone: %s\n\n", 
            database[i].id, database[i].name, database[i].address, database[i].phone);
        }
    }
}

void clear_database() {
    for(int i = 0; i < num_records; i++) {
        strcpy(database[i].id, "");
        strcpy(database[i].name, "");
        strcpy(database[i].address, "");
        strcpy(database[i].phone, "");
    }
    num_records = 0;
}