//FormAI DATASET v1.0 Category: Physics simulation ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    float acc, vel, pos, mass;
    float time, force, displacement, energy;
    int i=0;

    printf("Enter mass of the object: ");
    scanf("%f",&mass);

    printf("Enter initial velocity of the object: ");
    scanf("%f",&vel);

    printf("Enter initial position of the object: ");
    scanf("%f",&pos);

    printf("Enter acceleration of the object: ");
    scanf("%f",&acc);

    printf("Enter time interval: ");
    scanf("%f",&time);

    force=mass*acc;
    displacement=(vel*time)+0.5*acc*time*time;
    energy=0.5*mass*vel*vel;

    printf("Initial parameters:\n");
    printf("Acceleration: %f m/s2\n",acc);
    printf("Velocity: %f m/s\n",vel);
    printf("Position: %f m\n",pos);
    printf("Mass: %f Kg\n",mass);
    printf("Time interval: %f s\n",time);

    printf("\nSimulation starting...\n");

    for(i=1;i<=5;i++)
    {
        printf("\n------------------------\n");
        printf("Time t=%d\n",i);
        printf("------------------------\n");

        pos+=displacement;
        vel=vel+(acc*time);

        printf("Displacement: %f m\n",displacement);
        printf("Velocity: %f m/s\n",vel);
        printf("Position: %f m\n",pos);

        displacement=(vel*time)+0.5*acc*time*time;
    }

    printf("\nSimulation ended.\n");

    printf("\nFinal parameters:\n");
    printf("Acceleration: %f m/s2\n",acc);
    printf("Velocity: %f m/s\n",vel);
    printf("Position: %f m\n",pos);

    if(force>0)
        printf("Force acting on the object: %f N (in +x direction)\n",force);
    else if(force<0)
        printf("Force acting on the object: %f N (in -x direction)\n",abs(force));

     printf("Kinetic energy of the object: %f J\n",energy);

    return 0;
}