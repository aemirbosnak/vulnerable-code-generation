//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define PI 3.14159
#define GRAVITY 9.81

typedef struct {
    float x;
    float y;
    float velocity;
    float angle; // In degrees
} Projectile;

void launchProjectile(Projectile *p) {
    float radianAngle = p->angle * (PI / 180.0);
    p->velocity = (p->velocity * cos(radianAngle));
    p->y = (p->velocity * sin(radianAngle));
}

void simulate(Projectile *p) {
    int time = 0;
    float dt = 0.1; // Small time intervals to make our simulation smoother

    printf("Time (s)\tX Position (m)\tY Position (m)\n");
    printf("----------------------------------------------------\n");

    while (p->y >= 0) {
        printf("%.2f\t\t%.2f\t\t%.2f\n", (float)time * dt, p->x, p->y);
        
        // Update position using basic kinematics
        p->y = (p->velocity * sin(p->angle * (PI / 180.0))) * (time * dt) - (0.5 * GRAVITY * (time * dt) * (time * dt));
        p->x = (p->velocity * cos(p->angle * (PI / 180.0))) * (time * dt);

        time++;
        usleep(100000); // Sleep for 0.1 seconds (100 ms)
    }

    printf("----------------------------------------------------\n");
    printf("The projectile hit the ground at %.2f meters!\n", p->x);
}

int main() {
    Projectile p;
    float launchSpeed;

    printf("Welcome to the Fun-tastic Projectile Launcher!\n");
    printf("We all know physics can be rough, but let's launch something instead!\n");

    printf("Enter the launch speed (in m/s): ");
    scanf("%f", &launchSpeed);
    p.velocity = launchSpeed;

    printf("Now make your angle legendary (in degrees, from 0 to 90): ");
    scanf("%f", &p.angle);

    printf("Hold onto your hats, folks! We're launching a projectile!\n");
    p.x = 0; 
    p.y = 0;

    launchProjectile(&p);
    simulate(&p);

    printf("And there you have it, folks! Remember, physics is just a way of having fun (and missing the target)!\n");

    return 0;
}