//Falcon2-11B DATASET v1.0 Category: Physics simulation ; Style: complex
#include<stdio.h>
#include<math.h>

// Function to calculate the time taken by the ball to hit the ground
float calculateTime(float height)
{
    float x=height;
    float y=0;
    float g=9.8;
    float t;
    float t1=0;
    float t2=0;
    float t3=0;
    float t4=0;
    float t5=0;
    float t6=0;
    float t7=0;
    float t8=0;
    float t9=0;
    while(y >= 0)
    {
        t=y/x;
        t1=t1+t;
        t2=t2+x;
        t3=t3+y;
        x=x-g*t;
        y=y-0.5*g*t*t;
    }
    t4=t1+t2;
    t5=t3+t4;
    t6=t5+t2;
    t7=t6+t1;
    t8=t7+t4;
    t9=t8+t3;
    return t9;
}

// Function to calculate the final velocity of the ball
float calculateFinalVelocity(float initialVelocity, float time)
{
    float finalVelocity=initialVelocity-9.8*time;
    return finalVelocity;
}

// Function to calculate the total distance covered by the ball
float calculateTotalDistance(float initialVelocity, float time)
{
    float totalDistance=initialVelocity*time;
    return totalDistance;
}

int main()
{
    float height, initialVelocity, time;
    printf("Enter the initial height of the ball in meters: ");
    scanf("%f", &height);
    printf("Enter the initial velocity of the ball in meters per second: ");
    scanf("%f", &initialVelocity);
    printf("Enter the time taken by the ball to hit the ground in seconds: ");
    scanf("%f", &time);
    printf("The total distance covered by the ball is %f meters.\n", calculateTotalDistance(initialVelocity, time));
    printf("The final velocity of the ball is %f meters per second.\n", calculateFinalVelocity(initialVelocity, time));
    printf("The time taken by the ball to hit the ground is %f seconds.\n", calculateTime(height));
    return 0;
}