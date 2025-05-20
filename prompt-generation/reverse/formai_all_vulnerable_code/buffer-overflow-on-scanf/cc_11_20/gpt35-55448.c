//FormAI DATASET v1.0 Category: Database simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

typedef struct {
    int id;
    char name[20];
    int age;
} Record;

int main(void) {
    Record database[MAX_RECORDS];
    int num_records = 0;

    // Initialization
    memset(database, 0, sizeof(database));

    // Menu Loop
    while (1) {
        printf("Select an option:\n");
        printf("(1) Add Record\n");
        printf("(2) Delete Record\n");
        printf("(3) Search Record\n");
        printf("(4) Print Database\n");
        printf("(5) Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            // Add Record
            printf("Enter ID: ");
            scanf("%d", &database[num_records].id);
            printf("Enter Name: ");
            scanf("%s", database[num_records].name);
            printf("Enter Age: ");
            scanf("%d", &database[num_records].age);

            num_records++;
        } else if (choice == 2) {
            // Delete Record
            printf("Enter ID to delete: ");
            int id;
            scanf("%d", &id);

            int i;
            for (i = 0; i < num_records; i++) {
                if (database[i].id == id) {
                    // Shift remaining records to fill gap
                    for (int j = i; j < num_records - 1; j++) {
                        database[j] = database[j+1];
                    }
                    num_records--;
                    break;
                }
            }
            if (i == num_records) {
                printf("ID not found.\n");
            }
        } else if (choice == 3) {
            // Search Record
            printf("Enter ID to search: ");
            int id;
            scanf("%d", &id);

            int i;
            for (i = 0; i < num_records; i++) {
                if (database[i].id == id) {
                    printf("ID: %d\nName: %s\nAge: %d\n", database[i].id, database[i].name, database[i].age);
                    break;
                }
            }
            if (i == num_records) {
                printf("ID not found.\n");
            }
        } else if (choice == 4) {
            // Print Database
            printf("ID\tName\tAge\n");
            for (int i = 0; i < num_records; i++) {
                printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
            }
        } else if (choice == 5) {
            // Exit
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}