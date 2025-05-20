//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 50

typedef struct {
    char emails[MAX_LIST_SIZE][MAX_EMAIL_LENGTH];
    int count;
} MailingList;

void initMailingList(MailingList *list) {
    list->count = 0;
}

int addEmail(MailingList *list, const char *email) {
    if (list->count < MAX_LIST_SIZE) {
        strncpy(list->emails[list->count], email, MAX_EMAIL_LENGTH);
        list->emails[list->count][MAX_EMAIL_LENGTH - 1] = '\0'; // Ensure null-termination
        list->count++;
        printf("New survivor added to the mailing list: %s\n", email);
        return 1;
    }
    printf("Mailing list full, cannot add: %s\n", email);
    return 0;
}

int removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            printf("Removing email from the mailing list: %s\n", email);
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            return 1;
        }
    }
    printf("Email not found in the mailing list: %s\n", email);
    return 0;
}

void displayList(const MailingList *list) {
    if (list->count == 0) {
        printf("The mailing list is currently empty. Stay vigilant.\n");
        return;
    }
    printf("## Survivors Mailing List ##\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->emails[i]);
    }
    printf("###########################\n");
}

void saveToFile(const MailingList *list) {
    FILE *file = fopen("mailing_list.txt", "w");
    if (file) {
        for (int i = 0; i < list->count; i++) {
            fprintf(file, "%s\n", list->emails[i]);
        }
        fclose(file);
        printf("Mailing list saved to mailing_list.txt\n");
    } else {
        printf("Error saving mailing list to file.\n");
    }
}

void loadFromFile(MailingList *list) {
    FILE *file = fopen("mailing_list.txt", "r");
    if (file) {
        char email[MAX_EMAIL_LENGTH];
        while (fgets(email, sizeof(email), file) && list->count < MAX_LIST_SIZE) {
            email[strcspn(email, "\n")] = 0; // Remove newline
            addEmail(list, email);
        }
        fclose(file);
        printf("Mailing list loaded from mailing_list.txt\n");
    } else {
        printf("No previous mailing list found.\n");
    }
}

int main() {
    MailingList list;
    initMailingList(&list);
    
    loadFromFile(&list);

    char command[10];
    char email[MAX_EMAIL_LENGTH];

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add Email\n");
        printf("2. Remove Email\n");
        printf("3. Display Mailing List\n");
        printf("4. Save Mailing List\n");
        printf("5. Exit\n");
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "1") == 0) {
            printf("Enter an email to add (survivor contact): ");
            scanf("%s", email);
            addEmail(&list, email);
        } else if (strcmp(command, "2") == 0) {
            printf("Enter an email to remove (if you must): ");
            scanf("%s", email);
            removeEmail(&list, email);
        } else if (strcmp(command, "3") == 0) {
            displayList(&list);
        } else if (strcmp(command, "4") == 0) {
            saveToFile(&list);
        } else if (strcmp(command, "5") == 0) {
            printf("Gather your supplies and move with caution.\n");
            break;
        } else {
            printf("Unknown command. Try again, survivor.\n");
        }
    }

    return 0;
}