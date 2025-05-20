//FormAI DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_RECORDS 100

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Record;

void print_menu() {
    printf("1. Add a new record\n");
    printf("2. View all records\n");
    printf("3. Delete a record\n");
    printf("4. Search for a record\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}

int get_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

void get_record(Record *record) {
    printf("Enter username: ");
    scanf("%s", record->username);
    printf("Enter password: ");
    scanf("%s", record->password);
}

void add_record(Record records[], int *num_records) {
    if (*num_records == MAX_RECORDS) {
        printf("Error: Maximum number of records reached\n");
        return;
    }
    get_record(&records[*num_records]);
    (*num_records)++;
    printf("Record added successfully\n");
}

void view_all_records(Record records[], int num_records) {
    if (num_records == 0) {
        printf("No records found\n");
        return;
    }
    printf("Username                 Password\n");
    printf("---------------------------------\n");
    for (int i = 0; i < num_records; i++) {
        printf("%-20s%-20s\n", records[i].username, records[i].password);
    }
}

void delete_record(Record records[], int *num_records) {
    if (*num_records == 0) {
        printf("No records found\n");
        return;
    }
    printf("Enter username of record to delete: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);
    for (int i = 0; i < *num_records; i++) {
        if (strcmp(records[i].username, username) == 0) {
            for (int j = i; j < *num_records - 1; j++) {
                records[j] = records[j+1];
            }
            (*num_records)--;
            printf("Record deleted successfully\n");
            return;
        }
    }
    printf("Record not found\n");
}

void search_record(Record records[], int num_records) {
    if (num_records == 0) {
        printf("No records found\n");
        return;
    }
    printf("Enter username to search for: ");
    char username[MAX_USERNAME_LENGTH];
    scanf("%s", username);
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].username, username) == 0) {
            printf("Username                 Password\n");
            printf("---------------------------------\n");
            printf("%-20s%-20s\n", records[i].username, records[i].password);
            return;
        }
    }
    printf("Record not found\n");
}

int main() {
    Record records[MAX_RECORDS];
    int num_records = 0;
    
    while (1) {
        print_menu();
        int choice = get_choice();
        
        switch (choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                view_all_records(records, num_records);
                break;
            case 3:
                delete_record(records, &num_records);
                break;
            case 4:
                search_record(records, num_records);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}