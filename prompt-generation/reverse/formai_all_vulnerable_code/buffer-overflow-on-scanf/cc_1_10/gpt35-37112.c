//FormAI DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 1000

int arr[MAX], n, key, pos, flag = 0;

void *search(void *arg) {
   int start = *(int *) arg;
   int end = start + n/4;

   for(int i=start;i<end;i++) {
       if(arr[i] == key) {
           pos = i+1;
           flag = 1; 
       }
   }

   pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2, t3, t4;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements in the array: ", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    int start1 = 0, start2 = n/4, start3 = n/2, start4 = 3*n/4;

    pthread_create(&t1, NULL, search, &start1);
    pthread_create(&t2, NULL, search, &start2);
    pthread_create(&t3, NULL, search, &start3);
    pthread_create(&t4, NULL, search, &start4);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    if(flag == 0) {
        printf("Key not found in the array.\n");
    }
    else {
        printf("Key found at position %d in the array.\n", pos);
    }

    return 0;
}