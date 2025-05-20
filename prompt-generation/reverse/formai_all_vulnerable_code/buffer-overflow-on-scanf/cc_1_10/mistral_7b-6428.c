//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 5

typedef struct {
    char name[50];
    int age;
    float weight;
    char address[100];
    char phone[15];
} Record;

Record database[MAX_RECORDS];
int count = 0;

void add_record(Record new_record) {
    if (count < MAX_RECORDS) {
        database[count] = new_record;
        count++;
    } else {
        printf("Database is full.\n");
    }
}

void search_record(char name[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("\nName : %s\n", database[i].name);
            printf("Age : %d\n", database[i].age);
            printf("Weight : %.2f\n", database[i].weight);
            printf("Address : %s\n", database[i].address);
            printf("Phone : %s\n", database[i].phone);
            return;
        }
    }

    printf("Record not found.\n");
}

int main() {
    char name[50];
    char command;
    Record new_record;

    while (1) {
        printf("\nDatabase Simulation\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Quit\n");
        printf("Enter command : ");
        scanf("%c", &command);

        switch (command) {
            case '1':
                printf("Enter name : ");
                scanf("%s", name);
                printf("Enter age : ");
                scanf("%d", &new_record.age);
                printf("Enter weight : ");
                scanf("%f", &new_record.weight);
                printf("Enter address : ");
                scanf("%s", new_record.address);
                printf("Enter phone : ");
                scanf("%s", new_record.phone);

                add_record(new_record);
                break;

            case '2':
                printf("Enter name to search : ");
                scanf("%s", name);
                search_record(name);
                break;

            case '3':
                printf("Quitting...\n");
                exit(0);

            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}