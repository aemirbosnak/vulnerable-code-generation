//MISTRAL-7B DATASET v1.0 Category: Smart home light control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <signal.h>
#include <time.h>

#define LIGHT_FILE "/dev/light_control"
#define BUF_SIZE 10

typedef struct {
    char name[32];
    int brightness;
    int pin;
} Light;

Light lights[10];

void sigint_handler(int signum) {
    for (int i = 0; i < 10; i++) {
        int fd = open(lights[i].name, O_RDWR);
        write(fd, "0\n", 2);
        close(fd);
    }
    exit(EXIT_SUCCESS);
}

int main() {
    signal(SIGINT, sigint_handler);

    int ret;
    int fd;
    char buf[BUF_SIZE];
    char light_name[32];

    for (int i = 0; i < 10; i++) {
        printf("Enter light name and pin number: ");
        scanf("%s %d", light_name, &lights[i].pin);
        strcpy(lights[i].name, light_name);

        fd = open(light_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
        write(fd, "OFF\n", 4);
        close(fd);
    }

    while (1) {
        printf("\nCurrent lights:\n");
        for (int i = 0; i < 10; i++) {
            printf("%s - %s\n", lights[i].name, (lights[i].brightness > 0) ? "ON" : "OFF");
        }

        printf("\nEnter command for light (number or name): ");
        scanf("%s", buf);

        int index = -1;
        for (int i = 0; i < 10; i++) {
            if (strcmp(lights[i].name, buf) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("Invalid light number or name.\n");
            continue;
        }

        printf("Enter new brightness for light %s: ", buf);
        scanf("%d", &lights[index].brightness);

        fd = open(lights[index].name, O_RDWR);
        snprintf(buf, BUF_SIZE, "%d\n", lights[index].brightness);
        write(fd, buf, strlen(buf) + 1);
        close(fd);
    }

    return EXIT_SUCCESS;
}