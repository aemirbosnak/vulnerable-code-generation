//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// surrealist constants
#define PI 3.14159265358979323846
#define E 2.71828182845904523536
#define PHI 1.618033988749895
#define G 6.67430e-11
#define C 299792458

// surrealist function prototypes
double surreal(double x);
int main()
{
    int i, j, k, l;
    double x, y, z;
    char s[100];
    scanf("%s", s);
    for (i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]))
        {
            x = atof(s);
            y = surreal(x);
            printf("%f -> %f\n", x, y);
        }
        else if (isalpha(s[i]))
        {
            printf("Error: Input must be a number.\n");
            return 0;
        }
        else
        {
            printf("Error: Invalid input.\n");
            return 0;
        }
    }
    return 0;
}

double surreal(double x)
{
    double y = 0;
    int n = 0;
    while (n < 10)
    {
        y += pow(x, n) * sin(n * PI / 180);
        n++;
    }
    return y;
}