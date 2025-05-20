//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: imaginative
#include <stdio.h>

int main() {
    int battery_level = 100; // 100% battery at start
    int altitude = 0; // Drone's altitude
    int max_altitude = 100; // Maximum altitude allowed
    int speed = 0; // Speed of the drone in m/s
    int direction = 0; // 0 for north, 1 for east, 2 for south, 3 for west
    int rotation = 0; // 0 for no rotation, 1 for clockwise, -1 for counter-clockwise
    int connected = 0; // Connected to remote control or not
    int video_feed = 0; // 0 for off, 1 for on
    char cmd; // Command input

    printf("Welcome to Drone Remote Control Program!\n");
    printf("------------------------------------------\n");

    // Connect to remote control
    connected = 1;
    printf("Connected to remote control.\n");

    // Main control loop
    while (1) {
        printf("\n\n------------------------------------------\n");
        printf("Battery level: %d%%\n", battery_level);
        printf("Altitude: %d meters\n", altitude);
        printf("Speed: %d m/s\n", speed);
        printf("Direction: ");
        if (direction == 0) printf("North\n");
        else if (direction == 1) printf("East\n");
        else if (direction == 2) printf("South\n");
        else if (direction == 3) printf("West\n");
        printf("Rotation: ");
        if (rotation == 0) printf("No rotation\n");
        else if (rotation == 1) printf("Clockwise\n");
        else if (rotation == -1) printf("Counter-clockwise\n");
        printf("Video feed: ");
        if (video_feed) printf("On\n");
        else printf("Off\n");

        printf("\nPlease enter a command (WASDQEVT): ");
        scanf(" %c", &cmd);

        // Perform action based on command
        switch (cmd) {
            case 'W':
                altitude += 10; // Increase altitude by 10 meters
                if (altitude > max_altitude) altitude = max_altitude; // Limit altitude
                printf("Altitude increased to %d meters.\n", altitude);
                break;
            case 'A':
                direction -= 1; // Turn left (counter-clockwise)
                if (direction < 0) direction = 3; // Wrap around
                printf("Direction changed to ");
                if (direction == 0) printf("North.\n");
                else if (direction == 1) printf("East.\n");
                else if (direction == 2) printf("South.\n");
                else if (direction == 3) printf("West.\n");
                break;
            case 'S':
                altitude -= 10; // Decrease altitude by 10 meters
                if (altitude < 0) altitude = 0; // Don't go below ground
                printf("Altitude decreased to %d meters.\n", altitude);
                break;
            case 'D':
                direction += 1; // Turn right (clockwise)
                if (direction > 3) direction = 0; // Wrap around
                printf("Direction changed to ");
                if (direction == 0) printf("North.\n");
                else if (direction == 1) printf("East.\n");
                else if (direction == 2) printf("South.\n");
                else if (direction == 3) printf("West.\n");
                break;
            case 'Q':
                rotation = -1; // Start counter-clockwise rotation
                printf("Started counter-clockwise rotation.\n");
                break;
            case 'E':
                rotation = 1; // Start clockwise rotation
                printf("Started clockwise rotation.\n");
                break;
            case 'V':
                video_feed = !video_feed; // Toggle video feed on/off
                if (video_feed) printf("Video feed turned on.\n");
                else printf("Video feed turned off.\n");
                break;
            case 'T':
                speed += 5; // Increase speed by 5 m/s
                printf("Speed increased to %d m/s.\n", speed);
                break;
            case 'G':
                speed -= 5; // Decrease speed by 5 m/s
                if (speed < 0) speed = 0; // Don't go below 0 m/s
                printf("Speed decreased to %d m/s.\n", speed);
                break;
            default:
                printf("Invalid command!\n");
                break;
        }

        // Update battery level based on altitude and speed
        if (altitude > 50) battery_level -= 2; // Lose 2% battery per meter above 50 meters
        else if (altitude > 20) battery_level -= 1; // Lose 1% battery per meter above 20 meters
        if (speed > 20) battery_level -= 4; // Lose 4% battery per 5 m/s above 20 m/s
        else if (speed > 10) battery_level -= 2; // Lose 2% battery per 5 m/s above 10 m/s

        // Check if battery is dead
        if (battery_level <= 0) {
            printf("Battery dead! Drone landing...");
            break;
        }
    }

    // Disconnect from remote control
    connected = 0;
    printf("\n\nDisconnected from remote control.\n"); 
    return 0;
}