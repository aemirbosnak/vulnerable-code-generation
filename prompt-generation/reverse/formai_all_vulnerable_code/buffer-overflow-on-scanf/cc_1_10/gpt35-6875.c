//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100     // maximum number of emails in the mailing list
#define MAX_EMAIL_LEN 50   // maximum length of an email

typedef struct {
    char email[MAX_EMAIL_LEN];
    int age;
} Person;  // struct to hold a person's email and age

Person* mailingList[MAX_EMAILS];   // array of pointers to Person structs (mailing list)
int numEmails = 0;   // keeps track of number of emails in mailing list

/* Function prototypes */
void addPerson();
void removePerson();
void printMailingList();

int main() {
    int choice;

    printf("Welcome to the mailing list manager!\n");

    while (1) {
        printf("\n1. Add new person\n2. Remove person\n3. Print mailing list\n4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addPerson();
                break;
            case 2:
                removePerson();
                break;
            case 3:
                printMailingList();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

/* Adds a new person to the mailing list */
void addPerson() {
    Person* newPerson = (Person*) malloc(sizeof(Person));   // allocate memory for new person
    if (newPerson == NULL) {
        printf("Unable to allocate memory!\n");
        return;
    }

    printf("Enter person's email: ");
    scanf("%s", newPerson->email);

    printf("Enter person's age: ");
    scanf("%d", &(newPerson->age));

    mailingList[numEmails++] = newPerson;   // add new person to mailing list

    printf("Person added successfully!\n");
}

/* Removes a person from the mailing list */
void removePerson() {
    int i;
    char email[MAX_EMAIL_LEN];

    printf("Enter email of person to remove: ");
    scanf("%s", email);

    for (i = 0; i < numEmails; i++) {
        if (strcmp(email, mailingList[i]->email) == 0) {
            free(mailingList[i]);            // free memory allocated for person
            numEmails--;
            memmove(&mailingList[i], &mailingList[i+1], (numEmails-i) * sizeof(Person*));   // shift elements down
            printf("Person removed successfully!\n");
            return;
        }
    }

    printf("Person not found in mailing list.\n");
}

/* Prints the entire mailing list */
void printMailingList() {
    int i;

    if (numEmails == 0) {
        printf("Mailing list is empty.\n");
        return;
    }

    printf("Mailing list:\n");

    for (i = 0; i < numEmails; i++) {
        printf("%s,%d\n", mailingList[i]->email, mailingList[i]->age);
    }
}