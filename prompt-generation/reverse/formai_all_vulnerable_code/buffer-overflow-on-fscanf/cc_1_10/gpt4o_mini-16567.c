//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLOWERS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float petal_length;
    float petal_width;
    char classification[NAME_LENGTH];
} Flower;

void classify_flower(Flower *flower) {
    // Simple classification based on petal dimensions
    if (flower->petal_length < 2.0) {
        strcpy(flower->classification, "Setosa");
    } else if (flower->petal_length < 5.0) {
        strcpy(flower->classification, "Versicolor");
    } else {
        strcpy(flower->classification, "Virginica");
    }
}

void load_flowers_from_file(Flower *flowers, int *flower_count) {
    FILE *file = fopen("flowers.txt", "r");
    if (file == NULL) {
        printf("Could not open flowers.txt file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %f %f", flowers[*flower_count].name,
                   &flowers[*flower_count].petal_length,
                   &flowers[*flower_count].petal_width) == 3) {
        classify_flower(&flowers[*flower_count]);
        (*flower_count)++;
        if (*flower_count >= MAX_FLOWERS) {
            break;
        }
    }

    fclose(file);
}

void display_flowers(Flower *flowers, int flower_count) {
    printf("\nFlower Classification Results:\n");
    printf("--------------------------------\n");
    for (int i = 0; i < flower_count; i++) {
        printf("Name: %s, Petal Length: %.2f, Petal Width: %.2f, Classification: %s\n",
               flowers[i].name,
               flowers[i].petal_length,
               flowers[i].petal_width,
               flowers[i].classification);
    }
}

void save_classified_flowers(Flower *flowers, int flower_count) {
    FILE *file = fopen("classified_flowers.txt", "w");
    if (file == NULL) {
        printf("Could not open classified_flowers.txt file for writing.\n");
        return;
    }
    
    for (int i = 0; i < flower_count; i++) {
        fprintf(file, "%s %.2f %.2f %s\n",
                flowers[i].name,
                flowers[i].petal_length,
                flowers[i].petal_width,
                flowers[i].classification);
    }

    fclose(file);
}

int main() {
    Flower flowers[MAX_FLOWERS];
    int flower_count = 0;

    printf("Welcome to the Flower Data Mining Program!\n");
    load_flowers_from_file(flowers, &flower_count);
    display_flowers(flowers, flower_count);
    save_classified_flowers(flowers, flower_count);

    printf("Classified flower results are saved in classified_flowers.txt.\n");
    return 0;
}