//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_STRING_LENGTH 1000
#define MAX_THREADS 10

int len1, len2;
char str1[MAX_STRING_LENGTH], str2[MAX_STRING_LENGTH];
int distance[MAX_STRING_LENGTH+1][MAX_STRING_LENGTH+1];

void* calculate_distance(void* arg) {
    int thread_id = *((int*)arg);
    int start = (len2/MAX_THREADS)*thread_id + 1;
    int end = (len2/MAX_THREADS)*(thread_id+1);
    if(thread_id == MAX_THREADS-1) end = len2;

    for(int i=0; i<=len1; i++) {
        distance[i][0] = i;
    }
    for(int i=start; i<=end; i++) {
        distance[0][i] = i;
        for(int j=1; j<=len1; j++) {
            int cost = (str1[j-1] == str2[i-1]) ? 0 : 1;
            int min_distance = distance[j-1][i-1] + cost;
            if(distance[j][i-1] + 1 < min_distance) min_distance = distance[j][i-1] + 1;
            if(distance[j-1][i] + 1 < min_distance) min_distance = distance[j-1][i] + 1;
            distance[j][i] = min_distance;
        }
    }
    pthread_exit(0);
}

int main() {
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    pthread_t threads[MAX_THREADS];
    int thread_id[MAX_THREADS];

    for(int i=0; i<MAX_THREADS; i++) {
        thread_id[i] = i;
        pthread_create(&threads[i], NULL, calculate_distance, &thread_id[i]);
    }

    for(int i=0; i<MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Levenshtein Distance between %s and %s is %d\n", str1, str2, distance[len1][len2]);

    return 0;
}