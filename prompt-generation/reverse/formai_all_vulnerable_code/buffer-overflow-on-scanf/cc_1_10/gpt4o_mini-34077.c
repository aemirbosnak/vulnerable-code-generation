//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define EMAIL_LENGTH 100

// Structure to hold member information
typedef struct {
    char email[EMAIL_LENGTH];
} Member;

// Structure to hold the mailing list
typedef struct {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

// Function prototypes
void initializeList(MailingList *list);
int addMember(MailingList *list, const char *email);
int removeMember(MailingList *list, const char *email);
void displayMembers(const MailingList *list);
void displayMenu();
int isEmailExists(const MailingList *list, const char *email);

// Main function
int main() {
    MailingList list;
    initializeList(&list);

    int option;
    char email[EMAIL_LENGTH];

    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &option);
        getchar(); // To consume the newline character

        switch (option) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                if (addMember(&list, email)) {
                    printf("Email added successfully.\n");
                } else {
                    printf("Failed to add email. It may already exist or list is full.\n");
                }
                break;

            case 2:
                printf("Enter email to remove: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                if (removeMember(&list, email)) {
                    printf("Email removed successfully.\n");
                } else {
                    printf("Failed to remove email. It may not exist.\n");
                }
                break;

            case 3:
                printf("Current members of the mailing list:\n");
                displayMembers(&list);
                break;

            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 0);

    return 0;
}

// Function to initialize the mailing list
void initializeList(MailingList *list) {
    list->count = 0;
}

// Function to add a member to the mailing list
int addMember(MailingList *list, const char *email) {
    if (list->count >= MAX_MEMBERS || isEmailExists(list, email)) {
        return 0; // Fail to add member
    }
    strcpy(list->members[list->count].email, email);
    list->count++;
    return 1; // Success
}

// Function to remove a member from the mailing list
int removeMember(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            // Shift members down
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            return 1; // Success
        }
    }
    return 0; // Fail to remove member
}

// Function to display all members in the mailing list
void displayMembers(const MailingList *list) {
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->members[i].email);
    }
    if (list->count == 0) {
        printf("No members in the mailing list.\n");
    }
}

// Function to display the menu options
void displayMenu() {
    printf("\n--- Mailing List Manager ---\n");
    printf("1. Add member\n");
    printf("2. Remove member\n");
    printf("3. Display all members\n");
    printf("0. Exit\n");
}

// Check if the email already exists in the mailing list
int isEmailExists(const MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            return 1; // Email already exists
        }
    }
    return 0; // Email does not exist
}