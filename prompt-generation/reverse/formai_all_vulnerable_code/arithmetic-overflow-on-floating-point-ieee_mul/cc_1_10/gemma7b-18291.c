//Gemma-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, m, i, j, k, l;
    float x, y, z, p, q, r, s, t, u, v, w, h;

    printf("C Alien Invasion Probability Calculator\n");
    printf("------------------------\n");

    printf("Enter the number of aliens: ");
    scanf("%d", &n);

    printf("Enter the number of planets: ");
    scanf("%d", &m);

    printf("Enter the number of weapons: ");
    scanf("%d", &i);

    printf("Enter the alien invasion probability: ");
    scanf("%f", &p);

    printf("Enter the planet destruction probability: ");
    scanf("%f", &q);

    printf("Enter the weapon destruction probability: ");
    scanf("%f", &r);

    printf("Enter the number of alien spaceships: ");
    scanf("%d", &s);

    printf("Enter the number of planet shields: ");
    scanf("%d", &t);

    printf("Enter the number of weapon detonations: ");
    scanf("%d", &u);

    printf("Enter the alien spaceship speed: ");
    scanf("%f", &v);

    printf("Enter the planet shield strength: ");
    scanf("%f", &w);

    printf("Enter the weapon detonation strength: ");
    scanf("%f", &h);

    z = p * n * m * i * s * t * u;
    r = q * m * i * r;
    t = h * w * u;

    printf("The probability of an alien invasion is: %.2f%\n", z);
    printf("The probability of planet destruction is: %.2f%\n", r);
    printf("The probability of total destruction is: %.2f%\n", t);

    return 0;
}