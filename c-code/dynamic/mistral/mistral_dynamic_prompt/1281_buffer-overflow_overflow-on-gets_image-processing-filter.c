#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef unsigned char uint8_t;

void process_image(uint8_t* data, int size) {
    char buffer[10];
    char* args[] = {"-filter", buffer};
    char* argv[] = {"./image_processor", NULL};

    strcpy(buffer, gets(printf("Enter filter type: ")));
    for (int i = 0; i < size; ++i) {
        sprintf(buffer, "%d ", data[i]);
        argv[1] = args[0];
        argv[2] = buffer;
        system(argv[0]);
    }
}

int main() {
    const int image_size = 1000;
    uint8_t image_data[image_size];

    FILE* file = fopen("input.raw", "r");
    if (!file) {
        printf("Error: Could not open input file\n");
        return 1;
    }

    fread(image_data, sizeof(uint8_t), image_size, file);
    fclose(file);

    process_image(image_data, image_size);

    return 0;
}
