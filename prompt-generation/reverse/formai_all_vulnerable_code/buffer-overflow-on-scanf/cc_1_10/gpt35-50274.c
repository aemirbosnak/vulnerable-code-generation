//FormAI DATASET v1.0 Category: Smart home light control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function prototypes */
void login();
void add_user();
void remove_user();
void turn_on_light();
void turn_off_light();
void change_brightness();

/* global variables */
char username[20];
char password[20];
int brightness = 0;
int isLightOn = 0;
int num_users = 0;

/* set up user struct */
struct user {
    char username[20];
    char password[20];
};

/* initialize users */
struct user users[10] = {
    {"admin", "1234"}
};

/* main function */
int main() {
    int opt;

    printf("Welcome to Smart Home Light Control System!\n\n");

    login(); // authenticate user

    while (1) {
        printf("\n");
        printf("Please select an option below:\n");
        printf("1. Add User\n");
        printf("2. Remove User\n");
        printf("3. Turn On Light\n");
        printf("4. Turn Off Light\n");
        printf("5. Change Brightness\n");
        printf("6. Exit\n");

        scanf("%d", &opt);

        switch (opt) {
            case 1:
                add_user();
                break;
            case 2:
                remove_user();
                break;
            case 3:
                turn_on_light();
                break;
            case 4:
                turn_off_light();
                break;
            case 5:
                change_brightness();
                break;
            case 6:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please choose again.\n");
        }
    }

    return 0;
}

/* authenticate user */
void login() {
    int found = 0;

    while (!found) {
        printf("Username: ");
        scanf("%s", username);

        printf("Password: ");
        scanf("%s", password);

        for (int i = 0; i < 10; i++) {
            if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
                printf("\nWelcome, %s!\n\n", username);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Invalid username and/or password. Please try again.\n");
        }
    }
}

/* add user */
void add_user() {
    if (num_users == 10) {
        printf("Maximum number of users reached.\n");
        return;
    }

    struct user new_user;

    printf("Enter new username: ");
    scanf("%s", new_user.username);

    printf("Enter new password: ");
    scanf("%s", new_user.password);

    users[num_users] = new_user;
    num_users++;

    printf("\nUser added successfully!\n");
}

/* remove user */
void remove_user() {
    int found = 0;
    char target_user[20];

    printf("Enter username to remove: ");
    scanf("%s", target_user);

    for (int i = 0; i < 10; i++) {
        if (strcmp(users[i].username, target_user) == 0) {
            // shift all users after the removed user to fill in the gap
            for (int j = i; j < 9; j++) {
                users[j] = users[j+1];
            }

            num_users--;
            found = 1;
            printf("\nUser removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("User not found.\n");
    }
}

/* turn on light */
void turn_on_light() {
    if (isLightOn) {
        printf("Light is already turned on.\n");
    } else {
        isLightOn = 1;
        printf("Light turned on.\n");
    }
}

/* turn off light */
void turn_off_light() {
    if (!isLightOn) {
        printf("Light is already turned off.\n");
    } else {
        isLightOn = 0;
        printf("Light turned off.\n");
    }
}

/* change brightness */
void change_brightness() {
    int new_brightness;

    printf("Enter new brightness level (0-100): ");
    scanf("%d", &new_brightness);

    if (new_brightness < 0 || new_brightness > 100) {
        printf("Invalid brightness level. Please enter a value between 0 and 100.\n");
        return;
    }

    brightness = new_brightness;
    printf("\nBrightness level changed successfully!\n");
}