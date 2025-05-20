//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

// Function prototypes
void initialize_list(MailingList *list);
void add_member(MailingList *list);
void remove_member(MailingList *list);
void display_members(const MailingList *list);
void save_to_file(const MailingList *list, const char *filename);
void load_from_file(MailingList *list, const char *filename);
void show_menu();

int main() {
    MailingList list;
    initialize_list(&list);
    
    char filename[] = "mailing_list.txt";
    load_from_file(&list, filename);
    
    int choice;
    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character

        switch (choice) {
            case 1:
                add_member(&list);
                break;
            case 2:
                remove_member(&list);
                break;
            case 3:
                display_members(&list);
                break;
            case 4:
                save_to_file(&list, filename);
                printf("Mailing list saved to %s\n", filename);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void initialize_list(MailingList *list) {
    list->count = 0;
}

void add_member(MailingList *list) {
    if (list->count >= MAX_MEMBERS) {
        printf("Mailing list is full. Cannot add more members.\n");
        return;
    }
    
    Member new_member;
    printf("Enter name: ");
    fgets(new_member.name, MAX_NAME_LENGTH, stdin);
    new_member.name[strcspn(new_member.name, "\n")] = '\0'; // Remove newline

    printf("Enter email: ");
    fgets(new_member.email, EMAIL_LENGTH, stdin);
    new_member.email[strcspn(new_member.email, "\n")] = '\0'; // Remove newline

    list->members[list->count++] = new_member;
    printf("Member added successfully.\n");
}

void remove_member(MailingList *list) {
    char email[EMAIL_LENGTH];
    printf("Enter email of the member to remove: ");
    fgets(email, EMAIL_LENGTH, stdin);
    email[strcspn(email, "\n")] = '\0'; // Remove newline

    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            // Shift members down
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            printf("Member removed successfully.\n");
            return;
        }
    }
    
    printf("Member with email '%s' not found.\n", email);
}

void display_members(const MailingList *list) {
    if (list->count == 0) {
        printf("No members in the mailing list.\n");
        return;
    }

    printf("Current members:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. Name: %s, Email: %s\n", i + 1, list->members[i].name, list->members[i].email);
    }
}

void save_to_file(const MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s,%s\n", list->members[i].name, list->members[i].email);
    }

    fclose(file);
}

void load_from_file(MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file for reading");
        return;
    }

    while (!feof(file) && list->count < MAX_MEMBERS) {
        char line[EMAIL_LENGTH + MAX_NAME_LENGTH + 2];  // account for comma and null
        if (fgets(line, sizeof(line), file)) {
            char *token = strtok(line, ",");
            if (token) {
                strcpy(list->members[list->count].name, token);
                token = strtok(NULL, ",");
                if (token) {
                    strcpy(list->members[list->count].email, token);
                    list->count++;
                }
            }
        }
    }

    fclose(file);
}

void show_menu() {
    printf("\nMailing List Manager\n");
    printf("1. Add Member\n");
    printf("2. Remove Member\n");
    printf("3. Display Members\n");
    printf("4. Save to File\n");
    printf("5. Exit\n");
}