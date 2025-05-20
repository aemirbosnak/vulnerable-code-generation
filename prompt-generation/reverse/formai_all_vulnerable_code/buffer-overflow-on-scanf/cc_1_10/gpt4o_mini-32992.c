//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char email[MAX_EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int member_count;
} MailingList;

void init_mailing_list(MailingList *list) {
    list->member_count = 0;
}

int add_member(MailingList *list, const char *email) {
    if (list->member_count >= MAX_MEMBERS) {
        printf("Mailing list is full. Cannot add more members.\n");
        return -1;
    }
    strncpy(list->members[list->member_count].email, email, MAX_EMAIL_LENGTH);
    list->member_count++;
    printf("Added: %s\n", email);
    return 0;
}

int remove_member(MailingList *list, const char *email) {
    for (int i = 0; i < list->member_count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            // Shift members to fill the gap
            for (int j = i; j < list->member_count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->member_count--;
            printf("Removed: %s\n", email);
            return 0;
        }
    }
    printf("Email not found: %s\n", email);
    return -1;
}

void list_members(const MailingList *list) {
    if (list->member_count == 0) {
        printf("No members in the mailing list.\n");
    } else {
        printf("Mailing List Members:\n");
        for (int i = 0; i < list->member_count; i++) {
            printf("%d: %s\n", i + 1, list->members[i].email);
        }
    }
}

void save_to_file(const MailingList *list) {
    FILE *file = fopen("mailing_list.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < list->member_count; i++) {
        fprintf(file, "%s\n", list->members[i].email);
    }
    fclose(file);
    printf("Mailing list saved to mailing_list.txt\n");
}

void load_from_file(MailingList *list) {
    FILE *file = fopen("mailing_list.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    char email[MAX_EMAIL_LENGTH];
    while (fgets(email, sizeof(email), file) != NULL) {
        email[strcspn(email, "\n")] = 0; // Remove newline character
        add_member(list, email);
    }
    fclose(file);
    printf("Mailing list loaded from mailing_list.txt\n");
}

int main() {
    MailingList my_list;
    init_mailing_list(&my_list);
    
    int choice;
    char email[MAX_EMAIL_LENGTH];

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. List Members\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                add_member(&my_list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                remove_member(&my_list, email);
                break;
            case 3:
                list_members(&my_list);
                break;
            case 4:
                save_to_file(&my_list);
                break;
            case 5:
                load_from_file(&my_list);
                break;
            case 6:
                printf("Exiting the program peacefully.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}