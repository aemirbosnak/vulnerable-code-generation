//FormAI DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char name[20];
    int age;
};

void write_record(struct Record records[], int *num_records) {
    struct Record record;
    printf("Enter ID: ");
    scanf("%d", &record.id);
    printf("Enter Name: ");
    scanf("%s", record.name);
    printf("Enter Age: ");
    scanf("%d", &record.age);
    records[*num_records] = record;
    ++(*num_records);
}

void update_record(struct Record records[], int num_records) {
    int id;
    printf("Enter ID of record to update: ");
    scanf("%d", &id);
    for(int i = 0; i < num_records; ++i) {
        if(records[i].id == id) {
            printf("Enter Name: ");
            scanf("%s", records[i].name);
            printf("Enter Age: ");
            scanf("%d", &records[i].age);
            printf("Record updated successfully.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

void delete_record(struct Record records[], int *num_records) {
    int id;
    printf("Enter ID of record to delete: ");
    scanf("%d", &id);
    for(int i = 0; i < *num_records; ++i) {
        if(records[i].id == id) {
            --(*num_records);
            for(int j = i; j < *num_records; ++j) {
                records[j] = records[j+1];
            }
            printf("Record deleted successfully.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

void display_all_records(struct Record records[], int num_records) {
    printf("ID\tName\tAge\n");
    for(int i = 0; i < num_records; ++i) {
        printf("%d\t%s\t%d\n", records[i].id, records[i].name, records[i].age);
    }
}

int main() {
    struct Record records[MAX_RECORDS];
    int num_records = 0;
    int choice = 0;

    while(choice != 5) {
        printf("1. Add Record\n");
        printf("2. Update Record\n");
        printf("3. Delete Record\n");
        printf("4. Display All Records\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                if(num_records == MAX_RECORDS) {
                    printf("Database is full.\n");
                }
                else {
                    write_record(records, &num_records);
                    printf("Record added successfully.\n");
                }
                break;
            case 2:
                update_record(records, num_records);
                break;
            case 3:
                delete_record(records, &num_records);
                break;
            case 4:
                display_all_records(records, num_records);
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}