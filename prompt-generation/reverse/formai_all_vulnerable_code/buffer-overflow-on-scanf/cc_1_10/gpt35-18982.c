//FormAI DATASET v1.0 Category: Database simulation ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
    int id;
    char name[50];
    float percentage;
};

int main() {
    int option, index = 0, recordId, found = 0;
    struct Student students[10];

    while(1) {
        printf("Select an option:\n1. Add a new student record\n2. Search for a student record\n3. Display student records\n4. Exit the program\n");
        scanf("%d", &option);

        switch(option) {
            case 1: // Add a new student record
                printf("Enter ID, name and percentage:\n");
                scanf("%d%s%f", &students[index].id, students[index].name, &students[index].percentage);
                index++;
                break;

            case 2: // Search for a student record
                printf("Enter ID of the student you want to search for:\n");
                scanf("%d", &recordId);

                for(int i = 0; i < index; i++) {
                    if(students[i].id == recordId) {
                        printf("Student found with ID %d: Name: %s, Percentage: %f\n", students[i].id, students[i].name, students[i].percentage);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Student not found with ID %d\n", recordId);
                }
                break;

            case 3: // Display student records
                printf("ID\tName\tPercentage\n");

                for(int i = 0; i < index; i++) {
                    printf("%d\t%s\t%f\n", students[i].id, students[i].name, students[i].percentage);
                }
                break;

            case 4: // Exit the program
                exit(0);
                break;

            default:
                printf("Invalid option selected. Please select a valid option.\n");
                break;
        }
    }

    return 0;
}