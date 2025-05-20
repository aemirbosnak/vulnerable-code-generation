//FormAI DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int id;
    float gpa;
};

int main() {
    int choice, numRecords = 0, i = 0;
    struct student *records;

    printf("Welcome to the Happy Student Database\n");

    do {
        printf("\nChoose an option:\n");
        printf("1. Add a student\n");
        printf("2. View student record\n");
        printf("3. Exit program\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                numRecords++;
                records = (struct student*) realloc(records, numRecords * sizeof(struct student));
                printf("\nEnter student name: ");
                scanf("%s", (records + numRecords - 1)->name);
                printf("Enter student ID: ");
                scanf("%d", &(records + numRecords - 1)->id);
                printf("Enter student GPA: ");
                scanf("%f", &(records + numRecords - 1)->gpa);
                printf("\nStudent record added successfully!\n\n");
                break;
            case 2:
                printf("\nStudent records:\n");
                for (i = 0; i < numRecords; i++) {
                    printf("\nName: %s\n", (records + i)->name);
                    printf("ID: %d\n", (records + i)->id);
                    printf("GPA: %.2f\n", (records + i)->gpa);
                }
                printf("\n");
                break;
            case 3:
                printf("\nGoodbye! Thank you for using the Happy Student Database\n\n");
                break;
            default:
                printf("\nInvalid choice. Please select a valid option.\n");
        }
    } while (choice != 3);

    free(records);

    return 0;
}