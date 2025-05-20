//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float height; // height in meters
    float weight; // weight in kilograms
} Person;

void printStatistics(Person people[], int count);
void saveToFile(const char* filename, Person people[], int count);
void loadFromFile(const char* filename, Person people[], int* count);

int main() {
    Person people[MAX_RECORDS];
    int count = 0;
    char filename[MAX_FILE_NAME_LENGTH];
    int choice;

    printf("Welcome to the Statistical Data Program!\n");
    printf("Please enter the filename to save/load records: ");
    scanf("%s", filename);

    loadFromFile(filename, people, &count);
    printf("Loaded %d records.\n", count);

    do {
        printf("\nMenu:\n");
        printf("1. Add a new record\n");
        printf("2. View statistics\n");
        printf("3. Save records\n");
        printf("4. Load records\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX_RECORDS) {
                    printf("Maximum number of records reached.\n");
                } else {
                    printf("Enter name: ");
                    scanf("%s", people[count].name);
                    printf("Enter age: ");
                    scanf("%d", &people[count].age);
                    printf("Enter height (in meters): ");
                    scanf("%f", &people[count].height);
                    printf("Enter weight (in kilograms): ");
                    scanf("%f", &people[count].weight);
                    count++;
                    printf("Record added successfully!\n");
                }
                break;

            case 2:
                printStatistics(people, count);
                break;

            case 3:
                saveToFile(filename, people, count);
                break;

            case 4:
                loadFromFile(filename, people, &count);
                printf("Loaded %d records.\n", count);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void printStatistics(Person people[], int count) {
    if (count == 0) {
        printf("No records to display statistics.\n");
        return;
    }

    float totalHeight = 0.0, totalWeight = 0.0;
    int totalAge = 0;
    for (int i = 0; i < count; i++) {
        totalHeight += people[i].height;
        totalWeight += people[i].weight;
        totalAge += people[i].age;
    }

    float averageHeight = totalHeight / count;
    float averageWeight = totalWeight / count;
    float averageAge = (float)totalAge / count;

    printf("\nStatistics:\n");
    printf("Total Records: %d\n", count);
    printf("Average Height: %.2f meters\n", averageHeight);
    printf("Average Weight: %.2f kg\n", averageWeight);
    printf("Average Age: %.2f years\n", averageAge);
}

void saveToFile(const char* filename, Person people[], int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }

    fwrite(people, sizeof(Person), count, file);
    fclose(file);
    printf("Records saved successfully to '%s'.\n", filename);
}

void loadFromFile(const char* filename, Person people[], int* count) {
    FILE *file = fopen(filename, "r");
    if (file) {
        *count = fread(people, sizeof(Person), MAX_RECORDS, file);
        fclose(file);
    } else {
        printf("No previous records found in '%s'.\n", filename);
        *count = 0; // Reset count if unable to load
    }
}