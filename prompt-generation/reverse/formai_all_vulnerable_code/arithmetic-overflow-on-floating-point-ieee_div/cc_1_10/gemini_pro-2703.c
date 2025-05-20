//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: unmistakable
#include <stdio.h>
#include <math.h>

// Define the gravitational constant
#define G 6.674e-11

// Define the mass of the Earth
#define M_EARTH 5.972e24

// Define the radius of the Earth
#define R_EARTH 6.371e6

// Define the time step
#define DT 1.0

// Define the number of planets
#define N_PLANETS 10

// Define the planet masses
double m_planets[N_PLANETS] = {
    1.0, // Mercury
    1.0, // Venus
    1.0, // Earth
    1.0, // Mars
    1.0, // Jupiter
    1.0, // Saturn
    1.0, // Uranus
    1.0, // Neptune
    1.0, // Pluto
    1.0  // Moon
};

// Define the planet positions
double x_planets[N_PLANETS][3] = {
    {0.0, 0.0, 0.0}, // Mercury
    {0.0, 0.0, 0.0}, // Venus
    {0.0, 0.0, 0.0}, // Earth
    {0.0, 0.0, 0.0}, // Mars
    {0.0, 0.0, 0.0}, // Jupiter
    {0.0, 0.0, 0.0}, // Saturn
    {0.0, 0.0, 0.0}, // Uranus
    {0.0, 0.0, 0.0}, // Neptune
    {0.0, 0.0, 0.0}, // Pluto
    {0.0, 0.0, 0.0}  // Moon
};

// Define the planet velocities
double v_planets[N_PLANETS][3] = {
    {0.0, 0.0, 0.0}, // Mercury
    {0.0, 0.0, 0.0}, // Venus
    {0.0, 0.0, 0.0}, // Earth
    {0.0, 0.0, 0.0}, // Mars
    {0.0, 0.0, 0.0}, // Jupiter
    {0.0, 0.0, 0.0}, // Saturn
    {0.0, 0.0, 0.0}, // Uranus
    {0.0, 0.0, 0.0}, // Neptune
    {0.0, 0.0, 0.0}, // Pluto
    {0.0, 0.0, 0.0}  // Moon
};

// Calculate the gravitational force between two planets
void calculate_force(double *f, double *r, double m1, double m2) {
    double r_mag = sqrt(r[0] * r[0] + r[1] * r[1] + r[2] * r[2]);
    double f_mag = G * m1 * m2 / (r_mag * r_mag);
    f[0] = f_mag * r[0] / r_mag;
    f[1] = f_mag * r[1] / r_mag;
    f[2] = f_mag * r[2] / r_mag;
}

// Update the planet positions and velocities
void update_planets(double dt) {
    // Calculate the gravitational forces between the planets
    for (int i = 0; i < N_PLANETS; i++) {
        for (int j = i + 1; j < N_PLANETS; j++) {
            double r[3] = {
                x_planets[j][0] - x_planets[i][0],
                x_planets[j][1] - x_planets[i][1],
                x_planets[j][2] - x_planets[i][2]
            };
            double f[3];
            calculate_force(f, r, m_planets[i], m_planets[j]);
            v_planets[i][0] += f[0] * dt / m_planets[i];
            v_planets[i][1] += f[1] * dt / m_planets[i];
            v_planets[i][2] += f[2] * dt / m_planets[i];
            v_planets[j][0] -= f[0] * dt / m_planets[j];
            v_planets[j][1] -= f[1] * dt / m_planets[j];
            v_planets[j][2] -= f[2] * dt / m_planets[j];
        }
    }

    // Update the planet positions
    for (int i = 0; i < N_PLANETS; i++) {
        x_planets[i][0] += v_planets[i][0] * dt;
        x_planets[i][1] += v_planets[i][1] * dt;
        x_planets[i][2] += v_planets[i][2] * dt;
    }
}

// Main function
int main() {
    // Simulate the planet motion for 1000 time steps
    for (int i = 0; i < 1000; i++) {
        update_planets(DT);
    }

    // Print the final planet positions
    for (int i = 0; i < N_PLANETS; i++) {
        printf("Planet %d: (%.2f, %.2f, %.2f)\n", i, x_planets[i][0], x_planets[i][1], x_planets[i][2]);
    }

    return 0;
}