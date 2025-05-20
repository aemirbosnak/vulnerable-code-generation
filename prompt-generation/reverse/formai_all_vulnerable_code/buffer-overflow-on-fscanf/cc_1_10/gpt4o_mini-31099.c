//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records and the maximum length for each entry
#define MAX_RECORDS 100
#define MAX_LENGTH 256

// Structure to hold the information of each data entry
typedef struct {
    char name[MAX_LENGTH];
    int age;
    float salary;
} Record;

// Function prototypes
void loadData(Record records[], int *count);
void displayRecords(const Record records[], int count);
void findAgeAbove(Record records[], int count, int ageThreshold);
void calculateAverageSalary(Record records[], int count);
void sortRecords(Record records[], int count);
void swap(Record *a, Record *b);
void saveData(const Record records[], int count);

int main() {
    Record records[MAX_RECORDS];
    int count = 0;
    int choice;
    
    loadData(records, &count);
    
    do {
        printf("\n------ Data Mining Menu ------\n");
        printf("1. Display Records\n");
        printf("2. Find Age Greater Than\n");
        printf("3. Calculate Average Salary\n");
        printf("4. Sort Records by Age\n");
        printf("5. Save Records to File\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRecords(records, count);
                break;
            case 2:
                {
                    printf("Enter age threshold: ");
                    int threshold;
                    scanf("%d", &threshold);
                    findAgeAbove(records, count, threshold);
                }
                break;
            case 3:
                calculateAverageSalary(records, count);
                break;
            case 4:
                sortRecords(records, count);
                printf("Records sorted by age!\n");
                break;
            case 5:
                saveData(records, count);
                printf("Records saved to data.txt!\n");
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to load data from a file
void loadData(Record records[], int *count) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open data.txt for reading!\n");
        exit(EXIT_FAILURE);
    }
    while (fscanf(file, "%s %d %f", records[*count].name, &records[*count].age, &records[*count].salary) != EOF) {
        (*count)++;
        if (*count >= MAX_RECORDS) break;
    }
    fclose(file);
}

// Function to display all records
void displayRecords(const Record records[], int count) {
    printf("\n--- Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", records[i].name, records[i].age, records[i].salary);
    }
}

// Function to find records with age above a certain threshold
void findAgeAbove(Record records[], int count, int ageThreshold) {
    printf("\n--- Records with Age Greater Than %d ---\n", ageThreshold);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (records[i].age > ageThreshold) {
            printf("Name: %s, Age: %d, Salary: %.2f\n", records[i].name, records[i].age, records[i].salary);
            found = 1;
        }
    }
    if (!found) {
        printf("No records found with age greater than %d.\n", ageThreshold);
    }
}

// Function to calculate and display the average salary
void calculateAverageSalary(Record records[], int count) {
    if (count == 0) {
        printf("No records to calculate average salary!\n");
        return;
    }
    float totalSalary = 0.0;
    for (int i = 0; i < count; i++) {
        totalSalary += records[i].salary;
    }
    float averageSalary = totalSalary / count;
    printf("Average Salary: %.2f\n", averageSalary);
}

// Function to sort records based on age
void sortRecords(Record records[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (records[j].age > records[j + 1].age) {
                swap(&records[j], &records[j + 1]);
            }
        }
    }
}

// Function to swap two records
void swap(Record *a, Record *b) {
    Record temp = *a;
    *a = *b;
    *b = temp;
}

// Function to save records to a file
void saveData(const Record records[], int count) {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open data.txt for writing!\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f\n", records[i].name, records[i].age, records[i].salary);
    }
    fclose(file);
}