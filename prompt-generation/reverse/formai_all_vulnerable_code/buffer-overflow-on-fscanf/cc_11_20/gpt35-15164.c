//FormAI DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define NUM_RECORDS 100
 
// Define the structure for the Student record
typedef struct {
    int studentID;
    char firstName[20];
    char lastName[20];
    float gpa;
} StudentRecord;
 
int main()
{
    int option, i, numRecords = 0;
    char filename[50];
 
    StudentRecord records[NUM_RECORDS];
 
    printf("*** C Database Simulation ***\n");
    printf("Enter the name of the file to load: ");
    scanf("%s", filename);
 
    // Load the data from the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("FAILED to open the file '%s'.\n", filename);
        return -1;
    }
 
    while (!feof(file) && numRecords < NUM_RECORDS) {
        fscanf(file, "%d,%[^,],%[^,],%f\n", &records[numRecords].studentID,
                                               records[numRecords].firstName,
                                               records[numRecords].lastName,
                                              &records[numRecords].gpa);
        numRecords++;
    }
 
    fclose(file);
 
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Print all student records\n");
        printf("2. Add a new student record\n");
        printf("3. Search for a student record\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
 
        switch (option) {
            case 1:
                // Print all the student records
                printf("\n%-10s %-20s %-20s %-6s\n", "ID", "First Name", "Last Name", "GPA");
                printf("=====================================================\n");
                for (i = 0; i < numRecords; i++) {
                    printf("%-10d %-20s %-20s %6.2f\n", records[i].studentID,
                                                         records[i].firstName,
                                                         records[i].lastName,
                                                         records[i].gpa);
                }
                break;
 
            case 2:
                // Add a new student record
                if (numRecords < NUM_RECORDS) {
                    printf("\nEnter the student's information:\n");
                    printf("Student ID: ");
                    scanf("%d", &records[numRecords].studentID);
                    printf("First Name: ");
                    scanf("%s", records[numRecords].firstName);
                    printf("Last Name: ");
                    scanf("%s", records[numRecords].lastName);
                    printf("GPA: ");
                    scanf("%f", &records[numRecords].gpa);
 
                    numRecords++;
                    printf("\nRecord added.\n");
                } else {
                    printf("\nDatabase full. No more records can be added.\n");
                }
                break;
 
            case 3:
                // Search for a student record
                printf("\nEnter the student ID: ");
                int searchID;
                scanf("%d", &searchID);
 
                for (i = 0; i < numRecords; i++) {
                    if (records[i].studentID == searchID) {
                        printf("\n%-10s %-20s %-20s %-6s\n", "ID", "First Name", "Last Name", "GPA");
                        printf("=====================================================\n");
                        printf("%-10d %-20s %-20s %6.2f\n", records[i].studentID,
                                                             records[i].firstName,
                                                             records[i].lastName,
                                                             records[i].gpa);
                        break;
                    }
                }
 
                if (i == numRecords) {
                    printf("\nNo record found with ID '%d'.\n", searchID);
                }
                break;
 
            case 4:
                // Exit the program
                printf("\nExiting program...\n");
                break;
 
            default:
                printf("\nInvalid option. Please enter a number between 1-4.\n");
                break;
        }
 
    } while (option != 4);
 
    return 0;
}