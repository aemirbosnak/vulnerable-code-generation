//FormAI DATASET v1.0 Category: Mailing list manager ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_SUBSCRIBERS 100

typedef struct subscriber {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

int add_subscriber(Subscriber *subscribers, int *num_subscribers) {
    char name[MAX_NAME_LEN], email[MAX_EMAIL_LEN];
    printf("Enter name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove trailing newline
    printf("Enter email: ");
    fgets(email, MAX_EMAIL_LEN, stdin);
    email[strcspn(email, "\n")] = '\0'; // remove trailing newline
    if (*num_subscribers < MAX_SUBSCRIBERS) {
        // add subscriber to array
        Subscriber sub;
        strcpy(sub.name, name);
        strcpy(sub.email, email);
        subscribers[*num_subscribers] = sub;
        (*num_subscribers)++;
        return 1;
    } else {
        printf("Mailing list is full!\n");
        return 0;
    }
}

int remove_subscriber(Subscriber *subscribers, int *num_subscribers) {
    char email[MAX_EMAIL_LEN];
    printf("Enter email: ");
    fgets(email, MAX_EMAIL_LEN, stdin);
    email[strcspn(email, "\n")] = '\0'; // remove trailing newline
    for (int i = 0; i < *num_subscribers; i++) {
        if (strcmp(subscribers[i].email, email) == 0) {
            // remove subscriber from array
            for (int j = i; j < *num_subscribers - 1; j++) {
                subscribers[j] = subscribers[j + 1];
            }
            (*num_subscribers)--;
            return 1;
        }
    }
    printf("Subscriber not found!\n");
    return 0;
}

void display_subscribers(Subscriber *subscribers, int num_subscribers) {
    printf("Mailing list:\n");
    for (int i = 0; i < num_subscribers; i++) {
        printf("%s <%s>\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int num_subscribers = 0;

    int choice;
    do {
        printf("\nMailing List Manager\n");
        printf("1. Add subscriber\n");
        printf("2. Remove subscriber\n");
        printf("3. Display subscribers\n");
        printf("4. Quit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);
        getchar(); // remove trailing newline from scanf buffer

        switch (choice) {
            case 1:
                if (add_subscriber(subscribers, &num_subscribers)) {
                    printf("Subscriber added.\n");
                }
                break;
            case 2:
                if (remove_subscriber(subscribers, &num_subscribers)) {
                    printf("Subscriber removed.\n");
                }
                break;
            case 3:
                display_subscribers(subscribers, num_subscribers);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}