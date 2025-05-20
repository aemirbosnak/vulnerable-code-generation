//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float speedTest(int n, float s)
{
    float result;

    // Base case
    if (n == 0)
    {
        return s;
    }

    // Recursive case
    else
    {
        // Initialize variables
        float startTime, endTime, total;

        // Get start time
        startTime = (float) clock() / CLOCKS_PER_SEC;

        // Download file of size 100MB
        FILE* file = fopen("test.file", "wb");
        if (file != NULL)
        {
            for (int i = 0; i < 1024 * 100; i++)
            {
                fputc(random() % 256, file);
                fflush(file);
            }
        }

        // Get end time
        endTime = (float) clock() / CLOCKS_PER_SEC;

        // Calculate total time in seconds
        total = endTime - startTime;

        // Calculate speed in MB/s
        result = 100 / total;

        // Close file
        fclose(file);

        // Recursive call
        return speedTest(n - 1, result);
    }
}

int main()
{
    // Initialize variables
    int n;
    float speed;

    // Get number of iterations
    printf("Enter number of iterations: ");
    scanf("%d", &n);

    // Get initial speed
    printf("Enter initial speed in MB/s: ");
    scanf("%f", &speed);

    // Call recursive function
    float maxSpeed = speedTest(n, speed);

    // Output max speed
    printf("Max speed achieved is %.2f MB/s\n", maxSpeed);

    return 0;
}