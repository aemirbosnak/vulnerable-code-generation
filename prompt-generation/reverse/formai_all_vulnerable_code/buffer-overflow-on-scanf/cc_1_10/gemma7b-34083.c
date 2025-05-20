//Gemma-7B DATASET v1.0 Category: Physics simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int n, i, j, k, l, m, x, y, z, a, b, c, d, e, f, g, h, i1, i2, i3, j1, j2, j3, k1, k2, k3;

    printf("Enter the number of particles: ");
    scanf("%d", &n);

    // Allocate memory for the particles
    struct particle {
        int x, y, z;
        double mass;
    } *particles = (struct particle *)malloc(n * sizeof(struct particle));

    // Initialize the particles
    for (i = 0; i < n; i++)
    {
        particles[i].x = rand() % 1000;
        particles[i].y = rand() % 1000;
        particles[i].z = rand() % 1000;
        particles[i].mass = rand() % 1000;
    }

    // Calculate the force between two particles
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                x = particles[i].x - particles[j].x;
                y = particles[i].y - particles[j].y;
                z = particles[i].z - particles[j].z;

                a = x * x + y * y + z * z;
                b = sqrt(a);

                c = 1 / b;

                d = c * particles[i].mass * particles[j].mass;

                e = d * x;
                f = d * y;
                g = d * z;

                particles[i].x += e;
                particles[i].y += f;
                particles[i].z += g;
            }
        }
    }

    // Print the final positions of the particles
    for (i = 0; i < n; i++)
    {
        printf("Particle %d: (%d, %d, %d)\n", i + 1, particles[i].x, particles[i].y, particles[i].z);
    }

    // Free the memory allocated for the particles
    free(particles);

    return 0;
}