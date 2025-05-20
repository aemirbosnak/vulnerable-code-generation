//FormAI DATASET v1.0 Category: Mailing list manager ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Person;

typedef struct {
    Person list[MAX_LIST_SIZE];
    int size;
} MailingList;

void add_person(MailingList *list, char *name, char *email) {
    if (list->size >= MAX_LIST_SIZE) {
        printf("Mailing list is full!\n");
        return;
    }

    Person person;
    strncpy(person.name, name, MAX_NAME_LENGTH);
    strncpy(person.email, email, MAX_EMAIL_LENGTH);
    list->list[list->size] = person;
    list->size++;
}

void remove_person(MailingList *list, char *name) {
    int index = -1;
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->list[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index >= 0) {
        for (int i = index; i < list->size - 1; i++) {
            list->list[i] = list->list[i + 1];
        }
        list->size--;
    } else {
        printf("Person not found in mailing list!\n");
    }
}

void print_list(MailingList *list) {
    printf("%-20s %-30s\n", "Name", "Email");
    for (int i = 0; i < list->size; i++) {
        printf("%-20s %-30s\n", list->list[i].name, list->list[i].email);
    }
}

int main() {
    MailingList list = { .size = 0 };
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];
    int choice;

    while (1) {
        printf("1. Add person to mailing list\n");
        printf("2. Remove person from mailing list\n");
        printf("3. Print mailing list\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter email: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = '\0';
                add_person(&list, name, email);
                break;
            case 2:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';
                remove_person(&list, name);
                break;
            case 3:
                print_list(&list);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}