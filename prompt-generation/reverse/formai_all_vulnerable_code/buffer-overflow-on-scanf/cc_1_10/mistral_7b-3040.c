//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define RECORD_SIZE 100
#define FIELD_SIZE 50

typedef struct {
    char name[FIELD_SIZE];
    int age;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void create_record(char *name, int age) {
    if (num_records < MAX_RECORDS) {
        strcpy(records[num_records].name, name);
        records[num_records].age = age;
        num_records++;
    } else {
        printf("Database is full.\n");
    }
}

void display_records() {
    int i;
    printf("\n%-10s %-10s\n", "Name", "Age");
    for (i = 0; i < num_records; i++) {
        printf("%-10s %-10d\n", records[i].name, records[i].age);
    }
}

int main() {
    char name[FIELD_SIZE];
    int age;

    while (1) {
        printf("\n1. Create Record\n2. Display Records\n3. Exit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                create_record(name, age);
                break;
            case 2:
                display_records();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}