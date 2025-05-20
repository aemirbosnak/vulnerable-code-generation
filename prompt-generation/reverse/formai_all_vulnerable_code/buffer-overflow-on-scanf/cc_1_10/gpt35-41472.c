//FormAI DATASET v1.0 Category: Mailing list manager ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct MailingList {
    char name[50];
    char email[50];
    char phone[15];
} subscribers[100];

int numOfSubscribers = 0;

void addSubscriber() {
    if (numOfSubscribers == 100) {
        printf("Mailing list is full.\n");
        return;
    }
    struct MailingList subscriber;
    printf("Enter Subscriber details -\n");
    printf("Name: ");
    getchar();
    fgets(subscriber.name, 50, stdin);
    printf("Email: ");
    fgets(subscriber.email, 50, stdin);
    printf("Phone: ");
    fgets(subscriber.phone, 15, stdin);
    subscribers[numOfSubscribers++] = subscriber;
    printf("Subscriber added successfully.\n");
}

void showSubscribers() {
    if (numOfSubscribers == 0) {
        printf("Mailing list is empty.\n");
        return;
    }
    printf("List of subscribers -\n");
    for (int i = 0; i < numOfSubscribers; i++) {
        printf("Subscriber %d:\n", i+1);
        printf("Name: %s", subscribers[i].name);
        printf("Email: %s", subscribers[i].email);
        printf("Phone: %s", subscribers[i].phone);
    }
}

void searchSubscriber() {
    if (numOfSubscribers == 0) {
        printf("Mailing list is empty.\n");
        return;
    }
    char email[50];
    printf("Enter Email to search: ");
    getchar();
    fgets(email, 50, stdin);
    for (int i = 0; i < numOfSubscribers; i++) {
        if (strcmp(email, subscribers[i].email) == 0) {
            printf("Subscriber found:\n");
            printf("Name: %s", subscribers[i].name);
            printf("Email: %s", subscribers[i].email);
            printf("Phone: %s", subscribers[i].phone);
            return;
        }
    }
    printf("Subscriber not found.\n");
}

int main() {
    while (1) {
        printf("\n1. Add Subscriber\n");
        printf("2. Show Subscribers\n");
        printf("3. Search Subscriber by Email\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: addSubscriber(); break;
            case 2: showSubscribers(); break;
            case 3: searchSubscriber(); break;
            case 4: return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}