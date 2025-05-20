//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char email[NAME_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

// Function prototypes
void addMember(MailingList *list);
void removeMember(MailingList *list);
void displayMembers(const MailingList *list);
void saveToFile(const MailingList *list, const char *filename);
void loadFromFile(MailingList *list, const char *filename);
void showMenu();

int main() {
    MailingList list;
    list.count = 0;
    int choice;
    char filename[100] = "mailinglist.txt";

    // Load existing members from file
    loadFromFile(&list, filename);

    while (1) {
        showMenu();
        printf("Enter your choice: ");
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
                saveToFile(&list, filename);
                printf("Mailing list saved to %s\n", filename);
                break;
            case 5:
                printf("Exiting program.\n");
                saveToFile(&list, filename);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addMember(MailingList *list) {
    if (list->count >= MAX_MEMBERS) {
        printf("Mailing list is full. Cannot add more members.\n");
        return;
    }
    
    Member newMember;
    printf("Enter name: ");
    scanf("%s", newMember.name);
    printf("Enter email: ");
    scanf("%s", newMember.email);

    list->members[list->count] = newMember;
    list->count++;
    printf("Member added successfully!\n");
}

void removeMember(MailingList *list) {
    char email[NAME_LENGTH];
    printf("Enter email of the member to remove: ");
    scanf("%s", email);

    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            printf("Member removed successfully!\n");
            return;
        }
    }
    printf("Member with email %s not found.\n", email);
}

void displayMembers(const MailingList *list) {
    if (list->count == 0) {
        printf("The mailing list is currently empty.\n");
        return;
    }

    printf("Mailing List Members:\n");
    for (int i = 0; i < list->count; i++) {
        printf("Name: %s, Email: %s\n", list->members[i].name, list->members[i].email);
    }
}

void saveToFile(const MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    
    fprintf(file, "%d\n", list->count);
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s\n%s\n", list->members[i].name, list->members[i].email);
    }
    
    fclose(file);
}

void loadFromFile(MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file for reading. Starting with an empty list.\n");
        return;
    }

    fscanf(file, "%d\n", &list->count);
    for (int i = 0; i < list->count; i++) {
        fgets(list->members[i].name, NAME_LENGTH, file);
        list->members[i].name[strcspn(list->members[i].name, "\n")] = 0; // Remove newline character
        fgets(list->members[i].email, NAME_LENGTH, file);
        list->members[i].email[strcspn(list->members[i].email, "\n")] = 0; // Remove newline character
    }

    fclose(file);
}

void showMenu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Member\n");
    printf("2. Remove Member\n");
    printf("3. Display Members\n");
    printf("4. Save Mailing List to File\n");
    printf("5. Exit\n");
}