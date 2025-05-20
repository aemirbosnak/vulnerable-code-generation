//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: Alan Turing
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
    char address[50];
} Person;

typedef struct {
    char name[50];
    char subject[50];
    char message[500];
    char cc[50];
    char bcc[50];
} Email;

typedef struct {
    char name[50];
    char list[50];
    int num_members;
} List;

void add_person(List* list, Person* person) {
    strcpy(list->name, person->name);
    strcpy(list->list, person->email);
    list->num_members++;
}

void add_email(List* list, Email* email) {
    strcpy(list->name, email->name);
    strcpy(list->list, email->subject);
    strcpy(list->list, email->message);
    strcpy(list->list, email->cc);
    strcpy(list->list, email->bcc);
    list->num_members++;
}

void send_email(List* list) {
    for (int i = 0; i < list->num_members; i++) {
        printf("%s\n", list->list[i]);
    }
}

int main() {
    List my_list;
    Person person1;
    Person person2;
    Person person3;
    Email email1;
    Email email2;
    Email email3;

    strcpy(person1.name, "John Doe");
    strcpy(person1.email, "john.doe@example.com");
    strcpy(person1.address, "123 Main Street");
    add_person(&my_list, &person1);

    strcpy(person2.name, "Jane Smith");
    strcpy(person2.email, "jane.smith@example.com");
    strcpy(person2.address, "456 Oak Avenue");
    add_person(&my_list, &person2);

    strcpy(person3.name, "Bob Johnson");
    strcpy(person3.email, "bob.johnson@example.com");
    strcpy(person3.address, "789 Pine Street");
    add_person(&my_list, &person3);

    strcpy(email1.name, "John Doe");
    strcpy(email1.subject, "Hello");
    strcpy(email1.message, "How are you?");
    strcpy(email1.cc, "jane.smith@example.com");
    strcpy(email1.bcc, "bob.johnson@example.com");
    add_email(&my_list, &email1);

    strcpy(email2.name, "Jane Smith");
    strcpy(email2.subject, "Meeting Reminder");
    strcpy(email2.message, "The meeting is tomorrow at 10 AM.");
    strcpy(email2.cc, "");
    strcpy(email2.bcc, "");
    add_email(&my_list, &email2);

    strcpy(email3.name, "Bob Johnson");
    strcpy(email3.subject, "Invitation");
    strcpy(email3.message, "You are invited to my birthday party.");
    strcpy(email3.cc, "john.doe@example.com");
    strcpy(email3.bcc, "");
    add_email(&my_list, &email3);

    send_email(&my_list);

    return 0;
}