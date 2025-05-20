//MISTRAL-7B DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <string.h>

#define MAX_CHAR 100

typedef struct Temperature {
    float current;
    char name[MAX_CHAR];
} Temperature;

void get_cpu_temp(Temperature* temp) {
    FILE* file;
    char line[1024];
    char temp_str[MAX_CHAR];
    char* token;

    file = popen("cat /proc/cpuinfo | grep '^temparature:' | awk -F ':' '{ print $2, $3 }' | tail -n 1", "r");
    if (file == NULL) {
        printf("Failed to open file!\n");
        exit(1);
    }

    fgets(line, sizeof(line), file);
    pclose(file);

    strcpy(temp_str, line);
    token = strtok(temp_str, " ");

    strcpy(temp->name, "CPU");
    sscanf(token, "%f", &temp->current);
}

void get_mb_temp(Temperature* temp) {
    FILE* file;
    char line[1024];
    char temp_str[MAX_CHAR];
    char* token;

    file = popen("sensors | grep -i 'core' | awk '{ print $3, $4 }' | tail -n 1", "r");
    if (file == NULL) {
        printf("Failed to open file!\n");
        exit(1);
    }

    fgets(line, sizeof(line), file);
    pclose(file);

    strcpy(temp_str, line);
    token = strtok(temp_str, " ");

    strcpy(temp->name, "Motherboard");
    sscanf(token, "%f", &temp->current);
}

int main() {
    Temperature cpu, mb;

    while (1) {
        get_cpu_temp(&cpu);
        get_mb_temp(&mb);

        printf("\nTemperature Monitor\n");
        printf("--------------------\n");
        printf("Temperature Info:\n");
        printf("%s: %.2f°C\n", cpu.name, cpu.current);
        printf("%s: %.2f°C\n", mb.name, mb.current);

        sleep(5);
    }

    return 0;
}