//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <string.h>

struct Person {
    char name[50];
    char phoneNumber[20];
};

int main() {
    struct Person persons[100];
    int numPersons = 0;

    printf("Enter name: ");
    scanf("%s", persons[numPersons].name);
    printf("Enter phone number: ");
    scanf("%s", persons[numPersons].phoneNumber);

    numPersons++;

    printf("Do you want to enter another person? (y/n): ");
    char input;
    scanf(" %c", &input);
    if (input == 'y' || input == 'Y') {
        while (1) {
            printf("Enter name: ");
            scanf("%s", persons[numPersons].name);
            printf("Enter phone number: ");
            scanf("%s", persons[numPersons].phoneNumber);

            numPersons++;
            printf("Do you want to enter another person? (y/n): ");
            scanf(" %c", &input);
            if (input == 'n' || input == 'N') {
                break;
            }
        }
    } else {
        printf("Enter name: ");
        scanf("%s", persons[numPersons].name);
        printf("Enter phone number: ");
        scanf("%s", persons[numPersons].phoneNumber);
    }

    printf("Enter the name of the person you want to search: ");
    char searchName[50];
    scanf("%s", searchName);

    for (int i = 0; i < numPersons; i++) {
        if (strcmp(persons[i].name, searchName) == 0) {
            printf("%s: %s\n", searchName, persons[i].phoneNumber);
            break;
        }
    }

    return 0;
}