//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int num;
    char* word;
} thread_data;

// Function to read data from the file
void* read_data(void* data) {
    thread_data* td = (thread_data*)data;
    FILE* fp = fopen("data.txt", "r");
    fscanf(fp, "%d %s", &td->num, td->word);
    fclose(fp);
    return NULL;
}

int main(void) {
    pthread_t threads[10];
    thread_data td[10];
    FILE* fp = fopen("data.txt", "r");
    int num, i;

    for (i = 0; i < 10; i++) {
        td[i].num = 0;
        td[i].word = NULL;
    }

    while (fscanf(fp, "%d %s", &num, td[i].word)!= EOF) {
        if (i == 9) {
            i = 0;
        }
        td[i].num = num;
        td[i].word = strdup(td[i].word);
        i++;
    }

    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, read_data, &td[i]);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < 10; i++) {
        printf("%d %s\n", td[i].num, td[i].word);
        free(td[i].word);
    }

    fclose(fp);

    return 0;
}