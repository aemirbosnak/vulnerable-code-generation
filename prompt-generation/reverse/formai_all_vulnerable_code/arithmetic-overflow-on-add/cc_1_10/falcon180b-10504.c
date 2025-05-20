//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int i, j, k;
    double temp, avg_temp, max_temp, min_temp;
    char filename[50];
    FILE *fp;
    struct tm *tm;
    time_t now;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    now = time(NULL);
    tm = localtime(&now);

    printf("Date and time: %d/%d/%d %d:%d:%d\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900, tm->tm_hour, tm->tm_min, tm->tm_sec);

    avg_temp = 0;
    max_temp = -999;
    min_temp = 999;

    while (fscanf(fp, "%lf", &temp)!= EOF) {
        if (temp > max_temp) {
            max_temp = temp;
        }
        if (temp < min_temp) {
            min_temp = temp;
        }
        avg_temp += temp;
        i++;
    }

    avg_temp /= i;

    printf("Average temperature: %.2lf\n", avg_temp);
    printf("Minimum temperature: %.2lf\n", min_temp);
    printf("Maximum temperature: %.2lf\n", max_temp);

    fclose(fp);

    return 0;
}