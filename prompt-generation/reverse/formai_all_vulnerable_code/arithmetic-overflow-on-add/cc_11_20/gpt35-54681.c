//FormAI DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

struct email {
    char name[50];
    char address[50];
};

struct mailinglist {
    struct email emails[100];
    int numEmails;
};

int main() {
    struct mailinglist list;
    list.numEmails = 0;

    int choice = 0;
    while (choice != 4) {
        printf("Choose an option:\n");
        printf("1. Add an email\n");
        printf("2. Remove an email\n");
        printf("3. View mailing list\n");
        printf("4. Quit program\n");
        scanf("%d", &choice);

        if (choice == 1) {
            if (list.numEmails < 100) {
                printf("\nEnter name: ");
                scanf("%s", list.emails[list.numEmails].name);
                printf("Enter email address: ");
                scanf("%s", list.emails[list.numEmails].address);

                list.numEmails++;

                printf("\nEmail added to mailing list!\n\n");
            } else {
                printf("\nMailing list is full!\n\n");
            }
        } else if (choice == 2) {
            if (list.numEmails > 0) {
                int indexToRemove = -1;
                char emailToRemove[50];

                printf("\nEnter email address to remove: ");
                scanf("%s", emailToRemove);

                for (int i = 0; i < list.numEmails; i++) {
                    if (strcmp(list.emails[i].address, emailToRemove) == 0) {
                        indexToRemove = i;
                        break;
                    }
                }

                if (indexToRemove != -1) {
                    for (int i = indexToRemove; i < list.numEmails - 1; i++) {
                        strcpy(list.emails[i].name, list.emails[i + 1].name);
                        strcpy(list.emails[i].address, list.emails[i + 1].address);
                    }

                    list.numEmails--;

                    printf("\nEmail removed from mailing list!\n\n");
                } else {
                    printf("\nEmail not found in mailing list!\n\n");
                }
            } else {
                printf("\nMailing list is empty!\n\n");
            }
        } else if (choice == 3) {
            if (list.numEmails > 0) {
                printf("\nMailing List:\n");
                printf("Name\t\tAddress\n");

                for (int i = 0; i < list.numEmails; i++) {
                    printf("%s\t\t%s\n", list.emails[i].name, list.emails[i].address);
                }

                printf("\n");
            } else {
                printf("\nMailing list is empty!\n\n");
            }
        } else if (choice == 4) {
            printf("\nGoodbye!\n");
        } else {
            printf("\nInvalid choice!\n\n");
        }
    }

    return 0;
}