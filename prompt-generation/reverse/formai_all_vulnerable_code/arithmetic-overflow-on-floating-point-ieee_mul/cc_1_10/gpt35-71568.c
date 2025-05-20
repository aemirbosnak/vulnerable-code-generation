//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Cyberpunk
#include<stdio.h>
#include<math.h>

#define G 6.67*pow(10,-11)

struct planet {
    double x, y, vx, vy, mass;
};

double calculateDistance(struct planet p1, struct planet p2){
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

double calculateForce(struct planet p1, struct planet p2){
    double r = calculateDistance(p1, p2);
    return (G * p1.mass * p2.mass) / (r*r);
}

double calculateDirection(struct planet p1, struct planet p2){
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return atan2(dy, dx);
}

double calculateForceX(struct planet p1, struct planet p2){
    double f = calculateForce(p1, p2);
    double d = calculateDirection(p1, p2);
    return f * cos(d);
}

double calculateForceY(struct planet p1, struct planet p2){
    double f = calculateForce(p1, p2);
    double d = calculateDirection(p1, p2);
    return f * sin(d);
}

void updateVelocity(struct planet* p, double fx, double fy, double dt){
    p->vx += fx * dt / p->mass;
    p->vy += fy * dt / p->mass;
}

void updatePosition(struct planet* p, double dt){
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

void simulate(struct planet planets[], int n, double dt){
    for(int i=0;i<n;i++){
        double fx = 0, fy = 0;
        for(int j=0;j<n;j++){
            if(i!=j){
                fx += calculateForceX(planets[i], planets[j]);
                fy += calculateForceY(planets[i], planets[j]);
            }
        }
        updateVelocity(&planets[i], fx, fy, dt);
        updatePosition(&planets[i], dt);
    }
}

int main(){
    struct planet planets[3] = {
        {100, 100, 0, 0, pow(10, 15)},
        {200, 100, 0, 0, pow(10, 15)},
        {150, 200, 0, 0, pow(10, 14)}
    };
    int n = 3;
    double dt = 10000;
    for(int i=0;i<10;i++){
        simulate(planets, n, dt);
    }
    printf("Position of planets after 10 simulation iterations:\n");
    for(int i=0;i<n;i++){
        printf("Planet %d: (%f, %f)\n", i+1, planets[i].x, planets[i].y);
    }
    return 0;
}