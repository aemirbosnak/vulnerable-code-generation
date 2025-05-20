//FormAI DATASET v1.0 Category: Database simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_RECORDS 1000

typedef struct {
    char name[MAX_LENGTH];
    int age;
    float balance;
    int id;
} Record;

Record db[MAX_RECORDS];
int num_records = 0;

void print_menu()
{
    printf("1. Add a new record\n");
    printf("2. Search for a record\n");
    printf("3. Update a record\n");
    printf("4. Delete a record\n");
    printf("5. List all records\n");
    printf("6. Exit\n");
}

void add_record()
{
    // Prompt user for input
    printf("Enter name: ");
    scanf("%s", db[num_records].name);
    printf("Enter age: ");
    scanf("%d", &db[num_records].age);
    printf("Enter balance: ");
    scanf("%f", &db[num_records].balance);

    // Generate unique ID
    db[num_records].id = num_records;

    // Increment number of records in database
    num_records++;

    printf("Record added successfully.\n");
}

void search_record()
{
    // Prompt user for input
    printf("Enter name: ");
    char search_name[MAX_LENGTH];
    scanf("%s", search_name);

    // Linear search through database
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(db[i].name, search_name) == 0) {
            printf("\nID: %d\n", db[i].id);
            printf("Name: %s\n", db[i].name);
            printf("Age: %d\n", db[i].age);
            printf("Balance: %.2f\n", db[i].balance);
            return;
        }
    }

    printf("Record not found.\n");
}

void update_record()
{
    // Prompt user for input
    printf("Enter name: ");
    char search_name[MAX_LENGTH];
    scanf("%s", search_name);

    // Linear search through database
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(db[i].name, search_name) == 0) {
            printf("\nEnter new name (or press enter to keep as is): ");
            char new_name[MAX_LENGTH];
            getchar();
            fgets(new_name, MAX_LENGTH, stdin);
            new_name[strcspn(new_name, "\n")] = '\0';
            if (strlen(new_name) > 0) {
                strncpy(db[i].name, new_name, MAX_LENGTH);
            }

            printf("Enter new age (or -1 to keep as is): ");
            int new_age;
            scanf("%d", &new_age);
            if (new_age > 0) {
                db[i].age = new_age;
            }

            printf("Enter new balance (or -1 to keep as is): ");
            float new_balance;
            scanf("%f", &new_balance);
            if (new_balance > 0) {
                db[i].balance = new_balance;
            }

            printf("Record updated successfully.\n");
            return;
        }
    }

    printf("Record not found.\n");
}

void delete_record()
{
    // Prompt user for input
    printf("Enter name: ");
    char search_name[MAX_LENGTH];
    scanf("%s", search_name);

    // Linear search through database
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(db[i].name, search_name) == 0) {
            // Shift all records after the deleted record up by one
            int j;
            for (j = i; j < num_records - 1; j++) {
                db[j] = db[j+1];
            }

            // Decrement number of records in database
            num_records--;

            printf("Record deleted successfully.\n");
            return;
        }
    }

    printf("Record not found.\n");
}

void list_records()
{
    int i;
    for (i = 0; i < num_records; i++) {
        printf("\nID: %d\n", db[i].id);
        printf("Name: %s\n", db[i].name);
        printf("Age: %d\n", db[i].age);
        printf("Balance: %.2f\n", db[i].balance);
    }
}

int main()
{
    while (1) {
        print_menu();
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                search_record();
                break;
            case 3:
                update_record();
                break;
            case 4:
                delete_record();
                break;
            case 5:
                list_records();
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}