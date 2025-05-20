//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

//function to flip an image
void flip_image(int **image, int n, int m){
    //code to flip image horizontally
    for(int i=0; i<n; i++){
        for(int j=0; j<m/2; j++){
            int temp = image[i][j];
            image[i][j] = image[i][m-j-1];
            image[i][m-j-1] = temp;
        }
    }
    //code to flip image vertically
    for(int j=0; j<m; j++){
        for(int i=0; i<n/2; i++){
            int temp = image[i][j];
            image[i][j] = image[n-i-1][j];
            image[n-i-1][j] = temp;
        }
    }
}

//function to change brightness and contrast of an image
void change_brightness_contrast(int **image, int n, int m, int brightness, int contrast){
    //code to change brightness and contrast of the image
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            image[i][j] = (int)(factor * (image[i][j] - 128) + 128 + brightness);
        }
    }
}
int main(){
    int n, m, brightness, contrast;
    printf("Enter the dimensions of the image (n and m): ");
    scanf("%d %d", &n, &m);
    //dynamically allocate memory for the image
    int **image = (int **)malloc(n * sizeof(int *));
    for(int i=0; i<n; i++){
        image[i] = (int *)malloc(m * sizeof(int));
    }
    printf("Enter the elements of the image: ");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &image[i][j]);
        }
    }
    printf("Enter the brightness value: ");
    scanf("%d", &brightness);
    printf("Enter the contrast value: ");
    scanf("%d", &contrast);
    //flip the image
    flip_image(image, n, m);
    //change brightness and contrast of the image
    change_brightness_contrast(image, n, m, brightness, contrast);
    printf("The processed image is: ");
    for(int i=0; i<n; i++){
        printf("\n");
        for(int j=0; j<m; j++){
            printf("%d ", image[i][j]);
        }
    }
    //free the dynamically allocated memory
    for(int i=0; i<n; i++){
        free(image[i]);
    }
    free(image);
    return 0;
}