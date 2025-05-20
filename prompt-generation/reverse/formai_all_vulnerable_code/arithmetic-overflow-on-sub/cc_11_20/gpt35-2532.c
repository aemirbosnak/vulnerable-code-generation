//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: medieval
#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, k, l, r, flag;
    double x[1000], y[1000], z[1000], a, b, c, d, e, f;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the coordinates of the points:\n");
    for (i = 0; i < n; i++)
    {
        printf("Point %d: ", i+1);
        scanf("%lf %lf %lf", &x[i], &y[i], &z[i]);
    }

    flag = 0;
    for (i = 0; i < n-2; i++)
    {
        for (j = i+1; j < n-1; j++)
        {
            for (k = j+1; k < n; k++)
            {
                a = y[j] - y[i];
                b = x[i] - x[j];
                c = x[j]*y[i] - x[i]*y[j];

                d = z[k] - z[i];
                e = z[j] - z[i];
                f = z[i]*e - d*z[j];

                r = 0;
                for (l = 0; l < n; l++)
                {
                    if (l == i || l == j || l == k)
                        continue;

                    if (a*x[l]+b*y[l]+c == 0 && d*x[l]+e*y[l]+f == 0)
                        r++;
                }

                if (r == n-3)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag)
                break;
        }

        if (flag)
            break;
    }

    if (flag)
        printf("The points (%.2lf, %.2lf, %.2lf), (%.2lf, %.2lf, %.2lf), and (%.2lf, %.2lf, %.2lf) lie on a plane.\n", x[i], y[i], z[i], x[j], y[j], z[j], x[k], y[k], z[k]);
    else
        printf("No three points lie on a plane.\n");

    return 0;
}