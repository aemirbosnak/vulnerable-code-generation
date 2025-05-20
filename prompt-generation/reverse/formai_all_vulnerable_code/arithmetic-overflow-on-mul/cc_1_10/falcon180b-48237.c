//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define MODULE_SIZE 3
#define QUIET_ZONE 2
#define MAX_VALUE 9

void print_qrcode(char *data, int width, int height) {
    int i, j, value, mask = 1;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            value = data[i * width + j] - '0';
            if (value >= MAX_VALUE) {
                printf("X");
            } else if (value == 0) {
                printf(" ");
            } else {
                printf("%d", value);
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int width, height;
    printf("Enter the width of the QR code (max %d): ", WIDTH);
    scanf("%d", &width);
    if (width > WIDTH) {
        width = WIDTH;
    }
    printf("Enter the height of the QR code (max %d): ", HEIGHT);
    scanf("%d", &height);
    if (height > HEIGHT) {
        height = HEIGHT;
    }
    char *data = malloc(width * height + 1);
    data[width * height] = '\0';
    for (int i = 0; i < width * height; i++) {
        data[i] = rand() % MAX_VALUE + '0';
    }
    printf("Generated QR code:\n");
    print_qrcode(data, width, height);
    free(data);
    return 0;
}