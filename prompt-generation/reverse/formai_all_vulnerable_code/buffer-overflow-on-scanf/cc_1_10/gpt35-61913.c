//FormAI DATASET v1.0 Category: Physics simulation ; Style: multivariable
#include<stdio.h>
#include<math.h>

int main(){
  float u,v,a,theta,r,t;
  float x,y;

  printf("Enter the initial velocity (u): ");
  scanf("%f", &u);
  printf("Enter the final velocity (v): ");
  scanf("%f", &v);
  printf("Enter the acceleration (a): ");
  scanf("%f", &a);
  printf("Enter the angle of projection (theta) in degree: ");
  scanf("%f", &theta);
  printf("Enter the distance (r) between the two objects: ");
  scanf("%f", &r);
  printf("Enter the time (t) taken by the object to travel the distance: ");
  scanf("%f", &t);

  theta = (theta*M_PI)/180; // converting degree to radian

  x = r*cos(theta);
  y = r*sin(theta);

  //find the time taken to reach the max height
  float t1 = (v-u)/a;

  //find the max height
  float h = u*t1 + 0.5*a*(t1*t1);

  //find the time taken to hit the ground from max height
  float t2 = sqrt((2*h)/a);

  //find the distance travelled in x direction when the object is in air
  float x1 = u*t1 + 0.5*a*(t1*t1);

  //find the distance travelled in x direction when the object hits the ground
  float x2 = v*t2 + 0.5*a*(t2*t2);

  printf("Projectile Motion Details:\n");
  printf("Initial Velocity = %.2f m/s\n", u);
  printf("Final Velocity = %.2f m/s\n", v);
  printf("Acceleration = %.2f m/s^2\n", a);
  printf("Angle of projection = %.2f degree\n", theta*180/M_PI);
  printf("Distance between the two objects = %.2f m\n", r);
  printf("Time taken by the object to travel the distance = %.2f s\n", t);
  printf("Max height reached by the object = %.2f m\n", h);
  printf("Time taken to reach the max height = %.2f s\n", t1);
  printf("Time taken to hit the ground from max height = %.2f s\n", t2);
  printf("Distance travelled in x direction when the object is in air = %.2f m\n", x1);
  printf("Distance travelled in x direction when the object hits the ground = %.2f m\n", x2);

  return 0;
}