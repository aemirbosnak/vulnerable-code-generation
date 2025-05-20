//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBJECT_LEN 100
#define MAX_MESSAGE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char message[MAX_MESSAGE_LEN];
} email;

contact* add_contact(contact* list, int size, char* name, char* email) {
    contact* new_list = (contact*)realloc(list, sizeof(contact) * (size + 1));
    if (new_list == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    list = new_list;
    strcpy(list[size].name, name);
    strcpy(list[size].email, email);
    list[size].name[MAX_NAME_LEN - 1] = '\0';
    list[size].email[MAX_EMAIL_LEN - 1] = '\0';
    return list;
}

int send_email(char* email, char* subject, char* message) {
    printf("Sending email to %s with subject '%s' and message:\n%s\n", email, subject, message);
    return 1;
}

int main() {
    contact* list = NULL;
    int size = 0;
    char input[100];
    while (1) {
        printf("Enter name and email (separated by space): ");
        scanf("%s", input);
        char* name = strtok(input, " ");
        char* email = strtok(NULL, " ");
        if (name == NULL || email == NULL) {
            printf("Invalid input.\n");
            continue;
        }
        list = add_contact(list, size, name, email);
        size++;
    }
    while (1) {
        printf("Enter's' to send email or 'q' to quit: ");
        scanf("%s", input);
        if (strcmp(input, "s") == 0) {
            printf("Enter subject: ");
            scanf("%s", input);
            printf("Enter message: ");
            scanf("%s", input);
            int i;
            for (i = 0; i < size; i++) {
                send_email(list[i].email, input, input + strlen(input) + 1);
            }
        } else if (strcmp(input, "q") == 0) {
            break;
        } else {
            printf("Invalid input.\n");
        }
    }
    return 0;
}