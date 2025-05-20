//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get current temperature
float get_temperature(void)
{
    FILE *fp;
    char line[100];
    float temp = -1.0;

    fp = popen("vcgencmd measure_temp", "r");

    if (fp!= NULL)
    {
        fgets(line, sizeof(line), fp);
        pclose(fp);

        sscanf(line, "temp=%.2f", &temp);
    }

    return temp;
}

// function to log temperature
void log_temperature(float temp)
{
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    FILE *fp;
    char filename[50];

    sprintf(filename, "temperature_%04d%02d%02d_%02d%02d%02d.txt",
            tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
            tm->tm_hour, tm->tm_min, tm->tm_sec);

    fp = fopen(filename, "w");

    if (fp!= NULL)
    {
        fprintf(fp, "Temperature at %s: %.2f °C\n", ctime(&now), temp);
        fclose(fp);
    }
}

int main(void)
{
    float temp;

    while (1)
    {
        temp = get_temperature();

        if (temp!= -1.0)
        {
            printf("Current temperature: %.2f °C\n", temp);
            log_temperature(temp);
        }

        sleep(300);
    }

    return 0;
}