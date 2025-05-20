//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100

typedef struct Subscriber {
    char name[50];
    char email[50];
} Subscriber;

void addSubscriber(Subscriber subscriber);
void removeSubscriber(Subscriber subscriber);
void printSubscribers();

int main() {
    Subscriber subscriber;
    char input[50];

    while (1) {
        printf("Enter a command: ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter name and email: ");
            scanf("%s %s", subscriber.name, subscriber.email);
            addSubscriber(subscriber);
        } else if (strcmp(input, "remove") == 0) {
            printf("Enter name and email: ");
            scanf("%s %s", subscriber.name, subscriber.email);
            removeSubscriber(subscriber);
        } else if (strcmp(input, "print") == 0) {
            printSubscribers();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}

void addSubscriber(Subscriber subscriber) {
    FILE *fp = fopen("subscribers.txt", "a");
    fprintf(fp, "%s, %s\n", subscriber.name, subscriber.email);
    fclose(fp);
}

void removeSubscriber(Subscriber subscriber) {
    FILE *fp = fopen("subscribers.txt", "r");
    FILE *fp2 = fopen("temp.txt", "w");
    char line[50];
    while (fgets(line, 50, fp)) {
        if (strstr(line, subscriber.name) == NULL && strstr(line, subscriber.email) == NULL) {
            fprintf(fp2, "%s", line);
        }
    }
    fclose(fp);
    fclose(fp2);
    remove("subscribers.txt");
    rename("temp.txt", "subscribers.txt");
}

void printSubscribers() {
    FILE *fp = fopen("subscribers.txt", "r");
    char line[50];
    while (fgets(line, 50, fp)) {
        printf("%s", line);
    }
    fclose(fp);
}