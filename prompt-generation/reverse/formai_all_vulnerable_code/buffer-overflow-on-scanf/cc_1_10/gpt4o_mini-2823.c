//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A fun and cheerful program to manage a party of friends!

typedef struct {
    char name[50];
    int age;
} Friend;

// Function prototypes
void welcome();
void addFriend(Friend **friends, int *count);
void listFriends(Friend *friends, int count);
void freeMemory(Friend *friends);

int main() {
    welcome();

    int count = 0;
    int capacity = 2; // Start with space for two friends
    Friend *friends = malloc(capacity * sizeof(Friend));

    if (friends == NULL) {
        printf("Oops! Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    char choice;

    do {
        printf("\nWhat would you like to do?\n");
        printf("a: Add a friend\n");
        printf("l: List friends\n");
        printf("q: Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                if (count == capacity) {
                    // We need more space!
                    capacity *= 2;
                    friends = realloc(friends, capacity * sizeof(Friend));
                    if (friends == NULL) {
                        printf("Oops! Memory reallocation failed!\n");
                        return 1; // Exit if reallocation fails
                    }
                }
                addFriend(&friends, &count);
                break;
            case 'l':
                listFriends(friends, count);
                break;
            case 'q':
                printf("Thank you for visiting the friends party!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 'q');

    freeMemory(friends);
    return 0;
}

void welcome() {
    printf("🎉 Welcome to the Friends Party Memory Manager! 🎉\n");
    printf("Here, we manage our friends' details with love and joy! 😄\n");
}

void addFriend(Friend **friends, int *count) {
    printf("\nLet's add a new friend! 🎈\n");
    printf("Enter friend name: ");
    scanf(" %[^\n]", (*friends)[*count].name); // Read string with spaces
    printf("Enter friend age: ");
    scanf("%d", &(*friends)[*count].age);

    printf("🐣 Hooray! You've added %s, age %d 😊\n", (*friends)[*count].name, (*friends)[*count].age);
    (*count)++;
}

void listFriends(Friend *friends, int count) {
    if (count == 0) {
        printf("🎃 No friends to show! Let's invite someone! 💌\n");
        return;
    }

    printf("\n🎊 Here's the list of awesome friends! 🎊\n");
    for (int i = 0; i < count; i++) {
        printf("Friend %d: %s, Age: %d\n", i + 1, friends[i].name, friends[i].age);
    }
}

void freeMemory(Friend *friends) {
    free(friends);
    printf("🎈 All memory has been freed! Until next time at the party! 🎉\n");
}