//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_THREADS 10
#define MAX_FILE_SIZE 1024*1024*100 // 100 MB

typedef struct {
    char *filename;
    FILE *fp;
    int start_pos;
    int end_pos;
} ThreadData;

void *recover_data(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    FILE *fp = data->fp;
    int start_pos = data->start_pos;
    int end_pos = data->end_pos;
    char buffer[1024];

    fseek(fp, start_pos, SEEK_SET);
    while (start_pos < end_pos) {
        int bytes_read = fread(buffer, 1, 1024, fp);
        if (bytes_read <= 0) {
            break;
        }
        printf("%s", buffer);
        start_pos += bytes_read;
    }

    pthread_exit(NULL);
}

int main() {
    char filename[100];
    printf("Enter the name of the corrupted file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);

    if (filesize <= 0 || filesize > MAX_FILE_SIZE) {
        printf("Error: file size is invalid\n");
        fclose(fp);
        return 1;
    }

    int num_threads = filesize / MAX_FILE_SIZE;

    pthread_t threads[MAX_THREADS];
    ThreadData data[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        int start_pos = i * MAX_FILE_SIZE;
        int end_pos = (i == num_threads - 1)? filesize : (i + 1) * MAX_FILE_SIZE;

        data[i].filename = filename;
        data[i].fp = fp;
        data[i].start_pos = start_pos;
        data[i].end_pos = end_pos;

        pthread_create(&threads[i], NULL, recover_data, (void *) &data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(fp);
    return 0;
}