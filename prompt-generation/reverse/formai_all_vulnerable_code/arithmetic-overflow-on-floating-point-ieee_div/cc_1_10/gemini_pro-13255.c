//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define COLUMNS 80
#define ROWS 25
#define REFRESH_INTERVAL 1

enum {
    NORMAL = 0,
    IMPORTANT = 1
};

struct cpu_usage {
    float idle;
    float user;
};

char *usage_colors[] = {
    "\033[30m",
    "\033[31m"
};

char *row_colors[] = {
    "\033[43m",
    "\033[42m"
};

void get_cpu_usage(struct cpu_usage *usage)
{
    FILE *f = fopen("/proc/stat", "r");
    if (f == NULL) {
        perror("fopen");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), f) != NULL) {
        if (strncmp(line, "cpu ", 4) == 0) {
            unsigned long long idle, user, nice, system, io_wait, irq, softirq;
            sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu", &idle, &user, &nice, &system, &io_wait, &irq, &softirq);
            usage->idle = (float)idle / (float)(idle + user + nice + system + io_wait + irq + softirq) * 100.0;
            usage->user = (float)user / (float)(idle + user + nice + system + io_wait + irq + softirq) * 100.0;
            break;
        }
    }

    fclose(f);
}

void draw_bar(int x, int y, float value, int color)
{
    int width = (int)(value / 100.0 * COLUMNS);
    printf("\033[%d;%dH", y + 1, x + 1);
    printf("\033[40m");
    for (int i = 0; i < width; i++) {
        printf(" ");
    }
    printf("%s", usage_colors[color]);
    for (int i = width; i < COLUMNS; i++) {
        printf(" ");
    }
    printf("\033[0m");
}

void draw_grid()
{
    printf("\033[2J");
    printf("\033[1;1H");
    for (int y = 0; y < ROWS; y++) {
        printf("\033[%d;%dH", y + 1, 1);
        printf("%s", row_colors[y % 2]);
        for (int x = 0; x < COLUMNS; x++) {
            printf(" ");
        }
        printf("\033[0m");
    }
}

int main()
{
    struct cpu_usage usage;
    while (1) {
        get_cpu_usage(&usage);
        draw_grid();
        draw_bar(0, 0, usage.idle, NORMAL);
        draw_bar(0, 1, usage.user, IMPORTANT);
        printf("\033[%d;%dH", ROWS + 2, 1);
        printf("Idle: %.2f%% User: %.2f%%\n", usage.idle, usage.user);
        fflush(stdout);
        sleep(REFRESH_INTERVAL);
    }

    return 0;
}