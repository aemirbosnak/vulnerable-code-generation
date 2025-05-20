//FormAI DATASET v1.0 Category: Image Classification system ; Style: Claude Shannon
// C Image Classification System Example Program
// by the genius of communication theory - Claude Shannon

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initializing variables and arrays
    int i, j, k, classes, samples, features;
    float **data;
    float **cMeans;
    float **distances;
    float *sum;
    int *count;

    // Reading the input data
    printf("Enter the number of classes: ");
    scanf("%d", &classes);
    printf("Enter the number of samples per class: ");
    scanf("%d", &samples);
    printf("Enter the number of features per sample: ");
    scanf("%d", &features);
    data = (float**)malloc(classes * samples * sizeof(float));
    for(i = 0; i < classes * samples; i++) {
        data[i] = (float*)malloc(features * sizeof(float));
    }
    printf("Enter the data:\n");
    for(i = 0; i < classes * samples; i++) {
        for(j = 0; j < features; j++) {
            scanf("%f", &data[i][j]);
        }
    }

    // Initializing the cMeans array
    cMeans = (float**)malloc(classes * sizeof(float*));
    for(i = 0; i < classes; i++) {
        cMeans[i] = (float*)malloc(features * sizeof(float));
    }

    // Calculating the cMeans
    for(i = 0; i < classes; i++) {
        for(j = 0; j < features; j++) {
            sum[j] = 0.0;
            count[j] = 0;
        }
        for(j = 0; j < samples; j++) {
            for(k = 0; k < features; k++) {
                sum[k] += data[i * samples + j][k];
                count[k]++;
            }
        }
        for(j = 0; j < features; j++) {
            cMeans[i][j] = sum[j] / count[j];
        }
    }

    // Initializing the distances array
    distances = (float**)malloc(classes * samples * sizeof(float));
    for(i = 0; i < classes * samples; i++) {
        distances[i] = (float*)malloc(classes * sizeof(float));
    }

    // Calculating the distances
    for(i = 0; i < classes * samples; i++) {
        for(j = 0; j < classes; j++) {
            distances[i][j] = 0.0;
            for(k = 0; k < features; k++) {
                distances[i][j] += (data[i][k] - cMeans[j][k]) * (data[i][k] - cMeans[j][k]);
            }
        }
    }

    // Classifying the samples
    int *classification;
    classification = (int*)malloc(classes * samples * sizeof(int));
    for(i = 0; i < classes * samples; i++) {
        float min_distance = distances[i][0];
        int min_index = 0;
        for(j = 1; j < classes; j++) {
            if(distances[i][j] < min_distance) {
                min_distance = distances[i][j];
                min_index = j;
            }
        }
        classification[i] = min_index;
    }

    // Outputting the results
    printf("Classifications:\n");
    for(i = 0; i < classes * samples; i++) {
        printf("%d ", classification[i]);
        if((i + 1) % samples == 0) {
            printf("\n");
        }
    }

    // Cleaning up memory
    for(i = 0; i < classes * samples; i++) {
        free(data[i]);
    }
    free(data);
    for(i = 0; i < classes; i++) {
        free(cMeans[i]);
    }
    free(cMeans);
    for(i = 0; i < classes * samples; i++) {
        free(distances[i]);
    }
    free(distances);
    free(classification);

    return 0;
}