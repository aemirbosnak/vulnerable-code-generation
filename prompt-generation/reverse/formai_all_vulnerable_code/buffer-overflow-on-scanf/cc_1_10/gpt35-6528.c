//FormAI DATASET v1.0 Category: Database querying ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

/* Example struct representing a student record */
typedef struct {
    char name[50];
    int age;
    int id;
    float gpa;
} StudentRecord;

/* Helper function to display a student record */
void displayRecord(StudentRecord record) {
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
    printf("ID: %d\n", record.id);
    printf("GPA: %.2f\n", record.gpa);
}

/* Function to query the database by name */
void queryByName(StudentRecord records[], int count) {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    printf("Results for %s:\n", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].name, name) == 0) {
            displayRecord(records[i]);
        }
    }
}

/* Function to query the database by age range */
void queryByAge(StudentRecord records[], int count) {
    int minAge, maxAge;
    printf("Enter minimum age: ");
    scanf("%d", &minAge);
    printf("Enter maximum age: ");
    scanf("%d", &maxAge);
    printf("Results for age %d to %d:\n", minAge, maxAge);
    for (int i = 0; i < count; i++) {
        if (records[i].age >= minAge && records[i].age <= maxAge) {
            displayRecord(records[i]);
        }
    }
}

/* Function to query the database by GPA range */
void queryByGPA(StudentRecord records[], int count) {
    float minGPA, maxGPA;
    printf("Enter minimum GPA: ");
    scanf("%f", &minGPA);
    printf("Enter maximum GPA: ");
    scanf("%f", &maxGPA);
    printf("Results for GPA %.2f to %.2f:\n", minGPA, maxGPA);
    for (int i = 0; i < count; i++) {
        if (records[i].gpa >= minGPA && records[i].gpa <= maxGPA) {
            displayRecord(records[i]);
        }
    }
}

int main() {
    StudentRecord records[MAX_RECORDS];
    int count = 0;
    char input[10];
    do {
        printf("Enter command (add/query/exit): ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            if (count < MAX_RECORDS) {
                printf("Enter name: ");
                scanf("%s", records[count].name);
                printf("Enter age: ");
                scanf("%d", &records[count].age);
                printf("Enter ID: ");
                scanf("%d", &records[count].id);
                printf("Enter GPA: ");
                scanf("%f", &records[count].gpa);
                count++;
            } else {
                printf("Error: Maximum records reached.\n");
            }
        } else if (strcmp(input, "query") == 0) {
            printf("Enter query type (name/age/GPA): ");
            scanf("%s", input);
            if (strcmp(input, "name") == 0) {
                queryByName(records, count);
            } else if (strcmp(input, "age") == 0) {
                queryByAge(records, count);
            } else if (strcmp(input, "GPA") == 0) {
                queryByGPA(records, count);
            } else {
                printf("Error: Invalid query type.\n");
            }
        }
    } while (strcmp(input, "exit") != 0);

    return 0;
}