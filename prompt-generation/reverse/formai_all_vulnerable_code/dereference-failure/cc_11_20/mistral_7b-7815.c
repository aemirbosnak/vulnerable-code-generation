//MISTRAL-7B DATASET v1.0 Category: Traffic Light Controller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

typedef struct {
    int state;
    char magic[4];
} traffic_light;

int main(int argc, char **argv) {

    traffic_light lights[3];
    int fd[3];
    int i, j, k;
    char filename[10];

    for (i = 0; i < 3; i++) {
        lights[i].state = RED_LIGHT;
        strcpy(lights[i].magic, "TL");
        fd[i] = open(argv[i + 1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        write(fd[i], &lights[i], sizeof(traffic_light));
        close(fd[i]);
    }

    while (1) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (i != j) {
                    fd[i] = open(argv[i + 1], O_RDONLY);
                    read(fd[i], &lights[i], sizeof(traffic_light));
                    close(fd[i]);

                    if (lights[i].state == lights[j].state) {
                        for (k = 0; k < 3; k++) {
                            if (k != i && k != j) {
                                fd[k] = open(argv[k + 1], O_WRONLY);
                                lights[k].state = (lights[i].state == RED_LIGHT) ? GREEN_LIGHT : (lights[i].state == GREEN_LIGHT) ? YELLOW_LIGHT : RED_LIGHT;
                                write(fd[k], &lights[k], sizeof(traffic_light));
                                close(fd[k]);
                                break;
                            }
                        }
                    }
                }
                usleep(500000);
            }

            if (lights[i].state == lights[j].state && lights[i].state == lights[k].state) {
                for (j = 0; j < 3; j++) {
                    if (j != i) {
                        fd[j] = open(argv[j + 1], O_WRONLY);
                        lights[j].state = (lights[i].state == RED_LIGHT) ? GREEN_LIGHT : (lights[i].state == GREEN_LIGHT) ? YELLOW_LIGHT : RED_LIGHT;
                        write(fd[j], &lights[j], sizeof(traffic_light));
                        close(fd[j]);
                    }
                }
                usleep(1000000);
            }
        }
    }

    return 0;
}