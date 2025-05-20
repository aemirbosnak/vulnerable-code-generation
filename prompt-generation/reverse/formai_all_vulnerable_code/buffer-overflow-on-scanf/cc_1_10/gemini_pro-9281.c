//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: excited
// Step into the world of smart home lighting like a boss!

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Our trusty light switch
int light_state = 0; // 0 for off, 1 for on

// Prepare for the lighting revolution!
void init_light() {
    printf("Initializing the lighting system...\n");
    printf("May the brilliance illuminate your home!\n");
}

// Toggle the light like a pro
void toggle_light() {
    light_state = !light_state;
    printf((light_state) ? "Let there be light! The room basks in radiance.\n" : "Darkness descends. The room retreats to slumber.\n");
}

// Set the light to your desired state
void set_light(int state) {
    light_state = state;
    printf((light_state) ? "Light activated. May your room glow with joy!\n" : "Light deactivated. Farewell, sweet illumination.\n");
}

// Respond to user commands with grace
void handle_command(char command) {
    switch (command) {
    case 'T':
        toggle_light();
        break;
    case 'O':
        set_light(1);
        break;
    case 'F':
        set_light(0);
        break;
    default:
        printf("Invalid command. Try again, my friend!\n");
    }
}

// The grand finale - our lighting extravaganza!
int main() {
    init_light(); // Prepare the stage for lighting wonders

    char command; // Ready to receive your lighting directives!

    while (1) {
        printf("Enter your lighting command (T for toggle, O for on, F for off): \n");
        scanf(" %c", &command); // Scan for the user's brilliant idea

        handle_command(command); // Execute the user's lighting wish

        sleep(1); // Give the system a moment to bask in the glow or darkness
    }

    return 0; // End the lighting adventure with a smile!
}