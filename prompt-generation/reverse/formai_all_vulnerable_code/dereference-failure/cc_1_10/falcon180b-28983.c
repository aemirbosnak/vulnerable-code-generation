//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAILS_PER_PERSON 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_emails;
    char *emails[MAX_EMAILS_PER_PERSON];
} Person;

int main() {
    Person *people = NULL;
    int num_people = 0;

    while (1) {
        printf("Enter a name (or type 'quit' to exit):\n");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        Person *new_person = malloc(sizeof(Person));
        strcpy(new_person->name, name);
        new_person->num_emails = 0;

        people = realloc(people, sizeof(Person) * ++num_people);
        people[num_people - 1] = *new_person;
    }

    printf("Enter email addresses (one per line):\n");
    while (1) {
        char email[MAX_NAME_LENGTH];
        scanf("%s", email);

        if (strcmp(email, "") == 0) {
            break;
        }

        int i;
        for (i = 0; i < num_people; i++) {
            if (strcmp(people[i].name, email) == 0) {
                people[i].emails[people[i].num_emails++] = strdup(email);
                break;
            }
        }

        if (i == num_people) {
            printf("No person found with name '%s'.\n", email);
        }
    }

    printf("Mailing list:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s:\n", people[i].name);
        for (int j = 0; j < people[i].num_emails; j++) {
            printf("\t%s\n", people[i].emails[j]);
        }
    }

    free(people);
    return 0;
}