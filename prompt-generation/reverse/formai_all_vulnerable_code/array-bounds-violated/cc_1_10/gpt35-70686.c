//FormAI DATASET v1.0 Category: Database Indexing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

typedef struct {
    int id;
    int index;
} Index;

Index name_index[MAX_RECORDS];
int num_name_index = 0;

Index phone_index[MAX_RECORDS];
int num_phone_index = 0;

Record records[MAX_RECORDS];
int num_records = 0;

void add_record() {
    Record new_record;
    printf("Enter name: ");
    fgets(new_record.name, MAX_NAME_LENGTH, stdin);
    strtok(new_record.name, "\n"); // remove newline character from input
    printf("Enter address: ");
    fgets(new_record.address, MAX_ADDRESS_LENGTH, stdin);
    strtok(new_record.address, "\n");
    printf("Enter phone: ");
    fgets(new_record.phone, MAX_PHONE_LENGTH, stdin);
    strtok(new_record.phone, "\n");
    new_record.id = num_records++; // assign unique ID to new record
    
    // add new record to records array
    records[new_record.id] = new_record;
    
    // add new record to name_index array
    Index name_entry;
    name_entry.id = new_record.id;
    name_entry.index = num_name_index++;
    for (int i = 0; i < num_name_index - 1; i++) {
        if (strcmp(records[name_index[i].id].name, new_record.name) > 0) {
            // shift all entries to the right to make space for the new entry
            for (int j = num_name_index - 1; j > i; j--) {
                name_index[j] = name_index[j - 1];
                name_index[j].index++;
            }
            name_index[i] = name_entry;
            break;
        }
    }
    if (name_index[num_name_index - 1].id != new_record.id) {
        // the new record has the latest name so it goes at the end of the array
        name_index[num_name_index - 1] = name_entry;
    }
    
    // add new record to phone_index array
    Index phone_entry;
    phone_entry.id = new_record.id;
    phone_entry.index = num_phone_index++;
    for (int i = 0; i < num_phone_index - 1; i++) {
        if (strcmp(records[phone_index[i].id].phone, new_record.phone) > 0) {
            // shift all entries to the right to make space for the new entry
            for (int j = num_phone_index - 1; j > i; j--) {
                phone_index[j] = phone_index[j - 1];
                phone_index[j].index++;
            }
            phone_index[i] = phone_entry;
            break;
        }
    }
    if (phone_index[num_phone_index - 1].id != new_record.id) {
        // the new record has the latest phone so it goes at the end of the array
        phone_index[num_phone_index - 1] = phone_entry;
    }
}

void delete_record() {
    int id_to_delete;
    printf("Enter ID to delete: ");
    scanf("%d", &id_to_delete);
    getchar(); // remove newline character from input
    
    // remove record from records array
    for (int i = id_to_delete; i < num_records - 1; i++) {
        records[i] = records[i + 1];
        records[i].id--;
    }
    num_records--;
    
    // remove record from name_index array
    for (int i = 0; i < num_name_index; i++) {
        if (name_index[i].id == id_to_delete) {
            for (int j = i + 1; j < num_name_index; j++) {
                name_index[j].index--;
            }
            for (int j = i; j < num_name_index - 1; j++) {
                name_index[j] = name_index[j + 1];
            }
            num_name_index--;
            break;
        }
    }
    
    // remove record from phone_index array
    for (int i = 0; i < num_phone_index; i++) {
        if (phone_index[i].id == id_to_delete) {
            for (int j = i + 1; j < num_phone_index; j++) {
                phone_index[j].index--;
            }
            for (int j = i; j < num_phone_index - 1; j++) {
                phone_index[j] = phone_index[j + 1];
            }
            num_phone_index--;
            break;
        }
    }
}

void find_record_by_name() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search for: ");
    fgets(search_name, MAX_NAME_LENGTH, stdin);
    strtok(search_name, "\n"); // remove newline character from input
    
    // binary search for records with matching name
    int left = 0;
    int right = num_name_index - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int id = name_index[mid].id;
        if (strcmp(records[id].name, search_name) == 0) {
            printf("ID: %d, Name: %s, Address: %s, Phone: %s\n", 
                records[id].id, records[id].name, records[id].address, records[id].phone);
            return;
        }
        else if (strcmp(records[id].name, search_name) < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    printf("No record found with name '%s'\n", search_name);
}

void find_record_by_phone() {
    char search_phone[MAX_PHONE_LENGTH];
    printf("Enter phone to search for: ");
    fgets(search_phone, MAX_PHONE_LENGTH, stdin);
    strtok(search_phone, "\n"); // remove newline character from input
    
    // binary search for records with matching phone
    int left = 0;
    int right = num_phone_index - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int id = phone_index[mid].id;
        if (strcmp(records[id].phone, search_phone) == 0) {
            printf("ID: %d, Name: %s, Address: %s, Phone: %s\n", 
                records[id].id, records[id].name, records[id].address, records[id].phone);
            return;
        }
        else if (strcmp(records[id].phone, search_phone) < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    printf("No record found with phone '%s'\n", search_phone);
}

int main() {
    int choice;
    do {
        printf("1. Add record\n");
        printf("2. Delete record\n");
        printf("3. Find record by name\n");
        printf("4. Find record by phone\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // remove newline character from input
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                delete_record();
                break;
            case 3:
                find_record_by_name();
                break;
            case 4:
                find_record_by_phone();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    } while (choice != 5);
    
    return 0;
}