//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_DISTANCE 1000000000.0
#define MAX_POPULATION 1000000000
#define MAX_YEARS 1000000000
#define MIN_YEARS 1
#define MIN_DISTANCE 0.0
#define MIN_POPULATION 0

double distance(int x, int y)
{
    double dx = x - 50;
    double dy = y - 50;
    return sqrt(dx*dx + dy*dy);
}

double population(int x, int y)
{
    int count = 0;
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            if(distance(i,j) <= 10)
                count++;
        }
    }
    return (double)count / (x*y);
}

double years(int x, int y)
{
    double p = population(x,y);
    double d = distance(x,y);
    double t = (log(p) + 3*log(d)) / (0.1 * 4.5);
    return t;
}

int main()
{
    int x, y;
    printf("Enter population density (0-%d): ", MAX_POPULATION);
    scanf("%d", &x);
    printf("Enter distance from Earth (0-%g): ", MAX_DISTANCE);
    scanf("%lf", &y);

    double min_years = years(x, y);
    double max_years = years(0, 0);

    srand(time(NULL));
    int years = rand() % (int)(max_years - min_years + 1) + min_years;

    printf("Alien invasion will occur in %d years.\n", years);

    return 0;
}