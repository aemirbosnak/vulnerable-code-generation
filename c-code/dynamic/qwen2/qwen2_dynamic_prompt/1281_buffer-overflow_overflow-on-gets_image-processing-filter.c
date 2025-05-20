#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct {
    unsigned char data[MAX_IMAGE_SIZE];
} Image;

void apply_filter(Image *img, const char *filter) {
    int len = strlen(filter);
    if (len > MAX_IMAGE_SIZE - 1) {
        printf("Filter too long\n");
        return;
    }
    strcpy(img->data, filter);
}

int main() {
    Image img;
    char filter[2048];

    printf("Enter an image filter: ");
    gets(filter); // Vulnerable to buffer overflow

    apply_filter(&img, filter);

    printf("Filtered image: %s\n", img.data);

    return 0;
}
