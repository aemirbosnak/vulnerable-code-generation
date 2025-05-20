//Gemma-7B DATASET v1.0 Category: Temperature monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_READ_SIZE 1024

char **read_file_contents(char *filename)
{
    FILE *fp;
    char **contents = NULL;
    int size = 0;

    fp = fopen(filename, "r");
    if (fp)
    {
        fseek(fp, 0L, SEEK_END);
        size = ftell(fp);
        contents = malloc(size);
        fseek(fp, 0L, SEEK_SET);
        fread(contents, size, 1, fp);
        fclose(fp);
    }

    return contents;
}

int main()
{
    char **sensors_data = NULL;
    char sensor_data_filename[] = "/home/pi/sensors.txt";

    sensors_data = read_file_contents(sensor_data_filename);

    if (sensors_data)
    {
        for (int i = 0; sensors_data[i] != NULL; i++)
        {
            char sensor_name[MAX_READ_SIZE];
            char sensor_temp[MAX_READ_SIZE];

            sscanf(sensors_data[i], "%s %f", sensor_name, sensor_temp);

            printf("Sensor: %s, Temperature: %f\n", sensor_name, atof(sensor_temp));
        }

        free(sensors_data);
    }

    return 0;
}