//FormAI DATASET v1.0 Category: Database simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct {
    int id;
    char name[50];
    int age;
} person;

int main() {
    int choice, found_person, id, i;
    char name[50];
    person database[MAX_SIZE];
    
    while (1) {
        printf("\n===== C DATABASE SIMULATION =====\n");
        printf("1-Add a person to the database\n");
        printf("2-Remove a person from the database\n");
        printf("3-Search for a person in the database\n");
        printf("4-Display the entire database\n");
        printf("5-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                for (i = 0; i < MAX_SIZE; i++) {
                    if (database[i].id == 0) {
                        printf("\nAdd a person to the database:\n");
                        printf("ID: ");
                        scanf("%d", &database[i].id);
                        getchar(); // consuming the '\n' character
                        printf("Name: ");
                        fgets(database[i].name, 50, stdin);
                        printf("Age: ");
                        scanf("%d", &database[i].age);
                        printf("Person added to the database successfully!\n");
                        break;
                    }
                }
                if (i == MAX_SIZE) {
                    printf("\nSorry, database is full.\n");
                }
                break;
            
            case 2:
                found_person = 0;
                printf("\nRemove a person from the database:\n");
                printf("Enter the ID of the person you want to remove: ");
                scanf("%d", &id);
                for (i = 0; i < MAX_SIZE; i++) {
                    if (database[i].id == id) {
                        found_person = 1;
                        database[i].id = 0;
                        database[i].name[0] = '\0';
                        database[i].age = 0;
                    }
                }
                if (found_person) {
                    printf("Person removed from the database successfully!\n");
                } else {
                    printf("Sorry, person not found in the database.\n");
                }
                break;
            
            case 3:
                found_person = 0;
                printf("\nSearch for a person in the database:\n");
                printf("Enter the name of the person you want to search: ");
                fgets(name, 50, stdin);
                for (i = 0; i < MAX_SIZE; i++) {
                    if (strcmp(database[i].name, name) == 0) {
                        found_person = 1;
                        printf("ID: %d, Name: %s, Age: %d\n", database[i].id, database[i].name, database[i].age);
                    }
                }
                if (!found_person) {
                    printf("Sorry, person not found in the database.\n");
                }
                break;
            
            case 4:
                printf("\nDisplay the entire database:\n");
                for (i = 0; i < MAX_SIZE; i++) {
                    if (database[i].id != 0) {
                        printf("ID: %d, Name: %s, Age: %d\n", database[i].id, database[i].name, database[i].age);
                    }
                }
                break;
            
            case 5:
                printf("\nExiting Program.\n");
                exit(0);
            
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}