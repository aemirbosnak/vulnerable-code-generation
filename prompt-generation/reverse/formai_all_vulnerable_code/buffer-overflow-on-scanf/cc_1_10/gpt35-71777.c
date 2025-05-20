//FormAI DATASET v1.0 Category: Mailing list manager ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50 // Maximum length of a name in the mailing list
#define MAX_EMAIL_LENGTH 100 // Maximum length of an email address in the mailing list

// Struct representing a person in the mailing list
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Person;

// Struct representing the mailing list
typedef struct {
    int num_people;
    Person people[1000];
} MailingList;

// Function to add a person to the mailing list
void add_person(MailingList* list) {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline from user input

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0; // Remove trailing newline from user input

    Person new_person;
    strncpy(new_person.name, name, strlen(name)+1); // Copy name into new_person struct
    strncpy(new_person.email, email, strlen(email)+1); // Copy email into new_person struct

    list->people[list->num_people] = new_person; // Add new_person to the mailing list
    list->num_people++;
}

// Function to remove a person from the mailing list
void remove_person(MailingList* list, char* email) {
    for(int i = 0; i < list->num_people; i++) {
        if(strcmp(list->people[i].email, email) == 0) {
            for(int j = i; j < list->num_people-1; j++) {
                list->people[j] = list->people[j+1]; // Shift elements to fill gap
            }
            list->num_people--;
            break;
        }
    }
}

// Function to print out all people in the mailing list
void print_list(MailingList* list) {
    for(int i = 0; i < list->num_people; i++) {
        printf("%s (%s)\n", list->people[i].name, list->people[i].email);
    }
}

int main() {
    MailingList list = {
        .num_people = 0
    };

    while(1) {
        char option;
        printf("Enter option (a:add, r:remove, p:print, q:quit): ");
        scanf(" %c", &option);
        
        switch(option) {
            case 'a':
                add_person(&list);
                break;
            case 'r': {
                char email[MAX_EMAIL_LENGTH];
                printf("Enter email: ");
                scanf(" %99s", email);
                remove_person(&list, email);
                break;
            }
            case 'p':
                print_list(&list);
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}