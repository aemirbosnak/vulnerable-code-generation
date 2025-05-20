//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 100
#define MAX_EMAIL_LENGTH 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Member;

typedef struct {
    Member members[MAX_MEMBERS];
    int count;
} MailingList;

void init_list(MailingList *list) {
    list->count = 0;
}

void add_member(MailingList *list, const char *name, const char *email) {
    if (list->count < MAX_MEMBERS) {
        strncpy(list->members[list->count].name, name, NAME_LENGTH);
        strncpy(list->members[list->count].email, email, MAX_EMAIL_LENGTH);
        list->count++;
        printf("🎉 Successfully added %s (%s) to the mailing list! 🎉\n", name, email);
    } else {
        printf("❌ Unable to add member: List is full! ❌\n");
    }
}

void remove_member(MailingList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->members[i].email, email) == 0) {
            printf("😢 Removing %s (%s) from the mailing list. Goodbye! 😢\n", list->members[i].name, list->members[i].email);
            for (int j = i; j < list->count - 1; j++) {
                list->members[j] = list->members[j + 1];
            }
            list->count--;
            return;
        }
    }
    printf("🚫 No member found with the email %s! 🚫\n", email);
}

void display_members(const MailingList *list) {
    if (list->count == 0) {
        printf("😞 The mailing list is empty! Add some members! 😞\n");
        return;
    }
    printf("🌟 Current Mailing List Members 🌟\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s (%s)\n", i + 1, list->members[i].name, list->members[i].email);
    }
}

void save_to_file(const MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("❌ Failed to open file for saving! ❌\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s,%s\n", list->members[i].name, list->members[i].email);
    }
    fclose(file);
    printf("💾 Mailing list saved to %s successfully! 💾\n", filename);
}

void load_from_file(MailingList *list, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("❌ Failed to open file for loading! ❌\n");
        return;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char name[NAME_LENGTH];
        char email[MAX_EMAIL_LENGTH];

        if (sscanf(line, "%[^,],%s", name, email) == 2) {
            add_member(list, name, email);
        }
    }
    fclose(file);
    printf("📥 Mailing list loaded from %s successfully! 📥\n", filename);
}

int main() {
    MailingList mailingList;
    init_list(&mailingList);

    int choice;
    char name[NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char filename[100];

    do {
        printf("\n🙌 Welcome to the C Mailing List Manager! 🙌\n");
        printf("1. Add Member\n");
        printf("2. Remove Member\n");
        printf("3. Display Members\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter email: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                add_member(&mailingList, name, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline
                remove_member(&mailingList, email);
                break;
            case 3:
                display_members(&mailingList);
                break;
            case 4:
                printf("Enter filename to save: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                save_to_file(&mailingList, filename);
                break;
            case 5:
                printf("Enter filename to load: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                load_from_file(&mailingList, filename);
                break;
            case 6:
                printf("👍 Thank you for using the C Mailing List Manager! Goodbye! 👍\n");
                break;
            default:
                printf("🚫 Invalid choice! Please try again. 🚫\n");
        }
    } while (choice != 6);

    return 0;
}