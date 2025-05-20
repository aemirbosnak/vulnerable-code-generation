//FormAI DATASET v1.0 Category: Mailing list manager ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 30

struct email {
    char name[MAX_NAME_LENGTH];
    char address[50];
};

struct email_list {
    struct email emails[MAX_EMAILS];
    int count;
};

void print_menu() {
    printf("\nSelect an option:\n");
    printf("1. Add an email address\n");
    printf("2. Remove an email address\n");
    printf("3. Print the email list\n");
    printf("4. Quit\n");
}

int get_option() {
    int option;
    printf("\nEnter your choice: ");
    scanf("%d", &option);
    fflush(stdin);
    return option;
}

void add_email(struct email_list *list) {
    struct email new_email;
    printf("\nEnter name: ");
    fgets(new_email.name, MAX_NAME_LENGTH, stdin);
    printf("Enter address: ");
    fgets(new_email.address, 50, stdin);
    list->emails[list->count] = new_email;
    list->count++;
    printf("\nEmail added.\n");
}

void remove_email(struct email_list *list) {
    char name[MAX_NAME_LENGTH];
    int found = 0;
    printf("\nEnter name of email to remove: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    for (int i = 0; i < list->count; i++) {
        if (strcmp(name, list->emails[i].name) == 0) {
            list->count--;
            list->emails[i] = list->emails[list->count];
            printf("\nEmail removed.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nEmail not found.\n");
    }
}

void print_list(struct email_list *list) {
    printf("\nEmail list:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s %s", list->emails[i].name, list->emails[i].address);
    }
}

int main() {
    struct email_list list;
    list.count = 0;
    int option = 0;
    while (option != 4) {
        print_menu();
        option = get_option();
        switch (option) {
            case 1:
                add_email(&list);
                break;
            case 2:
                remove_email(&list);
                break;
            case 3:
                print_list(&list);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option. Try again.\n");
        }
    }
    return 0;
}