//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

// Data structure for each subscriber
typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Subscriber;

// Function prototypes
int compare_subscribers(const void *a, const void *b);
int add_subscriber(Subscriber *subscribers, int num_subscribers, char *name, char *email);
void print_subscriber_list(Subscriber *subscribers, int num_subscribers);
void sort_subscriber_list(Subscriber *subscribers, int num_subscribers);

int main() {
    Subscriber subscribers[100]; // Initialize with some maximum size
    int num_subscribers = 0;

    while (1) {
        printf("Enter name and email (or type 'quit' to exit):\n");
        char name[MAX_NAME_LEN];
        char email[MAX_EMAIL_LEN];
        scanf("%s %s", name, email);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        if (add_subscriber(subscribers, num_subscribers, name, email)) {
            num_subscribers++;
        }
    }

    sort_subscriber_list(subscribers, num_subscribers);
    print_subscriber_list(subscribers, num_subscribers);

    return 0;
}

int compare_subscribers(const void *a, const void *b) {
    Subscriber *sub_a = (Subscriber *)a;
    Subscriber *sub_b = (Subscriber *)b;

    return strcmp(sub_a->name, sub_b->name);
}

int add_subscriber(Subscriber *subscribers, int num_subscribers, char *name, char *email) {
    if (num_subscribers >= 100) {
        printf("Cannot add more subscribers.\n");
        return 0;
    }

    Subscriber new_subscriber;
    strcpy(new_subscriber.name, name);
    strcpy(new_subscriber.email, email);

    subscribers[num_subscribers] = new_subscriber;
    num_subscribers++;

    return 1;
}

void print_subscriber_list(Subscriber *subscribers, int num_subscribers) {
    printf("Subscriber list:\n");
    for (int i = 0; i < num_subscribers; i++) {
        printf("%s (%s)\n", subscribers[i].name, subscribers[i].email);
    }
}

void sort_subscriber_list(Subscriber *subscribers, int num_subscribers) {
    qsort(subscribers, num_subscribers, sizeof(Subscriber), compare_subscribers);
}