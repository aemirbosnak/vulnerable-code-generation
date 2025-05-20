//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

// Function declarations
void addMember(MailingList *list, const char *email);
void removeMember(MailingList *list, const char *email);
void displayMembers(const MailingList *list);
int isEmailInList(const MailingList *list, const char *email);

int main() {
    MailingList list;
    list.count = 0;

    int choice;
    char email[MAX_EMAIL_LENGTH];
    
    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add member\n");
        printf("2. Remove member\n");
        printf("3. Display members\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove the newline character
                addMember(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove the newline character
                removeMember(&list, email);
                break;
            case 3:
                displayMembers(&list);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

void addMember(MailingList *list, const char *email) {
    if (list->count >= MAX_MEMBERS) {
        printf("Mailing list is full! Cannot add more members.\n");
        return;
    }
    if (isEmailInList(list, email)) {
        printf("Email '%s' is already in the mailing list.\n", email);
        return;
    }

    strcpy(list->members[list->count].email, email);
    list->count++;
    printf("Email '%s' added to the mailing list!\n", email);
}

void removeMember(MailingList *list, const char *email) {
    int found = 0;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            found = 1;
            // Shift members down to remove the member
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            printf("Email '%s' removed from the mailing list!\n", email);
            break;
        }
    }
    if (!found) {
        printf("Email '%s' not found in the mailing list.\n", email);
    }
}

void displayMembers(const MailingList *list) {
    if (list->count == 0) {
        printf("The mailing list is empty.\n");
        return;
    }

    printf("\nMembers of the mailing list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->members[i].email);
    }
}

int isEmailInList(const MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            return 1; // Email exists in the list
        }
    }
    return 0; // Email does not exist in the list
}