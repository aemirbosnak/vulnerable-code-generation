#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISTANCE 255

typedef struct {
    char command[10];
    int distance;
} Control;

void process_input(Control* input) {
    if (strncmp(input->command, "forward", 7) == 0) {
        input->distance += 100;
        if (input->distance > MAX_DISTANCE)
            input->distance = MAX_DISTANCE;
    } else if (strncmp(input->command, "backward", 8) == 0) {
        input->distance -= 100;
        if (input->distance < 0)
            input->distance = 0;
    }
}

int main(int argc, char* argv[]) {
    Control input;
    int i;

    for (i = 1; i < argc; i++) {
        strcpy(input.command, argv[i]);
        process_input(&input);

        printf("Moving %s: %d units\n", input.command, input.distance);
    }

    return 0;
}
