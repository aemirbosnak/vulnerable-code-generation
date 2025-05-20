//FormAI DATASET v1.0 Category: Physics simulation ; Style: realistic
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define DT 0.01
#define G 6.6743*pow(10,-11)

typedef struct particle{
    double m,x,y,z,vx,vy,vz,ax,ay,az;
}particle;

void calculate_acceleration(particle* p, int n){
    int i,j;
    double dist,dx,dy,dz;
    for(i=0;i<n;i++){
        p[i].ax=0;
        p[i].ay=0;
        p[i].az=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j) continue;
            dx=p[j].x-p[i].x;
            dy=p[j].y-p[i].y;
            dz=p[j].z-p[i].z;
            dist=sqrt(dx*dx+dy*dy+dz*dz);
            p[i].ax+=G*p[j].m*dx/(dist*dist*dist);
            p[i].ay+=G*p[j].m*dy/(dist*dist*dist);
            p[i].az+=G*p[j].m*dz/(dist*dist*dist);
        }
    }
}

void calculate_velocity(particle* p, int n,double dt){
    int i;
    for(i=0;i<n;i++){
        p[i].vx+=p[i].ax*dt;
        p[i].vy+=p[i].ay*dt;
        p[i].vz+=p[i].az*dt;
    }
}

void calculate_position(particle* p, int n,double dt){
    int i;
    for(i=0;i<n;i++){
        p[i].x+=p[i].vx*dt;
        p[i].y+=p[i].vy*dt;
        p[i].z+=p[i].vz*dt;
    }
}

int main(){
    int n,i,t,j;
    scanf("%d",&n);
    double dt=DT;
    particle* p=(particle*)malloc(n*sizeof(particle));
    for(i=0;i<n;i++){
        scanf("%lf%lf%lf%lf%lf%lf%lf",&p[i].m,&p[i].x,&p[i].y,&p[i].z,&p[i].vx,&p[i].vy,&p[i].vz);
    }
    for(t=0;t<1000;t++){
        calculate_acceleration(p,n);
        calculate_velocity(p,n,dt);
        calculate_position(p,n,dt);
        printf("Time step t=%d\n",t);
        for(i=0;i<n;i++){
            printf("Particle %d: m=%.2lf x=%.2lf y=%.2lf z=%.2lf\n",i+1,p[i].m,p[i].x,p[i].y,p[i].z);
        }
    }
    free(p);
    return 0;
}