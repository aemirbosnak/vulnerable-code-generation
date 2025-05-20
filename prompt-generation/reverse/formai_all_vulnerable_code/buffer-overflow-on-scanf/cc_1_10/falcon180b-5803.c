//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    char email[MAX_EMAILS];
} subscriber;

void addSubscriber(subscriber *list, int *size) {
    printf("Enter your name: ");
    scanf("%s", list[*size].name);
    printf("Enter your email: ");
    scanf("%s", list[*size].email);
    (*size)++;
}

void viewSubscribers(subscriber *list, int size) {
    printf("Name\tEmail\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%s\n", list[i].name, list[i].email);
    }
}

void removeSubscriber(subscriber *list, int *size) {
    printf("Enter the name of the subscriber you want to remove: ");
    scanf("%s", list[0].name);
    for (int i = 0; i < *size; i++) {
        if (strcmp(list[i].name, list[0].name) == 0) {
            for (int j = i; j < *size - 1; j++) {
                strcpy(list[j].name, list[j+1].name);
                strcpy(list[j].email, list[j+1].email);
            }
            (*size)--;
            break;
        }
    }
}

void sendEmail(subscriber *list, int size) {
    char message[100];
    strcpy(message, "Hello ");
    strcat(message, list[0].name);
    strcat(message, ",\n\nThis is a test email from our mailing list.\n\nBest regards,\nThe Team");
    printf("Email sent to %s\n", list[0].email);
}

int main() {
    subscriber list[MAX_EMAILS];
    int size = 0;

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n2. View subscribers\n3. Remove subscriber\n4. Send email\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSubscriber(list, &size);
                break;
            case 2:
                viewSubscribers(list, size);
                break;
            case 3:
                removeSubscriber(list, &size);
                break;
            case 4:
                sendEmail(list, size);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}