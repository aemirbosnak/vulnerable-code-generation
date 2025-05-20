//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for each email
struct email {
    char to[100];
    char from[100];
    char subject[100];
    char message[1000];
};

// Define a function to add new emails to the list
void addEmail(struct email *list, int *count) {
    printf("Enter recipient email address:\n");
    scanf("%s", list[*count].to);
    printf("Enter sender email address:\n");
    scanf("%s", list[*count].from);
    printf("Enter email subject:\n");
    scanf("%s", list[*count].subject);
    printf("Enter email message:\n");
    scanf(" %[^\n]", list[*count].message);
    *count += 1;
    printf("Email added successfully!\n\n");
}

// Define a function to display all emails in the list
void viewEmails(struct email *list, int count) {
    if (count == 0) {
        printf("No emails to display.\n\n");
    } else {
        printf("Emails in list:\n");
        for (int i = 0; i < count; i++) {
            printf("To: %s\nFrom: %s\nSubject: %s\nMessage: %s\n\n", list[i].to, list[i].from, list[i].subject, list[i].message);
        }
    }
}

// Define the main function to run the program
int main() {
    printf("-------------------------------------------\n");
    printf("   Welcome to the Cyberpunk Mailing List\n");
    printf("-------------------------------------------\n\n");

    int count = 0;
    struct email *list = malloc(100 * sizeof(struct email));

    while (1) {
        printf("Menu:\n");
        printf("1. Add email\n");
        printf("2. View all emails\n");
        printf("3. Exit program\n");
        printf("Enter a command: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addEmail(list, &count);
        } else if (choice == 2) {
            viewEmails(list, count);
        } else if (choice == 3) {
            printf("Exiting program...\n");
            free(list);
            exit(0);
        } else {
            printf("Invalid command. Please try again.\n\n");
        }
    }

    return 0;
}