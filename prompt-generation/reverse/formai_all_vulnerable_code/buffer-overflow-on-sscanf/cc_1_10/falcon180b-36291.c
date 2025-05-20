//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME 100
#define MAX_EMAIL 100
#define MAX_SUBJECT 1000
#define MAX_BODY 10000

struct mailing_list {
    char name[MAX_NAME];
    char email[MAX_EMAIL];
};

struct message {
    char from[MAX_NAME];
    char to[MAX_NAME];
    char subject[MAX_SUBJECT];
    char body[MAX_BODY];
};

void add_to_mailing_list(struct mailing_list *list, int num_entries, char *name, char *email) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(list[i].name, name) == 0) {
            strcpy(list[i].email, email);
            return;
        }
    }
    strcpy(list[num_entries].name, name);
    strcpy(list[num_entries].email, email);
    num_entries++;
}

void send_message(struct mailing_list *list, int num_entries, char *from, char *to, char *subject, char *body) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (strcmp(list[i].name, to) == 0) {
            printf("Sending message from %s to %s\n", from, list[i].email);
            printf("Subject: %s\n", subject);
            printf("Body:\n%s\n", body);
        }
    }
}

int main() {
    struct mailing_list list[100];
    int num_entries = 0;
    char input[1000];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        if (input[0] == 'A') {
            char name[MAX_NAME];
            char email[MAX_EMAIL];
            sscanf(input, "A %s %s", name, email);
            add_to_mailing_list(list, num_entries, name, email);
        } else if (input[0] == 'S') {
            char from[MAX_NAME];
            char to[MAX_NAME];
            char subject[MAX_SUBJECT];
            char body[MAX_BODY];
            sscanf(input, "S %s %s %s %s", from, to, subject, body);
            send_message(list, num_entries, from, to, subject, body);
        }
    }
    return 0;
}