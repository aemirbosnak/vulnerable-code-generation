//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define DIMENSIONS 2 // Change this value to increase dimensions
#define CLUSTER_MAX 5 // Maximum number of clusters
#define DATA_MAX 100 // Maximum number of data points

// Structure to represent data points
typedef struct DataPoints{
    double dimensions[DIMENSIONS];
    int cluster;
}DataPoint;

// Function to generate random data points
void generateData(DataPoint data[], int size){
    int i, j;
    for(i=0; i<size; ++i){
        for(j=0; j<DIMENSIONS; ++j){
            data[i].dimensions[j] = (double)rand()/RAND_MAX*10; // Random value between 0 and 10
        }
        data[i].cluster = -1;
    }
}

// Function to print data points
void printData(DataPoint data[], int size){
    int i, j;
    for(i=0; i<size; ++i){
        for(j=0; j<DIMENSIONS; ++j){
            printf("%.2f ", data[i].dimensions[j]);
        }
        printf("%d\n", data[i].cluster);
    }
}

// Function to calculate Euclidean distance between two data points
double calculateDistance(DataPoint point1, DataPoint point2){
    double distance = 0;
    int i;
    for(i=0; i<DIMENSIONS; ++i){
        distance += pow(point1.dimensions[i] - point2.dimensions[i], 2);
    }
    return sqrt(distance);
}

// Function to assign data points to clusters
void assignClusters(DataPoint data[], int dataSize, DataPoint centroids[], int clusterSize){
    double distance, minDistance;
    int i, j, minCluster;

    for(i=0; i<dataSize; ++i){
        minDistance = calculateDistance(data[i], centroids[0]);
        minCluster = 0;

        for(j=1; j<clusterSize; ++j){
            distance = calculateDistance(data[i], centroids[j]);
            if(distance < minDistance){
                minDistance = distance;
                minCluster = j;
            }
        }

        data[i].cluster = minCluster;
    }
}

// Function to recalculate centroids based on current clusters
void recalculateCentroids(DataPoint data[], int dataSize, DataPoint centroids[], int clusterSize){
    int count[CLUSTER_MAX] = {0}; // Counter array to keep track of number of data points in a cluster
    int i, j;

    // Reset centroids to zero
    for(i=0; i<clusterSize; ++i){
        for(j=0; j<DIMENSIONS; ++j){
            centroids[i].dimensions[j] = 0;
        }
    }

    // Sum up data points in a cluster to get new centroid
    for(i=0; i<dataSize; ++i){
        for(j=0; j<DIMENSIONS; ++j){
            centroids[data[i].cluster].dimensions[j] += data[i].dimensions[j];
        }
        count[data[i].cluster]++;
    }

    // Divide sum by number of data points in a cluster to get average and set new centroid
    for(i=0; i<clusterSize; ++i){
        if(count[i] == 0){
            continue; // If a cluster has no data points, keep its centroid as previous value
        }
        for(j=0; j<DIMENSIONS; ++j){
            centroids[i].dimensions[j] /= count[i];
        }
    }
}

// Function to check if there is any change in clustering
int checkConvergence(DataPoint oldData[], DataPoint newData[], int dataSize){
    int i;
    for(i=0; i<dataSize; ++i){
        if(oldData[i].cluster != newData[i].cluster){
            return 0; // If any data point has changed cluster, return 0
        }
    }
    return 1; // Return 1 if all data points remain in the same cluster
}

int main(){
    DataPoint data[DATA_MAX], oldData[DATA_MAX];
    DataPoint centroids[CLUSTER_MAX];
    int i, j;
    int dataSize, clusterSize;
    int maxIterations = 10; // Maximum numbers of iterations to run program
    int iterations = 0;

    printf("Enter number of data points (maximum %d): ", DATA_MAX);
    scanf("%d", &dataSize);

    printf("Enter number of clusters (maximum %d): ", CLUSTER_MAX);
    scanf("%d", &clusterSize);

    // Generate random data points
    generateData(data, dataSize);

    // Set initial centroids to random data points
    for(i=0; i<clusterSize; ++i){
        centroids[i] = data[rand()%dataSize];
    }

    // Assign initial clusters based on initial centroids
    assignClusters(data, dataSize, centroids, clusterSize);

    while(iterations < maxIterations){
        // Save current clustering
        for(i=0; i<dataSize; ++i){
            oldData[i] = data[i];
        }

        // Recalculate centroids based on current clustering
        recalculateCentroids(data, dataSize, centroids, clusterSize);

        // Assign clusters based on new centroids
        assignClusters(data, dataSize, centroids, clusterSize);

        // Check for convergence
        if(checkConvergence(oldData, data, dataSize)){
            printf("Converged in %d iterations\n", iterations+1);
            break;
        }

        iterations++;
    }

    // Print final clusters
    printData(data, dataSize);

    return 0;
}