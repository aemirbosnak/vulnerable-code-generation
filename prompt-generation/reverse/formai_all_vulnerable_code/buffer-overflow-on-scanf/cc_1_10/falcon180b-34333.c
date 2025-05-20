//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} User;

User users[MAX_USERS];
int num_users = 0;

void add_user() {
    printf("Enter name: ");
    scanf("%s", users[num_users].name);
    printf("Enter email: ");
    scanf("%s", users[num_users].email);
    num_users++;
}

void remove_user() {
    printf("Enter email to remove: ");
    char email[MAX_EMAIL_LENGTH];
    scanf("%s", email);
    int i;
    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].email, email) == 0) {
            memmove(&users[i], &users[i+1], sizeof(User) * (num_users - i - 1));
            num_users--;
            printf("User removed.\n");
            break;
        }
    }
}

void list_users() {
    printf("Name\tEmail\n");
    int i;
    for (i = 0; i < num_users; i++) {
        printf("%s\t%s\n", users[i].name, users[i].email);
    }
}

void send_email() {
    printf("Enter email subject: ");
    char subject[MAX_EMAIL_LENGTH];
    scanf("%s", subject);
    printf("Enter email body: ");
    char body[MAX_EMAIL_LENGTH];
    scanf("%s", body);
    int i;
    for (i = 0; i < num_users; i++) {
        printf("Sending email to %s...\n", users[i].email);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add user\n2. Remove user\n3. List users\n4. Send email\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                remove_user();
                break;
            case 3:
                list_users();
                break;
            case 4:
                send_email();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}