//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: medieval
#include <stdio.h>
#include <math.h>

int main()
{
    // Define constants
    const double G = 6.67430e-11;
    const double M_sun = 1.989e30;
    const double M_mercury = 3.285e23;
    const double M_venus = 4.867e24;
    const double M_earth = 5.972e24;
    const double M_mars = 6.39e23;
    const double M_jupiter = 1.898e27;
    const double M_saturn = 5.683e26;
    const double M_uranus = 8.681e25;
    const double M_neptune = 1.024e26;
    const double M_pluto = 1.309e22;
    const double R_sun = 695.7e6;
    const double R_mercury = 2.439e6;
    const double R_venus = 6.052e6;
    const double R_earth = 6.371e6;
    const double R_mars = 3.390e6;
    const double R_jupiter = 69.911e6;
    const double R_saturn = 60.268e6;
    const double R_uranus = 25.559e6;
    const double R_neptune = 24.764e6;
    const double R_pluto = 1.188e6;
    const double AU = 1.496e11;
    const double year = 3600 * 24 * 365;

    // Define variables
    double x_sun, y_sun, z_sun, vx_sun, vy_sun, vz_sun;
    double x_mercury, y_mercury, z_mercury, vx_mercury, vy_mercury, vz_mercury;
    double x_venus, y_venus, z_venus, vx_venus, vy_venus, vz_venus;
    double x_earth, y_earth, z_earth, vx_earth, vy_earth, vz_earth;
    double x_mars, y_mars, z_mars, vx_mars, vy_mars, vz_mars;
    double x_jupiter, y_jupiter, z_jupiter, vx_jupiter, vy_jupiter, vz_jupiter;
    double x_saturn, y_saturn, z_saturn, vx_saturn, vy_saturn, vz_saturn;
    double x_uranus, y_uranus, z_uranus, vx_uranus, vy_uranus, vz_uranus;
    double x_neptune, y_neptune, z_neptune, vx_neptune, vy_neptune, vz_neptune;
    double x_pluto, y_pluto, z_pluto, vx_pluto, vy_pluto, vz_pluto;
    double x, y, z, r, a, theta;
    double t, dt;
    int i;

    // Set initial conditions
    x_sun = 0;
    y_sun = 0;
    z_sun = 0;
    vx_sun = 0;
    vy_sun = 0;
    vz_sun = 0;

    x_mercury = 0.39 * AU;
    y_mercury = 0;
    z_mercury = 0;
    vx_mercury = 0;
    vy_mercury = 47.87e3;
    vz_mercury = 0;

    x_venus = 0.72 * AU;
    y_venus = 0;
    z_venus = 0;
    vx_venus = 0;
    vy_venus = 35.02e3;
    vz_venus = 0;

    x_earth = 1 * AU;
    y_earth = 0;
    z_earth = 0;
    vx_earth = 0;
    vy_earth = 29.78e3;
    vz_earth = 0;

    x_mars = 1.52 * AU;
    y_mars = 0;
    z_mars = 0;
    vx_mars = 0;
    vy_mars = 24.13e3;
    vz_mars = 0;

    x_jupiter = 5.20 * AU;
    y_jupiter = 0;
    z_jupiter = 0;
    vx_jupiter = 0;
    vy_jupiter = 13.07e3;
    vz_jupiter = 0;

    x_saturn = 9.54 * AU;
    y_saturn = 0;
    z_saturn = 0;
    vx_saturn = 0;
    vy_saturn = 9.69e3;
    vz_saturn = 0;

    x_uranus = 19.19 * AU;
    y_uranus = 0;
    z_uranus = 0;
    vx_uranus = 0;
    vy_uranus = 6.81e3;
    vz_uranus = 0;

    x_neptune = 30.07 * AU;
    y_neptune = 0;
    z_neptune = 0;
    vx_neptune = 0;
    vy_neptune = 5.43e3;
    vz_neptune = 0;

    x_pluto = 39.48 * AU;
    y_pluto = 0;
    z_pluto = 0;
    vx_pluto = 0;
    vy_pluto = 4.67e3;
    vz_pluto = 0;

    // Set time step and simulation time
    dt = 10;
    t = 0;

    // Run simulation
    while (t <= 100 * year)
    {
        // Calculate distances and gravitational forces
        r = sqrt(pow(x_mercury - x_sun, 2) + pow(y_mercury - y_sun, 2) + pow(z_mercury - z_sun, 2));
        a = G * M_sun / pow(r, 2);
        theta = atan2(y_mercury - y_sun, x_mercury - x_sun);
        vx_mercury += -a * dt / M_mercury * cos(theta);
        vy_mercury += -a * dt / M_mercury * sin(theta);
        vz_mercury += -a * dt / M_mercury * sin(theta);

        r = sqrt(pow(x_venus - x_sun, 2) + pow(y_venus - y_sun, 2) + pow(z_venus - z_sun, 2));
        a = G * M_sun / pow(r, 2);
        theta = atan2(y_venus - y_sun, x_venus - x_sun);
        vx_venus += -a * dt / M_venus * cos(theta);
        vy_venus += -a * dt / M_venus * sin(theta);
        vz_venus += -a * dt / M_venus * sin(theta);

        r = sqrt(pow(x_earth - x_sun, 2) + pow(y_earth - y_sun, 2) + pow(z_earth - z_sun, 2));
        a = G * M_sun / pow(r, 2);
        theta = atan2(y_earth - y_sun, x_earth - x_sun);
        vx_earth += -a * dt / M_earth * cos(theta);
        vy_earth += -a * dt / M_earth * sin(theta);
        vz_earth += -a * dt / M_earth * sin(theta);

        r = sqrt(pow(x_mars - x_sun, 2) + pow(y_mars - y_sun, 2) + pow(z_mars - z_sun, 2));
        a = G * M_sun / pow(r, 2);
        theta = atan2(y_mars - y_sun, x_mars - x_sun);
        vx_mars += -a * dt / M_mars * cos(theta);
        vy_mars += -a * dt / M_mars * sin(theta);
        vz_mars += -a * dt / M_mars * sin(theta);

        r = sqrt(pow(x_jupiter - x_sun, 2) + pow(y_jupiter - y_sun, 2) + pow(z_jupiter - z_sun, 2));
        a = G * M_sun / pow(r, 2);
        theta = atan2(y_jupiter - y_sun, x_jupiter - x_sun);
        vx_jupiter += -a * dt / M_jupiter * cos(theta);
        vy_jupiter += -a * dt / M_jupiter * sin(theta);
        vz_jupiter += -a * dt / M_jupiter * sin(theta);

        r = sqrt(pow(x_saturn - x_sun, 2) + pow(y_saturn - y_sun, 2) + pow(z_saturn - z_sun, 2));
        a = G * M_sun / pow(r, 2);
        theta = atan2(y_saturn - y_sun, x_saturn - x_sun);
        vx_saturn += -a * dt / M_saturn * cos(theta);
        vy_saturn += -a * dt / M_saturn * sin(theta);
        vz_saturn += -a * dt / M_saturn * sin(theta);

        r = sqrt(pow(x_uranus - x_sun, 2) + pow(y_uranus - y_sun, 2) + pow(z_uranus - z_sun, 2));
        a = G * M_sun / pow(r, 2);
        theta = atan2(y_uranus - y_sun, x_uranus - x_sun);
        vx_uranus += -a * dt / M_uranus * cos(theta);
        vy_uranus += -a * dt / M_uranus * sin(theta);
        vz_uranus += -a * dt / M_uranus * sin(theta);

        r = sqrt(pow(x_neptune - x_sun, 2) + pow(y_neptune - y_sun, 2) + pow(z_neptune - z_sun, 2));
        a = G * M_sun / pow(r, 2);
        theta = atan2(y_neptune - y_sun, x_neptune - x_sun);
        vx_neptune += -a * dt / M_neptune * cos(theta);
        vy_neptune += -a * dt / M_neptune * sin(theta);
        vz_neptune += -a * dt / M_neptune * sin(theta);

        r = sqrt(pow(x_pluto - x_sun, 2) + pow(y_pluto - y_sun, 2) + pow(z_pluto - z_sun, 2));
        a = G * M_sun / pow(r, 2);
        theta = atan2(y_pluto - y_sun, x_pluto - x_sun);
        vx_pluto += -a * dt / M_pluto * cos(theta);
        vy_pluto += -a * dt / M_pluto * sin(theta);
        vz_pluto += -a * dt / M_pluto * sin(theta);

        // Update positions
        x_mercury += vx_mercury * dt;
        y_mercury += vy_mercury * dt;
        z_mercury += vz_mercury * dt;

        x_venus += vx_venus * dt;
        y_venus += vy_venus * dt;
        z_venus += vz_venus * dt;

        x_earth += vx_earth * dt;
        y_earth += vy_earth * dt;
        z_earth += vz_earth * dt;

        x_mars += vx_mars * dt;
        y_mars += vy_mars * dt;
        z_mars += vz_mars * dt;

        x_jupiter += vx_jupiter * dt;
        y_jupiter += vy_jupiter * dt;
        z_jupiter += vz_jupiter * dt;

        x_saturn += vx_saturn * dt;
        y_saturn += vy_saturn * dt;
        z_saturn += vz_saturn * dt;

        x_uranus += vx_uranus * dt;
        y_uranus += vy_uranus * dt;
        z_uranus += vz_uranus * dt;

        x_neptune += vx_neptune * dt;
        y_neptune += vy_neptune * dt;
        z_neptune += vz_neptune * dt;

        x_pluto += vx_pluto * dt;
        y_pluto += vy_pluto * dt;
        z_pluto += vz_pluto * dt;

        // Print positions
        printf("Mercury: (%f, %f, %f)\n", x_mercury, y_mercury, z_mercury);
        printf("Venus: (%f, %f, %f)\n", x_venus, y_venus, z_venus);
        printf("Earth: (%f, %f, %f)\n", x_earth, y_earth, z_earth);
        printf("Mars: (%f, %f, %f)\n", x_mars, y_mars, z_mars);
        printf("Jupiter: (%f, %f, %f)\n", x_jupiter, y_jupiter, z_jupiter);
        printf("Saturn: (%f, %f, %f)\n", x_saturn, y_saturn, z_saturn);
        printf("Uranus: (%f, %f, %f)\n", x_uranus, y_uranus, z_uranus);
        printf("Neptune: (%f, %f, %f)\n", x_neptune, y_neptune, z_neptune);
        printf("Pluto: (%f, %f, %f)\n", x_pluto, y_pluto, z_pluto);

        // Update time
        t += dt;
    }

    return 0;
}