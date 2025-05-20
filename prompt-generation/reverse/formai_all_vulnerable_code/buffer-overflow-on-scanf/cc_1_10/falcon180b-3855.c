//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: puzzling
/* This is a C Mailing list manager example program in a puzzling style */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAILS_PER_PERSON 10
#define MAX_PEOPLE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_emails;
    char emails[MAX_EMAILS_PER_PERSON][MAX_NAME_LENGTH];
} Person;

void add_person(Person people[], int num_people, char name[], char email[]) {
    int i;
    for (i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            strcpy(people[i].emails[people[i].num_emails], email);
            people[i].num_emails++;
            return;
        }
    }
    strcpy(people[num_people].name, name);
    strcpy(people[num_people].emails[0], email);
    people[num_people].num_emails = 1;
    num_people++;
}

void remove_person(Person people[], int num_people, char name[]) {
    int i;
    for (i = 0; i < num_people; i++) {
        if (strcmp(people[i].name, name) == 0) {
            memmove(&people[i], &people[i+1], (num_people - i - 1) * sizeof(Person));
            num_people--;
            return;
        }
    }
}

void print_people(Person people[], int num_people) {
    int i, j;
    for (i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i].name);
        for (j = 0; j < people[i].num_emails; j++) {
            printf("Email: %s\n", people[i].emails[j]);
        }
    }
}

int main() {
    Person people[MAX_PEOPLE];
    int num_people = 0;
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];

    while (1) {
        printf("Enter name: ");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter email: ");
        scanf("%s", email);

        add_person(people, num_people, name, email);
    }

    while (1) {
        printf("Enter name to remove: ");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        remove_person(people, num_people, name);
    }

    printf("People:\n");
    print_people(people, num_people);

    return 0;
}