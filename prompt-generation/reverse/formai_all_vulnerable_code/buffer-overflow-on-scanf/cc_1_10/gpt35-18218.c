//FormAI DATASET v1.0 Category: Physics simulation ; Style: genious
#include<stdio.h>
#include<math.h>

#define N 100
#define G 6.67430e-11

struct particle{
    double mass, x, y, vx, vy, ax, ay;
};

double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
}

void update_acceleration(struct particle *p, int n){
    double d, f;
    int i, j;

    for(i=0; i<n; ++i){
        p[i].ax = 0.0;
        p[i].ay = 0.0;

        for(j=0; j<n; ++j){
            if(i==j) continue;

            d = distance(p[i].x, p[i].y, p[j].x, p[j].y);

            if(d>1.0) f = G*p[i].mass*p[j].mass/pow(d, 2);
            else f = 0.0;

            p[i].ax += f*(p[j].x-p[i].x)/d;
            p[i].ay += f*(p[j].y-p[i].y)/d;
        }
    }
}

void update_velocity(struct particle *p, double dt, int n){
    int i;

    for(i=0; i<n; ++i){
        p[i].vx += p[i].ax*dt;
        p[i].vy += p[i].ay*dt;
    }
}

void update_position(struct particle *p, double dt, int n){
    int i;

    for(i=0; i<n; ++i){
        p[i].x += p[i].vx*dt;
        p[i].y += p[i].vy*dt;
    }
}

int main(){
    int i, n;
    double t;

    printf("Enter number of particles: ");
    scanf("%d", &n);

    if(n>N){
        printf("Maximum limit exceeded!\n");
        return 1;
    }

    struct particle p[n];

    for(i=0; i<n; ++i){
        printf("Enter mass, x, y, vx, vy of particle %d: ", i+1);
        scanf("%lf%lf%lf%lf%lf", &p[i].mass, &p[i].x, &p[i].y, &p[i].vx, &p[i].vy);
    }

    printf("Enter simulation time: ");
    scanf("%lf", &t);

    double dt = 0.001, time = 0.0;

    while(time<=t){
        update_acceleration(p, n);
        update_velocity(p, dt, n);
        update_position(p, dt, n);
        time += dt;
    }

    printf("Final positions: \n");

    for(i=0; i<n; ++i){
        printf("Particle %d: x=%.2lf y=%.2lf\n", i+1, p[i].x, p[i].y);
    }

    return 0;
}