//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TOKENS 100
#define MAX_THREADS 4

typedef struct {
    char *token;
    int thread_id;
} Token;

void *process_tokens(void *arg) {
    Token *t = (Token *) arg;
    printf("Thread %d processing token: %s\n", t->thread_id, t->token);
    free(t->token);
    free(t);
    return NULL;
}

void parse_file(FILE *fp, int num_threads) {
    char line[1024];
    Token tokens[MAX_TOKENS];
    int num_tokens = 0;
    pthread_t threads[MAX_THREADS];

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (num_tokens >= MAX_TOKENS) {
                printf("Error: Too many tokens\n");
                exit(1);
            }
            tokens[num_tokens].token = strdup(token);
            tokens[num_tokens++].thread_id = num_threads % MAX_THREADS;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, process_tokens, (void *) &tokens[i * MAX_TOKENS]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <num_threads>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", argv[1]);
        return 1;
    }

    int num_threads = atoi(argv[2]);
    if (num_threads <= 0) {
        printf("Error: Invalid number of threads\n");
        return 1;
    }

    parse_file(fp, num_threads);

    fclose(fp);
    return 0;
}