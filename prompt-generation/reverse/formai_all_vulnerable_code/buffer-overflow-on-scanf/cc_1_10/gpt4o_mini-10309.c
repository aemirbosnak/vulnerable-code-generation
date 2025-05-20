//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
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

void initializeList(MailingList* list) {
    list->count = 0;
}

int addMember(MailingList* list, const char* email) {
    if (list->count >= MAX_MEMBERS) {
        printf("Mailing list is full.\n");
        return -1;
    }
    strcpy(list->members[list->count].email, email);
    list->count++;
    printf("Email %s added successfully!\n", email);
    return 0;
}

int removeMember(MailingList* list, const char* email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            // Shift members down to fill the gap
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            printf("Email %s removed successfully!\n", email);
            return 0;
        }
    }
    printf("Email %s not found in the mailing list!\n", email);
    return -1;
}

void displayMembers(const MailingList* list) {
    if (list->count == 0) {
        printf("The mailing list is empty.\n");
        return;
    }
    printf("Mailing List Members:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->members[i].email);
    }
}

void menu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Member\n");
    printf("2. Remove Member\n");
    printf("3. Display Members\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList list;
    initializeList(&list);
    int choice;
    char email[EMAIL_LENGTH];

    while (1) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addMember(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeMember(&list, email);
                break;
            case 3:
                displayMembers(&list);
                break;
            case 4:
                printf("Exiting the Mailing List Manager. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}