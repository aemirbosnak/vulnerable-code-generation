//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: intelligent
/*
 * mailing_list.c
 *
 * A simple mailing list manager program in C.
 *
 * Usage: ./mailing_list [command] [arguments]
 *
 * Commands:
 *   - add <email> <name>
 *   - remove <email>
 *   - list
 *   - send <email> <subject> <message>
 *
 * Example:
 *   ./mailing_list add john.doe@example.com "John Doe"
 *   ./mailing_list remove john.doe@example.com
 *   ./mailing_list list
 *   ./mailing_list send john.doe@example.com "Hello, John!" "How are you?"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECT_LENGTH 50
#define MAX_MESSAGE_LENGTH 1000

struct mailing_list {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];
};

struct mailing_list mailing_list[100];
int mailing_list_size = 0;

int add_email(char* email, char* name) {
    if (mailing_list_size >= 100) {
        printf("Mailing list is full.\n");
        return -1;
    }

    strcpy(mailing_list[mailing_list_size].email, email);
    strcpy(mailing_list[mailing_list_size].name, name);
    mailing_list_size++;

    return 0;
}

int remove_email(char* email) {
    for (int i = 0; i < mailing_list_size; i++) {
        if (strcmp(mailing_list[i].email, email) == 0) {
            for (int j = i; j < mailing_list_size - 1; j++) {
                mailing_list[j] = mailing_list[j + 1];
            }
            mailing_list_size--;
            return 0;
        }
    }

    printf("Email not found.\n");
    return -1;
}

int list_emails() {
    for (int i = 0; i < mailing_list_size; i++) {
        printf("%s (%s)\n", mailing_list[i].email, mailing_list[i].name);
    }

    return 0;
}

int send_email(char* email, char* subject, char* message) {
    for (int i = 0; i < mailing_list_size; i++) {
        if (strcmp(mailing_list[i].email, email) == 0) {
            printf("Sending email to %s (%s):\n", mailing_list[i].email, mailing_list[i].name);
            printf("%s\n", subject);
            printf("%s\n", message);
            return 0;
        }
    }

    printf("Email not found.\n");
    return -1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./mailing_list [command] [arguments]\n");
        return -1;
    }

    if (strcmp(argv[1], "add") == 0) {
        if (argc != 4) {
            printf("Usage: ./mailing_list add <email> <name>\n");
            return -1;
        }

        add_email(argv[2], argv[3]);
    } else if (strcmp(argv[1], "remove") == 0) {
        if (argc != 3) {
            printf("Usage: ./mailing_list remove <email>\n");
            return -1;
        }

        remove_email(argv[2]);
    } else if (strcmp(argv[1], "list") == 0) {
        list_emails();
    } else if (strcmp(argv[1], "send") == 0) {
        if (argc != 5) {
            printf("Usage: ./mailing_list send <email> <subject> <message>\n");
            return -1;
        }

        send_email(argv[2], argv[3], argv[4]);
    } else {
        printf("Invalid command.\n");
        return -1;
    }

    return 0;
}