#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_image(char* filename) {
    int width, height;
    FILE* file = fopen(filename, "r");

    char buffer[10];
    char data[1024 * 1024 * 3]; // Buffer for image data (3 bytes per pixel for RGB)

    if (file) {
        fscanf(file, "%s %s %d %d", buffer, buffer, &width, &height);
        fread(data, sizeof(char), width * height * 3, file);
        fclose(file);

        // Process the image data... (I'm not doing that in this example)
    }

    char malicious_data[512];
    sprintf(malicious_data, "%s%s%d%s%d", "A" // valid data
        "%n%1024s" // overflow the width variable
        "%s", "B" // more valid data
    );

    char vulnerable[10];
    sscanf(malicious_data, "%s %s %d %s", vulnerable, vulnerable, &width, vulnerable);
    printf("Width: %d\n", width); // Segmentation fault due to buffer overflow
}

int main() {
    process_image("input.img");
    return 0;
}
