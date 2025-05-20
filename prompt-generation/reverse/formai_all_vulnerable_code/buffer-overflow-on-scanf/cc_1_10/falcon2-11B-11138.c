//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
    int count;
} MailEntry;

void add_mail(MailEntry* mails, int num_mails, int count) {
    mails[num_mails].name[strlen(mails[num_mails].name)] = '\0';
    mails[num_mails].email[strlen(mails[num_mails].email)] = '\0';
    mails[num_mails].count = count;
}

void print_mail(MailEntry mails[], int num_mails) {
    for (int i = 0; i < num_mails; i++) {
        printf("%s (%d)\n", mails[i].name, mails[i].count);
    }
}

int main() {
    MailEntry mails[10];
    int num_mails = 0;
    int count = 0;

    while (1) {
        printf("Enter the email address: ");
        fgets(mails[num_mails].email, sizeof(mails[num_mails].email), stdin);
        mails[num_mails].email[strlen(mails[num_mails].email)] = '\0';

        printf("Enter the name: ");
        fgets(mails[num_mails].name, sizeof(mails[num_mails].name), stdin);
        mails[num_mails].name[strlen(mails[num_mails].name)] = '\0';

        add_mail(mails, num_mails, count);
        count++;

        if (count == 5) {
            break;
        }

        printf("Do you want to add another email (y/n)? ");
        char c;
        scanf(" %c", &c);
        if (c == 'n') {
            break;
        }
    }

    print_mail(mails, num_mails);

    return 0;
}