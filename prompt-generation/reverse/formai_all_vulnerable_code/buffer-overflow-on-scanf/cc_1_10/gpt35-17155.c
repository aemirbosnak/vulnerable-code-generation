//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLANET_NAME 20
#define MAX_MSG_LENGTH 100

char name[MAX_PLANET_NAME];
char message[MAX_MSG_LENGTH];

void display_intro() {
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("What's your name, adventurer? ");
    scanf("%s", name);
    printf("Nice to meet you, %s!\n", name);
    printf("You have been selected for a mission to explore a planet in a distant galaxy.\n");
    printf("Are you ready to embark on this adventure? (y/n) ");
    char answer;
    scanf(" %c", &answer);
    if (answer == 'y' || answer == 'Y') {
        printf("Great! Let's blast off!\n");
    } else {
        printf("I'm sorry to hear that. Perhaps another time.\n");
        exit(0);
    }
}

char* get_random_message() {
    char* messages[] = {
        "This planet looks fascinating!",
        "I'm detecting strange readings on my scanner.",
        "Wow, this place is more beautiful than I expected.",
        "I need to be careful not to get lost in this vast terrain.",
        "I hope I can find some valuable resources here.",
        "The gravity on this planet is significantly stronger than on Earth.",
        "I'm picking up some unusual activity in the distance.",
        "I wonder if there are any intelligent beings on this planet.",
        "The atmosphere here is unlike anything I've ever encountered.",
        "I'm running low on supplies. I need to find a way to replenish them."
    };
    int num_messages = sizeof(messages) / sizeof(char*);
    int rand_index = rand() % num_messages;
    return messages[rand_index];
}

void display_message() {
    strcpy(message, get_random_message());
    printf("%s\n", message);
}

void navigate() {
    printf("Which direction would you like to explore?\n");
    printf("1. North\n");
    printf("2. South\n");
    printf("3. East\n");
    printf("4. West\n");
    printf("5. Stay put\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Heading North...\n");
            break;
        case 2:
            printf("Heading South...\n");
            break;
        case 3:
            printf("Heading East...\n");
            break;
        case 4:
            printf("Heading West...\n");
            break;
        case 5:
            printf("Staying put...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
            navigate();
            break;
    }
}

void perform_action() {
    printf("What would you like to do?\n");
    printf("1. Collect samples\n");
    printf("2. Repair equipment\n");
    printf("3. Take a break\n");
    printf("4. Continue exploring\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Collecting samples...\n");
            break;
        case 2:
            printf("Repairing equipment...\n");
            break;
        case 3:
            printf("Taking a break...\n");
            break;
        case 4:
            printf("Continuing exploring...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
            perform_action();
            break;
    }
}

void display_outro() {
    printf("That was a successful mission, %s!\n", name);
    printf("You have discovered some valuable resources and valuable data about the planet.\n");
    printf("Thank you for participating in this Procedural Space Adventure!\n");
}

int main() {
    display_intro();
    while (1) {
        display_message();
        navigate();
        perform_action();
        printf("------------------------------\n");
        printf("Press any key to continue...\n");
        char pause;
        scanf(" %c", &pause);
    }
    display_outro();
    return 0;
}