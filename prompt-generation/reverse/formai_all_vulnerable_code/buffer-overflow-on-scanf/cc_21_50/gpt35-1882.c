//FormAI DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold database record
struct Record {
    int id;
    char name[50];
    char address[100];
    char email[50];
};

int main() {
    int choice, nRecords = 0, i;
    char filename[50];
    struct Record *records = NULL;

    // User menu
    do {
        printf("\nWelcome to the Database Simulation Program!\n");
        printf("1. Create a new database\n");
        printf("2. Open existing database\n");
        printf("3. View all records\n");
        printf("4. Add a new record\n");
        printf("5. Delete a record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Create a new database
                if (records != NULL) {
                    printf("Please close the existing database first!\n");
                    break;
                }

                printf("Enter filename to create: ");
                scanf("%s", filename);

                FILE *f = fopen(filename, "w");
                if (f == NULL) {
                    printf("Error creating database file!\n");
                    break;
                }

                fclose(f);
                printf("Database created successfully!\n");
                break;

            case 2: // Open existing database
                if (records != NULL) {
                    printf("Please close the existing database first!\n");
                    break;
                }

                printf("Enter filename to open: ");
                scanf("%s", filename);

                f = fopen(filename, "r");
                if (f == NULL) {
                    printf("Error opening database file!\n");
                    break;
                }

                // Count number of records in file
                int c;
                while ((c = fgetc(f)) != EOF) {
                    if (c == '\n') {
                        nRecords++;
                    }
                }

                // Allocate memory for records
                records = (struct Record *) malloc(nRecords * sizeof(struct Record));
                rewind(f); // Move file pointer to beginning

                // Read records from file
                for (i = 0; i < nRecords; i++) {
                    fscanf(f, "%d %[^\n] %[^\n] %[^\n]\n", &records[i].id, records[i].name, records[i].address, records[i].email);
                }

                fclose(f);
                printf("Database opened successfully!\n");
                break;

            case 3: // View all records
                if (records == NULL) {
                    printf("No database currently open!\n");
                    break;
                }

                printf("Listing all records:\n");
                for (i = 0; i < nRecords; i++) {
                    printf("%d %s %s %s\n", records[i].id, records[i].name, records[i].address, records[i].email);
                }
                break;

            case 4: // Add a new record
                if (records == NULL) {
                    printf("No database currently open!\n");
                    break;
                }

                // Allocate memory for new record
                records = (struct Record *) realloc(records, (nRecords + 1) * sizeof(struct Record));

                printf("Enter record details:\n");
                printf("ID: ");
                scanf("%d", &records[nRecords].id);
                printf("Name: ");
                scanf(" %[^\n]", records[nRecords].name);
                printf("Address: ");
                scanf(" %[^\n]", records[nRecords].address);
                printf("Email: ");
                scanf(" %[^\n]", records[nRecords].email);

                nRecords++;
                printf("Record added successfully!\n");
                break;

            case 5: // Delete a record
                if (records == NULL) {
                    printf("No database currently open!\n");
                    break;
                }

                int idToDelete, recordIndex = -1;
                printf("Enter the ID of the record to delete: ");
                scanf("%d", &idToDelete);

                // Find index of record to delete
                for (i = 0; i < nRecords; i++) {
                    if (records[i].id == idToDelete) {
                        recordIndex = i;
                        break;
                    }
                }

                if (recordIndex == -1) {
                    printf("Record not found!\n");
                    break;
                }

                // Shift all records after the record to delete back one position
                for (i = recordIndex; i < nRecords - 1; i++) {
                    records[i] = records[i + 1];
                }

                // Reallocate memory for records
                records = (struct Record *) realloc(records, (nRecords - 1) * sizeof(struct Record));
                nRecords--;
                printf("Record deleted successfully!\n");
                break;

            case 6: // Exit
                if (records != NULL) {
                    free(records);
                }

                printf("Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice, try again!\n");
                break;
        }
    } while (1);

    return 0;
}