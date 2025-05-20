//FormAI DATASET v1.0 Category: Data mining ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NUM_STUDENTS 100
#define NUM_GRADES 5
#define NUM_CLUSTERS 2

float data[NUM_STUDENTS][NUM_GRADES] = {{0.0}};
float centroids[NUM_CLUSTERS][NUM_GRADES] = {{0.0}};
int membership[NUM_STUDENTS] = {0};

float euclidean_distance(float *a, float *b)
{
    float dist = 0.0;
    for(int i=0; i<NUM_GRADES; i++)
    {
        dist += pow(a[i] - b[i], 2);
    }
    return sqrt(dist);
}

void initialize_centroids()
{
    // Randomly select centroids from data
    for(int i=0; i<NUM_CLUSTERS; i++)
    {
        int rand_index = rand() % NUM_STUDENTS;
        for(int j=0; j<NUM_GRADES; j++)
        {
            centroids[i][j] = data[rand_index][j];
        }
    }
}

void assign_memberships()
{
    // Assign each student to the closest cluster centroid
    for(int i=0; i<NUM_STUDENTS; i++)
    {
        float min_dist = INFINITY;
        int min_index = -1;

        for(int j=0; j<NUM_CLUSTERS; j++)
        {
            float dist = euclidean_distance(data[i], centroids[j]);
            if(dist < min_dist)
            {
                min_dist = dist;
                min_index = j;
            }
        }

        membership[i] = min_index;
    }
}

void update_centroids()
{
    // Calculate new centroids for each cluster
    for(int i=0; i<NUM_CLUSTERS; i++)
    {
        int count = 0;
        float sum[NUM_GRADES] = {0.0};

        for(int j=0; j<NUM_STUDENTS; j++)
        {
            if(membership[j] == i)
            {
                count++;
                for(int k=0; k<NUM_GRADES; k++)
                {
                    sum[k] += data[j][k];
                }
            }
        }

        for(int k=0; k<NUM_GRADES; k++)
        {
            centroids[i][k] = sum[k] / count;
        }
    }
}

void print_memberships()
{
    // Print membership information for each student
    printf("Student memberships:\n");
    for(int i=0; i<NUM_STUDENTS; i++)
    {
        printf("%d ", membership[i]);
    }
    printf("\n");
}

int main()
{
    // Read in student data from file
    FILE *fp = fopen("grades.csv", "r");
    for(int i=0; i<NUM_STUDENTS; i++)
    {
        for(int j=0; j<NUM_GRADES; j++)
        {
            fscanf(fp, "%f", &data[i][j]);
        }
    }
    fclose(fp);

    // Initialize centroids and assign memberships
    initialize_centroids();
    assign_memberships();

    // Iterate until convergence
    int iterations = 0;
    while(iterations < 10)
    {
        update_centroids();
        assign_memberships();
        iterations++;
    }

    // Print final membership information
    print_memberships();

    return 0;
}