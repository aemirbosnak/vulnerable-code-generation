//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

typedef struct {
    char *filename;
    int thread_id;
    char buffer[BUFFER_SIZE];
} thread_data;

void *read_file(void *data) {
    thread_data *tdata = (thread_data *) data;
    FILE *fp = fopen(tdata->filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", tdata->filename);
        exit(1);
    }

    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        strncat(tdata->buffer, &ch, 1);
    }

    fclose(fp);
    printf("Thread %d has finished reading file %s\n", tdata->thread_id, tdata->filename);
}

int main() {
    pthread_t threads[MAX_THREADS];
    char filenames[MAX_THREADS][100];
    int thread_ids[MAX_THREADS];

    int num_files = 0;
    printf("Enter the number of files to read: ");
    scanf("%d", &num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Enter filename %d: ", i+1);
        scanf("%s", filenames[i]);
    }

    for (int i = 0; i < num_files; i++) {
        thread_data *tdata = (thread_data *) malloc(sizeof(thread_data));
        tdata->filename = strdup(filenames[i]);
        tdata->thread_id = i+1;
        pthread_create(&threads[i], NULL, read_file, tdata);
        thread_ids[i] = i+1;
    }

    for (int i = 0; i < num_files; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_files; i++) {
        printf("Contents of file %d:\n%s\n", thread_ids[i], filenames[i]);
    }

    return 0;
}