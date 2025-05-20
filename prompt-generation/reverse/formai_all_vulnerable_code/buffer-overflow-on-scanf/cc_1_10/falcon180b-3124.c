//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} subscriber;

void add_subscriber(subscriber *list, int *count) {
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your email: ");
    scanf("%s", email);
    strcpy(list[*count].name, name);
    strcpy(list[*count].email, email);
    (*count)++;
}

void remove_subscriber(subscriber *list, int *count) {
    char email[MAX_EMAIL_LENGTH];
    printf("Enter the email to remove: ");
    scanf("%s", email);
    for (int i = 0; i < *count; i++) {
        if (strcmp(list[i].email, email) == 0) {
            for (int j = i; j < *count - 1; j++) {
                strcpy(list[j].name, list[j+1].name);
                strcpy(list[j].email, list[j+1].email);
            }
            (*count)--;
            break;
        }
    }
}

void send_email(subscriber *list, int count) {
    printf("Sending email to %d subscribers:\n", count);
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Email: %s\n", list[i].name, list[i].email);
    }
}

int main() {
    subscriber list[100];
    int count = 0;
    int choice;
    do {
        printf("1. Add subscriber\n2. Remove subscriber\n3. Send email\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_subscriber(list, &count);
                break;
            case 2:
                remove_subscriber(list, &count);
                break;
            case 3:
                send_email(list, count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
    return 0;
}