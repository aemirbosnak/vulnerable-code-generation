//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_CLUSTERS 10
#define MAX_ITERATIONS 100

typedef struct {
   double x, y;
} Point;

typedef struct {
   int numPoints;
   Point centroid;
   Point points[MAX_POINTS];
} Cluster;

int numClusters;
Point points[MAX_POINTS];
Cluster clusters[MAX_CLUSTERS];
int numPoints;
double minDistance;
int minIndex;
int iteration;

double getEuclideanDistance(Point p1, Point p2) {
   double xDiff = p2.x - p1.x;
   double yDiff = p2.y - p1.y;
   return sqrt((xDiff * xDiff) + (yDiff * yDiff));
}

void initClusters() {
   int i, j;
   for (i = 0; i < numClusters; i++) {
      clusters[i].numPoints = 0;
      clusters[i].centroid.x = rand() % 100;
      clusters[i].centroid.y = rand() % 100;
      for (j = 0; j < MAX_POINTS; j++) {
         clusters[i].points[j].x = -1;
         clusters[i].points[j].y = -1;
      }
   }
}

void addPointToCluster(Point p, Cluster *c) {
   c->points[c->numPoints].x = p.x;
   c->points[c->numPoints].y = p.y;
   c->numPoints++;
}

void assignPointsToClusters() {
   int i, j, k;
   double distance;
   for (i = 0; i < numPoints; i++) {
      minDistance = 100000;
      for (j = 0; j < numClusters; j++) {
         distance = getEuclideanDistance(points[i], clusters[j].centroid);
         if (distance < minDistance) {
            minDistance = distance;
            minIndex = j;
         }
      }
      addPointToCluster(points[i], &clusters[minIndex]);
   }
}

void updateClusterCentroids() {
   int i, j;
   double avgX, avgY;
   for (i = 0; i < numClusters; i++) {
      avgX = 0;
      avgY = 0;
      if (clusters[i].numPoints > 0) {
         for (j = 0; j < clusters[i].numPoints; j++) {
            avgX += clusters[i].points[j].x;
            avgY += clusters[i].points[j].y;
         }
         clusters[i].centroid.x = avgX / clusters[i].numPoints;
         clusters[i].centroid.y = avgY / clusters[i].numPoints;
      }
   }
}

void printClusters() {
   int i, j;
   printf("Clusters:\n");
   for (i = 0; i < numClusters; i++) {
      printf("Cluster %d:\n", i + 1);
      printf("Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
      printf("Points:\n");
      for (j = 0; j < clusters[i].numPoints; j++) {
         printf("(%.2f, %.2f) ", clusters[i].points[j].x, clusters[i].points[j].y);
      }
      printf("\n");
   }
}

int main() {
   printf("Welcome to the C Clustering Algorithm Implementation program!\n");
   printf("Please enter the number of clusters: ");
   scanf("%d", &numClusters);
   printf("Please enter the number of points: ");
   scanf("%d", &numPoints);
   printf("Please enter the points:\n");
   int i;
   for (i = 0; i < numPoints; i++) {
      printf("Point %d: ", i + 1);
      scanf("%lf %lf", &points[i].x, &points[i].y);
   }

   initClusters();
   for (iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
      assignPointsToClusters();
      updateClusterCentroids();
   }

   printClusters();
   printf("Thank you for using the C Clustering Algorithm Implementation program!\n");
   return 0;
}