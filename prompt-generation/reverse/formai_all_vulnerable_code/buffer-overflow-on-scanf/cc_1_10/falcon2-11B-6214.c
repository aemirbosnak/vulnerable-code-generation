//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void medieval_greeting();
void add_user(char* name);
void remove_user(char* name);
void display_list();
void goodbye();

int main() {
    medieval_greeting();
    int choice = 0;
    while (choice!= 3) {
        printf("What would you like to do?\n");
        printf("1. Add a user to the list\n");
        printf("2. Remove a user from the list\n");
        printf("3. Display the list of users\n");
        printf("4. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_user(malloc(20));
                break;
            case 2:
                remove_user(malloc(20));
                break;
            case 3:
                display_list();
                break;
            case 4:
                goodbye();
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    goodbye();
    return 0;
}

void medieval_greeting() {
    printf("Greetings, noble traveler! Welcome to the realm of the mighty.\n");
}

void add_user(char* name) {
    printf("What is the name of the user you wish to add?\n");
    scanf("%s", name);
    printf("Welcome, %s!\n", name);
}

void remove_user(char* name) {
    printf("What is the name of the user you wish to remove?\n");
    scanf("%s", name);
    printf("Farewell, %s!\n", name);
}

void display_list() {
    char* list[] = {"Sir William", "Lady Jane", "Sir Thomas", "Lady Margaret"};
    int num_users = sizeof(list) / sizeof(list[0]);
    printf("Here is the list of users:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s\n", list[i]);
    }
}

void goodbye() {
    printf("Farewell, noble traveler. May your journey be safe and your deeds be remembered.\n");
}