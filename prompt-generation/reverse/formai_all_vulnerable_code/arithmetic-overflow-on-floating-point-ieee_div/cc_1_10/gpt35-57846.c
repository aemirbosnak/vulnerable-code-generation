//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define WIDTH 120 //screen width
#define HEIGHT 40 //screen height

#define NUM_PLANETS 5
#define G 0.0000000000667 //gravitational constant

typedef struct _planet{
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double m;
} planet;

//function to update position of a planet based on its velocity
void update_position(planet *p, double dt){
    p->x += p->vx*dt;
    p->y += p->vy*dt;
    p->z += p->vz*dt;
}

//function to update velocity of a planet based on the gravitational force
void update_velocity(planet *p, planet *others, int num_others, double dt){
    double fx, fy, fz, f, dx, dy, dz, dist;
    int i;

    fx = fy = fz = 0.0;

    //calculate gravitational force from all other planets
    for(i=0;i<num_others;i++){
        dx = others[i].x - p->x;
        dy = others[i].y - p->y;
        dz = others[i].z - p->z;

        dist = sqrt(dx*dx + dy*dy + dz*dz);

        f = (G * p->m * others[i].m)/(dist*dist);

        fx += f*(dx/dist);
        fy += f*(dy/dist);
        fz += f*(dz/dist);
    }

    //update velocity based on gravitational force
    p->vx += (fx/p->m)*dt;
    p->vy += (fy/p->m)*dt;
    p->vz += (fz/p->m)*dt;
}

//function to print the position of planets on the screen
void print_screen(planet *planets, int num_planets){
    int i, j, x, y;
    char screen[WIDTH][HEIGHT];

    printf("\033[2J");//clear the screen

    //initialize screen
    for(i=0;i<WIDTH;i++){
        for(j=0;j<HEIGHT;j++){
            screen[i][j] = ' ';
        }
    }

    //plot each planet on the screen
    for(i=0;i<num_planets;i++){
        x = (int)round(planets[i].x) + (WIDTH/2);
        y = (int)round(planets[i].y) + (HEIGHT/2);

        if(x>=0 && x<WIDTH && y>=0 && y<HEIGHT){
            screen[x][y] = 'o';
        }
    }

    //print the screen on the console
    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            putchar(screen[j][i]);
        }
        putchar('\n');
    }

    usleep(100000);//sleep for 0.1 second to control frame rate
}

int main(){
    planet planets[NUM_PLANETS] = {
        {0.0,0.0,0.0,0.0,0.0,0.0,1989000}, //Sun
        {57910000.0,0.0,0.0,0.0,47933.0,0.0,326.0}, //Mercury
        {108200000.0,0.0,0.0,0.0,35500.0,0.0,4867.0}, //Venus
        {227940000.0,0.0,0.0,0.0,30300.0,0.0,5972.0}, //Earth
        {778360000.0,0.0,0.0,0.0,13070.0,0.0,1898187.0} //Jupiter
    };

    int i, j;
    double dt = 0.01;//time step in seconds
    double t = 0.0;//simulation time in seconds

    while(1){//simulation loop
        for(i=0;i<NUM_PLANETS;i++){
            update_velocity(&planets[i], planets, NUM_PLANETS, dt);
        }

        for(i=0;i<NUM_PLANETS;i++){
            update_position(&planets[i], dt);
        }

        print_screen(planets, NUM_PLANETS);

        t += dt;
    }

    return 0;
}