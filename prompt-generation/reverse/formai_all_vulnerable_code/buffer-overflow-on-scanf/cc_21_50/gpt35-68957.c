//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Clustering Algorithm!\n");
    printf("Where we separate the cool kids from the not-so-cool kids.\n");

    int num_students;
    printf("How many students do we have today?: ");
    scanf("%d", &num_students);

    if (num_students < 1) {
        printf("Wow, you must be popular. Try again with more than 0 students.\n");
        return 1;
    }

    int* student_scores = calloc(num_students, sizeof(int));
    printf("\nGreat! Now let's get some data on each student.\n");
    printf("Input the scores of each student, separated by spaces: ");

    for (int i = 0; i < num_students; i++) {
        scanf("%d", &student_scores[i]);
    }

    int num_clusters;
    printf("\nOkay, now we need to decide how many clusters we want to create. Any ideas?: ");
    scanf("%d", &num_clusters);

    if (num_clusters > num_students) {
        printf("Sorry, we can't have more clusters than students. Let's try again.\n");
        return 1;
    }

    printf("\nNow the fun begins! Let's cluster the cool kids.\n");

    int* cluster_means = calloc(num_clusters, sizeof(int));

    // Randomly choose initial cluster means
    for (int i = 0; i < num_clusters; i++) {
        cluster_means[i] = student_scores[rand() % num_students];
    }

    int iteration = 1;

    while (1) {
        int* cluster_sums = calloc(num_clusters, sizeof(int));
        int* cluster_sizes = calloc(num_clusters, sizeof(int));
        int* old_cluster_means = calloc(num_clusters, sizeof(int));

        // Save old cluster means for comparison later
        for (int i = 0; i < num_clusters; i++) {
            old_cluster_means[i] = cluster_means[i];
        }

        // Assign each student to the closest mean
        for (int i = 0; i < num_students; i++) {
            int closest_mean = 0;
            int min_distance = abs(student_scores[i] - cluster_means[0]);

            for (int j = 1; j < num_clusters; j++) {
                int distance = abs(student_scores[i] - cluster_means[j]);

                if (distance < min_distance) {
                    closest_mean = j;
                    min_distance = distance;
                }
            }

            cluster_sums[closest_mean] += student_scores[i];
            cluster_sizes[closest_mean]++;
        }

        // Calculate new mean of each cluster
        for (int i = 0; i < num_clusters; i++) {
            if (cluster_sizes[i] > 0) {
                cluster_means[i] = cluster_sums[i] / cluster_sizes[i];
            }
        }

        // Break if means don't change
        int means_changed = 0;

        for (int i = 0; i < num_clusters; i++) {
            if (old_cluster_means[i] != cluster_means[i]) {
                means_changed = 1;
                break;
            }
        }

        if (!means_changed) {
            break;
        }

        // Print iteration results
        printf("\nIteration %d:\n", iteration);

        for (int i = 0; i < num_clusters; i++) {
            printf("Cluster %d:\n", i + 1);

            for (int j = 0; j < num_students; j++) {
                if ((abs(student_scores[j] - cluster_means[i]) <= 1 && i == 0) ||
                    (abs(student_scores[j] - cluster_means[i]) > 1 && i == 1)) {

                    printf("Student %d with score %d\n", j + 1, student_scores[j]);
                }
            }

            printf("New mean: %d\n", cluster_means[i]);
        }

        iteration++;

        free(cluster_sums);
        free(cluster_sizes);
        free(old_cluster_means);
    }

    free(student_scores);
    free(cluster_means);

    printf("\nExcellent work! The cool kids are now in their own clusters.\n");
    printf("Until next time, keep being cool.\n");

    return 0;
}