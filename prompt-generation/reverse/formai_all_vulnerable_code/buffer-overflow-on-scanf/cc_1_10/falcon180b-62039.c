//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define EMAIL_LEN 100

struct email {
    char address[EMAIL_LEN];
    char name[EMAIL_LEN];
};

void add_email(struct email *list, int count, char *address, char *name) {
    if (count >= MAX_EMAILS) {
        printf("Error: Email list is full.\n");
        return;
    }

    strcpy(list[count].address, address);
    strcpy(list[count].name, name);

    count++;
}

void print_emails(struct email *list, int count) {
    printf("Email Addresses:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", list[i].address, list[i].name);
    }
}

int main() {
    struct email list[MAX_EMAILS];
    int count = 0;

    while (count < MAX_EMAILS) {
        char address[EMAIL_LEN];
        char name[EMAIL_LEN];

        printf("Enter an email address (or type 'done' to finish):\n");
        scanf("%s", address);

        if (strcmp(address, "done") == 0) {
            break;
        }

        printf("Enter a name for %s:\n", address);
        scanf("%s", name);

        add_email(list, count, address, name);
    }

    print_emails(list, count);

    return 0;
}