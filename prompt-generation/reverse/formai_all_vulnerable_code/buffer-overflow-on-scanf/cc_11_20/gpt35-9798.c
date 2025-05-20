//FormAI DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    char name[20];
    int age;
    char email[30];
};

int main() {
    struct record db[100]; // assume a maximum of 100 records
    int num_records = 0; // keep track of how many records are in the database

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add a record\n");
        printf("2. Delete a record\n");
        printf("3. Search for a record\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the name, age, and email:\n");
            scanf("%s %d %s", db[num_records].name, &db[num_records].age, db[num_records].email);

            printf("Record added!\n");
            num_records++;
        }
        else if (choice == 2) {
            printf("Enter the name of the record to delete:\n");
            char name[20];
            scanf("%s", name);

            int i;
            for (i = 0; i < num_records; i++) {
                if (strcmp(db[i].name, name) == 0) {
                    // shift all records after this one back by one
                    int j;
                    for (j = i; j < num_records-1; j++) {
                        db[j] = db[j+1];
                    }
                    num_records--;
                    printf("Record deleted!\n");
                    break;
                }
            }

            if (i == num_records) {
                printf("Record not found.\n");
            }
        }
        else if (choice == 3) {
            printf("Enter the name of the record to search for:\n");
            char name[20];
            scanf("%s", name);

            int i;
            for (i = 0; i < num_records; i++) {
                if (strcmp(db[i].name, name) == 0) {
                    printf("Record found: %s %d %s\n", db[i].name, db[i].age, db[i].email);
                    break;
                }
            }

            if (i == num_records) {
                printf("Record not found.\n");
            }
        }
    }

    return 0;
}