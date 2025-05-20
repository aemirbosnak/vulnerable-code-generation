//FormAI DATASET v1.0 Category: Mailing list manager ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50 //maximum number of subscribers
#define EMAIL_LEN 50 //maximum length of an email address

//structure to store email addresses
struct subscriber {
    char email[EMAIL_LEN];
};

//function to add a subscriber
void add_subscriber(struct subscriber email_list[], int *num_subs) {
    char new_email[EMAIL_LEN];
    printf("Enter the email address to add: ");
    scanf("%s", new_email);
    getchar(); //to clear the input buffer
    if (*num_subs == MAX) {
        printf("Email list is full. Cannot add any more subscribers.\n");
        return;
    }
    for (int i = 0; i < *num_subs; i++) {
        if (strcmp(email_list[i].email, new_email) == 0) {
            printf("%s is already a subscriber.\n", new_email);
            return;
        }
    }
    strcpy(email_list[*num_subs].email, new_email);
    (*num_subs)++;
    printf("%s has been added to the email list.\n", new_email);
}

//function to remove a subscriber
void remove_subscriber(struct subscriber email_list[], int *num_subs) {
    char del_email[EMAIL_LEN];
    printf("Enter the email address to remove: ");
    scanf("%s", del_email);
    getchar();
    for (int i = 0; i < *num_subs; i++) {
        if (strcmp(email_list[i].email, del_email) == 0) {
            for (int j = i; j < *num_subs - 1; j++) {
                strcpy(email_list[j].email, email_list[j + 1].email);
            }
            (*num_subs)--;
            printf("%s has been removed from the email list.\n", del_email);
            return;
        }
    }
    printf("%s is not a subscriber.\n", del_email);
}

//function to print all subscribers
void print_subscribers(struct subscriber email_list[], int num_subs) {
    if (num_subs == 0) {
        printf("There are no subscribers.\n");
        return;
    }
    printf("Email List:\n");
    for (int i = 0; i < num_subs; i++) {
        printf("%d. %s\n", i+1, email_list[i].email);
    }
}

//main function
int main() {
    struct subscriber email_list[MAX];
    int num_subs = 0;
    int choice;

    printf("Welcome to the email list manager!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add a subscriber\n");
        printf("2. Remove a subscriber\n");
        printf("3. View all subscribers\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_subscriber(email_list, &num_subs);
                break;
            case 2:
                remove_subscriber(email_list, &num_subs);
                break;
            case 3:
                print_subscribers(email_list, num_subs);
                break;
            case 4:
                printf("Exiting email list manager...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}