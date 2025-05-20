//Falcon-180B DATASET v1.0 Category: Database querying ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_AGE 120
#define MAX_PEOPLE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int alive;
} Person;

int main() {
    FILE *database;
    Person people[MAX_PEOPLE];
    int num_people = 0;

    // Open the database file for reading
    database = fopen("database.txt", "r");
    if (database == NULL) {
        printf("Error opening database file.\n");
        return 1;
    }

    // Read in the people from the database file
    while (fscanf(database, "%s %d %d\n", people[num_people].name, &people[num_people].age, &people[num_people].alive)!= EOF) {
        num_people++;
    }

    // Sort the people by age
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[i].age > people[j].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Print out the sorted list of people
    printf("Name\tAge\tAlive\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s\t%d\t%d\n", people[i].name, people[i].age, people[i].alive);
    }

    // Close the database file
    fclose(database);

    return 0;
}