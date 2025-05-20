//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

//Struct to pass data to threads
struct v {
    char *filename;
    FILE *fp;
    char buffer[BUFFER_SIZE];
};

void *encrypt_file(void *arg) {
    struct v *data = (struct v *) arg;
    FILE *fp = data->fp;
    char buffer[BUFFER_SIZE];

    while (fread(data->buffer, 1, BUFFER_SIZE, fp)!= 0) {
        for (int i = 0; i < BUFFER_SIZE; i++) {
            data->buffer[i] = data->buffer[i] ^ 0xAA;
        }
        fwrite(data->buffer, 1, BUFFER_SIZE, fp);
    }

    fclose(fp);
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *fp_out = fopen(output_file, "wb");
    if (fp_out == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(fp_in);
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    struct v v[MAX_THREADS];

    int num_threads = 0;

    while (num_threads < MAX_THREADS && fread(v[num_threads].buffer, 1, BUFFER_SIZE, fp_in)!= 0) {
        v[num_threads].filename = input_file;
        v[num_threads].fp = fp_out;
        pthread_create(&threads[num_threads], NULL, encrypt_file, (void *)&v[num_threads]);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(fp_in);
    fclose(fp_out);

    printf("File encryption complete.\n");
    return 0;
}