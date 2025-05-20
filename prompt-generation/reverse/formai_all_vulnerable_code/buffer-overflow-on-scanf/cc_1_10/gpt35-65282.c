//FormAI DATASET v1.0 Category: Database simulation ; Style: future-proof
/* A C database simulation example program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 50

/* Define the record structure */
struct record {
    char name[20];
    int id;
    float salary;
};

/* Function to print the menu */
void print_menu() {
    printf("\n\n  Database Simulation: \n");
    printf("------------------------\n");
    printf("1. Add a record\n");
    printf("2. Delete a record\n");
    printf("3. Update a record\n");
    printf("4. Search for a record\n");
    printf("5. Display all records\n");
    printf("6. Exit program\n\n");
}

/* Function to add a record */
void add_record(struct record *records, int *num_records) {
    if (*num_records == MAX_RECORDS) {
        printf("Database is full, cannot add more records.\n");
        return;
    }

    printf("Enter the name of the employee: ");
    scanf("%s", records[*num_records].name);
    printf("Enter the employee ID: ");
    scanf("%d", &records[*num_records].id);
    printf("Enter the employee salary: ");
    scanf("%f", &records[*num_records].salary);
    
    (*num_records)++;
}

/* Function to delete a record */
void delete_record(struct record *records, int *num_records) {
    int id, i, j;

    printf("Enter the ID of the record you want to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *num_records; i++) {
        if (records[i].id == id) {
            for (j = i; j < (*num_records - 1); j++) {
                strcpy(records[j].name, records[j+1].name);
                records[j].id = records[j+1].id;
                records[j].salary = records[j+1].salary;
            }
            (*num_records)--;
            printf("Record with ID %d deleted successfully.\n", id);
            return;
        }
    }

    printf("Record with ID %d not found.\n", id);
}

/* Function to update a record */
void update_record(struct record *records, int num_records) {
    int id, choice, i;

    printf("Enter the ID of the record you want to update: ");
    scanf("%d", &id);

    for (i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            printf("What do you want to update?\n");
            printf("1. Name\n");
            printf("2. ID\n");
            printf("3. Salary\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("Enter the new name: ");
                    scanf("%s", records[i].name);
                    break;
                case 2:
                    printf("Enter the new ID: ");
                    scanf("%d", &records[i].id);
                    break;
                case 3:
                    printf("Enter the new salary: ");
                    scanf("%f", &records[i].salary);
                    break;
                default:
                    printf("Invalid choice.\n");
            }

            printf("Record updated successfully.\n");
            return;
        }
    }

    printf("Record with ID %d not found.\n", id);
}

/* Function to search for a record */
void search_record(struct record *records, int num_records) {
    int id, i;

    printf("Enter the ID of the record you want to search: ");
    scanf("%d", &id);

    for (i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            printf("Record found:\n");
            printf("Name: %s, ID: %d, Salary: %.2f\n", records[i].name, records[i].id, records[i].salary);
            return;
        }
    }

    printf("Record with ID %d not found.\n", id);
}

/* Function to display all records */
void display_records(struct record *records, int num_records) {
    int i;

    if (num_records == 0) {
        printf("No records found.\n");
        return;
    }

    printf("All records in database:\n");
    for (i = 0; i < num_records; i++) {
        printf("Name: %s, ID: %d, Salary: %.2f\n", records[i].name, records[i].id, records[i].salary);
    }
}

/* Main function */
int main() {
    struct record records[MAX_RECORDS];
    int num_records = 0;
    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                delete_record(records, &num_records);
                break;
            case 3:
                update_record(records, num_records);
                break;
            case 4:
                search_record(records, num_records);
                break;
            case 5:
                display_records(records, num_records);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 6);

    return 0;
}