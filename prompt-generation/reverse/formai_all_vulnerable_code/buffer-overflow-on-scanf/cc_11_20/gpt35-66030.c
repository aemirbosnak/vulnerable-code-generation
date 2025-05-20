//FormAI DATASET v1.0 Category: Database simulation ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    char name[20];
    int age;
    char address[50];
    double salary;
} Record;

int main() {
    Record records[MAX_RECORDS];

    int num_records = 0; // current number of records in our database
    char choice;

    printf("Welcome to the Database Simulator!\n");

    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Add Record\n");
        printf("2. Delete Record\n");
        printf("3. Print All Records\n");
        printf("4. Exit\n");

        scanf(" %c", &choice);

        switch(choice) {
            case '1': // Add Record
                if (num_records == MAX_RECORDS) {
                    printf("Error: Maximum number of records reached.\n");
                    break;
                }

                printf("Enter name, age, address, and salary (separated by spaces): ");
                scanf("%s %d %s %lf", records[num_records].name, &records[num_records].age, records[num_records].address, &records[num_records].salary);

                num_records++;
                printf("Record added!\n");
                break;

            case '2': // Delete Record
                if (num_records == 0) {
                    printf("Error: No records in database.\n");
                    break;
                }

                char name[20];
                printf("Enter the name of the record you want to delete: ");
                scanf("%s", name);

                int i, j;
                for (i = 0; i < num_records; i++) {
                    if (strcmp(records[i].name, name) == 0) { // found record
                        for (j = i; j < num_records-1; j++) {
                            records[j] = records[j+1]; // shift all records after it over by one
                        }
                        num_records--;
                        printf("Record deleted!\n");
                        break;
                    }
                }

                if (i == num_records) { // record not found
                    printf("Error: Record not found.\n");
                }

                break;

            case '3': // Print All Records
                if (num_records == 0) {
                    printf("No records found.\n");
                    break;
                }

                printf("\nName\tAge\tAddress\t\tSalary\n");
                for (i = 0; i < num_records; i++) {
                    printf("%s\t%d\t%s\t$%.2lf\n", records[i].name, records[i].age, records[i].address, records[i].salary);
                }
                break;

            case '4': // Exit
                printf("Goodbye!\n");
                return 0;
                break;

            default:
                printf("Error: Invalid choice.\n");
                break;
        }
    }

    return 0;
}