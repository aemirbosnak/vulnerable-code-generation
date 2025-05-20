//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    char gender;
} Person;

void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Gender: %c\n", person->gender);
}

void read_person(Person* person) {
    printf("Enter name (max %d characters): ", MAX_SIZE - 1);
    scanf("%s", person->name);
    printf("Enter age: ");
    scanf("%d", &person->age);
    printf("Enter gender (M/F): ");
    scanf(" %c", &person->gender);
}

int main() {
    Person people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        printf("Do you want to add a person? (Y/N): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y') {
            read_person(&people[num_people]);
            num_people++;
        } else {
            break;
        }
    }

    printf("Number of people: %d\n", num_people);

    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    return 0;
}