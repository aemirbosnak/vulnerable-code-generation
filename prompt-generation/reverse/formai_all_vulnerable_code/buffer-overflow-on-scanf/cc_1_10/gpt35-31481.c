//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_ENTRIES 100

struct entry {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

struct mailing_list {
    int num_entries;
    struct entry entries[MAX_ENTRIES];
};

void add_entry(struct mailing_list* list, char* name, char* email) {
    if (list->num_entries == MAX_ENTRIES) {
        printf("Error: mailing list is full\n");
        return;
    }
    struct entry new_entry;
    strncpy(new_entry.name, name, MAX_NAME_LENGTH);
    strncpy(new_entry.email, email, MAX_EMAIL_LENGTH);
    list->entries[list->num_entries] = new_entry;
    list->num_entries++;
    printf("New entry added to mailing list:\nName: %s\nEmail: %s\n", name, email);
}

void print_list(struct mailing_list* list) {
    printf("Mailing list entries:\n");
    for (int i = 0; i < list->num_entries; i++) {
        printf("Entry %d:\nName: %s\nEmail: %s\n", i+1, list->entries[i].name, list->entries[i].email);
    }
}

void save_list(struct mailing_list* list, char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: failed to open file '%s'\n", filename);
        return;
    }
    for (int i = 0; i < list->num_entries; i++) {
        fprintf(file, "%s,%s\n", list->entries[i].name, list->entries[i].email);
    }
    fclose(file);
    printf("Mailing list saved to file '%s'\n", filename);
}

int main() {
    printf("Welcome to the Linux-style mailing list manager\n");
    struct mailing_list list;
    list.num_entries = 0;
    while (1) {
        printf("Enter command (add, list, save, exit): ");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            char name[MAX_NAME_LENGTH];
            char email[MAX_EMAIL_LENGTH];
            printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH-1);
            scanf("%s", name);
            printf("Enter email (up to %d characters): ", MAX_EMAIL_LENGTH-1);
            scanf("%s", email);
            add_entry(&list, name, email);
        } else if (strcmp(command, "list") == 0) {
            print_list(&list);
        } else if (strcmp(command, "save") == 0) {
            char filename[100];
            printf("Enter filename to save to: ");
            scanf("%s", filename);
            save_list(&list, filename);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting mailing list manager...\n");
            exit(0);
        } else {
            printf("Unknown command: %s\n", command);
        }
    }
    return 0;
}