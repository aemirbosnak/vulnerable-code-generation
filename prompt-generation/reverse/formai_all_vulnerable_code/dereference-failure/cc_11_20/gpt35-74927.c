//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

int main() {
    int survivors = 100; // Number of survivors
    int **coordinates = malloc(survivors * sizeof(int*)); // 2D Coordinate array for survivors
    int clusters = 0; // Number of clusters
    int **centers = malloc(clusters * sizeof(int*)); // 2D Coordinate array for cluster centers
    
    // Generate random coordinates for survivors
    for(int i = 0; i < survivors; i++){
        coordinates[i] = malloc(2 * sizeof(int));
        coordinates[i][0] = rand() % 100;
        coordinates[i][1] = rand() % 100;
    }

    // Run clustering algorithm until all survivors are in clusters
    while(survivors > 0) {
        clusters++; // Increment cluster count
        centers = realloc(centers, clusters * sizeof(int*)); // Allocate memory for new cluster center
        centers[clusters-1] = malloc(2 * sizeof(int)); // Allocate memory for 2D coordinate array of center
        centers[clusters-1][0] = coordinates[0][0]; // Set initial center as first survivor
        centers[clusters-1][1] = coordinates[0][1];
        int members = 1; // Number of members in new cluster
        int *members_list = malloc(survivors * sizeof(int)); // List of indices of new cluster members
        members_list[0] = 0;
        
        // Find nearest survivor for center of new cluster
        for(int i = 1; i < survivors; i++) {
            int current_distance = abs(coordinates[i][0] - centers[clusters-1][0]) + abs(coordinates[i][1] - centers[clusters-1][1]);
            int best_distance = abs(coordinates[members_list[0]][0] - centers[clusters-1][0]) + abs(coordinates[members_list[0]][1] - centers[clusters-1][1]);
            if(current_distance < best_distance) {
                members_list[0] = i;
            }
        }
        
        // Add nearby survivors to new cluster
        for(int i = 1; i < survivors; i++) {
            int current_distance = abs(coordinates[i][0] - centers[clusters-1][0]) + abs(coordinates[i][1] - centers[clusters-1][1]);
            int best_distance = abs(coordinates[members_list[0]][0] - centers[clusters-1][0]) + abs(coordinates[members_list[0]][1] - centers[clusters-1][1]);
            
            // If distance is less than or equal to 10 units, add to new cluster
            if(current_distance <= 10) {
                members++;
                members_list = realloc(members_list, members * sizeof(int));
                members_list[members-1] = i;
                
                // Update center of new cluster
                centers[clusters-1][0] = (centers[clusters-1][0] * (members-1) + coordinates[i][0]) / members;
                centers[clusters-1][1] = (centers[clusters-1][1] * (members-1) + coordinates[i][1]) / members;
            }
        }
        
        // Remove survivors from global coordinate array
        for(int i = members-1; i >= 0; i--) {
            int index = members_list[i];
            for(int j = index; j < survivors-1; j++) {
                coordinates[j][0] = coordinates[j+1][0];
                coordinates[j][1] = coordinates[j+1][1];
            }
            survivors--;
            coordinates = realloc(coordinates, survivors * sizeof(int*));
        }
        
        // Print members of new cluster
        printf("Cluster %d members:\n", clusters);
        for(int i = 0; i < members; i++) {
            printf("(%d,%d)\n", coordinates[members_list[i]][0], coordinates[members_list[i]][1]);
        }
        printf("Center: (%d,%d)\n", centers[clusters-1][0], centers[clusters-1][1]);
        printf("\n");
    }
    
    printf("All survivors are in clusters.\n");
    
    // Free memory
    for(int i = 0; i < survivors; i++) {
        free(coordinates[i]);
    }
    free(coordinates);
    for(int i = 0; i < clusters; i++) {
        free(centers[i]);
    }
    free(centers);
    
    return 0;
}