//FormAI DATASET v1.0 Category: Image Classification system ; Style: post-apocalyptic
#include <stdio.h>

#define NUM_OF_CLASSES 5

char* class_labels[NUM_OF_CLASSES] = {
    "Survivor",
    "Raider",
    "Mutant",
    "Zombie",
    "Alien"
};

float compute_similarity(float data[], float weights[], int num_features){
    float similarity = 0.0;
    for(int i=0;i<num_features;i++){
        similarity += data[i] * weights[i];
    }
    return similarity;
}

int predict_class(float data[], float weights[][NUM_OF_CLASSES], int num_features){
    float similarities[NUM_OF_CLASSES];
    for(int i=0;i<NUM_OF_CLASSES;i++){
        similarities[i] = compute_similarity(data, weights[i], num_features);
    }
    int max_index = 0;
    float max_val = similarities[0];
    for(int i=1;i<NUM_OF_CLASSES;i++){
        if(similarities[i] > max_val){
            max_val = similarities[i];
            max_index = i;
        }
    }
    return max_index;
}

int main(){
    printf("Welcome to the post-apocalyptic image classification system!\n");

    // initialize weights for each class
    float weights[NUM_OF_CLASSES][4] = {
        {0.2, 3.4, 0.5, 1.2},
        {1.7, 0.1, 2.3, 0.5},
        {3.2, 1.8, 0.6, 2.9},
        {0.8, 0.2, 2.5, 1.1},
        {0.9, 2.1, 1.3, 3.0}
    };

    printf("Enter image features: ");
    float data[4];
    scanf("%f %f %f %f", &data[0], &data[1], &data[2], &data[3]);

    int predicted_class = predict_class(data, weights, 4);

    printf("The image is classified as: %s", class_labels[predicted_class]);

    return 0;
}