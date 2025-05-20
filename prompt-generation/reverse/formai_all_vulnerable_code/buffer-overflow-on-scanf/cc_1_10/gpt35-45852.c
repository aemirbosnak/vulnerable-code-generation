//FormAI DATASET v1.0 Category: Database simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct record {
    int id;
    char name[50];
    char address[100];
    char phone[15];
};

void add_record(struct record *records, int *count);
void view_record(struct record *records, int count);
void search_record(struct record *records, int count);

int main()
{
    struct record records[MAX_RECORDS];
    int count = 0;
    int choice;

    printf("Welcome to the Database Simulation Program!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Search Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record(records, &count);
                break;
            case 2:
                view_record(records, count);
                break;
            case 3:
                search_record(records, count);
                break;
            case 4:
                printf("\nThank you for using the Database Simulation Program!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void add_record(struct record *records, int *count)
{
    if (*count >= MAX_RECORDS) {
        printf("\nDatabase full! Cannot add more records.\n");
        return;
    }

    printf("\nEnter details for Record %d:\n", *count + 1);

    records[*count].id = *count + 1;

    printf("Name: ");
    scanf("%s", records[*count].name);

    printf("Address: ");
    scanf("%s", records[*count].address);

    printf("Phone: ");
    scanf("%s", records[*count].phone);

    printf("\nRecord added successfully!\n");

    (*count)++;
}

void view_record(struct record *records, int count)
{
    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n%-5s %-20s %-30s %-15s\n", "ID", "Name", "Address", "Phone");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-30s %-15s\n", records[i].id, records[i].name, records[i].address, records[i].phone);
    }
}

void search_record(struct record *records, int count)
{
    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    char search_name[50];
    int found = 0;

    printf("\nEnter name to search: ");
    scanf("%s", search_name);

    printf("\n%-5s %-20s %-30s %-15s\n", "ID", "Name", "Address", "Phone");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].name, search_name) == 0) {
            printf("%-5d %-20s %-30s %-15s\n", records[i].id, records[i].name, records[i].address, records[i].phone);
            found = 1;
        }
    }

    if (!found) {
        printf("\nRecord not found!\n");
    }
}