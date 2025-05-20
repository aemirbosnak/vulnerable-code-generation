//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: statistical
#include <stdio.h>
#include <string.h>

#define MAX_EMAIL 100

typedef struct {
    char email[MAX_EMAIL + 1];
    char message[MAX_EMAIL + 1];
    char from[MAX_EMAIL + 1];
} mail_t;

void display_list(mail_t *list, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s - %s\n", list[i].email, list[i].message);
    }
}

void add_mail(mail_t *list, int size, char *email, char *message, char *from) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(list[i].email, email) == 0) {
            printf("Email already exists.\n");
            return;
        }
    }
    strcpy(list[size].email, email);
    strcpy(list[size].message, message);
    strcpy(list[size].from, from);
    size++;
}

void remove_mail(mail_t *list, int size, char *email) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(list[i].email, email) == 0) {
            strcpy(list[i].email, "");
            strcpy(list[i].message, "");
            strcpy(list[i].from, "");
            size--;
            return;
        }
    }
    printf("Email not found.\n");
}

void main() {
    int size = 0;
    mail_t list[MAX_EMAIL];

    while (1) {
        printf("1. Add a new email\n2. Remove an email\n3. Display list\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Email: ");
                fgets(list[size].email, MAX_EMAIL, stdin);
                printf("Message: ");
                fgets(list[size].message, MAX_EMAIL, stdin);
                printf("From: ");
                fgets(list[size].from, MAX_EMAIL, stdin);
                add_mail(list, size, list[size].email, list[size].message, list[size].from);
                break;
            case 2:
                printf("Email to remove: ");
                fgets(list[size].email, MAX_EMAIL, stdin);
                remove_mail(list, size, list[size].email);
                break;
            case 3:
                display_list(list, size);
                break;
            case 4:
                printf("Goodbye!\n");
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}