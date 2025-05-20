//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: futuristic
// Welcome to the Astral Odyssey, Pilot. Prepare your vessel for an otherworldly excursion.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defining the celestial vessel and its navigation parameters
typedef struct {
    float x, y, z;       // Position in the cosmic expanse (x, y, z)
    float rx, ry, rz;    // Orientation in celestial degrees (roll, pitch, yaw)
    float vx, vy, vz;    // Velocity in parsecs per stellar cycle (x, y, z)
} Drone;

// The console serves as our mission control center
int main() {
    // Let us initialize our astral vehicle
    Drone vessel = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // Behold, the cosmic navigation dashboard!
    while (1) {
        // Transmitting telemetry from the ethereal void
        printf("Position: %.2f, %.2f, %.2f parsecs\n", vessel.x, vessel.y, vessel.z);
        printf("Orientation: %.2f, %.2f, %.2f degrees\n", vessel.rx, vessel.ry, vessel.rz);
        printf("Velocity: %.2f, %.2f, %.2f parsecs/cycle\n", vessel.vx, vessel.vy, vessel.vz);

        // Receiving commands from the cosmic control center
        char command;
        printf("Enter command (W/S/A/D/Q/E/Z/X/C/V): ");
        scanf(" %c", &command);

        // Interpreting the pilot's celestial maneuvers
        switch (command) {
            case 'W': vessel.vz += 1; break;  // Throttle forward
            case 'S': vessel.vz -= 1; break;  // Throttle backward
            case 'A': vessel.vx -= 1; break;  // Strafe left
            case 'D': vessel.vx += 1; break;  // Strafe right
            case 'Q': vessel.ry -= 1; break;  // Pitch down
            case 'E': vessel.ry += 1; break;  // Pitch up
            case 'Z': vessel.rx -= 1; break;  // Roll left
            case 'X': vessel.rx += 1; break;  // Roll right
            case 'C': vessel.rz -= 1; break;  // Yaw left
            case 'V': vessel.rz += 1; break;  // Yaw right
        }

        // Advancing the vessel through the starlit expanse
        const float dt = 0.1;  // Time step (stellar cycles)
        vessel.x += vessel.vx * dt;
        vessel.y += vessel.vy * dt;
        vessel.z += vessel.vz * dt;
        vessel.rx += vessel.rx * dt;
        vessel.ry += vessel.ry * dt;
        vessel.rz += vessel.rz * dt;

        // Maintaining celestial equilibrium
        if (vessel.rx > 360) vessel.rx -= 360;
        else if (vessel.rx < 0) vessel.rx += 360;
        if (vessel.ry > 180) vessel.ry -= 180;
        else if (vessel.ry < -180) vessel.ry += 180;
        if (vessel.rz > 360) vessel.rz -= 360;
        else if (vessel.rz < 0) vessel.rz += 360;
    }
}