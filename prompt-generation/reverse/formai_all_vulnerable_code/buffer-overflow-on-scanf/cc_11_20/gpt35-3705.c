//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[20];
    float gpa;
};

int main() {
    int maxSize, choice, i, found, id;
    struct student *database;
    
    printf("Enter the maximum number of students in the database: ");
    scanf("%d", &maxSize);
    
    database = (struct student*) malloc(maxSize * sizeof(struct student));
    if(database == NULL) {
        printf("Unable to allocate memory!\n");
        return 1;
    }
    
    printf("\nWelcome to the student database simulation!\n");

    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Add a student\n");
        printf("2. Search for a student\n");
        printf("3. Display all students\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // Add a student
                for(i=0; i<maxSize; i++) {
                    if(database[i].id == 0) {
                        printf("\nEnter the details of the student:\n");
                        printf("ID: ");
                        scanf("%d", &database[i].id);
                        printf("Name: ");
                        scanf("%s", database[i].name);
                        printf("GPA: ");
                        scanf("%f", &database[i].gpa);
                        
                        printf("\nStudent added successfully!\n");
                        break;
                    }
                }
                if(i == maxSize) {
                    printf("\nThe student database is full!\n");
                }
                break;
                
            case 2: // Search for a student
                found = 0;
                printf("\nEnter the student ID: ");
                scanf("%d", &id);
                for(i=0; i<maxSize; i++) {
                    if(database[i].id == id) {
                        printf("\nStudent found!\n");
                        printf("ID: %d\n", database[i].id);
                        printf("Name: %s\n", database[i].name);
                        printf("GPA: %.2f\n", database[i].gpa);
                        found = 1;
                        break;
                    }
                }
                if(found == 0) {
                    printf("\nStudent not found in the database!\n");
                }
                break;
                
            case 3: // Display all students
                printf("\nStudent database: \n");
                for(i=0; i<maxSize; i++) {
                    if(database[i].id != 0) {
                        printf("ID: %d\n", database[i].id);
                        printf("Name: %s\n", database[i].name);
                        printf("GPA: %.2f\n\n", database[i].gpa);
                    }
                }
                break;
                
            case 4: // Exit
                printf("\nThank you for using the student database simulation!\n");
                free(database);
                exit(0);
                
            default:
                printf("\nInvalid option!\n");
                break;
        }
    }

    return 0;
}