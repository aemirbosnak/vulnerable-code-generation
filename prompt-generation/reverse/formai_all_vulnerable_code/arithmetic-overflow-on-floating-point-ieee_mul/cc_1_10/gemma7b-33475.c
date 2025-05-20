//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024

int main()
{
    int i, j, k, n, m, r, c, a, b;
    float x, y, z, v, w, R, L, C, G;
    char str[MAX];

    printf("Enter the number of circuits: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the circuit name: ");
        scanf("%s", str);

        printf("Enter the resistance (R) in ohms: ");
        scanf("%f", &R);

        printf("Enter the inductance (L) in henrys: ");
        scanf("%f", &L);

        printf("Enter the capacitance (C) in farads: ");
        scanf("%f", &C);

        printf("Enter the gain (G) of the amplifier: ");
        scanf("%f", &G);

        // Calculate the time constant (tau)
        x = R * L;
        y = C * G;
        z = x * y;

        // Calculate the frequency of oscillation (fo)
        v = 1 / (2 * M_PI * z);

        // Print the results
        printf("Circuit name: %s\n", str);
        printf("Resistance (R): %f ohms\n", R);
        printf("Inductance (L): %f henrys\n", L);
        printf("Capacitance (C): %f farads\n", C);
        printf("Gain (G): %f\n", G);
        printf("Time constant (tau): %f seconds\n", x);
        printf("Frequency of oscillation (fo): %f Hz\n", v);
        printf("\n");
    }

    return 0;
}