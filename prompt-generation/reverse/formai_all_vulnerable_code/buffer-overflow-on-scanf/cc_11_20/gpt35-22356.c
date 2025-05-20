//FormAI DATASET v1.0 Category: Database querying ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[20];
    int age;
    char email[30];
} Person;

int main() {
    Person *personArr;
    int numPeople, i, choice, found = 0;
    char searchName[20], searchEmail[30], nameToChange[20];
    
    printf("Enter the number of people in database: ");
    scanf("%d", &numPeople);

    personArr = (Person*)calloc(numPeople, sizeof(Person));
    
    printf("\nEnter details of people in database:\n");
    for(i = 0; i < numPeople; i++) {
        printf("Person %d - ", i+1);
        printf("Name: ");
        scanf("%s", personArr[i].name);
        printf("Age: ");
        scanf("%d", &personArr[i].age);
        printf("Email: ");
        scanf("%s", personArr[i].email);
    }

    printf("\n1. Search for a person by name\n2. Search for a person by email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("\nEnter the name to search for: ");
        scanf("%s", searchName);
        for(i = 0; i < numPeople; i++) {
            if(strcmp(searchName, personArr[i].name) == 0) {
                printf("\nName: %s\nAge: %d\nEmail: %s\n", personArr[i].name, 
                                                         personArr[i].age, 
                                                         personArr[i].email);
                found = 1;
                break;
            }
        }
        if(!found) printf("\nNo person with that name found!\n");
    }
    else if(choice == 2) {
        printf("\nEnter the email to search for: ");
        scanf("%s", searchEmail);
        for(i = 0; i < numPeople; i++) {
            if(strcmp(searchEmail, personArr[i].email) == 0) {
                printf("\nName: %s\nAge: %d\nEmail: %s\n", personArr[i].name, 
                                                         personArr[i].age, 
                                                         personArr[i].email);
                found = 1;
                break;
            }
        }
        if(!found) printf("\nNo person with that email found!\n");
    }

    printf("\nEnter the name of the person whose email you wish to change: ");
    scanf("%s", nameToChange);

    for(i = 0; i < numPeople; i++) {
        if(strcmp(nameToChange, personArr[i].name) == 0) {
            printf("\nEnter new email: ");
            scanf("%s", personArr[i].email);
            printf("\n%s's email has been updated to %s.\n", personArr[i].name, personArr[i].email);
            break;
        }
    }

    free(personArr);

    return 0;
}