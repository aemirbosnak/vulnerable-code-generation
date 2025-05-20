//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *gender;
    char *occupation;
    char *description;
} Person;

Person *create_person(char *name, int age, char *gender, char *occupation, char *description) {
    Person *person = (Person *) malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    person->gender = strdup(gender);
    person->occupation = strdup(occupation);
    person->description = strdup(description);
    return person;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Gender: %s\n", person->gender);
    printf("Occupation: %s\n", person->occupation);
    printf("Description: %s\n", person->description);
}

int main() {
    srand(time(NULL));
    Person *people[] = {
        create_person("Sir William", 35, "male", "knight", "A brave and honorable knight."),
        create_person("Lady Isabella", 28, "female", "noble", "A beautiful and intelligent noblewoman."),
        create_person("Sir Thomas", 45, "male", "knight", "A wise and experienced knight."),
        create_person("Lady Catherine", 20, "female", "noble", "A kind and compassionate noblewoman."),
        create_person("Sir Richard", 30, "male", "knight", "A skilled and fearless knight."),
        create_person("Lady Margaret", 40, "female", "noble", "A wise and respected noblewoman."),
        create_person("Sir Edward", 25, "male", "knight", "A young and ambitious knight."),
        create_person("Lady Elizabeth", 32, "female", "noble", "A cunning and ambitious noblewoman.")
    };
    int num_people = sizeof(people) / sizeof(people[0]);
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }
    return 0;
}