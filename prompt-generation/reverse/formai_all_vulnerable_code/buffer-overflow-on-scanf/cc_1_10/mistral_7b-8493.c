//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIST_SIZE 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} mailing_list_entry;

mailing_list_entry *list = NULL;
int num_entries = 0;

void add_entry(const char *name, const char *email) {
    mailing_list_entry *new_entry;

    if ((new_entry = malloc(sizeof(mailing_list_entry))) == NULL) {
        fprintf(stderr, "Error: Out of memory!\n");
        return;
    }

    strcpy(new_entry->name, name);
    strcpy(new_entry->email, email);

    if (num_entries >= MAX_LIST_SIZE) {
        fprintf(stderr, "Error: Mailing list is full!\n");
        free(new_entry);
        return;
    }

    list[num_entries++] = *new_entry;
}

void remove_entry(const char *name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(list[i].name, name) == 0) {
            memmove(&list[i], &list[i + 1], (num_entries - i - 1) * sizeof(mailing_list_entry));
            num_entries--;
            break;
        }
    }

    if (i == num_entries) {
        fprintf(stderr, "Error: Name not found in mailing list!\n");
    }
}

void search_entry(const char *name) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(list[i].name, name) == 0) {
            printf("Name: %s\nEmail: %s\n", list[i].name, list[i].email);
            return;
        }
    }

    fprintf(stderr, "Error: Name not found in mailing list!\n");
}

void list_all() {
    int i;

    for (i = 0; i < num_entries; i++) {
        printf("%s -> %s\n", list[i].name, list[i].email);
    }
}

int main(int argc, char *argv[]) {
    char command[20], name[NAME_LENGTH], email[EMAIL_LENGTH];

    while (1) {
        printf("Mailing List Manager>\n");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        switch (*command) {
            case 'a':
                scanf("%s %s", name, email);
                add_entry(name, email);
                break;
            case 'r':
                scanf("%s", name);
                remove_entry(name);
                break;
            case 's':
                scanf("%s", name);
                search_entry(name);
                break;
            case 'l':
                list_all();
                break;
            default:
                fprintf(stderr, "Error: Invalid command!\n");
        }
    }

    free(list);

    return 0;
}