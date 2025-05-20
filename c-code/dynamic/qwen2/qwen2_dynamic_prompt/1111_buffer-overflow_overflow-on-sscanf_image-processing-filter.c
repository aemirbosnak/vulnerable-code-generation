#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_image(const char* input) {
    char filename[256];
    int width, height;

    // Vulnerable sscanf call that can lead to buffer overflow
    if (sscanf(input, "%s %d %d", filename, &width, &height) != 3) {
        printf("Error parsing input\n");
        return;
    }

    // Simulate image processing
    printf("Processing image: %s with dimensions %dx%d\n", filename, width, height);
}

int main() {
    const char* malicious_input = "example.jpg 1000000000 1000000000";
    process_image(malicious_input);
    return 0;
}
