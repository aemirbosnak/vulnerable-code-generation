//FormAI DATASET v1.0 Category: File handling ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for recording surrealistic data
typedef struct {
    char object[20];
    char texture[20];
    char color[20];
} surreal_data;

int main() {
    FILE *fp;
    surreal_data data;

    // Open file in write mode
    fp = fopen("surreal_data.txt", "w");

    // Check if file opened successfully
    if (fp == NULL) {
        printf("Error opening file...\n");
        exit(1);
    }

    // Get surrealistic data from user and write to file
    printf("Enter surrealistic data:\n");
    printf("Object: ");
    fgets(data.object, 20, stdin);
    data.object[strcspn(data.object, "\n")] = 0;
    printf("Texture: ");
    fgets(data.texture, 20, stdin);
    data.texture[strcspn(data.texture, "\n")] = 0;
    printf("Color: ");
    fgets(data.color, 20, stdin);
    data.color[strcspn(data.color, "\n")] = 0;

    fprintf(fp, "%s, %s, %s\n", data.object, data.texture, data.color);

    // Close file
    fclose(fp);

    // Open file in read mode
    fp = fopen("surreal_data.txt", "r");

    // Check if file opened successfully
    if (fp == NULL) {
        printf("Error opening file...\n");
        exit(1);
    }

    // Read surrealistic data from file and print to console
    printf("\nHere is your surrealistic data:\n");
    fscanf(fp, "%[^,], %[^,], %[^\n]", data.object, data.texture, data.color);
    printf("Object: %s\n", data.object);
    printf("Texture: %s\n", data.texture);
    printf("Color: %s\n", data.color);

    // Close file
    fclose(fp);

    return 0;
}