//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LINE_LENGTH 80

typedef struct {
    char *text;
    int start_line;
    int num_lines;
    int thread_id;
} thread_data_t;

void *thread_func(void *data) {
    thread_data_t *td = (thread_data_t *) data;
    int i;

    for (i = td->start_line; i < td->start_line + td->num_lines; i++) {
        printf("%s", td->text + (i * MAX_LINE_LENGTH));
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char text[1000000];
    int num_threads, i;
    pthread_t threads[MAX_THREADS];
    thread_data_t thread_data[MAX_THREADS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    num_threads = (int) (ftell(fp) / (MAX_LINE_LENGTH * MAX_THREADS));

    rewind(fp);
    fread(text, 1, sizeof(text), fp);
    fclose(fp);

    for (i = 0; i < num_threads; i++) {
        int lines_per_thread = (int) (ftell(fp) / MAX_LINE_LENGTH);
        if (i == num_threads - 1)
            lines_per_thread = ftell(fp) % MAX_LINE_LENGTH;

        thread_data[i].text = text;
        thread_data[i].start_line = i * lines_per_thread;
        thread_data[i].num_lines = lines_per_thread;
        thread_data[i].thread_id = i;

        pthread_create(&threads[i], NULL, thread_func, &thread_data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}