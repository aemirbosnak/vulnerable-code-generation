//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_KEY 100
#define MAX_VALUE_LEN 50

typedef struct {
    int key;
    char value[MAX_VALUE_LEN];
} Record;

Record database[MAX_KEY];

void *thread_func(void *arg) {
    int thread_id = *(int*) arg;
    char op;

    while(1) {
        op = getchar();

        if(op == 'I') {
            printf("Thread %d inserting record with key: ", thread_id);
            scanf("%d", &database[thread_id].key);
            printf("and value: ");
            scanf("%s", database[thread_id].value);
        }
        else if(op == 'R') {
            printf("Thread %d retrieving record with key: %d\n", thread_id, database[thread_id].key);
        }
        else if(op == 'Q') {
            break;
        }
        else {
            printf("Invalid operation\n");
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for(int i=0; i<NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, (void*) &thread_ids[i]);
    }

    while(1) {
        char op;
        scanf("%c", &op);

        if(op == 'I') {
            int thread_id;
            scanf("%d", &thread_id);
            printf("Thread %d inserting record with key: ", thread_id);
            scanf("%d", &database[thread_id].key);
            printf("and value: ");
            scanf("%s", database[thread_id].value);
        }
        else if(op == 'R') {
            int thread_id;
            scanf("%d", &thread_id);
            printf("Thread %d retrieving record with key: %d\n", thread_id, database[thread_id].key);
        }
        else if(op == 'Q') {
            break;
        }
        else {
            printf("Invalid operation\n");
        }
    }

    for(int i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}