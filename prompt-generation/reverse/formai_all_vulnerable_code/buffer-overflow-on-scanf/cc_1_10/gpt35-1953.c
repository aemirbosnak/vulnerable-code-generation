//FormAI DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ENTRY_SIZE 1000
#define MAX_ENTRIES 100
#define PASSWORD "mysecretpassword"

struct Entry {
    char date[20];
    char text[MAX_ENTRY_SIZE];
};

struct Diary {
    struct Entry entries[MAX_ENTRIES];
    int num_entries;
};

void display_menu() {
    printf("Welcome to your digital diary!\n");
    printf("1. View Entries\n");
    printf("2. Add Entry\n");
    printf("3. Delete Entry\n");
    printf("4. Change Password\n");
    printf("5. Exit\n");
}

bool authenticate() {
    char password[20];
    printf("Please enter your password: ");
    scanf("%s", password);
    return strcmp(password, PASSWORD) == 0;
}

void view_entries(struct Diary *diary) {
    printf("Your entries:\n");
    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s\n", diary->entries[i].date);
        printf("%s\n", diary->entries[i].text);
    }
}

void add_entry(struct Diary *diary) {
    if (diary->num_entries >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add new entry.\n");
        return;
    }
    printf("Enter the date (mm/dd/yyyy): ");
    scanf("%s", diary->entries[diary->num_entries].date);
    printf("Enter your text:\n");
    scanf(" %[^\n]s", diary->entries[diary->num_entries].text);
    diary->num_entries++;
}

void delete_entry(struct Diary *diary) {
    if (diary->num_entries == 0) {
        printf("No entries to delete.\n");
        return;
    }
    char date[20];
    printf("Enter the date of the entry to delete (mm/dd/yyyy): ");
    scanf("%s", date);
    for (int i = 0; i < diary->num_entries; i++) {
        if (strcmp(date, diary->entries[i].date) == 0) {
            for (int j = i; j < diary->num_entries - 1; j++) {
                diary->entries[j] = diary->entries[j + 1];
            }
            diary->num_entries--;
            printf("Entry deleted.\n");
            return;
        }
    }
    printf("Entry not found.\n");
}

void change_password() {
    char old_password[20], new_password1[20], new_password2[20];
    printf("Enter your old password: ");
    scanf("%s", old_password);
    if (strcmp(old_password, PASSWORD) != 0) {
        printf("Incorrect password.\n");
        return;
    }
    printf("Enter your new password: ");
    scanf("%s", new_password1);
    printf("Re-enter your new password: ");
    scanf("%s", new_password2);
    if (strcmp(new_password1, new_password2) != 0) {
        printf("Passwords do not match.\n");
        return;
    }
    strcpy(PASSWORD, new_password1);
    printf("Password changed.\n");
}

int main() {
    struct Diary diary = { .num_entries = 0 };
    while (true) {
        display_menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (!authenticate()) {
                    printf("Incorrect password.\n");
                    break;
                }
                view_entries(&diary);
                break;
            case 2:
                if (!authenticate()) {
                    printf("Incorrect password.\n");
                    break;
                }
                add_entry(&diary);
                break;
            case 3:
                if (!authenticate()) {
                    printf("Incorrect password.\n");
                    break;
                }
                delete_entry(&diary);
                break;
            case 4:
                if (!authenticate()) {
                    printf("Incorrect password.\n");
                    break;
                }
                change_password();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}