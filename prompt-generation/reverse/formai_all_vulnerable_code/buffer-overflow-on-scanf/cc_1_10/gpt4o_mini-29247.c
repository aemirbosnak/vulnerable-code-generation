//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_USERS 100
#define NAME_LENGTH 50

typedef struct {
    char username[NAME_LENGTH];
    time_t last_login;
} User;

User users[MAX_USERS];
int user_count = 0;

void addUser(const char *username) {
    if (user_count >= MAX_USERS) {
        printf("The garden of love is full, no more users can be added.\n");
        return;
    }

    strcpy(users[user_count].username, username);
    users[user_count].last_login = time(NULL);
    user_count++;
    printf("Oh, sweet %s, you've been welcomed into our garden of warmth and affection.\n", username);
}

void displayUsers() {
    printf("Here lies the list of beloved souls who have ventured into our digital embrace:\n");
    for (int i = 0; i < user_count; i++) {
        char login_time[26];
        ctime_r(&users[i].last_login, login_time);
        printf("User: %s, Last login: %s", users[i].username, login_time);
    }
}

void romanticDance() {
    printf("Ah, my dear, let us sway in rhythmic motions as we scan the cosmos!\n");
    for (int i = 3; i > 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }
    printf("The dance has unveiled a list of cherished users.\n");
}

void flowerOfLove() {
    printf("Sending love across the wires...\n");
    sleep(1);
    printf("Love sent and delivered!\n");
}

void romanticWhispers() {
    printf("Whisper your username into the serene abyss, and feel the magic of the moonlight:\n");
    char input[NAME_LENGTH];
    fgets(input, sizeof(input), stdin);
    strtok(input, "\n"); // Remove newline
    addUser(input);
}

void nightOfPassion() {
    printf("As the stars twinkle, we shall bask in the presence of our cherished users...\n");
    displayUsers();
}

int main() {
    printf("Welcome to our enchanting realm of system administration, where each user shines like a star!\n");

    while (1) {
        printf("\nChoose an action:\n");
        printf("1. Add a user\n");
        printf("2. Display users\n");
        printf("3. Romantic dance\n");
        printf("4. Send a flower of love\n");
        printf("5. Exit this digital Eden\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);
        getchar(); // consume newline after scanf

        switch (choice) {
            case 1:
                romanticWhispers();
                break;
            case 2:
                nightOfPassion();
                break;
            case 3:
                romanticDance();
                break;
            case 4:
                flowerOfLove();
                break;
            case 5:
                printf("Farewell, lover of code, may your heart always find joy in the embrace of technology.\n");
                exit(0);
            default:
                printf("Alas, an unknown path has been chosen, please try again.\n");
                break;
        }
    }

    return 0;
}