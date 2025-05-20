//MISTRAL-7B DATASET v1.0 Category: Mailing list manager ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[100];
} Subscriber;

int main(void) {
    int choice, i, len;
    char command[10];
    Subscriber *subscribers = NULL;
    int num_subscribers = 0;

    do {
        printf("\n--- TURING MAILING LIST MANAGER ---\n");
        printf("1. Add Subscriber\n");
        printf("2. Delete Subscriber\n");
        printf("3. Show Subscribers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                if (num_subscribers >= 1000) {
                    printf("Mailing list is full!\n");
                    break;
                }
                printf("Enter subscriber name: ");
                scanf("%s", subscribers[num_subscribers].name);
                printf("Enter subscriber email: ");
                scanf("%s", subscribers[num_subscribers].email);
                num_subscribers++;
                subscribers = realloc(subscribers, sizeof(Subscriber) * (num_subscribers + 1));
                break;

            case '2':
                if (num_subscribers <= 0) {
                    printf("No subscribers to delete!\n");
                    break;
                }
                printf("Enter index of subscriber to delete: ");
                scanf("%d", &i);
                if (i >= num_subscribers || i < 0) {
                    printf("Invalid index!\n");
                    break;
                }
                memmove(&subscribers[i], &subscribers[i+1], sizeof(Subscriber) * (num_subscribers - i - 1));
                num_subscribers--;
                subscribers = realloc(subscribers, sizeof(Subscriber) * num_subscribers);
                break;

            case '3':
                printf("\nList of Subscribers:\n");
                for (i = 0; i < num_subscribers; i++) {
                    printf("%d. %s (%s)\n", i+1, subscribers[i].name, subscribers[i].email);
                }
                break;

            case '4':
                free(subscribers);
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid command!\n");
        }
    } while (choice != '4');

    return 0;
}