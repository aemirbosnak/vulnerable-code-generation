//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: immersive
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
}

int addMember(MailingList *list, const char *email) {
    if (list->count >= MAX_MEMBERS) {
        printf("Mailing list is full. Cannot add more members.\n");
        return -1;
    }
    strcpy(list->members[list->count].email, email);
    list->count++;
    printf("Added member: %s\n", email);
    return 0;
}

int removeMember(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            printf("Removed member: %s\n", email);
            return 0;
        }
    }
    printf("Member not found: %s\n", email);
    return -1;
}

void displayMembers(const MailingList *list) {
    printf("Current members in the mailing list (%d total):\n", list->count);
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->members[i].email);
    }
}

void saveMembers(const MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s\n", list->members[i].email);
    }
    fclose(file);
    printf("Members saved to %s\n", filename);
}

void loadMembers(MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }
    char email[MAX_EMAIL_LENGTH];
    while (fgets(email, sizeof(email), file) != NULL) {
        email[strcspn(email, "\n")] = 0; // Remove newline character
        addMember(list, email);
    }
    fclose(file);
    printf("Members loaded from %s\n", filename);
}

int main() {
    MailingList myList;
    initializeList(&myList);
    
    int choice;
    char email[MAX_EMAIL_LENGTH];
    char filename[100];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Save Members to File\n");
        printf("5. Load Members from File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addMember(&myList, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeMember(&myList, email);
                break;
            case 3:
                displayMembers(&myList);
                break;
            case 4:
                printf("Enter filename to save members: ");
                scanf("%s", filename);
                saveMembers(&myList, filename);
                break;
            case 5:
                printf("Enter filename to load members: ");
                scanf("%s", filename);
                loadMembers(&myList, filename);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}