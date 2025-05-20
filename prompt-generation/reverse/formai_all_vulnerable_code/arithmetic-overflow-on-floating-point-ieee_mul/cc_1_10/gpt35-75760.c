//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11
#define solar_mass 1.989e30

typedef struct
{
    double x, y;
} vector;

typedef struct
{
    vector position, velocity;
    double mass;
} body;

vector add(vector a, vector b)
{
    vector result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

vector subtract(vector a, vector b)
{
    vector result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

vector multiply(double k, vector a)
{
    vector result;
    result.x = k * a.x;
    result.y = k * a.y;
    return result;
}

double length(vector a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

void update(body *bodies, int num_bodies, double time_step)
{
    int i, j;
    for (i = 0; i < num_bodies; i++)
    {
        vector acceleration = {0};
        body body1 = bodies[i];

        for (j = 0; j < num_bodies; j++)
        {
            if (i == j)
                continue;

            body body2 = bodies[j];
            vector direction = subtract(body2.position, body1.position);
            double distance = length(direction);
            double force_magnitude = G * body1.mass * body2.mass / (distance * distance + 1e5); 
            vector force = multiply(force_magnitude / distance, direction);
            acceleration = add(acceleration, multiply(1. / body1.mass, force));
        }

        bodies[i].position = add(body1.position, multiply(time_step, body1.velocity));
        bodies[i].velocity = add(body1.velocity, multiply(time_step, acceleration));
    }
}

int main()
{
    int i, num_bodies;
    double time_step;
    printf("Enter the number of bodies: ");
    scanf("%d", &num_bodies);

    body *bodies = (body *)malloc(num_bodies * sizeof(body));
    for (i = 0; i < num_bodies; i++)
    {
        printf("Enter the mass of the body %d (in solar masses): ", i + 1);
        scanf("%lf", &bodies[i].mass);
        printf("Enter the position of the body %d (x, y): ", i + 1);
        scanf("%lf %lf", &bodies[i].position.x, &bodies[i].position.y);
        printf("Enter the velocity of the body %d (x, y): ", i + 1);
        scanf("%lf %lf", &bodies[i].velocity.x, &bodies[i].velocity.y);
        bodies[i].mass *= solar_mass;
    }
    printf("Enter the time step (in seconds): ");
    scanf("%lf", &time_step);

    while (1)
    {
        printf("\n");
        for (i = 0; i < num_bodies; i++)
        {
            printf("Body %d:\n", i + 1);
            printf("\tMass: %.2e kg\n", bodies[i].mass);
            printf("\tPosition: (%.2e, %.2e) m\n", bodies[i].position.x, bodies[i].position.y);
            printf("\tVelocity: (%.2e, %.2e) m/s\n", bodies[i].velocity.x, bodies[i].velocity.y);
            printf("\n");
        }
        update(bodies, num_bodies, time_step);

        printf("Enter any key to continue or enter q to quit: ");
        char c = getchar();     
        if (c == 'q')
            break;
    }

    free(bodies);
    return 0;
}