//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

void initializeList(MailingList *list) {
    list->count = 0;
    printf("🎉 Welcome to Your Exciting Mailing List Manager! 🎉\n");
}

int addMember(MailingList *list, const char *email) {
    if (list->count < MAX_MEMBERS) {
        strcpy(list->members[list->count].email, email);
        list->count++;
        printf("✨ Email '%s' has been added to the mailing list! Total members: %d ✨\n", email, list->count);
        return 1; // Success
    } else {
        printf("❌ Error: Mailing list is full. Cannot add '%s'! ❌\n", email);
        return 0; // Failure
    }
}

int removeMember(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("🚀 Email '%s' is being removed from the mailing list! 🚀\n", email);
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            return 1; // Success
        }
    }
    printf("❌ Error: Email '%s' not found in the mailing list! ❌\n", email);
    return 0; // Failure
}

void displayMembers(const MailingList *list) {
    printf("📬 Current members in the Mailing List: 📬\n");
    for (int i = 0; i < list->count; i++) {
        printf("   - %s\n", list->members[i].email);
    }
    if (list->count == 0) {
        printf("   (No members in the list. Please add some!)\n");
    }
}

int main() {
    MailingList myMailingList;
    initializeList(&myMailingList);
    
    int choice;
    char email[MAX_EMAIL_LENGTH];

    do {
        printf("\n📋 Mailing List Manager Menu 📋\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addMember(&myMailingList, email);
                break;

            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeMember(&myMailingList, email);
                break;

            case 3:
                displayMembers(&myMailingList);
                break;

            case 4:
                printf("🔚 Exiting the Mailing List Manager. Goodbye! 🔚\n");
                break;

            default:
                printf("❗ Invalid choice! Please select between 1 and 4. ❗\n");
                break;
        }
    } while (choice != 4);

    return 0;
}