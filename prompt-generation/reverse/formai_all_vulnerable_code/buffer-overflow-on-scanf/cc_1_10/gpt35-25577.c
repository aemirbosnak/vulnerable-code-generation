//FormAI DATASET v1.0 Category: Image Editor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_TRANSFORMS 10

typedef struct Transform{
    char name[20];
    void (* func)(int**, int, int);
} Transform;

Transform transforms[MAX_TRANSFORMS];
int transform_count = 0;

void decrease_brightness(int** image, int width, int height){
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if(image[i][j] > 0)
                image[i][j]--;
        }
    }
}

void mirror_horizontally(int** image, int width, int height){
    for(int i=0; i<height; i++){
        for(int j=0; j<width/2; j++){
            int temp = image[i][j];
            image[i][j] = image[i][width-1-j];
            image[i][width-1-j] = temp;
        }
    }
}

void add_transform(char* name, void (* func)(int**, int, int)){
    transform_count++;
    strcpy(transforms[transform_count-1].name, name);
    transforms[transform_count-1].func = func;
}

void print_transforms(){
    printf("Available Transforms:\n");
    for(int i=0; i<transform_count; i++){
        printf("%s\n", transforms[i].name);
    }
}

int main(){
    char filename[MAX_FILENAME_LEN];
    printf("Enter the filename of the image to edit: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if(!file){
        printf("ERROR: File not found.\n");
        return 1;
    }

    int width, height;
    fscanf(file, "%d %d", &width, &height);

    int** image = malloc(height * sizeof(int*));
    for(int i=0; i<height; i++){
        image[i] = malloc(width * sizeof(int));
        for(int j=0; j<width; j++){
            fscanf(file, "%d", &image[i][j]);
        }
    }
    fclose(file);

    add_transform("Decrease Brightness", decrease_brightness);
    add_transform("Mirror Horizontally", mirror_horizontally);
    // Add more transforms here.

    printf("Original Image:\n");
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    int choice;
    while(1){
        printf("What transform would you like to apply? (Enter -1 to quit)\n");
        print_transforms();
        scanf("%d", &choice);

        if(choice == -1)
            break;

        if(choice < 0 || choice >= transform_count){
            printf("Invalid choice\n");
            continue;
        }

        transforms[choice].func(image, width, height);
        printf("Transform Applied: %s\n", transforms[choice].name);
        printf("Transformed Image:\n");
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                printf("%d ", image[i][j]);
            }
            printf("\n");
        }
    }

    // Write the modified image to a file.
    char new_filename[MAX_FILENAME_LEN];
    printf("Enter the filename to save the modified image: ");
    scanf("%s", new_filename);

    file = fopen(new_filename, "w");
    if(!file){
        printf("ERROR: Failed to create new file.\n");
        return 1;
    }

    fprintf(file, "%d %d\n", width, height);
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            fprintf(file, "%d ", image[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);

    // Free the image memory.
    for(int i=0; i<height; i++){
        free(image[i]);
    }
    free(image);

    return 0;
}