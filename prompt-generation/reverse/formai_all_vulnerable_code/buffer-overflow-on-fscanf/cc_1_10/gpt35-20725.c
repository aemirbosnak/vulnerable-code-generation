//FormAI DATASET v1.0 Category: Data mining ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3      // number of clusters
#define MAX_ITERS 100  // maximum number of iterations
#define EPSILON 0.0001  // convergence threshold

// data structure to represent a single customer record
typedef struct {
    double age;
    double income;
    double spending_score;
} CustomerRecord;

// function to calculate the distance between two customer records
double distance(CustomerRecord c1, CustomerRecord c2) {
    return sqrt(pow(c1.age - c2.age, 2) + pow(c1.income - c2.income, 2) + pow(c1.spending_score - c2.spending_score, 2));
}

int main() {
    // read customer data from a file
    FILE* fp = fopen("customer_data.txt", "r");
    CustomerRecord* records = malloc(sizeof(CustomerRecord) * 200);
    int i = 0;

    while(fscanf(fp, "%lf,%lf,%lf", &records[i].age, &records[i].income, &records[i].spending_score) == 3) {
        i++;
    }

    int num_records = i;
    fclose(fp);

    // initialize the centroids randomly
    CustomerRecord centroids[K];
    for(i = 0; i < K; i++) {
        centroids[i] = records[rand() % num_records];
    }

    // run k-means clustering
    int iter = 0;
    int assignment[num_records];

    while(iter < MAX_ITERS) {
        // assign each record to the nearest centroid
        for(i = 0; i < num_records; i++) {
            double min_dist = INFINITY;
            int min_index = 0;

            for(int j = 0; j < K; j++) {
                double dist = distance(records[i], centroids[j]);

                if(dist < min_dist) {
                    min_dist = dist;
                    min_index = j;
                }
            }

            assignment[i] = min_index;
        }

        // calculate new centroids
        int num_assigned[K] = {0};
        CustomerRecord sum[K] = {};

        for(i = 0; i < num_records; i++) {
            num_assigned[assignment[i]]++;
            sum[assignment[i]].age += records[i].age;
            sum[assignment[i]].income += records[i].income;
            sum[assignment[i]].spending_score += records[i].spending_score;
        }

        for(i = 0; i < K; i++) {
            centroids[i].age = sum[i].age / num_assigned[i];
            centroids[i].income = sum[i].income / num_assigned[i];
            centroids[i].spending_score = sum[i].spending_score / num_assigned[i];
        }

        // check for convergence
        double total_dist = 0.0;

        for(i = 0; i < num_records; i++) {
            total_dist += distance(records[i], centroids[assignment[i]]);
        }

        if(total_dist < EPSILON) {
            break;
        }

        iter++;
    }

    // print the final clusters
    for(i = 0; i < K; i++) {
        printf("Cluster %d:\n", i);

        for(int j = 0; j < num_records; j++) {
            if(assignment[j] == i) {
                printf("(%f, %f, %f)\n", records[j].age, records[j].income, records[j].spending_score);
            }
        }

        printf("\n");
    }

    free(records);

    return 0;
}