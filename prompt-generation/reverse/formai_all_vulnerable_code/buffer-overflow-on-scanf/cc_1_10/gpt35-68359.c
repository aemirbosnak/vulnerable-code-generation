//FormAI DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char occupation[50];
    int age;
    char location[50];
} Person;

int main() {
    FILE *database;
    char ch;

    // Open the database file
    database = fopen("medieval_database.txt", "r");
    if (database == NULL) {
        printf("Unable to open database file. Program exiting..\n");
        return 1;
    }

    printf("Welcome to the medieval database!\n");

    printf("Enter the name of the person you want to search for: ");
    char name[50];
    scanf("%s", name);

    // Read each record from the database
    Person person;
    while (fread(&person, sizeof(Person), 1, database)) {
        // Check if the name matches
        if (strcmp(name, person.name) == 0) {
            printf("\nName: %s\n", person.name);
            printf("Occupation: %s\n", person.occupation);
            printf("Age: %d\n", person.age);
            printf("Location: %s\n\n", person.location);
            break;
        }
    }

    if (feof(database)) {
        printf("Sorry, we couldn't find anyone with that name in our database..\n");
    } 

    fclose(database);

    return 0;
}