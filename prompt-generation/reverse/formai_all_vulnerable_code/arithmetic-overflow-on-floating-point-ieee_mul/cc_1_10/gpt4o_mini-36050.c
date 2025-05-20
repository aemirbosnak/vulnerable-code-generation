//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: medieval
#include <stdio.h>
#include <math.h>

#define G 9.81 // Gravitational acceleration in medieval units
#define PI 3.14159
#define MAX_PROJECTILES 100
#define TIME_STEP 0.1
#define SIMULATION_TIME 10.0

typedef struct {
    double x;       // Horizontal position
    double y;       // Vertical position
    double velocity; // Current speed
    double angle;   // Launch angle
    double time;    // Duration of flight
} Projectile;

void initialize_projectile(Projectile* p, double velocity, double angle) {
    p->x = 0.0; // Starting position
    p->y = 0.0; // Starting position
    p->velocity = velocity; // Initial speed
    p->angle = angle * (PI / 180); // Convert angle to radians
    p->time = 0.0; // Time initially set to zero
}

void simulate_projectile(Projectile* p) {
    while (p->time <= SIMULATION_TIME) {
        // Update positions
        p->x = p->velocity * cos(p->angle) * p->time; // Horizontal position
        p->y = (p->velocity * sin(p->angle) * p->time) - (0.5 * G * p->time * p->time); // Vertical position

        // Print the current state of the projectile
        printf("Time: %.2f s | Position: (%.2f, %.2f) m\n", p->time, p->x, p->y);
        
        // Increment time
        p->time += TIME_STEP;

        // Break if the projectile hits the ground
        if (p->y < 0) {
            printf("The projectile has hit the ground!\n");
            break;
        }
    }
}

int main() {
    Projectile projectiles[MAX_PROJECTILES];
    int projectile_count;
    
    printf("Welcome to the Medieval Projectile Simulator!\n");
    
    // Get number of projectiles to simulate
    printf("Enter the number of projectiles to launch (max %d): ", MAX_PROJECTILES);
    scanf("%d", &projectile_count);
    
    if (projectile_count > MAX_PROJECTILES) {
        projectile_count = MAX_PROJECTILES;
        printf("Reducing number of projectiles to %d.\n", MAX_PROJECTILES);
    }
    
    for (int i = 0; i < projectile_count; i++) {
        double velocity, angle;
        printf("Enter velocity (m/s) for projectile %d: ", i + 1);
        scanf("%lf", &velocity);
        printf("Enter launch angle (degrees) for projectile %d: ", i + 1);
        scanf("%lf", &angle);
        
        // Initialize projectile
        initialize_projectile(&projectiles[i], velocity, angle);
        
        // Simulate the projectile
        printf("\nSimulating Projectile %d:\n", i + 1);
        simulate_projectile(&projectiles[i]);
        printf("\n");
    }
    
    printf("All simulations completed! Farewell brave knight!\n");
    return 0;
}