//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBERS_PER_PERSON 5
#define MAX_PEOPLE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_phone_numbers;
    char *phone_numbers[MAX_NUMBERS_PER_PERSON];
} Person;

void add_person(Person *people, int num_people) {
    printf("Enter a name: ");
    scanf("%s", people[num_people].name);
    people[num_people].num_phone_numbers = 0;
}

void add_phone_number(Person *people, int person_index) {
    printf("Enter a phone number: ");
    char phone_number[20];
    scanf("%s", phone_number);
    people[person_index].phone_numbers[people[person_index].num_phone_numbers++] = strdup(phone_number);
}

void print_person(Person person) {
    printf("Name: %s\n", person.name);
    printf("Phone numbers:\n");
    for (int i = 0; i < person.num_phone_numbers; i++) {
        printf("\t%s\n", person.phone_numbers[i]);
    }
}

void print_people(Person *people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }
}

int main() {
    Person people[MAX_PEOPLE];
    int num_people = 0;

    while (num_people < MAX_PEOPLE) {
        char choice;
        printf("\nPhone book options:\n");
        printf("A - Add person\n");
        printf("P - Print people\n");
        printf("Q - Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
        case 'A':
        case 'a':
            add_person(people, num_people);
            num_people++;
            break;
        case 'P':
        case 'p':
            print_people(people, num_people);
            break;
        case 'Q':
        case 'q':
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}