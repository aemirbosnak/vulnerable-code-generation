//Falcon-180B DATASET v1.0 Category: Database querying ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_TITLE_LENGTH 100
#define MAX_ROYALTY_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char title[MAX_TITLE_LENGTH];
    char royalty[MAX_ROYALTY_LENGTH];
} Noble;

int main() {
    FILE *database;
    Noble nobles[100];
    int num_nobles = 0;

    // Open the database file for reading
    database = fopen("nobility.txt", "r");
    if (database == NULL) {
        printf("Error: Could not open database file.\n");
        return 1;
    }

    // Read the nobles from the database
    while (fscanf(database, "%s %s %s\n", nobles[num_nobles].name, nobles[num_nobles].title, nobles[num_nobles].royalty)!= EOF) {
        num_nobles++;
    }

    // Sort the nobles by name
    for (int i = 0; i < num_nobles - 1; i++) {
        for (int j = i + 1; j < num_nobles; j++) {
            if (strcmp(nobles[i].name, nobles[j].name) > 0) {
                Noble temp = nobles[i];
                nobles[i] = nobles[j];
                nobles[j] = temp;
            }
        }
    }

    // Print the nobles in alphabetical order
    printf("Nobility of the Realm:\n");
    for (int i = 0; i < num_nobles; i++) {
        printf("%s, %s, %s\n", nobles[i].name, nobles[i].title, nobles[i].royalty);
    }

    // Close the database file
    fclose(database);

    return 0;
}