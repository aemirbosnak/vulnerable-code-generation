//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Define the lattice size
    int lattice_size = 100;
    
    // Create the lattice array
    int *lattice = (int*) malloc(lattice_size * lattice_size * sizeof(int));
    for (int i = 0; i < lattice_size; i++) {
        for (int j = 0; j < lattice_size; j++) {
            lattice[i * lattice_size + j] = 0;
        }
    }
    
    // Initialize the percolation probability
    double p = 0.5;
    
    // Perform percolation simulation
    int total_percolations = 0;
    int max_percolations = 0;
    for (int i = 0; i < 1000; i++) {
        // Select a random site
        int site_i = (int) (rand() / (double) RAND_MAX * lattice_size);
        int site_j = (int) (rand() / (double) RAND_MAX * lattice_size);
        
        // Check if the site is occupied
        if (lattice[site_i * lattice_size + site_j] == 0) {
            // Flip the site
            lattice[site_i * lattice_size + site_j] = 1;
            
            // Check if there are any connected sites
            int connected_sites = 0;
            for (int j = -1; j <= 1; j++) {
                for (int k = -1; k <= 1; k++) {
                    if ((site_i + j) >= 0 && (site_i + j) < lattice_size && 
                        (site_j + k) >= 0 && (site_j + k) < lattice_size) {
                        if (lattice[(site_i + j) * lattice_size + (site_j + k)] == 1) {
                            connected_sites++;
                        }
                    }
                }
            }
            
            // If there are any connected sites, increment the percolation count
            if (connected_sites > 0) {
                total_percolations++;
                
                // If this is the maximum percolation count, update the maximum count
                if (connected_sites > max_percolations) {
                    max_percolations = connected_sites;
                }
            }
            
            // Flip the site back to 0
            lattice[site_i * lattice_size + site_j] = 0;
        }
    }
    
    // Print the results
    printf("Total percolations: %d\n", total_percolations);
    printf("Maximum percolation count: %d\n", max_percolations);
    
    // Free the memory
    free(lattice);
    
    return 0;
}