//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>
#include <math.h>

int main()
{
    struct rusage usage;
    int i, j, k, l;
    double cpu_usage;

    while (1)
    {
        if (getrusage(RUSAGE_SELF, &usage) == -1)
        {
            perror("getrusage");
            exit(EXIT_FAILURE);
        }

        cpu_usage = (double) usage.ru_utime.tv_sec + (double) usage.ru_utime.tv_usec / 1000000;
        cpu_usage += (double) usage.ru_stime.tv_sec + (double) usage.ru_stime.tv_usec / 1000000;

        printf("CPU Usage: %.2f%%\n", cpu_usage / (double) sysconf(_SC_CLK_TCK) * 100);

        for (i = 0; i < 50; i++)
        {
            for (j = 0; j < 80; j++)
            {
                k = rand() % 3;
                l = rand() % 3;

                switch (k)
                {
                    case 0:
                        printf("\033[0;31m");
                        break;

                    case 1:
                        printf("\033[0;32m");
                        break;

                    case 2:
                        printf("\033[0;34m");
                        break;
                }

                switch (l)
                {
                    case 0:
                        printf("\033[0m");
                        break;

                    case 1:
                        printf("\033[1m");
                        break;

                    case 2:
                        printf("\033[2m");
                        break;
                }

                printf("*");
            }

            printf("\n");
        }

        usleep(100000);
    }

    return 0;
}