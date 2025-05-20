#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_image(const char *input) {
    char filename[256];
    int width, height;

    // Vulnerable to buffer overflow due to lack of bounds checking
    sscanf(input, "%s %d %d", filename, &width, &height);

    printf("Processing image: %s with dimensions %dx%d\n", filename, width, height);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_description>\n", argv[0]);
        return 1;
    }

    process_image(argv[1]);

    return 0;
}
