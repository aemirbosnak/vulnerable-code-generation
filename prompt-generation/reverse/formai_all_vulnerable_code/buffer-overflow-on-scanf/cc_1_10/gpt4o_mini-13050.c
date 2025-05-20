//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

void initializeList(MailingList *list) {
    list->count = 0;
    printf("Mailing list initialized! Get ready to add some members!\n");
}

int addMember(MailingList *list, const char *email) {
    if (list->count >= MAX_MEMBERS) {
        printf("Oops! Mailing list is full! Can't add more members.\n");
        return -1;
    }
    strcpy(list->members[list->count].email, email);
    list->count++;
    printf("Hooray! Member %s added to the list!\n", email);
    return 0;
}

void removeMember(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("Bye-bye %s! You have been removed from the list.\n", email);
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            return;
        }
    }
    printf("Oops! Member %s not found in the list!\n", email);
}

void displayMembers(const MailingList *list) {
    if (list->count == 0) {
        printf("No members in the list yet! Time to get inviting!\n");
        return;
    }
    printf("Current Mailing List Members:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->members[i].email);
    }
}

void sendEmail(const MailingList *list, const char *message) {
    if (list->count == 0) {
        printf("Can't send emails! The mailing list is empty!\n");
        return;
    }

    printf("Sending emails...\n");
    for (int i = 0; i < list->count; i++) {
        printf("Email sent to: %s\nMessage: %s\n", list->members[i].email, message);
    }
}

void saveList(const MailingList *list) {
    FILE *file = fopen("mailing_list.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving!\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s\n", list->members[i].email);
    }
    fclose(file);
    printf("Mailing list saved successfully! Keep it safe!\n");
}

void loadList(MailingList *list) {
    FILE *file = fopen("mailing_list.txt", "r");
    if (file == NULL) {
        printf("No saved list found! Let's start fresh!\n");
        return;
    }
    while (fgets(list->members[list->count].email, MAX_EMAIL_LENGTH, file) != NULL) {
        list->members[list->count].email[strcspn(list->members[list->count].email, "\n")] = 0; // Remove newline
        list->count++;
        if (list->count >= MAX_MEMBERS) {
            break;
        }
    }
    fclose(file);
    printf("Mailing list loaded successfully with %d members!\n", list->count);
}

void displayMenu() {
    printf("\n--- Mailing List Manager ---\n");
    printf("1. Add Member\n");
    printf("2. Remove Member\n");
    printf("3. Display Members\n");
    printf("4. Send Email\n");
    printf("5. Save List to File\n");
    printf("6. Load List from File\n");
    printf("7. Exit\n");
    printf("---------------------------\n");
    printf("Choose an option: ");
}

int main() {
    MailingList list;
    initializeList(&list);

    int choice;
    char email[MAX_EMAIL_LENGTH];
    char message[256];

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                addMember(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                removeMember(&list, email);
                break;
            case 3:
                displayMembers(&list);
                break;
            case 4:
                printf("Enter message to send: ");
                fgets(message, 256, stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline
                sendEmail(&list, message);
                break;
            case 5:
                saveList(&list);
                break;
            case 6:
                loadList(&list);
                break;
            case 7:
                printf("Exiting the Mailing List Manager. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again!\n");
                break;
        }
    } while (choice != 7);

    return 0;
}