//FormAI DATASET v1.0 Category: Mailing list manager ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 1000

struct subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

struct mailing_list {
    int size;
    struct subscriber subscribers[MAX_LIST_SIZE];
};

int main() {
    struct mailing_list list;
    list.size = 0;

    char choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. List all subscribers\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        getchar();  // eat newline

        switch(choice) {
            case '1':
                if(list.size == MAX_LIST_SIZE) {
                    printf("\nThe mailing list is full. Cannot add more subscribers.\n");
                } else {
                    struct subscriber new_subscriber;
                    printf("\nEnter name: ");
                    fgets(new_subscriber.name, MAX_NAME_LENGTH, stdin);
                    printf("Enter email: ");
                    fgets(new_subscriber.email, MAX_EMAIL_LENGTH, stdin);

                    // remove newline from input
                    strtok(new_subscriber.name, "\n");
                    strtok(new_subscriber.email, "\n");

                    list.subscribers[list.size] = new_subscriber;
                    list.size++;

                    printf("\nSubscriber added successfully!\n");
                }
                break;

            case '2':
                if(list.size == 0) {
                    printf("\nThe mailing list is empty. Cannot remove subscribers.\n");
                } else {
                    char email_to_remove[MAX_EMAIL_LENGTH];
                    int found = 0;
                    printf("\nEnter email of subscriber to remove: ");
                    fgets(email_to_remove, MAX_EMAIL_LENGTH, stdin);

                    // remove newline from input
                    strtok(email_to_remove, "\n");

                    for(int i = 0; i < list.size; i++) {
                        if(strcmp(list.subscribers[i].email, email_to_remove) == 0) {
                            for(int j = i; j < list.size - 1; j++) {
                                list.subscribers[j] = list.subscribers[j+1];
                            }
                            list.size--;
                            found = 1;
                            break;
                        }
                    }
                    if(found) {
                        printf("\nSubscriber removed successfully!\n");
                    } else {
                        printf("\nSubscriber not found in mailing list.\n");
                    }
                }
                break;

            case '3':
                if(list.size == 0) {
                    printf("\nThe mailing list is empty.\n");
                } else {
                    printf("\nSubscribers:\n");
                    for(int i = 0; i < list.size; i++) {
                        printf("%s (%s)\n", list.subscribers[i].name, list.subscribers[i].email);
                    }
                }
                break;

            case '4':
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice.\n");
                break;
        }

    } while(choice != '4');

    return 0;
}