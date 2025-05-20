//FormAI DATASET v1.0 Category: Image Classification system ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("RETRO IMAGE CLASSIFICATION SYSTEM\n\n");

    // Load image
    unsigned char image[784];
    FILE *image_file = fopen("image.bin", "rb");
    if (!image_file) {
        printf("ERROR: Failed to open image file\n");
        exit(1);
    }
    fread(image, sizeof(image), 1, image_file);
    fclose(image_file);

    // Load weights
    float weights[784][10];
    FILE *weights_file = fopen("weights.bin", "rb");
    if (!weights_file) {
        printf("ERROR: Failed to open weights file\n");
        exit(1);
    }
    fread(weights, sizeof(weights), 1, weights_file);
    fclose(weights_file);

    // Perform classification
    int max_index = 0;
    float max_value = -1000000;
    for (int i = 0; i < 10; i++) {
        float sum = 0;
        for (int j = 0; j < 784; j++) {
            sum += image[j] / 255.0 * weights[j][i];
        }
        if (sum > max_value) {
            max_value = sum;
            max_index = i;
        }
    }

    // Print result
    printf("\nThe image was classified as a:\n");
    switch (max_index) {
        case 0:
            printf("    _______\n");
            printf("   /       \\\n");
            printf("  /   0 0   \\\n");
            printf(" (      ^      )\n");
            printf("  \\         /\n");
            printf("   \\_______/\n");
            break;
        case 1:
            printf("    _____\n");
            printf("  /      \\\n");
            printf(" |  0 0  |\n");
            printf(" |   -   |\n");
            printf("  \\_____/\n");
            break;
        case 2:
            printf("    _____\n");
            printf("  /      \\\n");
            printf(" |   /\\   |\n");
            printf(" |  /  \\  |\n");
            printf("  \\______/\n");
            break;
        case 3:
            printf("    _____\n");
            printf("  /      \\\n");
            printf(" |   0 0  |\n");
            printf(" |   ---  |\n");
            printf("  \\______/\n");
            break;
        case 4:
            printf("    _______\n");
            printf("   /       \\\n");
            printf("  /    o    \\\n");
            printf(" (          )\n");
            printf("  \\________/\n");
            break;
        case 5:
            printf("    _______\n");
            printf("   /       \\\n");
            printf("  /   0 0   \\\n");
            printf(" (     -     )\n");
            printf("  \\________/\n");
            break;
        case 6:
            printf("    _______\n");
            printf("   /       \\\n");
            printf("  /   0 0   \\\n");
            printf(" (      ~      )\n");
            printf("  \\________/\n");
            break;
        case 7:
            printf("    _______\n");
            printf("   /       \\\n");
            printf("  /   0 0   \\\n");
            printf(" (   \\___/  )\n");
            printf("  \\________/\n");
            break;
        case 8:
            printf("    _______\n");
            printf("   /       \\\n");
            printf("  /   0 0   \\\n");
            printf(" (    ___   )\n");
            printf("  \\________/\n");
            break;
        case 9:
            printf("    _____\n");
            printf("  /      \\\n");
            printf(" |   oo   |\n");
            printf(" |  /  \\  |\n");
            printf("  \\______/\n");
            break;
    }

    return 0;
}