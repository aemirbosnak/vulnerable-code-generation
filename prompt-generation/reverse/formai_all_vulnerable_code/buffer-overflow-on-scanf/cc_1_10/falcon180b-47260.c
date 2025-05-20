//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB

typedef struct {
    char *filename;
    char *buffer;
    size_t size;
} FileData;

void *scan_file(void *arg) {
    FileData *data = (FileData *) arg;
    char *virus_pattern = "EICAR-STANDARD-ANTIVIRUS-TEST-FILE!";
    char *pattern = (char *) malloc(strlen(virus_pattern) + 1);
    strcpy(pattern, virus_pattern);

    int found = 0;
    for (int i = 0; i < data->size; i++) {
        if (data->buffer[i] == pattern[0]) {
            int j = 0;
            while (i + j < data->size && data->buffer[i + j] == pattern[j]) {
                j++;
            }
            if (j == strlen(pattern)) {
                found = 1;
                break;
            }
        }
    }

    if (found) {
        printf("Virus found in file: %s\n", data->filename);
    } else {
        printf("No virus found in file: %s\n", data->filename);
    }

    free(pattern);
    free(data->buffer);
    free(data);
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_attr_t attr;
    FileData *data;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    while (1) {
        printf("Enter filename: ");
        scanf("%s", data->filename);

        FILE *fp = fopen(data->filename, "rb");
        if (fp == NULL) {
            printf("File not found.\n");
            continue;
        }

        fseek(fp, 0, SEEK_END);
        data->size = ftell(fp);
        if (data->size > MAX_FILE_SIZE) {
            printf("File is too large.\n");
            fclose(fp);
            continue;
        }

        rewind(fp);
        data->buffer = (char *) malloc(data->size);
        fread(data->buffer, data->size, 1, fp);
        fclose(fp);

        pthread_create(&thread_id, &attr, scan_file, data);
        pthread_join(thread_id, NULL);
    }

    return 0;
}