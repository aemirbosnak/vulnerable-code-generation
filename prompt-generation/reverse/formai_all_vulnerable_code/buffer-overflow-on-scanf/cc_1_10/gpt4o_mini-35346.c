//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_NAME_LENGTH 50

typedef struct Member {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
} Member;

typedef struct MailingList {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

void initializeList(MailingList *list) {
    list->count = 0;
}

int addMember(MailingList *list, const char *name, const char *email) {
    if (list->count >= MAX_MEMBERS) {
        printf("Error: Mailing list is full, cannot add more members.\n");
        return -1;
    }
    strncpy(list->members[list->count].name, name, MAX_NAME_LENGTH);
    strncpy(list->members[list->count].email, email, MAX_NAME_LENGTH);
    list->count++;
    printf("Added member: %s <%s>\n", name, email);
    return 0;
}

void displayMembers(const MailingList *list) {
    printf("\nMailing List Members:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s <%s>\n", i + 1, list->members[i].name, list->members[i].email);
    }
}

int removeMember(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("Removing member: %s <%s>\n", list->members[i].name, list->members[i].email);
            list->members[i] = list->members[list->count - 1]; // Move the last member to the current position
            list->count--;
            return 0;
        }
    }
    printf("Error: Member with email %s not found.\n", email);
    return -1;
}

void saveMembersToFile(const MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s <%s>\n", list->members[i].name, list->members[i].email);
    }
    fclose(file);
    printf("Members saved to %s\n", filename);
}

void loadMembersFromFile(MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file for reading.\n");
        return;
    }
    char name[MAX_NAME_LENGTH], email[MAX_NAME_LENGTH];
    while (fscanf(file, "%49s <%49s>", name, email) == 2) {
        addMember(list, name, email);
    }
    fclose(file);
    printf("Members loaded from %s\n", filename);
}

int main() {
    MailingList list;
    initializeList(&list);
    int choice;
    char name[MAX_NAME_LENGTH], email[MAX_NAME_LENGTH], filename[MAX_NAME_LENGTH];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Save Members to File\n");
        printf("5. Load Members from File\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name (Max %d characters): ", MAX_NAME_LENGTH - 1);
                scanf("%s", name);
                printf("Enter email (Max %d characters): ", MAX_NAME_LENGTH - 1);
                scanf("%s", email);
                addMember(&list, name, email);
                break;
            case 2:
                printf("Enter email of member to remove: ");
                scanf("%s", email);
                removeMember(&list, email);
                break;
            case 3:
                displayMembers(&list);
                break;
            case 4:
                printf("Enter filename to save members: ");
                scanf("%s", filename);
                saveMembersToFile(&list, filename);
                break;
            case 5:
                printf("Enter filename to load members: ");
                scanf("%s", filename);
                loadMembersFromFile(&list, filename);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}