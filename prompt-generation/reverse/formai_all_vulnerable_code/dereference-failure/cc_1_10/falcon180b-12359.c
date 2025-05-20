//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_FILE_SIZE 1000000

typedef struct {
    char filename[100];
    int filesize;
    char *encrypteddata;
    int encryptedsize;
} thread_data;

void *encrypt_file(void *arg) {
    thread_data *data = (thread_data *) arg;
    FILE *file = fopen(data->filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", data->filename);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    data->filesize = ftell(file);
    rewind(file);
    data->encrypteddata = (char *) malloc(data->filesize + 1);
    fread(data->encrypteddata, 1, data->filesize, file);
    fclose(file);
    int i;
    for (i = 0; i < data->filesize; i++) {
        data->encrypteddata[i] ^= 0xAA;
    }
    data->encryptedsize = data->filesize;
    return NULL;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    thread_data *data = (thread_data *) malloc(sizeof(thread_data));
    strcpy(data->filename, argv[1]);
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, encrypt_file, (void *) data);
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(NULL, NULL);
    }
    printf("File encrypted successfully!\n");
    return 0;
}