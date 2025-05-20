//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILES 10
#define MAX_FILENAME_LENGTH 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int word_count;
} FileData;

void* count_words(void* arg) {
    FileData* data = (FileData*)arg;
    FILE* file = fopen(data->filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        data->word_count = -1; // set to -1 in case of error
        pthread_exit(NULL);
    }

    data->word_count = 0;
    char word[100];
    
    while (fscanf(file, "%99s", word) == 1) {
        data->word_count++;
    }

    fclose(file);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_FILES];
    FileData files[MAX_FILES];
    int file_count = 0;

    printf("Enter number of files to process (max %d): ", MAX_FILES);
    scanf("%d", &file_count);
    getchar();  // clear newline character after number input

    if (file_count > MAX_FILES) {
        fprintf(stderr, "Exceeds maximum file limit of %d.\n", MAX_FILES);
        return 1;
    }

    for (int i = 0; i < file_count; i++) {
        printf("Enter filename %d: ", i + 1);
        fgets(files[i].filename, MAX_FILENAME_LENGTH, stdin);
        strtok(files[i].filename, "\n"); // Remove newline character

        if (pthread_create(&threads[i], NULL, count_words, (void*)&files[i]) != 0) {
            perror("Error creating thread");
            return 1;
        }
    }

    for (int i = 0; i < file_count; i++) {
        pthread_join(threads[i], NULL);
        if (files[i].word_count >= 0) {
            printf("File: %s -> Word count: %d\n", files[i].filename, files[i].word_count);
        } else {
            printf("File: %s -> Error reading file.\n", files[i].filename);
        }
    }

    return 0;
}