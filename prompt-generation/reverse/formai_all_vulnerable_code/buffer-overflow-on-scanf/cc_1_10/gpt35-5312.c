//FormAI DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 12

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

void print_menu() {
    printf("DATABASE SIMULATION MENU\n");
    printf("1. Add Record\n");
    printf("2. Remove Record\n");
    printf("3. Edit Record\n");
    printf("4. View Record\n");
    printf("5. Exit\n");
}

Record create_record(int id, char *name, char *email, char *phone) {
    Record record;
    record.id = id;
    strncpy(record.name, name, MAX_NAME_LENGTH);
    strncpy(record.email, email, MAX_EMAIL_LENGTH);
    strncpy(record.phone, phone, MAX_PHONE_LENGTH);
    return record;
}

void add_record(Record *records[], int *num_records) {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];

    printf("Enter name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    size_t len = strlen(name);
    if (len > 0 && name[len-1] == '\n') name[len-1] = '\0';

    printf("Enter email: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    len = strlen(email);
    if (len > 0 && email[len-1] == '\n') email[len-1] = '\0';

    printf("Enter phone: ");
    fgets(phone, MAX_PHONE_LENGTH, stdin);
    len = strlen(phone);
    if (len > 0 && phone[len-1] == '\n') phone[len-1] = '\0';

    Record record = create_record(*num_records + 1, name, email, phone);
    records[*num_records] = (Record *) malloc(sizeof(Record));
    memcpy(records[*num_records], &record, sizeof(Record));
    *num_records += 1;

    printf("Record added successfully!\n");
}

void remove_record(Record *records[], int *num_records) {
    printf("Enter record id to be removed: ");
    int id;
    scanf("%d", &id);
    getchar();

    int index = -1;
    for (int i = 0; i < *num_records; i++) {
        if (records[i]->id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Record with id %d not found!\n", id);
        return;
    }

    free(records[index]);

    for (int i = index; i < *num_records - 1; i++) {
        records[i] = records[i+1];
        records[i]->id = i+1;
    }

    *num_records -= 1;

    printf("Record removed successfully!\n");
}

void edit_record(Record *records[], int num_records) {
    printf("Enter record id to be edited: ");
    int id;
    scanf("%d", &id);
    getchar();

    int index = -1;
    for (int i = 0; i < num_records; i++) {
        if (records[i]->id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Record with id %d not found!\n", id);
        return;
    }

    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];

    printf("Enter new name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    size_t len = strlen(name);
    if (len > 0 && name[len-1] == '\n') name[len-1] = '\0';
    strncpy(records[index]->name, name, MAX_NAME_LENGTH);

    printf("Enter new email: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    len = strlen(email);
    if (len > 0 && email[len-1] == '\n') email[len-1] = '\0';
    strncpy(records[index]->email, email, MAX_EMAIL_LENGTH);

    printf("Enter new phone: ");
    fgets(phone, MAX_PHONE_LENGTH, stdin);
    len = strlen(phone);
    if (len > 0 && phone[len-1] == '\n') phone[len-1] = '\0';
    strncpy(records[index]->phone, phone, MAX_PHONE_LENGTH);

    printf("Record edited successfully!\n");
}

void view_record(Record *records[], int num_records) {
    printf("Enter record id to view: ");
    int id;
    scanf("%d", &id);
    getchar();

    int index = -1;
    for (int i = 0; i < num_records; i++) {
        if (records[i]->id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Record with id %d not found!\n", id);
        return;
    }

    Record record = *records[index];

    printf("Record ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Email: %s\n", record.email);
    printf("Phone: %s\n", record.phone);
}

int main() {
    Record *records[100];
    int num_records = 0;
    int choice;

    do {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                remove_record(records, &num_records);
                break;
            case 3:
                edit_record(records, num_records);
                break;
            case 4:
                view_record(records, num_records);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }

        printf("\n");

    } while (choice != 5);

    // free memory used by records
    for (int i = 0; i < num_records; i++) {
        free(records[i]);
    }

    return 0;
}