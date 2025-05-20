//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: cheerful
/*
 * Cheerful Mailing List Manager
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_EMAIL_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

void print_welcome_msg() {
    printf("Welcome to the Cheerful Mailing List Manager!\n");
    printf("Please enter your name and email address to subscribe to our list.\n");
}

void print_goodbye_msg() {
    printf("Thank you for using the Cheerful Mailing List Manager!\n");
    printf("We hope to see you again soon.\n");
}

void print_menu() {
    printf("Please select an option from the following menu:\n");
    printf("1. Subscribe to the mailing list\n");
    printf("2. Unsubscribe from the mailing list\n");
    printf("3. View the mailing list\n");
    printf("4. Quit the program\n");
}

int main() {
    Subscriber subscribers[MAX_LIST_SIZE];
    int num_subscribers = 0;
    int option;

    print_welcome_msg();

    while (1) {
        print_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Please enter your name and email address:\n");
                scanf("%s %s", subscribers[num_subscribers].name, subscribers[num_subscribers].email);
                num_subscribers++;
                break;
            case 2:
                printf("Please enter the email address of the subscriber to unsubscribe:\n");
                scanf("%s", subscribers[num_subscribers].email);
                for (int i = 0; i < num_subscribers; i++) {
                    if (strcmp(subscribers[i].email, subscribers[num_subscribers].email) == 0) {
                        printf("Subscriber %s has been unsubscribed.\n", subscribers[i].name);
                        num_subscribers--;
                        break;
                    }
                }
                break;
            case 3:
                printf("The current mailing list contains the following subscribers:\n");
                for (int i = 0; i < num_subscribers; i++) {
                    printf("%s <%s>\n", subscribers[i].name, subscribers[i].email);
                }
                break;
            case 4:
                print_goodbye_msg();
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}