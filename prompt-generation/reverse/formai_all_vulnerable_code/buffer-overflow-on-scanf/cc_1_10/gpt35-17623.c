//FormAI DATASET v1.0 Category: Phone Book ; Style: intelligent
#include<stdio.h>
#include<string.h>

struct contact {
    char name[50];
    char phone[15];
    char email[50];
};

int main() {

    // Initializing the phone book as an array of structures
    struct contact phone_book[100];

    // Initializing variables for user input handling
    char input[10];
    char query[50];
    int num_contacts = 0;

    // The main loop of the program
    while (1) {
        printf("What would you like to do? (add, search, exit)\n");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter a name:\n");
            scanf("%s", phone_book[num_contacts].name);

            printf("Enter a phone number:\n");
            scanf("%s", phone_book[num_contacts].phone);

            printf("Enter an email address:\n");
            scanf("%s", phone_book[num_contacts].email);

            printf("Added %s to phone book.\n", phone_book[num_contacts].name);

            num_contacts++;
        }

        else if (strcmp(input, "search") == 0) {
            printf("Enter a name to search for:\n");
            scanf("%s", query);

            int found = 0;
            for (int i=0; i<num_contacts; i++) {
                if (strcmp(phone_book[i].name, query) == 0) {
                    printf("Name: %s\nPhone: %s\nEmail: %s\n", phone_book[i].name, phone_book[i].phone, phone_book[i].email);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("No contact found with name '%s'.\n", query);
            }
        }

        else if (strcmp(input, "exit") == 0) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        else {
            printf("Invalid input. Please try again.\n");
        }

    }

    return 0;
}