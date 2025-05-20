//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

void initializeList(MailingList* list) {
    list->count = 0;
}

int addMember(MailingList* list, const char* name, const char* email) {
    if (list->count >= MAX_MEMBERS) {
        printf("Mailing list is full!\n");
        return -1;
    }
    strncpy(list->members[list->count].name, name, MAX_NAME_LENGTH);
    strncpy(list->members[list->count].email, email, MAX_EMAIL_LENGTH);
    list->count++;
    printf("Added: %s <%s>\n", name, email);
    return 0;
}

int removeMember(MailingList* list, const char* email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("Removing: %s <%s>\n", list->members[i].name, list->members[i].email);
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            return 0;
        }
    }
    printf("Email %s not found in the list.\n", email);
    return -1;
}

void showMembers(const MailingList* list) {
    if (list->count == 0) {
        printf("The mailing list is empty.\n");
        return;
    }
    printf("Mailing List Members:\n");
    for (int i = 0; i < list->count; i++) {
        printf(" %d. %s <%s>\n", i + 1, list->members[i].name, list->members[i].email);
    }
}

void saveListToFile(const MailingList* list, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s,%s\n", list->members[i].name, list->members[i].email);
    }
    fclose(file);
    printf("Mailing list saved to %s.\n", filename);
}

void loadListFromFile(MailingList* list, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for reading.\n");
        return;
    }
    
    char line[150];
    while (fgets(line, sizeof(line), file) && list->count < MAX_MEMBERS) {
        char* token = strtok(line, ",");
        if (token) {
            strncpy(list->members[list->count].name, token, MAX_NAME_LENGTH);
            token = strtok(NULL, ",");
            if (token) {
                strncpy(list->members[list->count].email, token, MAX_EMAIL_LENGTH - 1);
                list->members[list->count].email[strcspn(list->members[list->count].email, "\n")] = '\0'; // Remove \n
                list->count++;
            }
        }
    }
    fclose(file);
    printf("Mailing list loaded from %s.\n", filename);
}

int main() {
    MailingList list;
    initializeList(&list);
    int choice;
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Show Members\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove \n
                printf("Enter email: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove \n
                addMember(&list, name, email);
                break;
            case 2:
                printf("Enter email of member to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = '\0'; // Remove \n
                removeMember(&list, email);
                break;
            case 3:
                showMembers(&list);
                break;
            case 4:
                saveListToFile(&list, "mailing_list.txt");
                break;
            case 5:
                loadListFromFile(&list, "mailing_list.txt");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}