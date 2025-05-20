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

void initializeList(MailingList* list) {
    list->count = 0;
    printf("🎉 Mailing list initialized! 🎉\n");
}

int addMember(MailingList* list, const char* email) {
    if (list->count >= MAX_MEMBERS) {
        printf("🚫 Error: Mailing list is full! Can't add more members.\n");
        return -1;
    }
    strncpy(list->members[list->count].email, email, MAX_EMAIL_LENGTH);
    list->count++;
    printf("📧 Member added: %s 🎊\n", email);
    return 0;
}

int removeMember(MailingList* list, const char* email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("🔥 Removing member: %s\n", email);
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            printf("✅ Member removed successfully!\n");
            return 0;
        }
    }
    printf("🚫 Error: Member not found!\n");
    return -1;
}

void displayMembers(const MailingList* list) {
    if (list->count == 0) {
        printf("😢 No members in the mailing list yet!\n");
        return;
    }
    printf("📜 Mailing List Members:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->members[i].email);
    }
}

void sendNewsletter(const MailingList* list, const char* newsletter) {
    if (list->count == 0) {
        printf("🚫 Warning: No members to send newsletter.\n");
        return;
    }
    printf("✉️ Sending out newsletter: %s\n", newsletter);
    for (int i = 0; i < list->count; i++) {
        printf("✅ Sent to: %s\n", list->members[i].email);
    }
    printf("🎉 Newsletter sent to all members successfully! 🎉\n");
}

int main() {
    MailingList list;
    initializeList(&list);

    int choice;
    char email[MAX_EMAIL_LENGTH];
    char newsletter[256];

    do {
        printf("\n✨ Mailing List Manager Menu ✨\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Send Newsletter\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the input buffer

        switch (choice) {
            case 1:
                printf("Enter member email to add: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline
                addMember(&list, email);
                break;
            case 2:
                printf("Enter member email to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline
                removeMember(&list, email);
                break;
            case 3:
                displayMembers(&list);
                break;
            case 4:
                printf("Enter newsletter content: ");
                fgets(newsletter, 256, stdin);
                newsletter[strcspn(newsletter, "\n")] = 0;  // Remove newline
                sendNewsletter(&list, newsletter);
                break;
            case 5:
                printf("🛑 Exiting the mailing list manager. Goodbye! 🛑\n");
                break;
            default:
                printf("🚫 Invalid choice, please try again!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}