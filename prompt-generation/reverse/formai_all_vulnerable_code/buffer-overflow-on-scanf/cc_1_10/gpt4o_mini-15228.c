//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define EMAIL_LENGTH 100

typedef struct {
    char email[EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int member_count;
} MailingList;

void initialize_list(MailingList *list) {
    list->member_count = 0;
}

void add_member(MailingList *list, const char *email) {
    if (list->member_count < MAX_MEMBERS) {
        strncpy(list->members[list->member_count].email, email, EMAIL_LENGTH);
        list->members[list->member_count].email[EMAIL_LENGTH - 1] = '\0';
        list->member_count++;
        printf("Added: %s\n", email);
    } else {
        printf("Mailing list is full!\n");
    }
}

void remove_member(MailingList *list, const char *email) {
    for (int i = 0; i < list->member_count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            for (int j = i; j < list->member_count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->member_count--;
            printf("Removed: %s\n", email);
            return;
        }
    }
    printf("Email %s not found in the list.\n", email);
}

void display_members(const MailingList *list) {
    printf("Mailing List Members:\n");
    if (list->member_count == 0) {
        printf("No members in the list.\n");
        return;
    }
    for (int i = 0; i < list->member_count; i++) {
        printf("%d: %s\n", i + 1, list->members[i].email);
    }
}

void save_members(const MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }
    for (int i = 0; i < list->member_count; i++) {
        fprintf(file, "%s\n", list->members[i].email);
    }
    fclose(file);
    printf("Members saved to %s\n", filename);
}

void load_members(MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return;
    }
    char email[EMAIL_LENGTH];
    while (fgets(email, sizeof(email), file) && list->member_count < MAX_MEMBERS) {
        email[strcspn(email, "\n")] = 0;  // Remove newline character
        add_member(list, email);
    }
    fclose(file);
    printf("Members loaded from %s\n", filename);
}

int main() {
    MailingList list;
    initialize_list(&list);

    int choice;
    char email[EMAIL_LENGTH];
    char filename[100];

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Save Members\n");
        printf("5. Load Members\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline character
                add_member(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;  // Remove newline character
                remove_member(&list, email);
                break;
            case 3:
                display_members(&list);
                break;
            case 4:
                printf("Enter filename to save: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline character
                save_members(&list, filename);
                break;
            case 5:
                printf("Enter filename to load: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline character
                load_members(&list, filename);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}