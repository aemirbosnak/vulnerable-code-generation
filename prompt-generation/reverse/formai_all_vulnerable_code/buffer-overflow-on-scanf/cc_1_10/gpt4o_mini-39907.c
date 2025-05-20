//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char email[NAME_LENGTH];
} Subscriber;

Subscriber *subscribers[MAX_SUBSCRIBERS];
int subscriber_count = 0;

void add_subscriber(const char* name, const char* email) {
    if (subscriber_count >= MAX_SUBSCRIBERS) {
        printf("Inspector! The mailing list is full. No more suspects can be added!\n");
        return;
    }
    Subscriber *new_subscriber = malloc(sizeof(Subscriber));
    strcpy(new_subscriber->name, name);
    strcpy(new_subscriber->email, email);
    subscribers[subscriber_count++] = new_subscriber;
    printf("The esteemed \"%s\" has been meticulously added to our list.\n", name);
}

void display_subscribers() {
    if (subscriber_count == 0) {
        printf("The list is currently empty, my dear Watson. No suspects here!\n");
        return;
    }
    printf("\nSuspects in the Mailing List:\n");
    for (int i = 0; i < subscriber_count; ++i) {
        printf("%d. %s - %s\n", i + 1, subscribers[i]->name, subscribers[i]->email);
    }
}

void remove_subscriber(int index) {
    if (index < 0 || index >= subscriber_count) {
        printf("A most peculiar choice! No such suspect found at index %d!\n", index);
        return;
    }
    printf("The suspect \"%s\" has been removed from our records.\n", subscribers[index]->name);
    free(subscribers[index]);
    for (int i = index; i < subscriber_count - 1; ++i) {
        subscribers[i] = subscribers[i + 1];
    }
    subscriber_count--;
}

void free_memory() {
    for (int i = 0; i < subscriber_count; ++i) {
        free(subscribers[i]);
    }
}

int main() {
    char name[NAME_LENGTH];
    char email[NAME_LENGTH];
    int choice, index;

    printf("Welcome to the Mailing List of Suspicious Characters!\n");
    while (1) {
        printf("\n1. Add Suspect\n");
        printf("2. Display Suspects\n");
        printf("3. Remove Suspect\n");
        printf("4. Exit\n");
        printf("Please choose your next course of action, dear Watson: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the suspect: ");
                scanf("%s", name);
                printf("Enter the email of the suspect: ");
                scanf("%s", email);
                add_subscriber(name, email);
                break;

            case 2:
                display_subscribers();
                break;

            case 3:
                printf("Enter the index of the suspect to remove: ");
                scanf("%d", &index);
                remove_subscriber(index - 1); // Adjust for zero-based index
                break;

            case 4:
                free_memory();
                printf("Goodbye, until the next case arises!\n");
                return 0;

            default:
                printf("That makes no sense! Please choose a valid option.\n");
        }
    }
}