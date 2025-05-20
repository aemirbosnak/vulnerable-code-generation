//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: calm
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

void initialize_list(MailingList *list) {
    list->count = 0;
}

int add_member(MailingList *list, const char *name, const char *email) {
    if (list->count >= MAX_MEMBERS) {
        printf("Mailing list is full. Cannot add more members.\n");
        return -1;
    }
    strncpy(list->members[list->count].name, name, MAX_NAME_LENGTH - 1);
    list->members[list->count].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
    strncpy(list->members[list->count].email, email, MAX_EMAIL_LENGTH - 1);
    list->members[list->count].email[MAX_EMAIL_LENGTH - 1] = '\0'; // Ensure null-termination
    list->count++;
    printf("Added member: %s <%s>\n", name, email);
    return 0;
}

int remove_member(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("Removing member: %s <%s>\n", list->members[i].name, list->members[i].email);
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1]; // Shift members left
            }
            list->count--;
            return 0;
        }
    }
    printf("Member with email %s not found.\n", email);
    return -1;
}

void list_members(const MailingList *list) {
    if (list->count == 0) {
        printf("No members in the mailing list.\n");
        return;
    }
    printf("Mailing List Members:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s <%s>\n", i + 1, list->members[i].name, list->members[i].email);
    }
}

void save_list(const MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Unable to open file %s for writing.\n", filename);
        return;
    }
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s,%s\n", list->members[i].name, list->members[i].email);
    }
    fclose(file);
    printf("Mailing list saved to %s.\n", filename);
}

void load_list(MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file %s for reading.\n", filename);
        return;
    }
    char line[200];
    while (fgets(line, sizeof(line), file) && list->count < MAX_MEMBERS) {
        char *name = strtok(line, ",");
        char *email = strtok(NULL, "\n");
        if (name && email) {
            add_member(list, name, email);
        }
    }
    fclose(file);
    printf("Mailing list loaded from %s.\n", filename);
}

int main() {
    MailingList list;
    initialize_list(&list);
    
    int choice;
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];
    const char *filename = "mailing_list.txt";

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. List Members\n");
        printf("4. Save List\n");
        printf("5. Load List\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                add_member(&list, name, email);
                break;

            case 2:
                printf("Enter email to remove: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                remove_member(&list, email);
                break;

            case 3:
                list_members(&list);
                break;

            case 4:
                save_list(&list, filename);
                break;

            case 5:
                load_list(&list, filename);
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}