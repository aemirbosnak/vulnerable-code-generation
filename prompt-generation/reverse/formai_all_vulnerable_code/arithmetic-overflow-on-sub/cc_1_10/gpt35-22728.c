//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 40
#define MAX_PLANETS 6
#define G 0.1

double random_double(double min, double max){
    return min + (rand() / (double) RAND_MAX) * (max - min);
}

typedef struct Vector{
    double x;
    double y;
}Vector;

typedef struct Planet{
    char symbol;
    double mass;
    double radius;
    Vector position;
    Vector velocity;
    Vector acceleration;
}Planet;

Planet planets[MAX_PLANETS];

void initialize_planets(){
    planets[0] = (Planet){'S', 1000, 10, (Vector){WIDTH/2.0, HEIGHT/2.0}, (Vector){0,0}, (Vector){0,0}};
    planets[1] = (Planet){'M', 100, 5, (Vector){WIDTH/2.0 + 60.0, HEIGHT/2.0}, (Vector){0,1.6}, (Vector){0,0}};
    planets[2] = (Planet){'E', 5, 3, (Vector){WIDTH/2.0 + 30.0, HEIGHT/2.0}, (Vector){0,-2.5}, (Vector){0,0}};
    planets[3] = (Planet){'V', 2, 2, (Vector){WIDTH/2.0 - 50.0, HEIGHT/2.0}, (Vector){0,4}, (Vector){0,0}};
    planets[4] = (Planet){'R', 3, 2.5, (Vector){WIDTH/2.0 + 100.0, HEIGHT/2.0}, (Vector){0,-3}, (Vector){0,0}};
    planets[5] = (Planet){'T', 4, 3.2, (Vector){WIDTH/2.0 - 100.0, HEIGHT/2.0}, (Vector){0,2.3}, (Vector){0,0}};
}

void clear_screen(){
    system("clear");
}

void draw_planets(){
    char screen[HEIGHT][WIDTH];
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            screen[i][j] = ' ';
        }
    }
    for(int i=0;i<MAX_PLANETS;i++){
        int x = (int) planets[i].position.x;
        int y = (int) planets[i].position.y;
        if((x >= 0 && x < WIDTH) && (y >=0 && y < HEIGHT)){
            screen[y][x] = planets[i].symbol;
        }
    }
    for(int i=0;i<HEIGHT;i++){
        printf("|");
        for(int j=0;j<WIDTH;j++){
            printf("%c",screen[i][j]);
        }
        printf("|\n");
    }
}

void calculate_forces(){
    for(int i=0;i<MAX_PLANETS;i++){
        planets[i].acceleration.x = 0;
        planets[i].acceleration.y = 0;
        for(int j=0;j<MAX_PLANETS;j++){
            if(i == j){
                continue;
            }
            double distance = sqrt(pow(planets[j].position.x - planets[i].position.x, 2) + pow(planets[j].position.y - planets[i].position.y, 2));
            double force = G * planets[i].mass * planets[j].mass / pow(distance, 2);
            double angle = atan2(planets[j].position.y - planets[i].position.y, planets[j].position.x - planets[i].position.x);
            planets[i].acceleration.x += force / planets[i].mass * cos(angle);
            planets[i].acceleration.y += force / planets[i].mass * sin(angle);
        }
    }
}

void update_positions(double time_step){
    for(int i=0;i<MAX_PLANETS;i++){
        planets[i].velocity.x += planets[i].acceleration.x * time_step;
        planets[i].velocity.y += planets[i].acceleration.y * time_step;
        planets[i].position.x += planets[i].velocity.x * time_step;
        planets[i].position.y += planets[i].velocity.y * time_step;
    }
}

int main(){
    srand(time(NULL));
    initialize_planets();
    clock_t last_time = clock();
    while(1){
        clock_t current_time = clock();
        double time_step = (double) (current_time - last_time) / CLOCKS_PER_SEC;
        calculate_forces();
        update_positions(time_step);

        clear_screen();
        draw_planets();

        last_time = current_time;
    }
    return 0;
}