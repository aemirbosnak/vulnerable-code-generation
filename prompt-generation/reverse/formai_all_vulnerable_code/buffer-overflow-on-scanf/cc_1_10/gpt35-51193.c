//FormAI DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECORDS 100

struct record {
    int id;
    char name[100];
    char email[100];
};

int num_records = 0;
struct record records[MAX_RECORDS];

void add_record() {
    if (num_records >= MAX_RECORDS) {
        printf("Error: database is full\n");
        return;
    }

    struct record new_record;
    
    printf("Enter ID: ");
    scanf("%d", &new_record.id);
    
    printf("Enter name: ");
    scanf("%s", new_record.name);
    
    printf("Enter email: ");
    scanf("%s", new_record.email);
    
    records[num_records++] = new_record;
    
    printf("Record added succesfully\n");
}

void print_record(struct record* r) {
    printf("ID: %d\n", r->id);
    printf("Name: %s\n", r->name);
    printf("Email: %s\n", r->email);
    printf("\n");
}

void list_records() {
    if (num_records == 0) {
        printf("No records found\n");
        return;
    }
    
    printf("---- Records ----\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d) ", i+1);
        print_record(&records[i]);
    }
}

void delete_record(int id) {
    for (int i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            memmove(&records[i], &records[i+1], sizeof(struct record) * (num_records - i - 1));
            num_records--;
            printf("Record deleted succesfully\n");
            return;
        }
    }
    
    printf("Error: record not found\n");
}

int main() {
    while (1) {
        printf("---- Database Simulation ----\n");
        printf("1) Add Record\n");
        printf("2) List Records\n");
        printf("3) Delete Record\n");
        printf("4) Exit\n");
        
        int choice;
        printf("Enter  your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                list_records();
                break;
            case 3: {
                int id;
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                delete_record(id);
                break;
            }
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Error: invalid choice\n");
                break;
        }
        
        printf("\n");
    }
}