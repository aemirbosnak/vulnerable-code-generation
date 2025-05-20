//FormAI DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char email[50];
    struct contact *next;
};

void add_contact(struct contact **head_ref, char *name, char *email) {
    struct contact *new_contact = (struct contact*)malloc(sizeof(struct contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    new_contact->next = *head_ref;
    *head_ref = new_contact;
}

void delete_contact(struct contact **head_ref, char *name) {
    struct contact *prev = NULL;
    struct contact *current = *head_ref;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                *head_ref = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void update_contact(struct contact **head_ref, char *name, char *new_email) {
    struct contact *current = *head_ref;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            strcpy(current->email, new_email);
            return;
        }
        current = current->next;
    }
}

void print_contacts(struct contact *head) {
    struct contact *current = head;
    while (current != NULL) {
        printf("%s - %s\n", current->name, current->email);
        current = current->next;
    }
}

void save_contacts(struct contact *head) {
    FILE *fp;
    fp = fopen("contacts.txt", "w");
    struct contact *current = head;
    while (current != NULL) {
        fprintf(fp, "%s,%s\n", current->name, current->email);
        current = current->next;
    }
    fclose(fp);
}

void load_contacts(struct contact **head_ref) {
    FILE *fp;
    fp = fopen("contacts.txt", "r");
    if (fp == NULL) {
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        char name[50];
        char email[50];
        sscanf(line, "%[^,],%s", name, email);
        add_contact(head_ref, name, email);
    }
    fclose(fp);
}

int main() {
    struct contact *head = NULL;
    load_contacts(&head);
    char option;
    while (1) {
        printf("Select an option:\n");
        printf(" 1 - Add contact\n");
        printf(" 2 - Delete contact\n");
        printf(" 3 - Update contact\n");
        printf(" 4 - Print contacts\n");
        printf(" 5 - Save contacts\n");
        printf(" 6 - Exit\n");
        scanf(" %c", &option);
        switch (option) {
            case '1': {
                char name[50];
                char email[50];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_contact(&head, name, email);
                printf("Contact added.\n");
                break;
            }
            case '2': {
                char name[50];
                printf("Enter name: ");
                scanf("%s", name);
                delete_contact(&head, name);
                printf("Contact deleted.\n");
                break;
            }
            case '3': {
                char name[50];
                char new_email[50];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter new email: ");
                scanf("%s", new_email);
                update_contact(&head, name, new_email);
                printf("Contact updated.\n");
                break;
            }
            case '4': {
                print_contacts(head);
                break;
            }
            case '5': {
                save_contacts(head);
                printf("Contacts saved.\n");
                break;
            }
            case '6': {
                save_contacts(head);
                return 0;
            }
            default: {
                printf("Invalid option.\n");
                break;
            }
        }
    }
    return 0;
}