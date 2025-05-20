//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

// Global variables
const char* funny_message[] = {
    "Hey there, stranger!",
    "What's up, buttercup?",
    "Greetings, mortal!",
    "Hola, amigo!",
    "Salutations, human!"
};

int main() {
    // Create a phone book with funny names and phone numbers
    struct phone_book {
        char name[MAX_NAME_LENGTH];
        char phone_number[MAX_PHONE_NUMBER_LENGTH];
    };

    struct phone_book phone_book[5] = {
        {"John Doe", "555-1234"},
        {"Jane Doe", "555-5678"},
        {"Bob Smith", "555-9012"},
        {"Alice Johnson", "555-1111"},
        {"Mike Brown", "555-2222"}
    };

    // Print a funny message when the program starts
    printf("Welcome to the funniest phone book ever! %s\n", funny_message[rand() % 5]);

    // Print the phone book with funny names and phone numbers
    for (int i = 0; i < 5; i++) {
        printf("%d. %s %s\n", i + 1, phone_book[i].name, phone_book[i].phone_number);
    }

    // Print a funny message when the user searches for a name
    printf("Enter a name to find their phone number: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(name, phone_book[i].name) == 0) {
            found = 1;
            printf("Found! %s %s\n", phone_book[i].name, phone_book[i].phone_number);
            break;
        }
    }
    if (!found) {
        printf("Sorry, %s is not in the phone book. Maybe try again?\n", name);
    }

    // Print a funny message when the user searches for a phone number
    printf("Enter a phone number to find the owner's name: ");
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
    scanf("%s", phone_number);
    for (int i = 0; i < 5; i++) {
        if (strcmp(phone_number, phone_book[i].phone_number) == 0) {
            printf("Found! %s %s\n", phone_book[i].name, phone_book[i].phone_number);
            break;
        }
    }
    if (!found) {
        printf("Sorry, %s is not in the phone book. Maybe try again?\n", phone_number);
    }

    return 0;
}