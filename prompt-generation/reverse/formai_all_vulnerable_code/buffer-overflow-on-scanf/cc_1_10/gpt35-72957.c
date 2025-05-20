//FormAI DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXRECORDS 10 // Maximum records to be saved
#define MAXLEN 50 // Maximum length of each record

struct Record { // Define the Record structure
    char name[MAXLEN];
    int age;
    float salary;
};

int main() {
    struct Record records[MAXRECORDS]; // Create an array of Records
    int numRecords = 0; // The number of current records stored in the array

    // Prompt the user to add new records
    printf("Enter new records (or 'done' to stop):\n");
    char input[MAXLEN];
    do {
        printf("Name: ");
        fgets(input, MAXLEN, stdin); // Read the input as a string
        if (strcmp(input, "done\n") == 0) break; // If the user is done, break out of the loop
        else {
            // Add a new record to the array
            strcpy(records[numRecords].name, input); // Copy the string into the name field
            printf("Age: ");
            scanf("%d", &records[numRecords].age); // Read the age as an integer
            printf("Salary: ");
            scanf("%f", &records[numRecords].salary); // Read the salary as a float
            getchar(); // Read the newline character left over by scanf
            numRecords++; // Increment the number of records in the array
        }
    } while (numRecords < MAXRECORDS); // Keep adding records until MAXRECORDS is reached

    // Print out all the records
    printf("\nHere are all the records:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%d. %s", i+1, records[i].name);
        printf("Age: %d\n", records[i].age);
        printf("Salary: %.2f\n", records[i].salary);
    }

    // Search for a specific record
    printf("\nEnter a name to search for: ");
    fgets(input, MAXLEN, stdin); // Read the name to search for
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(records[i].name, input) == 0) { // Check if the names match
            printf("\nRecord found:\n");
            printf("Name: %s", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Salary: %.2f\n", records[i].salary);
            break; // Stop searching once a match is found
        }
    }

    return 0; // Exit the program
}