//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define LEN 50

typedef struct {
    char name[LEN];
    char email[LEN];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

void print_welcome_message() {
    printf("Welcome to the Infinite Apostrophe Mailing List Manager!\n");
    printf("Where every email counts... except the ones that bounce, \n");
    printf("because those just make us sad. Ready to dive into the fun? Let's go!\n");
}

void add_member(MailingList *list) {
    if (list->count >= MAX_MEMBERS) {
        printf("Oops! Looks like we've hit our maximum capacity! Time to throw a confetti party!\n");
        return;
    }

    Member new_member;
    printf("Enter the name of the new member (with a sprinkle of creativity!): ");
    scanf(" %[^\n]%*c", new_member.name);
    printf("And what delightful email shall we associate with %s? ", new_member.name);
    scanf(" %[^\n]%*c", new_member.email);

    list->members[list->count++] = new_member;
    printf("%s has been added to the mailing list! Yay!\n", new_member.name);
}

void view_members(const MailingList *list) {
    if (list->count == 0) {
        printf("We have no members yet! Let's just say, it's quite *lonely* here...\n");
        return;
    }
    printf("Here are the lovely folks in our mailing list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s - %s\n", i + 1, list->members[i].name, list->members[i].email);
    }
}

void remove_member(MailingList *list) {
    if (list->count == 0) {
        printf("Oh no! There's no one to remove! Is this a ghost town?!\n");
        return;
    }

    int idx;
    printf("Enter the number of the member you want to remove (1-%d): ", list->count);
    scanf("%d", &idx);

    if (idx < 1 || idx > list->count) {
        printf("Oops! Invalid choice. No members were harmed in this operation!\n");
        return;
    }

    idx--; // Adjust for 0-based index
    printf("Goodbye %s! You will be missed... or not?\n", list->members[idx].name);
    
    for (int i = idx; i < list->count - 1; i++) {
        list->members[i] = list->members[i + 1]; // Shift members left
    }
    list->count--; // Decrease member count
}

void display_menu() {
    printf("\nSelect an option from the menu below:\n");
    printf("1. Add Member\n");
    printf("2. View Members\n");
    printf("3. Remove Member\n");
    printf("4. Leave this Freelance Fun!\n");
}

int main() {
    MailingList list = {{0}, 0}; // Initialize mailing list
    int choice;

    print_welcome_message();

    while (1) {
        display_menu();
        printf("Your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_member(&list);
                break;
            case 2:
                view_members(&list);
                break;
            case 3:
                remove_member(&list);
                break;
            case 4:
                printf("Thanks for using the Infinite Apostrophe Mailing List Manager! Stay whimsical and fabulous!\n");
                exit(0);
            default:
                printf("Whoa there! That's not a valid option! Let's keep it to 1, 2, 3, or 4, shall we?\n");
        }
    }

    return 0;
}