//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define EMAIL_LENGTH 100

typedef struct {
    char email[EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

void initMailingList(MailingList *list) {
    list->count = 0;
}

int addMember(MailingList *list, const char *email) {
    if (list->count >= MAX_MEMBERS) {
        printf("Mailing list is full.\n");
        return -1; // Failed to add member
    }
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("Email %s is already in the mailing list.\n", email);
            return -1; // Email already exists
        }
    }
    
    strncpy(list->members[list->count].email, email, EMAIL_LENGTH);
    list->count++;
    return 0; // Success
}

int removeMember(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            list->members[i] = list->members[list->count - 1]; // Replace with last member
            list->count--;
            return 0; // Success
        }
    }
    printf("Email %s not found in the mailing list.\n", email);
    return -1; // Email not found
}

void viewMembers(const MailingList *list) {
    if (list->count == 0) {
        printf("No members in the mailing list.\n");
        return;
    }
    printf("Members of the mailing list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->members[i].email);
    }
}

void saveMailingList(const MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file for saving mailing list.\n");
        return;
    }

    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s\n", list->members[i].email);
    }
    fclose(file);
    printf("Mailing list saved to %s.\n", filename);
}

void loadMailingList(MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file for loading mailing list.\n");
        return;
    }

    char buffer[EMAIL_LENGTH];
    while (fgets(buffer, sizeof(buffer), file) && list->count < MAX_MEMBERS) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        addMember(list, buffer);
    }
    fclose(file);
    printf("Mailing list loaded from %s.\n", filename);
}

void freeMailingList(MailingList *list) {
    list->count = 0; // Clear the list
}

int main() {
    MailingList list;
    initMailingList(&list);
    
    char option;
    char email[EMAIL_LENGTH];
    char filename[100];

    printf("Welcome to the Mailing List Manager!\n");

    while (1) {
        printf("\nChoose an option: \n");
        printf("a: Add member\n");
        printf("r: Remove member\n");
        printf("v: View members\n");
        printf("s: Save to file\n");
        printf("l: Load from file\n");
        printf("q: Quit\n");
        printf("Option: ");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                printf("Enter email to add: ");
                scanf("%s", email);
                addMember(&list, email);
                break;
            case 'r':
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeMember(&list, email);
                break;
            case 'v':
                viewMembers(&list);
                break;
            case 's':
                printf("Enter filename to save: ");
                scanf("%s", filename);
                saveMailingList(&list, filename);
                break;
            case 'l':
                printf("Enter filename to load: ");
                scanf("%s", filename);
                loadMailingList(&list, filename);
                break;
            case 'q':
                freeMailingList(&list);
                printf("Exiting Mailing List Manager.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}