//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define G 6.6743E-11 // Gravitational constant

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 50

#define SUN_RADIUS 15 // in pixels
#define SUN_MASS 1.9885E30 // in kilograms
#define SUN_X SCREEN_WIDTH/2 // initial x position of sun
#define SUN_Y SCREEN_HEIGHT/2 // initial y position of sun

#define EARTH_RADIUS 5 // in pixels
#define EARTH_MASS 5.972E24 // in kilograms
#define EARTH_DISTANCE 150E9 // in meters
#define EARTH_VELOCITY 29.29E3 // in meters/second
#define EARTH_ANGLE M_PI // in radians

#define SCALE_FACTOR 1E-11 // pixels per meter

bool is_within_boundaries(int x, int y);
void draw(int x, int y, char character);

int main()
{
    srand(time(NULL));

    // Initialization of positions, velocities, and masses
    double sun_x = SUN_X, sun_y = SUN_Y, sun_vx = 0, sun_vy = 0, sun_mass = SUN_MASS;
    double earth_x = sun_x + EARTH_DISTANCE, earth_y = sun_y, earth_vx = 0, earth_vy = EARTH_VELOCITY, earth_mass = EARTH_MASS;

    // Calculation of initial forces between sun and earth
    double distance = sqrt(pow(earth_x - sun_x, 2) + pow(earth_y - sun_y, 2));
    double force = G * sun_mass * earth_mass / pow(distance, 2);
    double acceleration = force / earth_mass;
    double angle = atan2(earth_y - sun_y, earth_x - sun_x);
    double force_x = acceleration * cos(angle);
    double force_y = acceleration * sin(angle);

    // Simulation loop
    for (int i = 0; i < 1000000; i++)
    {
        // Calculation of sun's and earth's velocities and positions
        sun_vx += force_x / sun_mass;
        sun_vy += force_y / sun_mass;
        sun_x += sun_vx;
        sun_y += sun_vy;
        earth_vx += force_x / earth_mass;
        earth_vy += force_y / earth_mass;
        earth_x += earth_vx;
        earth_y += earth_vy;

        // Calculation of new force between sun and earth
        distance = sqrt(pow(earth_x - sun_x, 2) + pow(earth_y - sun_y, 2));
        force = G * sun_mass * earth_mass / pow(distance, 2);
        acceleration = force / earth_mass;
        angle = atan2(earth_y - sun_y, earth_x - sun_x);
        force_x = acceleration * cos(angle);
        force_y = acceleration * sin(angle);

        // Drawing the solar system
        for (int y = 0; y < SCREEN_HEIGHT; y++)
        {
            for (int x = 0; x < SCREEN_WIDTH; x++)
            {
                if (x == sun_x/SCALE_FACTOR && y == sun_y/SCALE_FACTOR)
                {
                    draw(x, y, 'O'); // Sun
                }
                else if (x == earth_x/SCALE_FACTOR && y == earth_y/SCALE_FACTOR)
                {
                    draw(x, y, '*'); // Earth
                }
                else
                {
                    draw(x, y, '.'); // Space
                }
            }
            printf("\n");
        }

        // Stopping the simulation if earth leaves the boundaries of the screen
        if (!is_within_boundaries(earth_x/SCALE_FACTOR, earth_y/SCALE_FACTOR))
        {
            break;
        }

        // Sleeping for a short time to slow down the simulation speed
        for (int j = 0; j < 100000000; j++);
    }

    return 0;
}

// Checks if a given x and y position is within the boundaries of the screen
bool is_within_boundaries(int x, int y)
{
    return x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT;
}

// Draws a given character at the given x and y position on the screen
void draw(int x, int y, char character)
{
    if (x == 0 && y == 0)
    {
        printf("+"); // Upper left corner
    }
    else if (x == SCREEN_WIDTH - 1 && y == 0)
    {
        printf("+"); // Upper right corner
    }
    else if (x == 0 && y == SCREEN_HEIGHT - 1)
    {
        printf("+"); // Lower left corner
    }
    else if (x == SCREEN_WIDTH - 1 && y == SCREEN_HEIGHT - 1)
    {
        printf("+"); // Lower right corner
    }
    else if (x == 0 || x == SCREEN_WIDTH - 1)
    {
        printf("|"); // Vertical border
    }
    else if (y == 0 || y == SCREEN_HEIGHT - 1)
    {
        printf("-"); // Horizontal border
    }
    else
    {
        printf("%c", character); // Normal character
    }
}