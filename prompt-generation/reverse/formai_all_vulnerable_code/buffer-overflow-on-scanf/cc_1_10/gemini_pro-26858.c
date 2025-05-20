//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: visionary
// Immersive GPS Navigation Simulation: Embark on a Visionary Journey

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

// GPS Coordinates
#define LATITUDE 0.0
#define LONGITUDE 0.0

// User Interface Colors
#define COLOR_DEFAULT "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"

// ASCII Art Objects
#define CAR "🚗"
#define ROAD "🛣"
#define DESTINATION "🏁"

// Terminal Size
#define TERMINAL_WIDTH 80
#define TERMINAL_HEIGHT 24

// Navigation Variables
int current_lat = LATITUDE;
int current_lon = LONGITUDE;
int destination_lat;
int destination_lon;
int distance = 0;
int speed = 0;

// User Input Variables
int input = 0;

// Function Declarations
void initialize_terminal();
void reset_terminal();
void draw_screen();
void update_navigation();
int get_user_input();

int main() {
    // Initialize terminal for full-screen navigation
    initialize_terminal();

    // Set destination coordinates
    printf("Enter destination latitude: ");
    scanf("%d", &destination_lat);
    printf("Enter destination longitude: ");
    scanf("%d", &destination_lon);

    // Start navigation loop
    while (current_lat != destination_lat || current_lon != destination_lon) {
        // Update navigation
        update_navigation();

        // Draw screen
        draw_screen();

        // Check for user input
        input = get_user_input();

        // Handle user input
        switch (input) {
            case 'w':
                speed += 1;
                break;
            case 's':
                speed -= 1;
                break;
            case 'a':
                current_lon -= 1;
                break;
            case 'd':
                current_lon += 1;
                break;
            case 'q':
                exit(0);
                break;
            default:
                break;
        }
    }

    // Arrived at destination
    printf("\nYou have arrived at your destination!\n");

    // Reset terminal
    reset_terminal();

    return 0;
}

// Initialize terminal for full-screen navigation
void initialize_terminal() {
    struct termios terminal;
    tcgetattr(STDIN_FILENO, &terminal);
    terminal.c_lflag &= ~(ICANON | ECHO);
    terminal.c_cc[VMIN] = 0;
    terminal.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &terminal);
}

// Reset terminal to default settings
void reset_terminal() {
    struct termios terminal;
    tcgetattr(STDIN_FILENO, &terminal);
    terminal.c_lflag |= (ICANON | ECHO);
    terminal.c_cc[VMIN] = 1;
    terminal.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &terminal);
}

// Draw the navigation screen
void draw_screen() {
    // Clear the screen
    printf("\033[2J\033[H");

    // Draw the road
    for (int i = 0; i < TERMINAL_WIDTH; i++) {
        printf(ROAD);
    }

    // Draw the car
    int car_position = (current_lon * TERMINAL_WIDTH) / (destination_lon - current_lon);
    printf("\033[%d;%dH", car_position, 1);
    printf(COLOR_RED "%s" COLOR_DEFAULT, CAR);

    // Draw the destination
    int destination_position = (destination_lon * TERMINAL_WIDTH) / (destination_lon - current_lon);
    printf("\033[%d;%dH", destination_position, 1);
    printf(COLOR_YELLOW "%s" COLOR_DEFAULT, DESTINATION);

    // Draw navigation information
    printf("\033[%d;%dH", 0, 0);
    printf(COLOR_BLUE "Latitude: %d, Longitude: %d, Distance: %d, Speed: %d" COLOR_DEFAULT, current_lat, current_lon, distance, speed);
}

// Update the navigation variables
void update_navigation() {
    // Calculate distance
    distance = abs(destination_lat - current_lat) + abs(destination_lon - current_lon);

    // Update speed
    speed = distance / 10;
}

// Get user input
int get_user_input() {
    int c = getchar();
    if (c == -1) {
        return 0;
    } else {
        return c;
    }
}