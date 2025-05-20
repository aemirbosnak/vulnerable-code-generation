//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define G 6.6743e-11 //Gravitational constant
#define MAX_PLANETS 10 //Maximum number of planets in the system
#define UNIVERSE_SIZE 100 //Size of the universe in meters
#define TIME_INTERVAL 86400 //Time interval between calculations in seconds

struct planet{
    char name[20];
    double mass;
    double position_x;
    double position_y;
    double velocity_x;
    double velocity_y;
    double acceleration_x;
    double acceleration_y;
}planets[MAX_PLANETS];

double distance(double x1, double y1, double x2, double y2);
double force(double mass1, double mass2, double distance);
double acceleration(double force, double mass);
void calculate_acceleration(struct planet *planet1, struct planet *planet2);
void update_velocity(struct planet *planet);
void update_position(struct planet *planet);
void simulate(int num_planets);

int main(){
    printf("Welcome to the C Planet Gravity Simulation Example Program!\n");
    printf("Please enter the number of planets in your system (Maximum %d): ", MAX_PLANETS);
    int num_planets = 0;
    scanf("%d", &num_planets);
    if(num_planets > MAX_PLANETS){
        printf("Sorry, the maximum number of planets is %d.\n", MAX_PLANETS);
        return 0;
    }
    for(int i = 0; i < num_planets; i++){
        printf("\nEnter details for planet %d:\n", i+1);
        printf("Name: ");
        scanf("%s", planets[i].name);
        printf("Mass (in kg): ");
        scanf("%lf", &planets[i].mass);
        printf("Position (x, y) in meters (within a 100 x 100 universe): ");
        scanf("%lf %lf", &planets[i].position_x, &planets[i].position_y);
        printf("Velocity (x, y) in m/s: ");
        scanf("%lf %lf", &planets[i].velocity_x, &planets[i].velocity_y);
        printf("Acceleration (x, y) in m/s^2: ");
        scanf("%lf %lf", &planets[i].acceleration_x, &planets[i].acceleration_y);
    }
    simulate(num_planets);
    return 0;
}

double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

double force(double mass1, double mass2, double distance){
    return G * ((mass1 * mass2) / pow(distance, 2));
}

double acceleration(double force, double mass){
    return force / mass;
}

void calculate_acceleration(struct planet *planet1, struct planet *planet2){
    double dist = distance(planet1->position_x, planet1->position_y, planet2->position_x, planet2->position_y);
    double f = force(planet1->mass, planet2->mass, dist);
    double a1 = acceleration(f, planet1->mass);
    double a2 = acceleration(f, planet2->mass);
    planet1->acceleration_x = a1 * (planet2->position_x - planet1->position_x) / dist;
    planet1->acceleration_y = a1 * (planet2->position_y - planet1->position_y) / dist;
    planet2->acceleration_x = a2 * (planet1->position_x - planet2->position_x) / dist;
    planet2->acceleration_y = a2 * (planet1->position_y - planet2->position_y) / dist;
}

void update_velocity(struct planet *planet){
    planet->velocity_x += planet->acceleration_x * TIME_INTERVAL;
    planet->velocity_y += planet->acceleration_y * TIME_INTERVAL;
}

void update_position(struct planet *planet){
    planet->position_x += planet->velocity_x * TIME_INTERVAL;
    planet->position_y += planet->velocity_y * TIME_INTERVAL;
}

void simulate(int num_planets){
    for(int i = 0; i < num_planets; i++){
        printf("\nStarting details for planet %d:\n", i+1);
        printf("Name: %s\n", planets[i].name);
        printf("Mass (in kg): %lf\n", planets[i].mass);
        printf("Position (x, y) in meters: (%lf, %lf)\n", planets[i].position_x, planets[i].position_y);
        printf("Velocity (x, y) in m/s: (%lf, %lf)\n", planets[i].velocity_x, planets[i].velocity_y);
        printf("Acceleration (x, y) in m/s^2: (%lf, %lf)\n", planets[i].acceleration_x, planets[i].acceleration_y);
    }
    printf("\n\nSimulation starting...\n\n");
    for(int t = 0; t < 365; t++){
        printf("\n\nDay %d\n\n", t+1);
        for(int i = 0; i < num_planets; i++){
            for(int j = i+1; j < num_planets; j++){
                calculate_acceleration(&planets[i], &planets[j]);
            }
        }
        for(int i = 0; i < num_planets; i++){
            update_velocity(&planets[i]);
            update_position(&planets[i]);
            printf("Position of planet %s after %d days: (%lf, %lf)\n", planets[i].name, t+1, planets[i].position_x, planets[i].position_y);
        }
    }
    printf("\nSimulation finished.\n");
}