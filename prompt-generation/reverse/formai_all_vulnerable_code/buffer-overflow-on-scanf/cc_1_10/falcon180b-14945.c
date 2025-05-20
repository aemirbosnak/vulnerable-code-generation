//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

#define MAX_THREADS 5
#define MAX_STR_LEN 100

pthread_t threads[MAX_THREADS];
int thread_count;

char input_str[MAX_STR_LEN];
char *output_str;

void *thread_func(void *arg) {
    int i;
    for(i=0; i<strlen(input_str); i++) {
        if(input_str[i] == 'a' || input_str[i] == 'e' || input_str[i] == 'i' || input_str[i] == 'o' || input_str[i] == 'u') {
            output_str[i] = input_str[i] + 'A' - 'a';
        }
        else {
            output_str[i] = input_str[i];
        }
    }
    return NULL;
}

int main() {
    printf("Enter a string: ");
    scanf("%s", input_str);

    output_str = malloc(MAX_STR_LEN);
    if(output_str == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    thread_count = 0;
    while(thread_count < MAX_THREADS) {
        int chunk_size = strlen(input_str)/MAX_THREADS;
        int start_pos = thread_count*chunk_size;
        int end_pos = (thread_count+1)*chunk_size - 1;
        if(thread_count == MAX_THREADS-1) {
            end_pos = strlen(input_str) - 1;
        }
        pthread_create(&threads[thread_count], NULL, thread_func, (void *)&start_pos);
        thread_count++;
    }

    for(int i=0; i<thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Output string: %s\n", output_str);

    free(output_str);
    return 0;
}