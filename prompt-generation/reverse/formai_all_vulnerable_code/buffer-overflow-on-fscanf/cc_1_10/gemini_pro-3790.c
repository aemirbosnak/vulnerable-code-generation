//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int size;
    unsigned char *data;
} image_t;

typedef struct {
    char *name;
    int num_classes;
    char **classes;
    float **probs;
} classifier_t;

image_t *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    image_t *image = malloc(sizeof(image_t));
    if (!image) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    image->size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image->data = malloc(image->size);
    if (!image->data) {
        perror("malloc");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, 1, image->size, fp);
    fclose(fp);

    return image;
}

void free_image(image_t *image) {
    if (image) {
        if (image->data) {
            free(image->data);
        }
        free(image);
    }
}

classifier_t *load_classifier(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    classifier_t *classifier = malloc(sizeof(classifier_t));
    if (!classifier) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    classifier->name = malloc(ftell(fp) + 1);
    if (!classifier->name) {
        perror("malloc");
        fclose(fp);
        free(classifier);
        return NULL;
    }

    fseek(fp, 0, SEEK_SET);
    fread(classifier->name, 1, ftell(fp), fp);

    fscanf(fp, "%d", &classifier->num_classes);

    classifier->classes = malloc(classifier->num_classes * sizeof(char *));
    if (!classifier->classes) {
        perror("malloc");
        fclose(fp);
        free(classifier->name);
        free(classifier);
        return NULL;
    }

    for (int i = 0; i < classifier->num_classes; i++) {
        fscanf(fp, " %s", classifier->classes[i]);
    }

    classifier->probs = malloc(classifier->num_classes * sizeof(float *));
    if (!classifier->probs) {
        perror("malloc");
        fclose(fp);
        for (int i = 0; i < classifier->num_classes; i++) {
            free(classifier->classes[i]);
        }
        free(classifier->classes);
        free(classifier->name);
        free(classifier);
        return NULL;
    }

    for (int i = 0; i < classifier->num_classes; i++) {
        classifier->probs[i] = malloc(1000 * sizeof(float));
        if (!classifier->probs[i]) {
            perror("malloc");
            fclose(fp);
            for (int j = 0; j < i; j++) {
                free(classifier->probs[j]);
            }
            free(classifier->probs);
            for (int j = 0; j < classifier->num_classes; j++) {
                free(classifier->classes[j]);
            }
            free(classifier->classes);
            free(classifier->name);
            free(classifier);
            return NULL;
        }

        for (int j = 0; j < 1000; j++) {
            fscanf(fp, "%f", &classifier->probs[i][j]);
        }
    }

    fclose(fp);

    return classifier;
}

void free_classifier(classifier_t *classifier) {
    if (classifier) {
        if (classifier->probs) {
            for (int i = 0; i < classifier->num_classes; i++) {
                free(classifier->probs[i]);
            }
            free(classifier->probs);
        }
        if (classifier->classes) {
            for (int i = 0; i < classifier->num_classes; i++) {
                free(classifier->classes[i]);
            }
            free(classifier->classes);
        }
        if (classifier->name) {
            free(classifier->name);
        }
        free(classifier);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <image> <classifier>\n", argv[0]);
        return EXIT_FAILURE;
    }

    image_t *image = load_image(argv[1]);
    if (!image) {
        fprintf(stderr, "Error loading image\n");
        return EXIT_FAILURE;
    }

    classifier_t *classifier = load_classifier(argv[2]);
    if (!classifier) {
        fprintf(stderr, "Error loading classifier\n");
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    int guess = rand() % classifier->num_classes;

    printf("The image is a %s\n", classifier->classes[guess]);

    free_image(image);
    free_classifier(classifier);

    return EXIT_SUCCESS;
}