//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

void initMailingList(MailingList *list) {
    list->count = 0;
}

void addMember(MailingList *list) {
    if (list->count >= MAX_MEMBERS) {
        printf("Mailing list is full! Cannot add more members.\n");
        return;
    }

    Member newMember;
    printf("Enter name: ");
    fgets(newMember.name, NAME_LENGTH, stdin);
    newMember.name[strcspn(newMember.name, "\n")] = 0; // Remove newline character

    printf("Enter email: ");
    fgets(newMember.email, EMAIL_LENGTH, stdin);
    newMember.email[strcspn(newMember.email, "\n")] = 0; // Remove newline character

    list->members[list->count++] = newMember;
    printf("Member added successfully!\n");
}

void removeMember(MailingList *list) {
    char email[EMAIL_LENGTH];
    printf("Enter the email of the member to remove: ");
    fgets(email, EMAIL_LENGTH, stdin);
    email[strcspn(email, "\n")] = 0; // Remove newline character

    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            list->members[i] = list->members[list->count - 1]; // Replace with last member
            list->count--;
            printf("Member removed successfully!\n");
            return;
        }
    }
    printf("No member found with that email.\n");
}

void listMembers(MailingList *list) {
    if (list->count == 0) {
        printf("The mailing list is empty.\n");
        return;
    }
    printf("Members in the mailing list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s - %s\n", i + 1, list->members[i].name, list->members[i].email);
    }
}

void searchMember(MailingList *list) {
    char email[EMAIL_LENGTH];
    printf("Enter the email of the member to search: ");
    fgets(email, EMAIL_LENGTH, stdin);
    email[strcspn(email, "\n")] = 0; // Remove newline character

    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("Member found: %s - %s\n", list->members[i].name, list->members[i].email);
            return;
        }
    }
    printf("No member found with that email.\n");
}

void saveMailingList(MailingList *list) {
    FILE *file = fopen("mailing_list.txt", "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s\n%s\n", list->members[i].name, list->members[i].email);
    }
    fclose(file);
    printf("Mailing list saved to mailing_list.txt.\n");
}

void loadMailingList(MailingList *list) {
    FILE *file = fopen("mailing_list.txt", "r");
    if (!file) {
        printf("Could not open file for reading. Starting with an empty mailing list.\n");
        return;
    }

    while (fscanf(file, "%[^\n]\n %[^\n]\n", list->members[list->count].name, list->members[list->count].email) != EOF) {
        list->count++;
        if (list->count >= MAX_MEMBERS) break; // Prevent overflow
    }
    fclose(file);
    printf("Mailing list loaded successfully!\n");
}

void displayMenu() {
    printf("\n---- Mailing List Manager ----\n");
    printf("1. Add Member\n");
    printf("2. Remove Member\n");
    printf("3. List Members\n");
    printf("4. Search Member\n");
    printf("5. Save Mailing List\n");
    printf("6. Load Mailing List\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

int main() {
    MailingList list;
    initMailingList(&list);
    loadMailingList(&list);

    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        while(getchar() != '\n');  // Flush the newline character

        switch (choice) {
            case 1:
                addMember(&list);
                break;
            case 2:
                removeMember(&list);
                break;
            case 3:
                listMembers(&list);
                break;
            case 4:
                searchMember(&list);
                break;
            case 5:
                saveMailingList(&list);
                break;
            case 6:
                loadMailingList(&list);
                break;
            case 7:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1-7.\n");
        }
    }
    return 0;
}