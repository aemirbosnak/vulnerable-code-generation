//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>

#define MAX_CLUSTERS 10
#define MAX_DATA_POINTS 1000
#define MAX_ITERATIONS 10

double distances[MAX_DATA_POINTS][MAX_CLUSTERS];
int assignments[MAX_DATA_POINTS];
double data_points[MAX_DATA_POINTS][2];
double cluster_centers[MAX_CLUSTERS][2];

int num_clusters,num_data_points,num_iterations;

void *calculate_distances(void *thread_id){
    long tid;
    tid = (long)thread_id;

    int start = tid * num_data_points / num_clusters;
    int end = (tid+1) * num_data_points / num_clusters;

    for(int i=start;i<end;i++){
        double x1 = data_points[i][0];
        double y1 = data_points[i][1];
        for(int j=0;j<num_clusters;j++){
            double x2 = cluster_centers[j][0];
            double y2 = cluster_centers[j][1];
            distances[i][j] = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
        }
    }
    pthread_exit(NULL);
}

void assign_clusters(int tid){
    int start = tid * num_data_points / num_clusters;
    int end = (tid+1) * num_data_points / num_clusters;
    for(int i=start;i<end;i++){
        double min_dist = 10000;
        int min_ind = -1;
        for(int j=0;j<num_clusters;j++){
            if(distances[i][j] < min_dist){
                min_dist = distances[i][j];
                min_ind = j;
            }
        }
        assignments[i] = min_ind;
    }
    pthread_exit(NULL);
}

void calculate_centroids(int tid){
    int start = tid * num_clusters / 4;
    int end = (tid+1) * num_clusters / 4;
    for(int i=start;i<end;i++){
        double x_sum = 0;
        double y_sum = 0;
        int count = 0;
        for(int j=0;j<num_data_points;j++){
            if(assignments[j] == i){
                x_sum += data_points[j][0];
                y_sum += data_points[j][1];
                count++;
            }
        }
        if(count > 0){
            cluster_centers[i][0] = x_sum / count;
            cluster_centers[i][1] = y_sum / count;
        }
    }
    pthread_exit(NULL);
}

int main(){

    printf("Enter the number of clusters:");
    scanf("%d",&num_clusters);

    printf("Enter the number of data points:");
    scanf("%d",&num_data_points);

    printf("Enter the number of iterations:");
    scanf("%d",&num_iterations);

    printf("\nEnter the data points:\n");
    for(int i=0;i<num_data_points;i++){
        scanf("%lf %lf",&data_points[i][0],&data_points[i][1]);
    }

    pthread_t tid[5];
    int rc;

    //Initialize cluster centers randomly
    for(int i=0;i<num_clusters;i++){
        cluster_centers[i][0] = data_points[i][0];
        cluster_centers[i][1] = data_points[i][1];
    }

    for(int i=0;i<num_iterations;i++){
        //Calculate distances from each data point to each cluster center
        for(int j=0;j<5;j++){
            rc=pthread_create(&tid[j],NULL,calculate_distances,(void*)j);
            if(rc){
                printf("Error! Unable to create thread.\n");
                exit(-1);
            }
        }

        for(int j=0;j<5;j++){
            pthread_join(tid[j],NULL);
        }

        //Assign each data point to the nearest cluster
        for(int j=0;j<5;j++){
            rc=pthread_create(&tid[j],NULL,assign_clusters,(void*)j);
            if(rc){
                printf("Error! Unable to create thread.\n");
                exit(-1);
            }
        }

        for(int j=0;j<5;j++){
            pthread_join(tid[j],NULL);
        }

        //Calculate the new cluster centers
        for(int j=0;j<4;j++){
            rc=pthread_create(&tid[j],NULL,calculate_centroids,(void*)j);
            if(rc){
                printf("Error! Unable to create thread.\n");
                exit(-1);
            }
        }

        for(int j=0;j<4;j++){
            pthread_join(tid[j],NULL);
        }

        printf("\nIteration %d:\n",i+1);
        for(int j=0;j<num_clusters;j++){
            printf("Cluster %d: (%.2lf,%.2lf)\n",j+1,cluster_centers[j][0],cluster_centers[j][1]);
        }

    }

    return 0;
}