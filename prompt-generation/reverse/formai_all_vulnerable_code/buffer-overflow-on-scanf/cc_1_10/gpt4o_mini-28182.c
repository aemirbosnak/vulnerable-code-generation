//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>

#define G 9.81                 // Acceleration due to gravity (m/s^2)
#define TIMESTEP 0.01         // Time step for the simulation (seconds)
#define NUM_BODIES 5          // Number of bodies in the simulation
#define WINDOW_SIZE_X 100     // Size of simulated window in X-axis
#define WINDOW_SIZE_Y 100     // Size of simulated window in Y-axis
#define MAX_VELOCITY 100.0    // Max velocity of bodies

// Structure to represent a physical body in the simulation
typedef struct {
    double mass;              // Mass of the body (kg)
    double x;                 // X position
    double y;                 // Y position
    double vx;                // X velocity
    double vy;                // Y velocity
} Body;

// Array of bodies
Body bodies[NUM_BODIES];

// Function declarations
void initializeBodies();
void updatePositions();
void printState();
void* physicsLoop(void* arg);

// Main function
int main() {
    // Initialize simulation
    initializeBodies();

    // Create a thread for the physics simulation
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, physicsLoop, NULL);

    // Run the main loop for interaction (pause/exit)
    while(1) {
        char command;
        printf("Press 'p' to print state, 'q' to quit: ");
        scanf(" %c", &command);
        if (command == 'p') {
            printState();
        } else if (command == 'q') {
            break; // Exit loop and end program
        }
    }

    // Clean up and exit
    pthread_cancel(thread_id);
    pthread_join(thread_id, NULL);
    return 0;
}

// Function to initialize bodies with random parameters
void initializeBodies() {
    srand(time(NULL));  // Seed random number generator
    for (int i = 0; i < NUM_BODIES; i++) {
        bodies[i].mass = (rand() % 10 + 1); // Mass between 1 and 10 kg
        bodies[i].x = (rand() % WINDOW_SIZE_X); // Random X position
        bodies[i].y = (rand() % WINDOW_SIZE_Y); // Random Y position
        bodies[i].vx = (rand() % (int)MAX_VELOCITY) - MAX_VELOCITY / 2; // Random X velocity
        bodies[i].vy = (rand() % (int)MAX_VELOCITY) - MAX_VELOCITY / 2; // Random Y velocity
    }
}

// Function to update positions of bodies based on their velocity
void updatePositions() {
    for (int i = 0; i < NUM_BODIES; i++) {
        bodies[i].x += bodies[i].vx * TIMESTEP;
        bodies[i].y += bodies[i].vy * TIMESTEP;

        // Apply simple boundary conditions
        if (bodies[i].x < 0 || bodies[i].x > WINDOW_SIZE_X) {
            bodies[i].vx = -bodies[i].vx; // Reflect X velocity
        }
        if (bodies[i].y < 0 || bodies[i].y > WINDOW_SIZE_Y) {
            bodies[i].vy = -bodies[i].vy; // Reflect Y velocity
        }

        // Gravity effect on Y velocity
        bodies[i].vy -= G * TIMESTEP; // Update Y velocity due to gravity
    }
}

// Function to print the current state of bodies
void printState() {
    printf("\nCurrent State of Bodies:\n");
    for (int i = 0; i < NUM_BODIES; i++) {
        printf("Body %d: Mass=%.2f kg, Position=(%.2f, %.2f), Velocity=(%.2f, %.2f)\n",
               i, bodies[i].mass, bodies[i].x, bodies[i].y, bodies[i].vx, bodies[i].vy);
    }
    printf("\n");
}

// Function for physics loop (thread function)
void* physicsLoop(void* arg) {
    while (1) {
        updatePositions();
        usleep(10000); // Sleep for 10 milliseconds
    }
    return NULL;
}