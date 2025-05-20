//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function to check if the user is authorized to control the drone
int authenticate(char user_name[], char password[]) {
    if(strcmp(user_name, "admin") == 0 && strcmp(password, "1234") == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to send the commands to the drone's flight controller
void send_command(char command[]) {
    // Code to send command to the drone's flight controller
    printf("Command sent: %s\n", command);
}

int main() {
    char user_name[20];
    char password[20];
    int isAuthorized = 0;

    printf("Enter your username: ");
    scanf("%s", user_name);

    printf("Enter your password: ");
    scanf("%s", password);

    // Authenticate the user
    isAuthorized = authenticate(user_name, password);

    if(isAuthorized) {
        printf("Access granted.\n");

        // Start remote control session
        int session_active = 1;
        char command[50];

        while(session_active) {
            printf("Enter command (or 'exit' to end session): ");
            scanf("%s", command);

            if(strcmp(command, "exit") == 0) {
                session_active = 0;
            } else {
                // Send the command to the drone
                send_command(command);
            }
        }

        printf("Remote control session ended.\n");

    } else {
        printf("Access Denied.\n");
    }

    return 0;
}