//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#define MAX_FORTUNES 100
#define MAX_THREADS 10
#define MAX_FORTUNE_LENGTH 80

typedef struct {
    char fortune[MAX_FORTUNE_LENGTH];
} Fortune;

Fortune fortunes[MAX_FORTUNES];
int num_fortunes;

void *generate_fortunes(void *arg) {
    int i;
    srand(time(NULL) + (int) arg);

    for (i = 0; i < 10; i++) {
        strcpy(fortunes[num_fortunes].fortune, "Your future holds: ");
        strcat(fortunes[num_fortunes].fortune, (char *) malloc(rand() % 80 + 1));
        strcat(fortunes[num_fortunes].fortune, ".\n");
        num_fortunes++;
    }

    pthread_exit(NULL);
}

void *tell_fortunes(void *arg) {
    int i;

    for (i = 0; i < num_fortunes; i++) {
        printf("%s", fortunes[i].fortune);
    }

    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];

    srand(time(NULL));

    num_fortunes = 0;

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, generate_fortunes, (void *) i);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < num_fortunes; i++) {
        pthread_create(&threads[i], NULL, tell_fortunes, NULL);
    }

    for (i = 0; i < num_fortunes; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}