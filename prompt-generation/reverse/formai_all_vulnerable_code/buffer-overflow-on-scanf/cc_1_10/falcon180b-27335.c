//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

char buffer[BUFFER_SIZE];
int buffer_index = 0;

void *process_url(void *arg) {
    char *url = (char *) arg;
    int i = 0;

    while (url[i]!= '\0') {
        if (isalnum(url[i])) {
            buffer[buffer_index++] = url[i];
        } else if (url[i] == '.' || url[i] == '-') {
            buffer[buffer_index++] = url[i];
        } else {
            buffer[buffer_index++] = '%';
            buffer[buffer_index++] = (char) (url[i] / 16 + '0');
            buffer[buffer_index++] = (char) (url[i] % 16 + '0');
        }
        i++;
    }

    buffer[buffer_index] = '\0';

    printf("Sanitized URL: %s\n", buffer);

    return NULL;
}

int main() {
    int num_threads, i;
    pthread_t threads[MAX_THREADS];

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    for (i = 0; i < num_threads; i++) {
        char url[50];
        printf("Enter URL to sanitize %d: ", i + 1);
        scanf("%s", url);

        pthread_create(&threads[i], NULL, process_url, (void *) url);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}