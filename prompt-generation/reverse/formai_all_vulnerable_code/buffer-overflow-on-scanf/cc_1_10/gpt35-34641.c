//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int battery_level;
    int flight_time;
    int signal_strength;
} DroneStatus;

typedef struct {
    int x;
    int y;
    int z;
} Position;

typedef struct {
    int throttle; // 0 to 100
    int roll;     // -100 to 100
    int pitch;    // -100 to 100
    int yaw;      // -100 to 100
} ControlSignal;

// Function to get the drone status
DroneStatus get_drone_status() {
    DroneStatus status = {rand() % 101, rand() % 61, rand() % 101};
    return status;
}

// Function to set the drone's position
void set_drone_position(Position pos) {
    printf("Setting drone position to: (%d, %d, %d)\n", pos.x, pos.y, pos.z);
}

// Function to send control signal to the drone
void send_control_signal(ControlSignal signal) {
    printf("Sending control signal: {throttle:%d, roll:%d, pitch:%d, yaw:%d}\n",
            signal.throttle, signal.roll, signal.pitch, signal.yaw);
}

int main() {
    printf("Welcome to C Drone Remote Control\n");
    
    // Get initial drone status
    DroneStatus status = get_drone_status();
    printf("Battery Level: %d%%\nFlight Time: %d min\nSignal Strength: %d%%\n",
            status.battery_level, status.flight_time, status.signal_strength);
    
    // Set initial drone position
    Position initial_pos = {0, 0, 0};
    set_drone_position(initial_pos);
    
    // Loop to get user input and send control signals to the drone
    int quit = 0;
    while (!quit) {
        // Get user input
        int throttle, roll, pitch, yaw;
        printf("Enter control signals (throttle roll pitch yaw) or 'q' to quit: ");
        int input_count = scanf("%d %d %d %d", &throttle, &roll, &pitch, &yaw);
        
        // If user entered invalid input or 'q' to quit
        if (input_count != 4 || getchar() == 'q') {
            quit = 1;
            printf("Quitting...\n");
            continue;
        }
        
        // Make sure control signal values are within range
        if (throttle < 0) throttle = 0;
        else if (throttle > 100) throttle = 100;
        if (roll < -100) roll = -100;
        else if (roll > 100) roll = 100;
        if (pitch < -100) pitch = -100;
        else if (pitch > 100) pitch = 100;
        if (yaw < -100) yaw = -100;
        else if (yaw > 100) yaw = 100;
        
        // Send control signals to the drone
        ControlSignal signal = {throttle, roll, pitch, yaw};
        send_control_signal(signal);
    }
    
    return 0;
}