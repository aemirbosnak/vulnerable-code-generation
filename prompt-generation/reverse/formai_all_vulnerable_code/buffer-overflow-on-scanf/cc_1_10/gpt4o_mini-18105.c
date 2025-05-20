//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <dirent.h>
#include <stdint.h>

#define IMAGE_WIDTH 32
#define IMAGE_HEIGHT 32
#define NUM_CLASSES 10
#define CLASS_NAMES {"Neon", "Grit", "Tech", "Synth", "Cyber", "Glow", "Rogue", "Byte", "Hacker", "Clone"}

typedef struct {
    uint8_t pixels[IMAGE_WIDTH][IMAGE_HEIGHT];
    char *class_label;
} Image;

float calculate_similarity(uint8_t img1[IMAGE_WIDTH][IMAGE_HEIGHT], uint8_t img2[IMAGE_WIDTH][IMAGE_HEIGHT]) {
    float score = 0.0;
    for (int i = 0; i < IMAGE_WIDTH; i++) {
        for (int j = 0; j < IMAGE_HEIGHT; j++) {
            score += (img1[i][j] == img2[i][j]) ? 1.0 : 0.0;
        }
    }
    return score / (IMAGE_WIDTH * IMAGE_HEIGHT);
}

Image load_image(const char *file_path) {
    Image img;
    memset(&img, 0, sizeof(img));

    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Failed to open image file");
        exit(EXIT_FAILURE);
    }

    fread(img.pixels, sizeof(uint8_t), IMAGE_WIDTH * IMAGE_HEIGHT, file);
    fclose(file);
    img.class_label = "Unidentified";

    return img;
}

void classify_image(Image *img, Image *catalog, size_t catalog_size) {
    float best_similarity = -1;
    for (size_t i = 0; i < catalog_size; i++) {
        float similarity = calculate_similarity(img->pixels, catalog[i].pixels);
        if (similarity > best_similarity) {
            best_similarity = similarity;
            img->class_label = catalog[i].class_label;
        }
    }
}

void load_catalog(Image **catalog, size_t *catalog_size) {
    *catalog_size = 0;
    struct dirent *entry;
    DIR *dp = opendir("catalog");
    if (dp == NULL) {
        perror("Unable to open catalog directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            *catalog_size += 1;
        }
    }
    rewinddir(dp);

    *catalog = malloc(*catalog_size * sizeof(Image));
    size_t index = 0;

    const char *classes[] = CLASS_NAMES;

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) {
            char path[256];
            snprintf(path, sizeof(path), "catalog/%s", entry->d_name);
            (*catalog)[index] = load_image(path);
            (*catalog)[index].class_label = classes[index % NUM_CLASSES];
            index++;
        }
    }
    closedir(dp);
}

void print_classification(Image *img) {
    printf("Classification Result: %s\n", img->class_label);
}

int main() {
    Image *catalog = NULL;
    size_t catalog_size = 0;

    load_catalog(&catalog, &catalog_size);

    char file_path[256];
    printf("Enter the path to the image file for classification: ");
    scanf("%s", file_path);

    Image input_image = load_image(file_path);
    classify_image(&input_image, catalog, catalog_size);
    print_classification(&input_image);

    free(catalog);
    return 0;
}