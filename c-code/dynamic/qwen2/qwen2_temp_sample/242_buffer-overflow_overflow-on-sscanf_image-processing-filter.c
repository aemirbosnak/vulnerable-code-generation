#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void process_image(const char* input_path) {
    FILE* file = fopen(input_path, "r");
    if (!file) {
        printf("Failed to open file\n");
        return;
    }

    int width, height;
    fscanf(file, "%d %d", &width, &height);
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), file)) {
        // Simulate image processing operation
        sscanf(buffer, "%*s %d", &height); // Vulnerable line with buffer overflow risk
    }

    fclose(file);
}

int main() {
    const char* input_path = "input.txt";
    process_image(input_path);
    return 0;
}
