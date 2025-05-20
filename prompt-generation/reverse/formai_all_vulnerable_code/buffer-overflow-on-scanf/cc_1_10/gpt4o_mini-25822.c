//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define NAME_LENGTH 50

typedef struct Member {
    char name[NAME_LENGTH];
    char email[NAME_LENGTH];
} Member;

typedef struct MailingList {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

void initList(MailingList *list) {
    list->count = 0;
}

int addMember(MailingList *list, const char *name, const char *email) {
    if (list->count >= MAX_MEMBERS) {
        printf("Error: Mailing list is full!\n");
        return -1;
    }
    strncpy(list->members[list->count].name, name, NAME_LENGTH);
    strncpy(list->members[list->count].email, email, NAME_LENGTH);
    list->count++;
    printf("Added: %s <%s>\n", name, email);
    return 0;
}

void removeMember(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("Removing: %s <%s>\n", list->members[i].name, email);
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            return;
        }
    }
    printf("Error: Member with email %s not found!\n", email);
}

void displayMembers(const MailingList *list) {
    printf("\nCurrent Mailing List Members:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s <%s>\n", i + 1, list->members[i].name, list->members[i].email);
    }
}

void saveListToFile(const MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing!\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s <%s>\n", list->members[i].name, list->members[i].email);
    }
    fclose(file);
    printf("Mailing list saved to %s\n", filename);
}

void loadListFromFile(MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading!\n");
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), file) && list->count < MAX_MEMBERS) {
        char name[NAME_LENGTH], email[NAME_LENGTH];
        sscanf(line, "%49[^<]<%49[^\n]>", name, email);
        addMember(list, name, email);
    }
    fclose(file);
    printf("Mailing list loaded from %s\n", filename);
}

void displayMenu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Member\n");
    printf("2. Remove Member\n");
    printf("3. Display Members\n");
    printf("4. Save to File\n");
    printf("5. Load from File\n");
    printf("6. Exit\n");
}

int main() {
    MailingList list;
    initList(&list);
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            char name[NAME_LENGTH], email[NAME_LENGTH];
            printf("Enter name: ");
            scanf(" %49[^\n]", name);
            printf("Enter email: ");
            scanf(" %49[^\n]", email);
            addMember(&list, name, email);
        } else if (choice == 2) {
            char email[NAME_LENGTH];
            printf("Enter email to remove: ");
            scanf(" %49s", email);
            removeMember(&list, email);
        } else if (choice == 3) {
            displayMembers(&list);
        } else if (choice == 4) {
            char filename[NAME_LENGTH];
            printf("Enter filename to save: ");
            scanf(" %49s", filename);
            saveListToFile(&list, filename);
        } else if (choice == 5) {
            char filename[NAME_LENGTH];
            printf("Enter filename to load: ");
            scanf(" %49s", filename);
            loadListFromFile(&list, filename);
        } else if (choice == 6) {
            printf("Exiting the Mailing List Manager. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}