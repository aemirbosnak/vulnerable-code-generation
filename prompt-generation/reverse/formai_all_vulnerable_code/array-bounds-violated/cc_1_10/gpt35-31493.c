//FormAI DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define surreal phone book data structure */
typedef struct surrealist_phonebook {
    char* name;
    char* phone_number;
    char* favorite_food;
    char* dream_destination;
    char* favorite_color;
} Surrealist_Phonebook;

int main() {
    Surrealist_Phonebook* contacts = NULL;
    int num_contacts = 0;
    char input[256];

    printf("Welcome to the Surrealist Phone Book!\n");

    /* Loop through menu options until exit is chosen */
    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add new contact\n");
        printf("2. View existing contacts\n");
        printf("3. Exit\n");
        fgets(input, 256, stdin);
        input[strlen(input) - 1] = '\0';

        /* Add new contact */
        if (strcmp(input, "1") == 0) {
            contacts = realloc(contacts, (num_contacts + 1) * sizeof(Surrealist_Phonebook));
            Surrealist_Phonebook new_contact;

            printf("What is the name of your new contact?\n");
            fgets(input, 256, stdin);
            input[strlen(input) - 1] = '\0';
            new_contact.name = strdup(input);

            printf("What is the phone number for %s?\n", new_contact.name);
            fgets(input, 256, stdin);
            input[strlen(input) - 1] = '\0';
            new_contact.phone_number = strdup(input);

            printf("What is %s's favorite food?\n", new_contact.name);
            fgets(input, 256, stdin);
            input[strlen(input) - 1] = '\0';
            new_contact.favorite_food = strdup(input);

            printf("What is %s's dream destination?\n", new_contact.name);
            fgets(input, 256, stdin);
            input[strlen(input) - 1] = '\0';
            new_contact.dream_destination = strdup(input);

            printf("What is %s's favorite color?\n", new_contact.name);
            fgets(input, 256, stdin);
            input[strlen(input) - 1] = '\0';
            new_contact.favorite_color = strdup(input);

            contacts[num_contacts++] = new_contact;
            printf("New contact %s added to the phone book!\n", new_contact.name);
        }

        /* View existing contacts */
        else if (strcmp(input, "2") == 0) {
            if (num_contacts == 0) {
                printf("There are no contacts in the phone book!\n");
            }
            else {
                printf("Here are the contacts stored in the phone book:\n");

                for (int i = 0; i < num_contacts; i++) {
                    Surrealist_Phonebook current_contact = contacts[i];

                    printf("Name: %s\n", current_contact.name);
                    printf("Phone number: %s\n", current_contact.phone_number);
                    printf("Favorite food: %s\n", current_contact.favorite_food);
                    printf("Dream destination: %s\n", current_contact.dream_destination);
                    printf("Favorite color: %s\n\n", current_contact.favorite_color);
                }
            }
        }

        /* Exit */
        else if (strcmp(input, "3") == 0) {
            printf("Thank you for using the Surrealist Phone Book!\n");
            for (int i = 0; i < num_contacts; i++) {
                free(contacts[i].name);
                free(contacts[i].phone_number);
                free(contacts[i].favorite_food);
                free(contacts[i].dream_destination);
                free(contacts[i].favorite_color);
            }
            free(contacts);
            break;
        }

        /* Invalid input */
        else {
            printf("Incorrect input, please try again.\n");
        }
    }

    return 0;
}