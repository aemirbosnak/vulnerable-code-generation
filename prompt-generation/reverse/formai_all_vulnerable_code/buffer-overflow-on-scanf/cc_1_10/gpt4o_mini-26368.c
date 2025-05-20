//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_LENGTH 100

typedef struct {
    char email[MAX_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_EMAILS];
    int count;
} MailingList;

// Function to initialize the mailing list
void initializeList(MailingList *list) {
    list->count = 0;
}

// Function to add an email to the mailing list
int addEmail(MailingList *list, const char *email) {
    if (list->count >= MAX_EMAILS) {
        printf("The mailing list is full. Unable to add %s.\n", email);
        return -1; 
    }
    
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            printf("Subscriber %s is already in the list.\n", email);
            return 0; 
        }
    }

    strncpy(list->subscribers[list->count].email, email, MAX_LENGTH);
    list->count++;
    printf("Subscriber %s added to the mailing list.\n", email);
    return 1; 
}

// Function to remove an email from the mailing list
int removeEmail(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            list->subscribers[i] = list->subscribers[list->count - 1]; 
            list->count--;
            printf("Subscriber %s removed from the mailing list.\n", email);
            return 1; 
        }
    }
    printf("Subscriber %s not found in the mailing list.\n", email);
    return -1; 
}

// Function to display the mailing list
void displayList(const MailingList *list) {
    if (list->count == 0) {
        printf("The mailing list is empty. No survivors\' emails to show.\n");
        return;
    }
    
    printf("Survivors' Emails in the Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->subscribers[i].email);
    }
}

// Function to save the mailing list to a file
void saveList(const MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }
    
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s\n", list->subscribers[i].email);
    }
    
    fclose(file);
    printf("Mailing list saved to %s.\n", filename);
}

// Function to load the mailing list from a file
void loadList(MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No previous list found. Starting new list.\n");
        return;
    }
    
    char email[MAX_LENGTH];
    while (fgets(email, sizeof(email), file) != NULL) {
        email[strcspn(email, "\n")] = 0;  // Remove newline character
        addEmail(list, email);
    }
    
    fclose(file);
    printf("Mailing list loaded from %s.\n", filename);
}

// Function to handle user commands
void commandHandler(MailingList *list) {
    char command[10];
    char email[MAX_LENGTH];

    while (1) {
        printf("\nEnter a command (add/remove/display/save/load/quit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter email to add: ");
            scanf("%s", email);
            addEmail(list, email);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter email to remove: ");
            scanf("%s", email);
            removeEmail(list, email);
        } else if (strcmp(command, "display") == 0) {
            displayList(list);
        } else if (strcmp(command, "save") == 0) {
            saveList(list, "mailing_list.txt");
        } else if (strcmp(command, "load") == 0) {
            loadList(list, "mailing_list.txt");
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting the ruins of the past. Stay alive, survivor!\n");
            break;
        } else {
            printf("Unknown command. Try again.\n");
        }
    }
}

int main() {
    MailingList list;
    initializeList(&list);
    commandHandler(&list);
    return 0;
}