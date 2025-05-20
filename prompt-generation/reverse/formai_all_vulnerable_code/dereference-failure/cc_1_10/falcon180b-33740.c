//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_EMAILS_PER_PERSON 10

typedef struct {
    char name[MAX_NAME_LEN];
    int num_emails;
    char *emails[MAX_EMAILS_PER_PERSON];
} Person;

Person *create_person(char *name) {
    Person *person = malloc(sizeof(Person));
    strcpy(person->name, name);
    person->num_emails = 0;
    return person;
}

void add_email(Person *person, char *email) {
    if (person->num_emails >= MAX_EMAILS_PER_PERSON) {
        printf("Error: Person already has maximum number of emails.\n");
        return;
    }
    person->emails[person->num_emails] = malloc(strlen(email) + 1);
    strcpy(person->emails[person->num_emails], email);
    person->num_emails++;
}

void send_email(Person *person, char *subject, char *body) {
    int i;
    for (i = 0; i < person->num_emails; i++) {
        printf("Sending email to %s...\n", person->emails[i]);
    }
}

int main() {
    Person *person1 = create_person("John Doe");
    add_email(person1, "john.doe@example.com");
    add_email(person1, "johndoe@gmail.com");

    Person *person2 = create_person("Jane Smith");
    add_email(person2, "jane.smith@example.com");

    send_email(person1, "Test Email", "Hello World!");
    send_email(person2, "Test Email", "Hello World!");

    return 0;
}