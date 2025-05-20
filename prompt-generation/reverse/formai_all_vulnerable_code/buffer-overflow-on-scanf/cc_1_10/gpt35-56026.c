//FormAI DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {
    char address[50];
    char name[50];
    struct email *next;
};

void display_menu() {
    printf("\n\n");
    printf("Mailing List Manager\n");
    printf("--------------------\n");
    printf("1. Add Email Address\n");
    printf("2. Remove Email Address\n");
    printf("3. Display Mailing List\n");
    printf("4. Exit\n\n");
}

void add_email(struct email **head) {
    char address[50], name[50];
    printf("Enter Email Address: ");
    scanf("%s", address);
    printf("Enter Name: ");
    scanf("%s", name);
    struct email *new_email = (struct email*)malloc(sizeof(struct email));
    strcpy(new_email->address, address);
    strcpy(new_email->name, name);
    new_email->next = NULL;
    if (*head == NULL) {
        *head = new_email;
    } else {
        struct email *p = *head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new_email;
    }
    printf("%s has been added to the mailing list.\n", name);
}

void remove_email(struct email **head) {
    if (*head == NULL) {
        printf("Mailing List is empty.\n");
        return;
    }
    char address[50], name[50];
    printf("Enter Email Address: ");
    scanf("%s", address);
    struct email *p = *head;
    if (strcmp(p->address, address) == 0) {
        *head = p->next;
        printf("%s has been removed from the mailing list.\n", p->name);
        free(p);
        return;
    }
    while (p->next != NULL && strcmp(p->next->address, address) != 0) {
        p = p->next;
    }
    if (p->next == NULL) {
        printf("%s is not in the mailing list.\n", address);
        return;
    }
    struct email *q = p->next;
    p->next = q->next;
    printf("%s has been removed from the mailing list.\n", q->name);
    free(q);
}

void display_list(struct email *head) {
    if (head == NULL) {
        printf("Mailing List is empty.\n");
        return;
    }
    printf("Mailing List:\n");
    printf("--------------\n");
    while (head != NULL) {
        printf("%s <%s>\n", head->name, head->address);
        head = head->next;
    }
}

int main() {
    struct email *head = NULL;
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_email(&head);
                break;
            case 2:
                remove_email(&head);
                break;
            case 3:
                display_list(head);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);
    return 0;
}