//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Subscriber;

typedef struct {
    Subscriber members[MAX_MEMBERS];
    int count;
} MailingList;

void initializeList(MailingList* list) {
    list->count = 0;
    printf("Mailing list initialized. Ready for subscribers.\n");
}

void addSubscriber(MailingList* list) {
    if (list->count >= MAX_MEMBERS) {
        printf("Mailing list is full! Cannot add more subscribers.\n");
        return;
    }

    Subscriber newSubscriber;

    printf("Enter subscriber name: ");
    scanf(" %[^\n]", newSubscriber.name);
    printf("Enter subscriber email: ");
    scanf(" %[^\n]", newSubscriber.email);

    list->members[list->count] = newSubscriber;
    list->count++;

    printf("Subscriber added: %s <%s>\n", newSubscriber.name, newSubscriber.email);
}

void removeSubscriber(MailingList* list) {
    if (list->count == 0) {
        printf("No subscribers to remove.\n");
        return;
    }

    char email[EMAIL_LENGTH];
    printf("Enter subscriber email to remove: ");
    scanf(" %[^\n]", email);

    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            printf("Subscriber with email %s removed.\n", email);
            return;
        }
    }
    printf("No subscriber found with email %s.\n", email);
}

void displaySubscribers(MailingList* list) {
    if (list->count == 0) {
        printf("No subscribers in the mailing list.\n");
        return;
    }

    printf("Current Subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s <%s>\n", i + 1, list->members[i].name, list->members[i].email);
    }
}

void sendMessage(MailingList* list) {
    char message[500];
    printf("Enter your message: ");
    scanf(" %[^\n]", message);

    printf("Sending message to all subscribers:\n");
    for (int i = 0; i < list->count; i++) {
        printf("To: %s <%s>\n", list->members[i].name, list->members[i].email);
        printf("Message: %s\n", message);
        printf("-----\n");
    }
}

void showMenu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Subscriber\n");
    printf("2. Remove Subscriber\n");
    printf("3. Display Subscribers\n");
    printf("4. Send Message\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList mailingList;
    initializeList(&mailingList);

    int choice;
    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSubscriber(&mailingList);
                break;
            case 2:
                removeSubscriber(&mailingList);
                break;
            case 3:
                displaySubscribers(&mailingList);
                break;
            case 4:
                sendMessage(&mailingList);
                break;
            case 5:
                printf("Exiting... Thank you for using the Mailing List Manager!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}