//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Subscriber {
    char name[20];
    char email[50];
    int age;
} Subscriber;

int main()
{
    Subscriber subscribers[100];
    int count = 0;

    printf("Enter your name:\n");
    scanf("%s", subscribers[count].name);

    printf("What's thine age, fair subscriber?\n");
    scanf("%d", &subscribers[count].age);

    printf("And thy email address, that I may send thee correspondences?\n");
    scanf("%s", subscribers[count].email);

    printf("Thou art added to the list of subscribers, good %s.\n", subscribers[count].name);
    count++;

    printf("\nWouldst thou like to add another subscriber? (y/n)\n");
    char response;
    scanf(" %c", &response);
    if (response == 'n') {
        printf("Farewell, good sirs and ladies. Until we meet again.\n");
        return 0;
    }
    else if (response == 'y') {
        while (count < 100) {
            printf("\nWhat is thy name, fair subscriber?\n");
            scanf("%s", subscribers[count].name);

            printf("What is thy age?\n");
            scanf("%d", &subscribers[count].age);

            printf("And thy email address?\n");
            scanf("%s", subscribers[count].email);

            printf("Thou art added to the list of subscribers, good %s.\n", subscribers[count].name);
            count++;

            printf("\nWouldst thou like to add another subscriber? (y/n)\n");
            scanf(" %c", &response);
            if (response == 'n') {
                printf("Farewell, good sirs and ladies. Until we meet again.\n");
                break;
            }
            else if (response != 'y') {
                printf("I know not how to respond to thy answer. Begone from this place.\n");
                return 0;
            }
        }
    }

    printf("\nWouldst thou like to see the list of subscribers? (y/n)\n");
    scanf(" %c", &response);
    if (response == 'y') {
        printf("\nThy list of subscribers:\n");
        for (int i = 0; i < count; i++) {
            printf("%s, %d, %s\n", subscribers[i].name, subscribers[i].age, subscribers[i].email);
        }
    }
    else if (response == 'n') {
        printf("As you wish, good subscriber. Fare thee well.\n");
    }
    else {
        printf("I know not what thou meanest by '%c'. I pray thee, be clear.\n", response);
    }

    return 0;
}