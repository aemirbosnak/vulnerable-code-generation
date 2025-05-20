//Falcon-180B DATASET v1.0 Category: Database querying ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_ADDRESS_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
} Person;

void read_person_data(Person *person) {
    printf("Enter name: ");
    scanf("%s", person->name);

    printf("Enter address: ");
    scanf("%s", person->address);
}

void print_person_data(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Address: %s\n", person->address);
}

int main() {
    Person *people = NULL;
    int num_people = 0;
    char query[200];

    printf("Enter number of people: ");
    scanf("%d", &num_people);

    people = (Person *) malloc(num_people * sizeof(Person));

    for (int i = 0; i < num_people; i++) {
        read_person_data(&people[i]);
    }

    // Example queries
    strcpy(query, "SELECT * FROM people WHERE address LIKE '%Main%'");
    printf("\n%s\n", query);
    for (int i = 0; i < num_people; i++) {
        if (strstr(people[i].address, "Main")!= NULL) {
            print_person_data(&people[i]);
        }
    }

    strcpy(query, "SELECT * FROM people WHERE name LIKE '%John%'");
    printf("\n%s\n", query);
    for (int i = 0; i < num_people; i++) {
        if (strstr(people[i].name, "John")!= NULL) {
            print_person_data(&people[i]);
        }
    }

    free(people);
    return 0;
}