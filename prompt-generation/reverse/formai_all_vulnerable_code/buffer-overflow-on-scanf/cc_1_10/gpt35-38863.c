//FormAI DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMAIL_LEN 50
#define MAX_NAME_LEN 50
#define MAX_PEOPLE 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Person;

int add_person(Person*, int);
void remove_person(Person*, int);
void print_list(Person*, int);

int main() {
    Person people[MAX_PEOPLE];
    int num_people = 0;
    char option;

    while(1) {
        printf("\nWelcome to the mailing list manager.");
        printf("\nChoose an option:\n");
        printf("\t1. Add a person");

        if(num_people > 0) {
            printf("\n\t2. Remove a person\n");
            printf("\t3. Print the list\n");
            printf("\t4. Quit\n");
        }
        else {
            printf("\n\t2. Quit\n");
        }

        printf("> ");
        scanf(" %c", &option);

        switch(option) {
            case '1':
                num_people = add_person(people, num_people);
                break;
            case '2':
                if(num_people > 0) {
                    remove_person(people, num_people);
                    num_people--;
                }
                else {
                    printf("\nThere are no people on the list.\n");
                }
                break;
            case '3':
                if(num_people > 0) {
                    print_list(people, num_people);
                }
                else {
                    printf("\nThere are no people on the list.\n");
                }
                break;
            case '4':
                if(num_people > 0) {
                    printf("\nGoodbye.\n");
                }
                else {
                    printf("\nThere are no people on the list.\n");
                }
                return 0;
            default:
                printf("\nInvalid option.\n");
        }
    }
}

int add_person(Person* people, int num_people) {
    if(num_people == MAX_PEOPLE) {
        printf("\nThe list is full.\n");
        return num_people;
    }

    while(getchar() != '\n');

    printf("\nEnter the person's name: ");
    fgets(people[num_people].name, MAX_NAME_LEN, stdin);
    people[num_people].name[strcspn(people[num_people].name, "\n")] = 0;

    printf("Enter the person's email: ");
    fgets(people[num_people].email, MAX_EMAIL_LEN, stdin);
    people[num_people].email[strcspn(people[num_people].email, "\n")] = 0;

    printf("\n%s <%s> has been added to the list.\n", people[num_people].name, people[num_people].email);

    return num_people + 1;
}

void remove_person(Person* people, int num_people) {
    int i, index;
    char name[MAX_NAME_LEN];

    while(getchar() != '\n');

    printf("\nEnter the name of the person to remove: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = 0;

    for(i = 0; i < num_people; i++) {
        if(strcmp(name, people[i].name) == 0) {
            index = i;
            break;
        }
    }

    if(i == num_people) {
        printf("\n%s is not on the list.\n", name);
        return;
    }

    printf("\n%s <%s> has been removed from the list.\n", people[index].name, people[index].email);

    for(i = index; i < num_people - 1; i++) {
        people[i] = people[i + 1];
    }
}

void print_list(Person* people, int num_people) {
    int i;

    printf("\nMailing list:\n");
    for(i = 0; i < num_people; i++) {
        printf("%s <%s>\n", people[i].name, people[i].email);
    }
}