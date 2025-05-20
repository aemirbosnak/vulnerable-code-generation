//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_EMAIL_LEN 100
#define MAX_NAME_LEN 50

typedef struct Member {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Member;

typedef struct MailingList {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

// Function prototypes
void initializeList(MailingList* list);
void addMember(MailingList* list);
void removeMember(MailingList* list);
void displayMembers(const MailingList* list);
void saveListToFile(const MailingList* list, const char* filename);
void loadListFromFile(MailingList* list, const char* filename);
void clearList(MailingList* list);

int main() {
    MailingList mailingList;
    char filename[MAX_NAME_LEN];
    int choice;

    initializeList(&mailingList);
    
    printf("Enter the filename to load/save the mailing list: ");
    scanf("%s", filename);
    loadListFromFile(&mailingList, filename);

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Save to File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMember(&mailingList);
                break;
            case 2:
                removeMember(&mailingList);
                break;
            case 3:
                displayMembers(&mailingList);
                break;
            case 4:
                saveListToFile(&mailingList, filename);
                printf("Mailing list saved to %s\n", filename);
                break;
            case 5:
                clearList(&mailingList);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void initializeList(MailingList* list) {
    list->count = 0;
}

void addMember(MailingList* list) {
    if (list->count < MAX_MEMBERS) {
        printf("Enter name: ");
        scanf(" %[^\n]%*c", list->members[list->count].name);
        printf("Enter email: ");
        scanf(" %[^\n]%*c", list->members[list->count].email);
        list->count++;
        printf("Member added successfully!\n");
    } else {
        printf("Error: Members list is full!\n");
    }
}

void removeMember(MailingList* list) {
    char email[MAX_EMAIL_LEN];
    int found = 0;
    
    printf("Enter the email of the member to remove: ");
    scanf(" %[^\n]%*c", email);
    
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            found = 1;
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            printf("Member removed successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Error: Member with email '%s' not found.\n", email);
    }
}

void displayMembers(const MailingList* list) {
    if (list->count == 0) {
        printf("No members in the mailing list.\n");
        return;
    }
    printf("Current Members:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s <%s>\n", i + 1, list->members[i].name, list->members[i].email);
    }
}

void saveListToFile(const MailingList* list, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for saving!\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s,%s\n", list->members[i].name, list->members[i].email);
    }
    fclose(file);
}

void loadListFromFile(MailingList* list, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for loading! Starting with empty list.\n");
        return;
    }
    char line[200];
    while (fgets(line, sizeof(line), file) && list->count < MAX_MEMBERS) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        char* name = strtok(line, ",");
        char* email = strtok(NULL, ",");
        if (name && email) {
            strncpy(list->members[list->count].name, name, MAX_NAME_LEN);
            strncpy(list->members[list->count].email, email, MAX_EMAIL_LEN);
            list->count++;
        }
    }
    fclose(file);
}

void clearList(MailingList* list) {
    list->count = 0;
    printf("Mailing list cleared.\n");
}