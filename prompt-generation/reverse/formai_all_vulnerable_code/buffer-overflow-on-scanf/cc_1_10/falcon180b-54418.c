//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1024
#define PI 3.14159265358979323846

int main()
{
    int i, n;
    double x[N], y[N], t;
    FILE *fp;
    char filename[50];

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(0);
    }

    for (i = 0; i < N; i++)
    {
        fscanf(fp, "%lf", &x[i]);
    }

    fclose(fp);

    for (i = 0; i < N; i++)
    {
        y[i] = sin(x[i] * PI / 180);
    }

    printf("Enter the name of the output file: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(0);
    }

    for (i = 0; i < N; i++)
    {
        fprintf(fp, "%lf\n", y[i]);
    }

    fclose(fp);

    return 0;
}