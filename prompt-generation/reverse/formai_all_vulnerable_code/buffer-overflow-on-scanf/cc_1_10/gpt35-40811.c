//FormAI DATASET v1.0 Category: Image Editor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void load_image(int **image, int *rows, int *cols);
void display_image(int **image, int rows, int cols);
void invert_image(int **image, int rows, int cols);
void save_image(int **image, int rows, int cols);

int main() {
    int **image, rows, cols, choice;
    
    printf("Welcome to the C Image Editor!\n");
    
    load_image(image, &rows, &cols);
    
    do {
        printf("\nMenu:\n1. Display Image\n2. Invert Image\n3. Save Image\n4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                display_image(image, rows, cols);
                break;
            
            case 2:
                invert_image(image, rows, cols);
                printf("Image inverted successfully!\n");
                break;
            
            case 3:
                save_image(image, rows, cols);
                printf("Image saved successfully!\n");
                break;
            
            case 4:
                printf("Exiting...\n");
                break;
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
    } while(choice != 4);
    
    // Free dynamically allocated memory
    for(int i=0; i<rows; i++) {
        free(image[i]);
    }
    free(image);
    
    return 0;
}

// Function to load image from file
void load_image(int **image, int *rows, int *cols) {
    FILE *file;
    int temp;
    
    file = fopen("image.txt", "r");
    if(file == NULL) {
        printf("Error opening image file!\n");
        exit(1);
    }
    
    fscanf(file, "%d %d", rows, cols);
    
    // Create 2D dynamic array for image
    image = (int **)malloc(*rows * sizeof(int *));
    for(int i=0; i<*rows; i++) {
        image[i] = (int *)malloc(*cols * sizeof(int));
    }
    
    for(int i=0; i<*rows; i++) {
        for(int j=0; j<*cols; j++) {
            fscanf(file, "%d", &temp);
            image[i][j] = temp;
        }
    }
    
    fclose(file);
}

// Function to display image on the console
void display_image(int **image, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

// Function to invert image
void invert_image(int **image, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            image[i][j] = 255 - image[i][j];
        }
    }
}

// Function to save image to file
void save_image(int **image, int rows, int cols) {
    FILE *file;
    
    file = fopen("new_image.txt", "w");
    if(file == NULL) {
        printf("Error opening output file!\n");
        exit(1);
    }
    
    fprintf(file, "%d %d\n", rows, cols);
    
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            fprintf(file, "%d ", image[i][j]);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
}