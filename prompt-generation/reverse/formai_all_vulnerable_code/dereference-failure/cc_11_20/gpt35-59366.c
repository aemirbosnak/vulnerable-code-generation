//FormAI DATASET v1.0 Category: Image Classification system ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_classes = 5;
    int image_size = 500;
    
    int** images = (int**) malloc(num_classes * sizeof(int*));
    for(int i = 0; i < num_classes; i++){
        images[i] = (int*) malloc(image_size * sizeof(int));
    }
    
    int* labels = (int*) malloc(num_classes * sizeof(int));
    
    printf("Welcome to our Cryptic Image Classification System\n");
    printf("Enter the images for each class and the corresponding label\n");
    
    for(int i = 0; i < num_classes; i++){
        printf("Enter the images for class %d:\n", i);
        for(int j = 0; j < image_size; j++){
            scanf("%d", &images[i][j]);
        }
        printf("Enter the label for class %d:\n", i);
        scanf("%d", &labels[i]);
    }
    
    printf("Training complete!\n");
    
    int num_test_images = 10;
    int** test_images = (int**) malloc(num_test_images * sizeof(int*));
    for(int i = 0; i < num_test_images; i++){
        test_images[i] = (int*) malloc(image_size * sizeof(int));
    }
    
    printf("Enter the test images:\n");
    for(int i = 0; i < num_test_images; i++){
        printf("Test image %d:\n", i);
        for(int j = 0; j < image_size; j++){
            scanf("%d", &test_images[i][j]);
        }
    }
    
    printf("Testing complete!\n");
    
    int* predicted_labels = (int*) malloc(num_test_images * sizeof(int));
    
    for(int i = 0; i < num_test_images; i++){
        int max_class = 0;
        int max_score = 0;
        for(int j = 0; j < num_classes; j++){
            int score = 0;
            for(int k = 0; k < image_size; k++){
                score += images[j][k] * test_images[i][k];
            }
            if(score > max_score){
                max_class = j;
                max_score = score;
            }
        }
        predicted_labels[i] = labels[max_class];
    }
    
    printf("Predicted labels:\n");
    for(int i = 0; i < num_test_images; i++){
        printf("%d ", predicted_labels[i]);
    }
    printf("\n");
    
    return 0;
}