//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t lock;

void* fortune(void* arg) {
    pthread_mutex_lock(&lock);
    printf("Thread %d says: \n", *((int*)arg));

    srand(time(NULL));
    
    int fortuneNum = rand() % 4;

    switch(fortuneNum) {
        case 0:
            printf("You will have a great day today.\n");
            break;
        case 1:
            printf("You will meet someone important today.\n");
            break;
        case 2:
            printf("Your hard work will pay off.\n");
            break;
        case 3:
            printf("Something unexpected will happen, but it will be for the best.\n");
            break;
        default:
            printf("Invalid fortune number.\n");
            break;
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    int numThreads;
    printf("How many fortunes would you like me to tell? (1-10) ");
    scanf("%d", &numThreads);
    printf("\n");

    pthread_t threads[numThreads];
    int threadNums[numThreads];

    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < numThreads; i++) {
        threadNums[i] = i + 1;
        int createReturn = pthread_create(&threads[i], NULL, fortune, &threadNums[i]);

        if(createReturn) {
            printf("Error creating thread %d\n", i+1);
        }
    }

    for(int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}