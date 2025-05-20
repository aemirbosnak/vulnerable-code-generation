//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 50
#define MAX_QUERY_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char city[MAX_NAME_LEN];
    char address[MAX_NAME_LEN];
    int phone;
} Person;

int main() {
    Person people[10];
    int num_people = 0;

    // Read people's information from the database
    printf("Welcome to the Happy People Database!\n");
    printf("Enter the number of people you want to add: ");
    scanf("%d", &num_people);

    for (int i = 0; i < num_people; i++) {
        printf("Enter person %d's name: ", i + 1);
        scanf("%s", people[i].name);

        printf("Enter person %d's age: ", i + 1);
        scanf("%d", &people[i].age);

        printf("Enter person %d's city: ", i + 1);
        scanf("%s", people[i].city);

        printf("Enter person %d's address: ", i + 1);
        scanf("%s", people[i].address);

        printf("Enter person %d's phone number: ", i + 1);
        scanf("%d", &people[i].phone);
    }

    // Print out the people's information
    printf("\nHere are the happy people in our database:\n");
    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("City: %s\n", people[i].city);
        printf("Address: %s\n", people[i].address);
        printf("Phone: %d\n", people[i].phone);
    }

    // Perform a query on the database
    printf("\nEnter a query: ");
    char query[MAX_QUERY_LEN];
    scanf("%s", query);

    int found = 0;
    for (int i = 0; i < num_people; i++) {
        if (strcmp(query, people[i].name) == 0) {
            found = 1;
            printf("Found %s!\n", query);
            break;
        }
    }

    if (found == 0) {
        printf("Sorry, we could not find the person you are looking for.\n");
    }

    return 0;
}