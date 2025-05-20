//FormAI DATASET v1.0 Category: Database querying ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ID;
    char name[20];
    int age;
    float salary;
} employee;

employee database[10];

int main() {

    int choice, count = 0;

    while(1) {
        printf("Please select an action to perform:\n");
        printf("1. Add employee\n");
        printf("2. Search employee by ID\n");
        printf("3. View all employees\n");
        printf("4. Exit program\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter employee ID: ");
                scanf("%d", &database[count].ID);

                printf("Enter employee name: ");
                scanf("%s", database[count].name);

                printf("Enter employee age: ");
                scanf("%d", &database[count].age);

                printf("Enter employee salary: ");
                scanf("%f", &database[count].salary);

                printf("Employee added successfully!\n");
                count++;
                break;
            
            case 2:
                if(count == 0) {
                    printf("No employees added yet!\n");
                    break;
                }

                printf("Enter employee ID to search: ");
                int searchID, found = 0;
                scanf("%d", &searchID);

                for(int i = 0; i < count; i++) {
                    if(database[i].ID == searchID) {
                        printf("Employee found!\n");
                        printf("ID: %d, Name: %s, Age: %d, Salary: %f\n", database[i].ID, database[i].name, database[i].age, database[i].salary);
                        found = 1;
                        break;
                    }
                }

                if(!found) {
                    printf("Employee not found!\n");
                }
                break;

            case 3:
                if(count == 0) {
                    printf("No employees added yet!\n");
                    break;
                }

                printf("List of all employees:\n");
                for(int i = 0; i < count; i++) {
                    printf("ID: %d, Name: %s, Age: %d, Salary: %f\n", database[i].ID, database[i].name, database[i].age, database[i].salary);
                }
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}