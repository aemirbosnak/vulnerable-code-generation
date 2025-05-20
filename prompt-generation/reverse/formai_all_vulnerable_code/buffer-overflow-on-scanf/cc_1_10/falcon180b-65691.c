//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define MAX_THREADS 10
#define STACK_SIZE 100000

typedef struct {
    char *input;
    char output[100];
    int thread_id;
} thread_data;

void *calculate(void *param) {
    thread_data *data = (thread_data *) param;
    char *token = strtok(data->input, " ");
    int count = 0;

    while (token!= NULL) {
        if (strcmp(token, "+") == 0) {
            strcat(data->output, "+");
        } else if (strcmp(token, "-") == 0) {
            strcat(data->output, "-");
        } else if (strcmp(token, "*") == 0) {
            strcat(data->output, "*");
        } else if (strcmp(token, "/") == 0) {
            strcat(data->output, "/");
        } else if (isdigit(token[0])) {
            strcat(data->output, token);
            strcat(data->output, " ");
        }
        token = strtok(NULL, " ");
        count++;
    }

    data->output[count - 1] = '\0';
    printf("Thread %d: %s = %s\n", data->thread_id, data->input, data->output);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    char input[100];

    printf("Enter the number of threads: ");
    scanf("%d", &thread_count);

    printf("Enter the inputs:\n");
    fgets(input, 100, stdin);
    char *token = strtok(input, "\n");

    while (token!= NULL) {
        if (thread_count >= MAX_THREADS) {
            printf("Maximum number of threads reached.\n");
            break;
        }
        thread_data *data = (thread_data *) malloc(sizeof(thread_data));
        data->input = strdup(token);
        data->thread_id = thread_count;
        pthread_create(&threads[thread_count], NULL, calculate, data);
        thread_count++;
        token = strtok(NULL, "\n");
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}