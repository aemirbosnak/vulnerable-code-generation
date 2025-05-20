//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct record {
    char name[50];
    char address[100];
    char phone[15];
    char email[50];
};

void read_record(struct record *record) {
    printf("Enter name: ");
    scanf("%s", record->name);

    printf("Enter address: ");
    scanf("%s", record->address);

    printf("Enter phone: ");
    scanf("%s", record->phone);

    printf("Enter email: ");
    scanf("%s", record->email);
}

void display_record(struct record *record) {
    printf("Name: %s\n", record->name);
    printf("Address: %s\n", record->address);
    printf("Phone: %s\n", record->phone);
    printf("Email: %s\n", record->email);
}

int main() {
    struct record *records = (struct record*)malloc(100 * sizeof(struct record));
    int num_records = 0;

    printf("Enter number of records: ");
    scanf("%d", &num_records);

    for (int i = 0; i < num_records; i++) {
        struct record record;
        read_record(&record);
        records[i] = record;
    }

    printf("Records:\n");
    for (int i = 0; i < num_records; i++) {
        display_record(&records[i]);
        printf("\n");
    }

    free(records);
    return 0;
}