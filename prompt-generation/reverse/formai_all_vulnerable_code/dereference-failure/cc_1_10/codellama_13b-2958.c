//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256
#define MAX_SUBJECT_LEN 128
#define MAX_BODY_LEN 512

struct email {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    struct email *next;
};

struct email *head = NULL;

void add_email(char *subject, char *body) {
    struct email *new_email = (struct email *)malloc(sizeof(struct email));
    strcpy(new_email->subject, subject);
    strcpy(new_email->body, body);
    new_email->next = head;
    head = new_email;
}

void display_emails() {
    struct email *temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->subject);
        printf("%s\n", temp->body);
        temp = temp->next;
    }
}

void delete_email(char *subject) {
    struct email *temp = head;
    struct email *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->subject, subject) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

void read_emails() {
    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), stdin)) {
        char *subject = strtok(line, ":");
        char *body = strtok(NULL, ":");
        add_email(subject, body);
    }
}

int main() {
    read_emails();
    display_emails();
    delete_email("Subject 2");
    display_emails();
    return 0;
}