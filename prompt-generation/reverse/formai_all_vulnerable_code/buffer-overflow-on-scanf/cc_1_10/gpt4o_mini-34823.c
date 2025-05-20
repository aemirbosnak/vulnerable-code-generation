//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char email[NAME_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

void addSubscriber(MailingList *list, const char *name, const char *email) {
    if (list->count < MAX_SUBSCRIBERS) {
        strcpy(list->subscribers[list->count].name, name);
        strcpy(list->subscribers[list->count].email, email);
        list->count++;
        printf("Subscriber added: %s <%s>\n", name, email);
    } else {
        printf("Mailing list is full, cannot add subscriber.\n");
    }
}

void removeSubscriber(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            printf("Subscriber removed: <%s>\n", email);
            return;
        }
    }
    printf("Subscriber not found: <%s>\n", email);
}

void viewMailingList(MailingList *list) {
    if (list->count == 0) {
        printf("Mailing list is empty.\n");
    } else {
        printf("Mailing List:\n");
        for (int i = 0; i < list->count; i++) {
            printf("  %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
        }
    }
}

void saveMailingListToFile(MailingList *list) {
    FILE *file = fopen("mailing_list.txt", "w");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s,%s\n", list->subscribers[i].name, list->subscribers[i].email);
    }
    fclose(file);
    printf("Mailing list saved to 'mailing_list.txt'.\n");
}

void loadMailingListFromFile(MailingList *list) {
    FILE *file = fopen("mailing_list.txt", "r");
    if (file == NULL) {
        printf("No existing mailing list file found.\n");
        return;
    }
    char line[NAME_LENGTH * 2];
    while (fgets(line, sizeof(line), file)) {
        char name[NAME_LENGTH], email[NAME_LENGTH];
        sscanf(line, "%49[^,],%49[^\n]", name, email);
        addSubscriber(list, name, email);
    }
    fclose(file);
}

int main() {
    MailingList mailingList = { .count = 0 };
    loadMailingListFromFile(&mailingList);

    int choice;
    char name[NAME_LENGTH], email[NAME_LENGTH];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Subscriber\n");
        printf("2. Remove Subscriber\n");
        printf("3. View Mailing List\n");
        printf("4. Save Mailing List and Exit\n");
        printf("5. Exit without Saving\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline
                printf("Enter email: ");
                fgets(email, NAME_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline
                addSubscriber(&mailingList, name, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, NAME_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline
                removeSubscriber(&mailingList, email);
                break;
            case 3:
                viewMailingList(&mailingList);
                break;
            case 4:
                saveMailingListToFile(&mailingList);
                printf("Exiting...\n");
                break;
            case 5:
                printf("Exiting without saving...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4 && choice != 5);

    return 0;
}