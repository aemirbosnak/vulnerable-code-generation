//Code Llama-13B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_INPUT_LENGTH 128

typedef struct {
    char name[MAX_INPUT_LENGTH];
    float x_pos;
    float y_pos;
    float z_pos;
    float speed;
    float direction;
    bool is_alive;
} Alien;

void get_input(Alien *alien) {
    char buffer[MAX_BUFFER_SIZE];
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    sscanf(buffer, "%s %f %f %f %f %f %d", alien->name, &alien->x_pos, &alien->y_pos, &alien->z_pos, &alien->speed, &alien->direction, &alien->is_alive);
}

float calculate_probability(Alien alien) {
    float probability = 1.0f;
    if (alien.x_pos < 0) {
        probability *= 0.9f;
    } else if (alien.x_pos > 1000) {
        probability *= 0.8f;
    }
    if (alien.y_pos < 0) {
        probability *= 0.7f;
    } else if (alien.y_pos > 1000) {
        probability *= 0.6f;
    }
    if (alien.z_pos < 0) {
        probability *= 0.5f;
    } else if (alien.z_pos > 1000) {
        probability *= 0.4f;
    }
    if (alien.speed < 10) {
        probability *= 0.3f;
    } else if (alien.speed > 100) {
        probability *= 0.2f;
    }
    if (alien.direction < 0) {
        probability *= 0.1f;
    } else if (alien.direction > 100) {
        probability *= 0.01f;
    }
    return probability;
}

int main() {
    Alien alien;
    get_input(&alien);
    printf("Probability of alien invasion: %.2f%%\n", calculate_probability(alien) * 100);
    return 0;
}