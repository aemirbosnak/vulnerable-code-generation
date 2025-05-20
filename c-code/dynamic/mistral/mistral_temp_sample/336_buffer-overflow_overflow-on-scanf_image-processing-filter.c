#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_image(char *buffer) {
    char image[100];
    char filter[100];
    printf("Enter Image File: ");
    scanf("%s", image);
    printf("Enter Filter File: ");
    scanf("%s", filter);

    FILE *img_file = fopen(image, "r");
    FILE *fil_file = fopen(filter, "r");

    if (img_file == NULL || fil_file == NULL) {
        printf("Error: File not found!\n");
        return;
    }

    fread(buffer, 1000, 1, img_file);
    fread(buffer + 1000, 1, 5000, fil_file);

    // Image processing using the filter buffer
    // (Code for filtering removed for brevity)

    fclose(img_file);
    fclose(fil_file);
}

int main() {
    char buffer[1000 + 5000];
    process_image(buffer);

    return 0;
}
