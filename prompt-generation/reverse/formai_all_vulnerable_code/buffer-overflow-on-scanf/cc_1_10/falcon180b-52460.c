//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
    int id;
} Person;

void create_database(Person *database, int num_people) {
    printf("Creating database...\n");
    for (int i = 0; i < num_people; i++) {
        printf("Enter name for person %d: ", i + 1);
        scanf("%s", database[i].name);
        printf("Enter age for person %s: ", database[i].name);
        scanf("%d", &database[i].age);
        printf("Enter ID for person %s: ", database[i].name);
        scanf("%d", &database[i].id);
    }
}

void search_database(Person *database, int num_people, char *query) {
    printf("Searching database for %s...\n", query);
    int found = 0;
    for (int i = 0; i < num_people; i++) {
        if (strcmp(database[i].name, query) == 0) {
            printf("Found %s! Name: %s Age: %d ID: %d\n", query, database[i].name, database[i].age, database[i].id);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No results found for %s.\n", query);
    }
}

int main() {
    Person database[MAX_SIZE];
    int num_people;
    
    printf("Welcome to the Medieval Database!\n");
    printf("Enter the number of people in the database: ");
    scanf("%d", &num_people);
    
    create_database(database, num_people);
    
    printf("Enter a name to search for: ");
    char query[MAX_SIZE];
    scanf("%s", query);
    
    search_database(database, num_people, query);
    
    return 0;
}