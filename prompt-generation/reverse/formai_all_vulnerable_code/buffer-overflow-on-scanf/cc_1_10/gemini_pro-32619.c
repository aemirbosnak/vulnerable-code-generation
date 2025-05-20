//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of subscribers
#define MAX_SUBSCRIBERS 100

// Define the structure of a subscriber
typedef struct subscriber {
    char name[50];
    char email[50];
} subscriber;

// Define the mailing list
subscriber subscribers[MAX_SUBSCRIBERS];

// Define the number of subscribers
int num_subscribers = 0;

// Define the menu options
enum menu_option {
    ADD_SUBSCRIBER,
    REMOVE_SUBSCRIBER,
    SEND_EMAIL,
    EXIT
};

// Get a menu option from the user
enum menu_option get_menu_option() {
    int option;
    do {
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
    } while (option < 1 || option > 4);
    return option;
}

// Add a subscriber to the mailing list
void add_subscriber() {
    if (num_subscribers == MAX_SUBSCRIBERS) {
        printf("The mailing list is full.\n");
        return;
    }
    printf("Enter the subscriber's name: ");
    scanf("%s", subscribers[num_subscribers].name);
    printf("Enter the subscriber's email: ");
    scanf("%s", subscribers[num_subscribers].email);
    num_subscribers++;
}

// Remove a subscriber from the mailing list
void remove_subscriber() {
    if (num_subscribers == 0) {
        printf("The mailing list is empty.\n");
        return;
    }
    printf("Enter the name of the subscriber to remove: ");
    char name[50];
    scanf("%s", name);
    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].name, name) == 0) {
            subscribers[i] = subscribers[num_subscribers - 1];
            num_subscribers--;
            break;
        }
    }
    if (i == num_subscribers) {
        printf("The subscriber was not found.\n");
    }
}

// Send an email to all subscribers
void send_email() {
    if (num_subscribers == 0) {
        printf("The mailing list is empty.\n");
        return;
    }
    printf("Enter the subject of the email: ");
    char subject[50];
    scanf("%s", subject);
    printf("Enter the body of the email: ");
    char body[255];
    scanf("%s", body);
    int i;
    for (i = 0; i < num_subscribers; i++) {
        printf("To: %s <%s>\n", subscribers[i].name, subscribers[i].email);
        printf("Subject: %s\n", subject);
        printf("Body: %s\n", body);
    }
}

// Main function
int main() {
    // Initialize the mailing list
    num_subscribers = 0;

    // Main loop
    while (1) {
        // Get a menu option from the user
        enum menu_option option = get_menu_option();

        // Perform the selected action
        switch (option) {
            case ADD_SUBSCRIBER:
                add_subscriber();
                break;
            case REMOVE_SUBSCRIBER:
                remove_subscriber();
                break;
            case SEND_EMAIL:
                send_email();
                break;
            case EXIT:
                return 0;
        }
    }

    return 0;
}