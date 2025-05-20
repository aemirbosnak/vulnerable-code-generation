//FormAI DATASET v1.0 Category: Database querying ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    int age;
};

int main() {
    int num_records;
    printf("Enter the number of records: ");
    scanf("%d", &num_records);

    struct Student records[num_records];
    printf("Enter the records in the format id-name-age:\n");
    for (int i = 0; i < num_records; i++) {
        scanf("%d-%s-%d", &records[i].id, records[i].name, &records[i].age);
    }

    int choice = 1;
    while (choice != 0) {
        printf("Select a query option:\n");
        printf("1. List all records\n");
        printf("2. Search by name\n");
        printf("3. Search by age\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nID    Name                Age\n");
            printf("----------------------------------\n");
            for (int i = 0; i < num_records; i++) {
                printf("%-5d %-20s %d\n", records[i].id, records[i].name, records[i].age);
            }
            printf("\n");
        } else if (choice == 2) {
            char name[20];
            printf("\nEnter the name to search: ");
            scanf("%s", name);
            printf("\nID    Name                Age\n");
            printf("----------------------------------\n");
            int found = 0;
            for (int i = 0; i < num_records; i++) {
                if (strcmp(records[i].name, name) == 0) {
                    printf("%-5d %-20s %d\n", records[i].id, records[i].name, records[i].age);
                    found = 1;
                }
            }
            if (!found) {
                printf("No records found.\n");
            }
            printf("\n");
        } else if (choice == 3) {
            int age;
            printf("\nEnter the age to search: ");
            scanf("%d", &age);
            printf("\nID    Name                Age\n");
            printf("----------------------------------\n");
            int found = 0;
            for (int i = 0; i < num_records; i++) {
                if (records[i].age == age) {
                    printf("%-5d %-20s %d\n", records[i].id, records[i].name, records[i].age);
                    found = 1;
                }
            }
            if (!found) {
                printf("No records found.\n");
            }
            printf("\n");
        }
    }

    return 0;
}