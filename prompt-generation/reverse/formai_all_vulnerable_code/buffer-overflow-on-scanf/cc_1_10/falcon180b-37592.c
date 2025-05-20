//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} subscriber;

subscriber subscribers[MAX_SUBSCRIBERS];
int num_subscribers = 0;

void add_subscriber() {
    printf("Enter name: ");
    scanf("%s", subscribers[num_subscribers].name);

    printf("Enter email: ");
    scanf("%s", subscribers[num_subscribers].email);

    num_subscribers++;
}

void remove_subscriber() {
    printf("Enter email to remove: ");
    char email[MAX_EMAIL_LENGTH];
    scanf("%s", email);

    int i;
    for (i = 0; i < num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            num_subscribers--;
            break;
        }
    }
}

void send_email() {
    printf("Enter subject: ");
    char subject[MAX_EMAIL_LENGTH];
    scanf("%s", subject);

    printf("Enter message: ");
    char message[1024];
    scanf("%[^\n]s", message);

    printf("Enter recipient email: ");
    char recipient_email[MAX_EMAIL_LENGTH];
    scanf("%s", recipient_email);

    FILE *fp;
    fp = fopen("message.txt", "w");
    fprintf(fp, "Subject: %s\n", subject);
    fprintf(fp, "Message: %s\n", message);
    fclose(fp);

    system("echo -e \"$(cat message.txt)\" | ssmtp $RECIPIENT_EMAIL");
}

int main() {
    int choice;

    do {
        printf("\nCyberpunk Mailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Send email\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_subscriber();
                break;
            case 2:
                remove_subscriber();
                break;
            case 3:
                send_email();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}