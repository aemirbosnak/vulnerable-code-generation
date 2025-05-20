//FormAI DATASET v1.0 Category: Mailing list manager ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_ENTRIES 1000

struct entry {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

int add_entry(struct entry *entries, int n) {
    if (n >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return n;
    }

    printf("Enter name: ");
    scanf("%s", entries[n].name);

    printf("Enter email: ");
    scanf("%s", entries[n].email);

    printf("Entry added.\n");

    return n + 1;
}

void print_entry(int i, struct entry *entries) {
    printf("%d. %s <%s>\n", i, entries[i].name, entries[i].email);
}

void print_entries(struct entry *entries, int n) {
    printf("Mailing list:\n");
    for (int i = 0; i < n; i++) {
        print_entry(i, entries);
    }
}

int find_entry(char *name, struct entry *entries, int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(name, entries[i].name) == 0) {
            return i;
        }
    }

    return -1;
}

int remove_entry(char *name, struct entry *entries, int n) {
    int i = find_entry(name, entries, n);

    if (i >= 0) {
        memmove(&entries[i], &entries[i+1], sizeof(struct entry) * (n-i-1));
        printf("Entry removed.\n");
        return n - 1;
    } else {
        printf("Error: Entry not found.\n");
        return n;
    }
}

void help() {
    printf("Usage:\n");
    printf("add - add an entry to the mailing list.\n");
    printf("remove - remove an entry from the mailing list by name.\n");
    printf("list - display the entire mailing list.\n");
    printf("help - display this help message.\n");
    printf("quit - exit the program.\n");
}

int main() {
    struct entry entries[MAX_ENTRIES];
    int n = 0;

    printf("Mailing list manager.\n");
    printf("Type \"help\" for a list of commands.\n");

    while (1) {
        char command[10];
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            n = add_entry(entries, n);
        } else if (strcmp(command, "remove") == 0) {
            char name[MAX_NAME_LENGTH];
            printf("Enter name to remove: ");
            scanf("%s", name);
            n = remove_entry(name, entries, n);
        } else if (strcmp(command, "list") == 0) {
            print_entries(entries, n);
        } else if (strcmp(command, "help") == 0) {
            help();
        } else if (strcmp(command, "quit") == 0) {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Error: Unknown command.\n");
            help();
        }
    }
}