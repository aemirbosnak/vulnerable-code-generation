//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAILS_PER_PERSON 10

typedef struct {
    char name[MAX_NAME_LEN];
    char emails[MAX_EMAILS_PER_PERSON][100];
    int num_emails;
} Person;

void add_email(Person *person, char *email) {
    if (person->num_emails >= MAX_EMAILS_PER_PERSON) {
        printf("Error: person already has %d emails\n", MAX_EMAILS_PER_PERSON);
        return;
    }
    strcpy(person->emails[person->num_emails], email);
    person->num_emails++;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Emails:\n");
    for (int i = 0; i < person->num_emails; i++) {
        printf("- %s\n", person->emails[i]);
    }
}

int main() {
    Person *people = NULL;
    int num_people = 0;

    while (1) {
        printf("Enter a name (or type 'done' to finish): ");
        char name[MAX_NAME_LEN];
        scanf("%s", name);
        if (strcmp(name, "done") == 0) {
            break;
        }

        Person *new_person = (Person *)malloc(sizeof(Person));
        strcpy(new_person->name, name);
        new_person->num_emails = 0;
        people = (Person *)realloc(people, sizeof(Person) * ++num_people);
        people[num_people - 1] = *new_person;
        free(new_person);

        while (1) {
            printf("Enter an email (or type 'done' to finish): ");
            char email[100];
            scanf("%s", email);
            if (strcmp(email, "done") == 0) {
                break;
            }
            add_email(&people[num_people - 1], email);
        }
    }

    printf("People:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    free(people);
    return 0;
}