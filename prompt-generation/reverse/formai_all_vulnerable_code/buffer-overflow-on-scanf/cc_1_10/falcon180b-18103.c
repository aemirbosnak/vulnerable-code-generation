//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

int compare_names(const void *a, const void *b) {
    Subscriber *sub1 = (Subscriber *)a;
    Subscriber *sub2 = (Subscriber *)b;
    return strcmp(sub1->name, sub2->name);
}

int compare_emails(const void *a, const void *b) {
    Subscriber *sub1 = (Subscriber *)a;
    Subscriber *sub2 = (Subscriber *)b;
    return strcmp(sub1->email, sub2->email);
}

void print_subscribers(Subscriber *subscribers, int num_subscribers) {
    printf("Name\tEmail\n");
    for (int i = 0; i < num_subscribers; i++) {
        printf("%s\t%s\n", subscribers[i].name, subscribers[i].email);
    }
}

int main() {
    Subscriber subscribers[100];
    int num_subscribers = 0;

    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    while (1) {
        printf("1. Add subscriber\n2. Remove subscriber\n3. Print subscribers\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                strcpy(subscribers[num_subscribers].name, name);
                strcpy(subscribers[num_subscribers].email, email);
                num_subscribers++;
                break;
            case 2:
                printf("Enter name to remove: ");
                scanf("%s", name);
                int index = -1;
                for (int i = 0; i < num_subscribers; i++) {
                    if (strcmp(name, subscribers[i].name) == 0) {
                        index = i;
                        break;
                    }
                }
                if (index == -1) {
                    printf("Subscriber not found.\n");
                } else {
                    for (int i = index; i < num_subscribers - 1; i++) {
                        strcpy(subscribers[i].name, subscribers[i + 1].name);
                        strcpy(subscribers[i].email, subscribers[i + 1].email);
                    }
                    num_subscribers--;
                }
                break;
            case 3:
                print_subscribers(subscribers, num_subscribers);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}