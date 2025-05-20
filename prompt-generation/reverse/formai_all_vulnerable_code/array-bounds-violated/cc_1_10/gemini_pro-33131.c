//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LIGHTS 16
#define MAX_NAME_LENGTH 32
#define MAX_STATUS_LENGTH 16

struct light {
    char name[MAX_NAME_LENGTH];
    bool on;
    char status[MAX_STATUS_LENGTH];
};

struct light lights[MAX_LIGHTS];
int num_lights = 0;

void load_lights() {
    FILE *f = fopen("lights.txt", "r");
    if (f == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), f)) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        char *name = strtok(line, ",");
        char *on = strtok(NULL, ",");
        char *status = strtok(NULL, ",");

        if (name == NULL || on == NULL || status == NULL) {
            fprintf(stderr, "Invalid light data: %s\n", line);
            continue;
        }

        struct light light;
        strncpy(light.name, name, sizeof(light.name));
        light.on = atoi(on);
        strncpy(light.status, status, sizeof(light.status));

        lights[num_lights++] = light;
    }

    fclose(f);
}

void print_lights() {
    for (int i = 0; i < num_lights; i++) {
        printf("%s: %s (%s)\n", lights[i].name, lights[i].on ? "on" : "off", lights[i].status);
    }
}

void toggle_light(char *name) {
    for (int i = 0; i < num_lights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].on = !lights[i].on;
            snprintf(lights[i].status, sizeof(lights[i].status), "%s", lights[i].on ? "on" : "off");
            break;
        }
    }
}

void set_light_status(char *name, char *status) {
    for (int i = 0; i < num_lights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            strncpy(lights[i].status, status, sizeof(lights[i].status));
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    load_lights();
    print_lights();

    if (argc >= 3) {
        if (strcmp(argv[1], "toggle") == 0) {
            toggle_light(argv[2]);
        } else if (strcmp(argv[1], "status") == 0) {
            set_light_status(argv[2], argv[3]);
        } else {
            fprintf(stderr, "Invalid command: %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }

        print_lights();
    }

    return EXIT_SUCCESS;
}