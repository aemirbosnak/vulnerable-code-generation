//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>

#define MAX_COMMAND_SIZE 100
#define DRONE_TAKEOFF "TAKEOFF"
#define DRONE_LAND "LAND"
#define DRONE_MOVE_FORWARD "FORWARD"
#define DRONE_MOVE_BACKWARD "BACKWARD"
#define DRONE_MOVE_LEFT "LEFT"
#define DRONE_MOVE_RIGHT "RIGHT"
#define DRONE_YAW_LEFT "YAW_LEFT"
#define DRONE_YAW_RIGHT "YAW_RIGHT"
#define DRONE_HOVER "HOVER"

void clear_terminal() {
    printf("\033[H\033[J"); // ANSI escape to clear the terminal
}

void display_menu() {
    clear_terminal();
    printf("---- Drone Remote Control ----\n");
    printf("Commands:\n");
    printf("1 - TAKEOFF\n");
    printf("2 - LAND\n");
    printf("3 - MOVE FORWARD\n");
    printf("4 - MOVE BACKWARD\n");
    printf("5 - TURN LEFT\n");
    printf("6 - TURN RIGHT\n");
    printf("7 - YAW LEFT\n");
    printf("8 - YAW RIGHT\n");
    printf("9 - HOVER\n");
    printf("0 - EXIT\n");
    printf("Select an action: ");
}

int getch(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void send_command(const char *command) {
    printf("Command Sent: %s\n", command);
}

int main() {
    int choice = -1;

    while (choice != 0) {
        display_menu();
        choice = getch() - '0'; // Convert char to int

        switch (choice) {
            case 1:
                send_command(DRONE_TAKEOFF);
                break;
            case 2:
                send_command(DRONE_LAND);
                break;
            case 3:
                send_command(DRONE_MOVE_FORWARD);
                break;
            case 4:
                send_command(DRONE_MOVE_BACKWARD);
                break;
            case 5:
                send_command(DRONE_MOVE_LEFT);
                break;
            case 6:
                send_command(DRONE_MOVE_RIGHT);
                break;
            case 7:
                send_command(DRONE_YAW_LEFT);
                break;
            case 8:
                send_command(DRONE_YAW_RIGHT);
                break;
            case 9:
                send_command(DRONE_HOVER);
                break;
            case 0:
                printf("Exiting remote control.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        if (choice != 0) {
            printf("Press any key to continue...\n");
            getch();
        }
    }

    return 0;
}