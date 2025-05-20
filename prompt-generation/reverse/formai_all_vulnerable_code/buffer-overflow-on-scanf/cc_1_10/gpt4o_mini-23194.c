//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define G 9.81  // Gravity constant
#define PI 3.141592653589793

typedef struct {
    double x, y;
    double velocity;
    double angle;  // in radians
} Projectile;

void initialize_projectile(Projectile *p, double velocity, double angle) {
    p->x = 0.0;
    p->y = 0.0;
    p->velocity = velocity;
    p->angle = angle * (PI / 180.0); // Convert degrees to radians
}

void update_position(Projectile *p, double time) {
    p->x = p->velocity * cos(p->angle) * time;
    p->y = (p->velocity * sin(p->angle) * time) - (0.5 * G * time * time);
}

int check_ground_collision(Projectile *p) {
    return (p->y < 0);
}

void print_position(Projectile *p) {
    printf("Projectile Position: (x: %.2f, y: %.2f)\n", p->x, p->y);
}

void simulate_projectile_motion(double initial_velocity, double launch_angle, double time_step, double total_time) {
    Projectile p;
    initialize_projectile(&p, initial_velocity, launch_angle);
    
    double current_time = 0.0;
    while (current_time <= total_time) {
        update_position(&p, current_time);
        
        if (check_ground_collision(&p)) {
            printf("Projectile has hit the ground!\n");
            break;
        }
        
        print_position(&p);
        usleep(100000);  // Sleep for 100 milliseconds
        current_time += time_step;
    }
}

int main() {
    double initial_velocity, launch_angle, time_step, total_time;

    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &initial_velocity);

    printf("Enter launch angle (degrees): ");
    scanf("%lf", &launch_angle);

    printf("Enter time step for simulation (seconds): ");
    scanf("%lf", &time_step);

    printf("Enter total time for simulation (seconds): ");
    scanf("%lf", &total_time);

    if (initial_velocity <= 0 || launch_angle < 0 || launch_angle > 90 || time_step <= 0 || total_time <= 0) {
        printf("Please enter valid input values.\n");
        return 1;
    }

    simulate_projectile_motion(initial_velocity, launch_angle, time_step, total_time);

    return 0;
}