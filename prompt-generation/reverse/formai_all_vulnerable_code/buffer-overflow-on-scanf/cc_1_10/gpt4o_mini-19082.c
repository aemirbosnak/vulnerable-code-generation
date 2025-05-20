//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_MESSAGE_LENGTH 500

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int memberCount;
} MailingList;

void initializeList(MailingList *list) {
    list->memberCount = 0;
    printf("The Grand Mailing List hath been prepared!\n");
}

void addMember(MailingList *list) {
    if (list->memberCount >= MAX_MEMBERS) {
        printf("Alas! The Mailing List doth overfloweth with members.\n");
        return;
    }

    Member newMember;
    printf("Enter the name of the noble:\n");
    scanf("%s", newMember.name);
    printf("Enter the email of the noble:\n");
    scanf("%s", newMember.email);

    list->members[list->memberCount] = newMember;
    list->memberCount++;
    printf("Huzzah! %s hath been added to the list!\n", newMember.name);
}

void removeMember(MailingList *list) {
    char name[MAX_NAME_LENGTH];
    printf("Whose presence is to be relinquished? Enter their name:\n");
    scanf("%s", name);

    for (int i = 0; i < list->memberCount; i++) {
        if (strcmp(list->members[i].name, name) == 0) {
            for (int j = i; j < list->memberCount - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->memberCount--;
            printf("%s hath been removed from the list.\n", name);
            return;
        }
    }
    printf("Alas! There be no noble with the name '%s' in our ranks.\n", name);
}

void sendMessage(MailingList *list) {
    if (list->memberCount == 0) {
        printf("Alas! There be no nobles to send a missive to.\n");
        return;
    }

    char message[MAX_MESSAGE_LENGTH];
    printf("What missive dost thou wish to send?\n");
    getchar(); // To consume the leftover newline character
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    printf("To all noble members:\n");
    for (int i = 0; i < list->memberCount; i++) {
        printf("To: %s <%s>\n%s\n", list->members[i].name, list->members[i].email, message);
    }
    printf("Huzzah! The missive hath been sent!\n");
}

void listMembers(MailingList *list) {
    if (list->memberCount == 0) {
        printf("The list of members be empty. None can be found here.\n");
        return;
    }

    printf("List of noble members:\n");
    for (int i = 0; i < list->memberCount; i++) {
        printf("%d. %s <%s>\n", i + 1, list->members[i].name, list->members[i].email);
    }
}

int main() {
    MailingList myList;
    initializeList(&myList);
  
    int choice = 0;
    while (choice != 5) {
        printf("Choose thine action:\n");
        printf("1. Add Member\n2. Remove Member\n3. Send Message\n4. List Members\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addMember(&myList);
                break;
            case 2: 
                removeMember(&myList);
                break;
            case 3: 
                sendMessage(&myList);
                break;
            case 4: 
                listMembers(&myList);
                break;
            case 5: 
                printf("The Grand Mailing List hath been closed. Farewell!\n");
                break;
            default: 
                printf("Prithee, choose a valid option from yon list.\n");
                break;
        }
    }
  
    return 0;
}