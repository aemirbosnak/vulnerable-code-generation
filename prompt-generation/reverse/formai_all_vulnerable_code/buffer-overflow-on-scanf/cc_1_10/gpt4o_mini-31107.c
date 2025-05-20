//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FRIENDS 100
#define NAME_LENGTH 50

// Define a structure for a Friend
typedef struct Friend {
    char name[NAME_LENGTH];
    int age;
} Friend;

// Declare an array to hold friends
Friend friends[MAX_FRIENDS];
int friend_count = 0;

// Function prototypes
void add_friend();
void view_friends();
void delete_friend();
void surprise_greeting();

int main() {
    int choice;

    printf("🎉 Welcome to the Happy Friends Database! 🎉\n");
    
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add a Friend\n");
        printf("2. View Friends\n");
        printf("3. Delete a Friend\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        getchar(); // Clean the newline from the buffer

        switch (choice) {
            case 1:
                add_friend();
                break;
            case 2:
                view_friends();
                break;
            case 3:
                delete_friend();
                break;
            case 4:
                printf("🌈 Thank you for using the Happy Friends Database! Goodbye! 🌈\n");
                exit(0);
            default:
                printf("❌ Invalid choice. Please try again! ❌\n");
        }
    }
    return 0;
}

void add_friend() {
    if (friend_count >= MAX_FRIENDS) {
        printf("😢 Oh no! The database is full! Can't add more friends! 😢\n");
        return;
    }

    Friend new_friend;
    printf("Enter the friend's name: ");
    fgets(new_friend.name, NAME_LENGTH, stdin);
    new_friend.name[strcspn(new_friend.name, "\n")] = '\0'; // Remove the newline character

    printf("Enter the friend's age: ");
    scanf("%d", &new_friend.age);
    getchar(); // Clean the newline from the buffer

    friends[friend_count++] = new_friend;

    surprise_greeting();
    printf("🎈 Friend added: %s, Age: %d 🎈\n", new_friend.name, new_friend.age);
}

void view_friends() {
    if (friend_count == 0) {
        printf("😞 No friends in the database! Add some friends! 😞\n");
        return;
    }

    printf("🌟 Here are your friends! 🌟\n");
    for (int i = 0; i < friend_count; i++) {
        printf("%d. %s, Age: %d\n", i + 1, friends[i].name, friends[i].age);
    }
}

void delete_friend() {
    if (friend_count == 0) {
        printf("😞 No friends to delete! Add some friends first! 😞\n");
        return;
    }

    int index;
    view_friends();

    printf("Enter the number of the friend you want to delete: ");
    scanf("%d", &index);
    getchar(); // Clean the newline from the buffer

    if (index < 1 || index > friend_count) {
        printf("❌ Invalid number. Please try again! ❌\n");
        return;
    }

    // Shift friends down to delete the specified friend
    for (int i = index - 1; i < friend_count - 1; i++) {
        friends[i] = friends[i + 1];
    }
    friend_count--;

    surprise_greeting();
    printf("🎉 Friend deleted! You've made room for more friendships! 🎉\n");
}

void surprise_greeting() {
    printf("🎊 Surprise! You are a wonderful friend! 🎊\n");
}