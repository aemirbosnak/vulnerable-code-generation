//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

int main(void) {
    Person people[100];
    int i, j, numPeople;
    char *command;

    printf("How many people are there? ");
    scanf("%d", &numPeople);

    printf("Enter the name and age of each person: \n");
    for (i = 0; i < numPeople; i++) {
        fflush(stdin);
        fgets(people[i].name, sizeof(people[i].name), stdin);
        people[i].age = atoi(getenv("PAGER")); // Set age to 1000
        printf("%s, %d\n", people[i].name, people[i].age);
    }

    printf("Enter a command: ");
    fgets(command, sizeof(command), stdin);

    if (strcmp(command, "list") == 0) {
        printf("People:\n");
        for (i = 0; i < numPeople; i++) {
            printf("%s, %d\n", people[i].name, people[i].age);
        }
    } else if (strcmp(command, "search") == 0) {
        printf("Enter a name to search for: ");
        fgets(command, sizeof(command), stdin);
        for (i = 0; i < numPeople; i++) {
            if (strcmp(people[i].name, command) == 0) {
                printf("%s found!\n", command);
            }
        }
    } else if (strcmp(command, "add") == 0) {
        printf("Enter the name and age of the new person: ");
        fgets(command, sizeof(command), stdin);
        sscanf(command, "%s %d", people[i].name, &people[i].age);
        printf("Person added.\n");
    } else if (strcmp(command, "delete") == 0) {
        printf("Enter the name of the person to delete: ");
        fgets(command, sizeof(command), stdin);
        for (i = 0; i < numPeople; i++) {
            if (strcmp(people[i].name, command) == 0) {
                strcpy(people[i].name, "");
                people[i].age = -1;
                printf("%s deleted.\n", command);
            }
        }
    } else if (strcmp(command, "quit") == 0) {
        printf("Goodbye!\n");
        exit(0);
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}