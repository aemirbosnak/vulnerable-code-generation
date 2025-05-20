//FormAI DATASET v1.0 Category: Email Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_BODY_SIZE 1000
#define MAX_SUBJECT_SIZE 100

typedef struct {
    char to[50];
    char from[50];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];
} Email;

void print_menu() {
    printf("1. Compose Email\n");
    printf("2. View Inbox\n");
    printf("3. Delete Email\n");
    printf("4. Exit\n");
}

Email* compose_email() {
    Email* email = (Email*)malloc(sizeof(Email));

    printf("To: ");
    scanf("%s", email->to);
    printf("From: ");
    scanf("%s", email->from);
    printf("Subject: ");
    scanf("%s", email->subject);
    printf("Body: ");
    getchar();
    fgets(email->body, MAX_BODY_SIZE, stdin);

    printf("Email sent!\n");

    return email;
}

void view_inbox(Email** inbox, int size) {
    printf("Inbox:\n");
    for(int i = 0; i < size; i++) {
        printf("Email #%d\n", i+1);
        printf("To: %s\n", inbox[i]->to);
        printf("From: %s\n", inbox[i]->from);
        printf("Subject: %s\n", inbox[i]->subject);
        printf("Body: %s\n", inbox[i]->body);
    }
}

void delete_email(Email** inbox, int* size) {
    int index;
    printf("Enter the number of the email to delete: ");
    scanf("%d", &index);
    index--;

    if(index < 0 || index >= *size) {
        printf("Invalid number\n");
    } else {
        free(inbox[index]);
        for(int i = index; i < *size-1; i++) {
            inbox[i] = inbox[i+1];
        }
        inbox[*size-1] = NULL;
        (*size)--;
        printf("Email deleted!\n");
    }
}

int main() {
    Email* inbox[100];
    int inbox_size = 0;
    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                inbox[inbox_size] = compose_email();
                inbox_size++;
                break;
            case 2:
                view_inbox(inbox, inbox_size);
                break;
            case 3:
                delete_email(inbox, &inbox_size);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

    } while(choice != 4);

    return 0;
}