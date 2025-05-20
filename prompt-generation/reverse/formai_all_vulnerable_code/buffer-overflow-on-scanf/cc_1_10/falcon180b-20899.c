//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159

//Function to calculate distance between two points
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

//Function to calculate angle between two points
double angle(double x1, double y1, double x2, double y2)
{
    double dist = distance(x1,y1,x2,y2);
    double angle_rad = atan2(y2-y1,x2-x1);
    double angle_deg = angle_rad*180/PI;
    return angle_deg;
}

//Function to move the robot
void move(double angle, double speed)
{
    printf("Moving robot at %f degrees with speed %f\n",angle,speed);
}

//Function to rotate the robot
void rotate(double angle, double speed)
{
    printf("Rotating robot at %f degrees with speed %f\n",angle,speed);
}

//Function to stop the robot
void stop()
{
    printf("Stopping robot\n");
}

//Main function
int main()
{
    double x1 = 0, y1 = 0, x2 = 10, y2 = 10;
    double angle_deg, speed;

    //Move the robot
    printf("Enter angle of movement: ");
    scanf("%lf",&angle_deg);
    printf("Enter speed of movement: ");
    scanf("%lf",&speed);
    move(angle_deg,speed);

    //Rotate the robot
    printf("Enter angle of rotation: ");
    scanf("%lf",&angle_deg);
    printf("Enter speed of rotation: ");
    scanf("%lf",&speed);
    rotate(angle_deg,speed);

    //Stop the robot
    stop();

    return 0;
}