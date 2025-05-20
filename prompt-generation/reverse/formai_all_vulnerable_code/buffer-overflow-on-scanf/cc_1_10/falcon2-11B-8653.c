//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

struct phonebook {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

struct phonebook phonebook[100];

void addPhoneBook(char name[], char number[]) {
    int i;

    for (i = 0; i < 100; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            strcpy(phonebook[i].number, number);
            break;
        }
    }

    if (i == 100) {
        strcpy(phonebook[i].name, name);
        strcpy(phonebook[i].number, number);
    }
}

void printPhoneBook() {
    int i;

    printf("Phone Book:\n");
    for (i = 0; i < 100; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    char name[MAX_NAME_LENGTH], number[MAX_NUMBER_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter number: ");
    scanf("%s", number);

    addPhoneBook(name, number);

    printf("Phone Book:\n");
    printPhoneBook();

    return 0;
}