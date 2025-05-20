//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 2

float calculate_area(float* a, float* b, float* c) {
   float s = (*a + *b + *c)/2.0;
   float area = sqrt(s*(s-*a)*(s-*b)*(s-*c));
   return area;
}

void* triangle_area(void* args) {
   float* sides = (float*) args;
   float area;

   area = calculate_area(&sides[0], &sides[1], &sides[2]);

   printf("Thread %ld: The area of the triangle is %f\n", pthread_self(), area);

   pthread_exit(NULL);
}

int main() {
   int i;
   float sides[3];
   pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;

   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

   for (i = 0; i < NUM_THREADS; i++) {
      printf("Enter side %d of the triangle: ", i+1);
      scanf("%f", &sides[i]);
   }

   for (i = 0; i < NUM_THREADS; i++) {
      pthread_create(&threads[i], &attr, triangle_area, (void*)sides);
   }

   pthread_attr_destroy(&attr);

   for (i = 0; i < NUM_THREADS; i++) {
      pthread_join(threads[i], NULL);
   }

   pthread_exit(NULL);
}