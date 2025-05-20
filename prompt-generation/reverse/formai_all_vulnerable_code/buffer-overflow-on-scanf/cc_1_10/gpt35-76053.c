//FormAI DATASET v1.0 Category: Database querying ; Style: Romeo and Juliet
/* Scene: Verona, Italy. The database supplies information about the Montagues and Capulets. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char city[50];
    int age;
} Person;

int main() {
    printf("Enter the name of the desired character's family (Montagues or Capulets): ");
    char family[20];
    scanf("%s", family);
    if (strcmp(family, "Montagues") != 0 && strcmp(family, "Capulets") != 0) {
        printf("Invalid family name entered.\n");
        return 1;
    }
    printf("Enter the name of the desired character: ");
    char name[50];
    scanf("%s", name);
    printf("\n");

    // Connect to the database
    FILE *file = fopen("romeoandjuliet.db", "r");
    if (file == NULL) {
        printf("Database not found.\n");
        return 1;
    }

    // Query the database and print the results
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        char *token = strtok(line, ",");
        int id = atoi(token);
        token = strtok(NULL, ",");
        char personName[50];
        strcpy(personName, token);
        token = strtok(NULL, ",");
        char city[50];
        strcpy(city, token);
        token = strtok(NULL, ",");
        int age = atoi(token);

        if (strcmp(personName, name) == 0) {
            if (strcmp(city, family) == 0) {
                printf("%s, %d years old\n", personName, age);
                printf("ID: %d\n", id);
                printf("------------------------------------------------\n");
            }
        }
    }

    // Close the database
    fclose(file);
    return 0;
}