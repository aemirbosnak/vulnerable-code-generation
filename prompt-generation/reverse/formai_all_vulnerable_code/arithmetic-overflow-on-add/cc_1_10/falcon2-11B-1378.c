//Falcon2-11B DATASET v1.0 Category: Time Travel Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    char name[50];
} Person;

Person* createPerson(int age, char* name) {
    Person* person = (Person*) malloc(sizeof(Person));
    if (person == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    person->age = age;
    strcpy(person->name, name);

    return person;
}

void printPerson(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main() {
    int age;
    char name[50];

    printf("Enter the age: ");
    scanf("%d", &age);
    printf("Enter the name: ");
    scanf("%s", name);

    Person* person = createPerson(age, name);

    if (person!= NULL) {
        printf("Created person: %s, %d years old\n", person->name, person->age);
        printPerson(person);

        Person* futurePerson = createPerson(age+10, name);

        if (futurePerson!= NULL) {
            printf("Created future person: %s, %d years old\n", futurePerson->name, futurePerson->age);
            printPerson(futurePerson);

            Person* pastPerson = createPerson(age-10, name);

            if (pastPerson!= NULL) {
                printf("Created past person: %s, %d years old\n", pastPerson->name, pastPerson->age);
                printPerson(pastPerson);

                printf("Here's how time travel works:\n");

                free(person);
                person = futurePerson;

                free(futurePerson);
                futurePerson = pastPerson;

                free(pastPerson);
                pastPerson = person;

                printf("Created person: %s, %d years old\n", pastPerson->name, pastPerson->age);
                printPerson(pastPerson);

                printf("Created person: %s, %d years old\n", person->name, person->age);
                printPerson(person);

                printf("Created person: %s, %d years old\n", futurePerson->name, futurePerson->age);
                printPerson(futurePerson);
            } else {
                printf("Memory allocation failed for past person\n");
            }
        } else {
            printf("Memory allocation failed for future person\n");
        }
    } else {
        printf("Memory allocation failed for current person\n");
    }

    free(person);
    person = NULL;

    return 0;
}