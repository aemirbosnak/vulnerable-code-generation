//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 50
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    char email[NAME_LEN];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

void initializeList(MailingList *list) {
    list->count = 0;
}

void addMember(MailingList *list) {
    if (list->count >= MAX_MEMBERS) {
        printf("Oops! We cannot add more members! The list is full! 🎉\n");
        return;
    }
    
    Member newMember;
    
    printf("Enter the name of the new member: ");
    scanf(" %[^\n]", newMember.name);
    
    printf("Enter the email of the new member: ");
    scanf(" %[^\n]", newMember.email);
    
    list->members[list->count] = newMember;
    list->count++;
    
    printf("Hooray! %s has been added to the mailing list! 🎊\n", newMember.name);
}

void removeMember(MailingList *list) {
    char email[NAME_LEN];
    int found = 0;

    if (list->count == 0) {
        printf("Uh-oh! The mailing list is empty! 🥺\n");
        return;
    }

    printf("Enter the email of the member to remove: ");
    scanf(" %[^\n]", email);
    
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("%s has left the mailing list. We will miss you! 💔\n", list->members[i].name);
            found = 1;
            // Shift the remaining members one step up
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            break;
        }
    }

    if (!found) {
        printf("Oops! We couldn't find a member with that email! 🤷‍♂️\n");
    }
}

void displayMembers(const MailingList *list) {
    if (list->count == 0) {
        printf("The mailing list is empty! Let's add some friends! 🥳\n");
        return;
    }

    printf("Here's the list of happy members! 🌟\n");
    for (int i = 0; i < list->count; i++) {
        printf("Member %d: Name: %s, Email: %s\n", i + 1, list->members[i].name, list->members[i].email);
    }
}

void saveMembersToFile(const MailingList *list) {
    FILE *file = fopen("mailing_list.txt", "w");
    if (file == NULL) {
        printf("Whoops! There was an error creating the file! 📁\n");
        return;
    }

    for (int i = 0; i < list->count; i++) {
        fprintf(file, "Name: %s, Email: %s\n", list->members[i].name, list->members[i].email);
    }

    fclose(file);
    printf("The mailing list has been saved to 'mailing_list.txt'! 🎉\n");
}

int main() {
    MailingList list;
    int choice;

    initializeList(&list);

    do {
        printf("\nWelcome to the Cheerful Mailing List Manager! 😃\n");
        printf("1. Add a member\n");
        printf("2. Remove a member\n");
        printf("3. Display all members\n");
        printf("4. Save members to file\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMember(&list);
                break;
            case 2:
                removeMember(&list);
                break;
            case 3:
                displayMembers(&list);
                break;
            case 4:
                saveMembersToFile(&list);
                break;
            case 5:
                printf("Thank you for using the mailing list manager! Goodbye! 🌈\n");
                break;
            default:
                printf("Hmm... That's not a valid option. Please try again! 😊\n");
        }
    } while (choice != 5);

    return 0;
}