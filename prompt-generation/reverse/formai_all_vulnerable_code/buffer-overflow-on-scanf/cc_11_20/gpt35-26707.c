//FormAI DATASET v1.0 Category: Data mining ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define K 2 
//number of clusters, you can change it to any number

int main()
{
    int n=5, m=3, i, j, l, count=0, index, min_distance, iterations=10, pos[K];
    //n is the number of data points, m is the number of attributes, and iterations is the maximum number of iterations to run for.
    //pos[] stores the positions of the center points of the clusters.
    
    float data[n][m], distance[K], sum[K][m], centroid[K][m], avg[K][m];
    //data[][] is our input data, distance[] stores the minimum distance between a data point and the center points of the clusters.
    //sum[][] is temporary storage used for calculating the new values of the center points of the clusters.
    //centroid[][] stores the current position of the center points of the clusters.
    //avg[][] is used for storing the average values of the data points in each cluster.
    
    printf("************ K-Means Clustering Algorithm ************\n");
    printf("Enter %d data points each with %d attributes\n",n,m);
    
    for(i=0; i<n; i++) 
    {
        printf("\n Enter data point %d: ", i+1);
        for(j=0; j<m; j++)
            scanf("%f", &data[i][j]);
    }
    
    for(l=0; l<K; l++) 
    {
        pos[l]=(n/K)*l+(n%(K-l)>l); 
        //Divide the data into equal parts and use each part's center points as the initial centers for each cluster.
        //pos[] stores the indices of these center points.
        
        for(j=0; j<m; j++)
            centroid[l][j]=data[pos[l]][j];
    }
    
    while(count<iterations) 
    {
        for(l=0; l<K; l++)
        {
            for(i=0; i<m; i++)
                sum[l][i]=0.0;
        }
        
        //Calculate the minimum distance between each data point and the center points of the clusters.
        for(i=0; i<n; i++) 
        {
            min_distance=99999;
            for(l=0; l<K; l++) 
            {
                distance[l]=0.0;
                for(j=0; j<m; j++)
                    distance[l]+=pow((data[i][j]-centroid[l][j]), 2);
                distance[l]=sqrt(distance[l]);
                
                if(distance[l]<min_distance) 
                {
                    min_distance=distance[l];
                    index=l;
                }
            }
            
            //Assign each data point to its closest cluster.
            for(j=0; j<m; j++)
                sum[index][j]+=data[i][j];
        }
        
        //Calculate the new center points of each cluster.
        for(l=0; l<K; l++) 
        {
            for(j=0; j<m; j++) 
            {
                if(sum[l][j]!=0.0)
                    avg[l][j]=sum[l][j]/pos[l];
                else
                    avg[l][j]=0.0;
                centroid[l][j]=avg[l][j];
            }
        }
        
        count++;
    }
    
    //Print the final center points of the clusters.
    printf("\n\nThe final centers of the clusters are:\n");
    for(i=0; i<K; i++) 
    {
        printf("Cluster %d: [ ", i+1);
        for(j=0; j<m; j++)
            printf("%.2f ", centroid[i][j]);
        printf("]\n");
    }
    
    return 0;
}