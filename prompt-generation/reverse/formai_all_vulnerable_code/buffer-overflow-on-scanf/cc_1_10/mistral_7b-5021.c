//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef enum { FAIL, SUCCESS } Status;

struct Person {
    char name[MAX_NAME_LENGTH];
    int age;
};

Status createPerson(struct Person* person, const char* name, int age) {
    if (name == NULL || age < 0) {
        perror("Name or age is invalid");
        return FAIL;
    }

    strcpy(person->name, name);
    person->age = age;

    return SUCCESS;
}

int main() {
    struct Person romeo, juliet;
    char romeoName[MAX_NAME_LENGTH], julietName[MAX_NAME_LENGTH];
    int romeoAge, julietAge;

    printf("Enter Romeo's name: ");
    scanf("%s", romeoName);
    romeoAge = 16; // For the sake of our tragic love story

    if (!createPerson(&romeo, romeoName, romeoAge)) {
        printf("Oh woe is me, the stars did conspire\n");
        printf("To cast a shadow on our young Romeo's name:\n");
        return 1;
    }

    printf("Enter Juliet's name: ");
    scanf("%s", julietName);
    julietAge = 13; // A tragic age difference in our tale

    if (!createPerson(&juliet, julietName, julietAge)) {
        printf("Alas, my fair Juliet's name is cursed\n");
        printf("The heavens forbid her name be spoken:\n");
        return 1;
    }

    printf("Romeo's name: %s\n", romeo.name);
    printf("Romeo's age: %d\n", romeo.age);

    printf("Juliet's name: %s\n", juliet.name);
    printf("Juliet's age: %d\n", juliet.age);

    printf("Our star-crossed lovers have been brought to life:\n");

    return 0;
}