//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 100
#define FILENAME "records.dat"

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

void addPerson(Person people[], int *count);
void displayPeople(const Person people[], int count);
void saveToFile(const Person people[], int count);
void loadFromFile(Person people[], int *count);

int main() {
    Person people[MAX_RECORDS];
    int count = 0;
    int choice;

    loadFromFile(people, &count);

    do {
        printf("\n====== Person Record Management ======\n");
        printf("1. Add Person\n");
        printf("2. Display All People\n");
        printf("3. Save to File\n");
        printf("4. Load from File\n");
        printf("5. Exit\n");
        printf("======================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline left by scanf

        switch (choice) {
            case 1:
                addPerson(people, &count);
                break;
            case 2:
                displayPeople(people, count);
                break;
            case 3:
                saveToFile(people, count);
                break;
            case 4:
                loadFromFile(people, &count);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addPerson(Person people[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Maximum number of records reached!\n");
        return;
    }

    printf("Enter name: ");
    fgets(people[*count].name, MAX_NAME_LENGTH, stdin);
    people[*count].name[strcspn(people[*count].name, "\n")] = 0; // remove newline

    printf("Enter age: ");
    scanf("%d", &people[*count].age);
    getchar(); // consume newline

    (*count)++;
    printf("Person added successfully!\n");
}

void displayPeople(const Person people[], int count) {
    if (count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\n--- List of People ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Age: %d\n", i + 1, people[i].name, people[i].age);
    }
}

void saveToFile(const Person people[], int count) {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    fwrite(people, sizeof(Person), count, file);
    fclose(file);
    printf("Records saved successfully!\n");
}

void loadFromFile(Person people[], int *count) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("Error opening file for reading or file does not exist. Starting with empty records.\n");
        *count = 0;
        return;
    }

    *count = fread(people, sizeof(Person), MAX_RECORDS, file);
    fclose(file);
    printf("Records loaded successfully! %d records found.\n", *count);
}