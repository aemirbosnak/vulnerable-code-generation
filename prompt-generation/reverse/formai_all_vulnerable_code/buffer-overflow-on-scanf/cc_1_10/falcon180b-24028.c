//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    char input_file[100];
    char output_file[100];
    char key[20];
} thread_data;

void *encrypt_file(void *arg) {
    thread_data *data = (thread_data *) arg;
    FILE *input_file, *output_file;
    char ch;
    int key_index = 0;

    input_file = fopen(data->input_file, "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    output_file = fopen(data->output_file, "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    while ((ch = fgetc(input_file))!= EOF) {
        ch = ch ^ data->key[key_index];
        key_index = (key_index + 1) % strlen(data->key);
        fputc(ch, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Thread %ld completed encryption of %s to %s\n", pthread_self(), data->input_file, data->output_file);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data data[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        printf("Enter input file name for thread %d: ", i);
        scanf("%s", data[i].input_file);

        printf("Enter output file name for thread %d: ", i);
        scanf("%s", data[i].output_file);

        printf("Enter encryption key for thread %d: ", i);
        scanf("%s", data[i].key);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, encrypt_file, &data[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}