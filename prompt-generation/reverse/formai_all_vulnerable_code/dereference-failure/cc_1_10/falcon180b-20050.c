//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: shocked
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

void add_email(Person *person, char *email) {
    if (person->num_emails >= MAX_EMAILS_PER_PERSON) {
        printf("Error: Person already has %d emails, can't add more.\n", MAX_EMAILS_PER_PERSON);
        return;
    }
    person->emails[person->num_emails] = strdup(email);
    person->num_emails++;
}

int main() {
    Person *people = malloc(sizeof(Person));
    int num_people = 1;

    people[0].num_emails = 0;

    while (1) {
        printf("Enter name (leave blank to finish): ");
        scanf("%s", people[num_people-1].name);
        if (strcmp(people[num_people-1].name, "") == 0) {
            break;
        }
        num_people++;
        people = realloc(people, sizeof(Person) * num_people);
    }

    for (int i = 0; i < num_people; i++) {
        printf("Enter emails for %s (one per line, enter blank line when finished):\n", people[i].name);
        while (1) {
            char email[100];
            scanf("%s", email);
            if (strcmp(email, "") == 0) {
                break;
            }
            add_email(&people[i], email);
        }
    }

    printf("Mailing list:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s:\n", people[i].name);
        for (int j = 0; j < people[i].num_emails; j++) {
            printf("\t%s\n", people[i].emails[j]);
        }
    }

    for (int i = 0; i < num_people; i++) {
        for (int j = 0; j < people[i].num_emails; j++) {
            free(people[i].emails[j]);
        }
        free(people[i].emails);
    }
    free(people);

    return 0;
}