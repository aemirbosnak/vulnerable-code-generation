//Falcon-180B DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main() {
    int i, j, k, n, m, p, q, r, s;
    double x, y, z, a, b, c, d, e, f, g, h, u, v, w, sum, avg, sd, cv, se;
    char str[100];
    struct tm timeinfo;
    time_t now;
    FILE *fp;

    // Initialize random seed
    srand(time(NULL));

    // Get current date and time
    now = time(NULL);
    localtime_r(&now, &timeinfo);
    strftime(str, 100, "%Y-%m-%d %H:%M:%S", &timeinfo);

    // Open output file
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: unable to open output file.\n");
        exit(1);
    }

    // Write header to output file
    fprintf(fp, "Date and time: %s\n", str);
    fprintf(fp, "Random numbers:\n");

    // Generate and write random numbers to output file
    for (i = 1; i <= 100; i++) {
        x = rand() % 101;
        fprintf(fp, "%d\n", x);
    }

    // Close output file
    fclose(fp);

    // Calculate statistics
    n = 100;
    sum = 0;
    for (i = 1; i <= n; i++) {
        sum += i;
    }
    avg = sum / n;
    sd = sqrt(pow(avg - 50, 2) / n);
    cv = sd / avg * 100;
    se = sd / sqrt(n);

    // Write statistics to output file
    fprintf(fp, "\nStatistics:\n");
    fprintf(fp, "Mean: %.2f\n", avg);
    fprintf(fp, "Standard deviation: %.2f\n", sd);
    fprintf(fp, "Coefficient of variation: %.2f%%\n", cv);
    fprintf(fp, "Standard error: %.2f\n", se);

    // Close output file
    fclose(fp);

    return 0;
}