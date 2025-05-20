//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSCRIBERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
} Subscriber;

typedef struct {
    Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
} MailingList;

// Function prototypes
void addSubscriber(MailingList *list);
void removeSubscriber(MailingList *list);
void viewSubscribers(MailingList *list);
void clearBuffer();

int main() {
    MailingList catLoversList;
    catLoversList.count = 0;
    int choice;

    printf("Welcome to the Totally Serious Cats Lovers Mailing List Manager!\n");
    printf("1. Add a Subscriber\n");
    printf("2. Remove a Subscriber\n");
    printf("3. View Subscribers\n");
    printf("4. Exit (but we'll still be watching you...)\n");

    do {
        printf("Please enter your choice (1-4): ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addSubscriber(&catLoversList);
                break;
            case 2:
                removeSubscriber(&catLoversList);
                break;
            case 3:
                viewSubscribers(&catLoversList);
                break;
            case 4:
                printf("Thanks for using the Totally Serious Cats Lovers Mailing List Manager!\n");
                printf("Remember, cats are watching you even now...\n");
                break;
            default:
                printf("Oops! It seems like your choice went on a cat nap. Try again!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addSubscriber(MailingList *list) {
    if (list->count >= MAX_SUBSCRIBERS) {
        printf("Meow! It seems we have too many cat enthusiasts. Cannot add more!\n");
        return;
    }
    
    printf("Enter the name of the new subscriber (max %d characters): ", NAME_LENGTH - 1);
    fgets(list->subscribers[list->count].name, NAME_LENGTH, stdin);
    list->subscribers[list->count].name[strcspn(list->subscribers[list->count].name, "\n")] = '\0'; // Remove newline
    printf("Cat-astrophic! %s has been added to the list!\n", list->subscribers[list->count].name);
    list->count++;
}

void removeSubscriber(MailingList *list) {
    if (list->count == 0) {
        printf("No subscribers to remove! Even the cats are sad...\n");
        return;
    }

    viewSubscribers(list);
    
    printf("Enter the number of the subscriber to remove (1 to %d): ", list->count);
    int index;
    scanf("%d", &index);
    clearBuffer();

    if (index < 1 || index > list->count) {
        printf("That number is as lost as a cat in a car dealership!\n");
        return;
    }

    printf("Goodbye %s! We hope to see you meow again!\n", list->subscribers[index - 1].name);
    for (int i = index - 1; i < list->count - 1; i++) {
        list->subscribers[i] = list->subscribers[i + 1]; // Shift left
    }
    list->count--;
}

void viewSubscribers(MailingList *list) {
    if (list->count == 0) {
        printf("Our mailing list is empty... just like my soul after watching a sad cat video.\n");
        return;
    }

    printf("\nCurrent Subscribers to the Totally Serious Cats Lovers Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->subscribers[i].name);
    }
    printf("\n");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}