//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: accurate
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

void initializeList(MailingList *list) {
    list->count = 0;
}

int addMember(MailingList *list, const char *email) {
    if (list->count >= MAX_MEMBERS) {
        printf("Mailing list is full. Cannot add more members.\n");
        return -1;
    }
    strncpy(list->members[list->count].email, email, EMAIL_LENGTH);
    list->count++;
    printf("Added: %s\n", email);
    return 0;
}

int removeMember(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            printf("Removed: %s\n", email);
            return 0;
        }
    }
    printf("Email not found: %s\n", email);
    return -1;
}

void displayMembers(const MailingList *list) {
    if (list->count == 0) {
        printf("No members in the mailing list.\n");
        return;
    }
    printf("Mailing List Members:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->members[i].email);
    }
}

void saveMembersToFile(const MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file for writing: %s\n", filename);
        return;
    }
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s\n", list->members[i].email);
    }
    fclose(file);
    printf("Members saved to %s\n", filename);
}

void loadMembersFromFile(MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file for reading: %s\n", filename);
        return;
    }
    char buffer[EMAIL_LENGTH];
    while (fgets(buffer, sizeof(buffer), file) && list->count < MAX_MEMBERS) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
        addMember(list, buffer);
    }
    fclose(file);
    printf("Members loaded from %s\n", filename);
}

int main() {
    MailingList list;
    initializeList(&list);

    int choice;
    char email[EMAIL_LENGTH];
    const char *filename = "members.txt";

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Save Members to File\n");
        printf("5. Load Members from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                addMember(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                removeMember(&list, email);
                break;
            case 3:
                displayMembers(&list);
                break;
            case 4:
                saveMembersToFile(&list, filename);
                break;
            case 5:
                loadMembersFromFile(&list, filename);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}