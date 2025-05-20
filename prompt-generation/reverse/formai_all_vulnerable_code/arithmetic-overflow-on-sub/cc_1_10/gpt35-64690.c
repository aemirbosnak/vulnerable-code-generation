//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int is_number(char number[])
{
    int i;
    for (i = 0; number[i] != '\0'; i++)
    {
        if (!isdigit(number[i]))
            return 0;
    }
    return 1;
}

int get_cpu_usage()
{
    FILE *file_ptr = fopen("/proc/stat", "r");
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, file_ptr);
    fclose(file_ptr);

    char *token = strtok(buffer, " ");
    int counter = 0;
    int result;
    while (token != NULL)
    {
        if (counter == 0)
        {
            counter++;
        }
        else if (!is_number(token))
        {
            counter = 0;
            break;
        }
        else
        {
            result += atoi(token);
            counter++;
        }
        token = strtok(NULL, " ");
    }
    return result;
}

int main()
{
    int cpu_usage_1, cpu_usage_2, cpu_usage;
    while (1)
    {
        cpu_usage_1 = get_cpu_usage();
        usleep(500000);
        cpu_usage_2 = get_cpu_usage();
        cpu_usage = cpu_usage_2 - cpu_usage_1;
        if (cpu_usage > 90)
        {
            fprintf(stderr, "Alert! CPU usage is too high: %d\n", cpu_usage);
            exit(1);
        }
    }
    return 0;
}