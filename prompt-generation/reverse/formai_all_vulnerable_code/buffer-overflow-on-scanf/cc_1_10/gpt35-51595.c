//FormAI DATASET v1.0 Category: Mailing list manager ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_ENTRIES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} entry;

int num_entries = 0;
entry mailing_list[MAX_ENTRIES];

void add_entry() {
    if (num_entries == MAX_ENTRIES) {
        printf("Mailing list is full.\n");
        return;
    }

    entry new_entry;
    printf("Enter name: ");
    fgets(new_entry.name, MAX_NAME_LENGTH, stdin);
    strtok(new_entry.name, "\n"); // Remove newline character
    printf("Enter email: ");
    fgets(new_entry.email, MAX_EMAIL_LENGTH, stdin);
    strtok(new_entry.email, "\n"); // Remove newline character

    mailing_list[num_entries++] = new_entry;
    printf("Entry added.\n");
}

void remove_entry() {
    if (num_entries == 0) {
        printf("Mailing list is empty.\n");
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter name of entry to remove: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    strtok(name, "\n"); // Remove newline character

    int index_to_remove = -1;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(name, mailing_list[i].name) == 0) {
            index_to_remove = i;
            break;
        }
    }

    if (index_to_remove == -1) {
        printf("Entry not found.\n");
        return;
    }

    for (int i = index_to_remove; i < num_entries - 1; i++) {
        mailing_list[i] = mailing_list[i + 1];
    }
    num_entries--;

    printf("Entry removed.\n");
}

void print_list() {
    if (num_entries == 0) {
        printf("Mailing list is empty.\n");
        return;
    }

    printf("Mailing List:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s <%s>\n", mailing_list[i].name, mailing_list[i].email);
    }
}

int main() {
    int choice;

    printf("Welcome to the Mailing List Manager!\n");
    while (1) {
        printf("1. Add entry\n");
        printf("2. Remove entry\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Remove newline character from input buffer

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                remove_entry();
                break;
            case 3:
                print_list();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}