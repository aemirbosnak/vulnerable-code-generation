//Falcon2-11B DATASET v1.0 Category: Text to Morse code conversion ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100
#define MAX_THREADS 4
#define SEGMENT_SIZE 10
#define DOT_DURATION 1.0
#define DASH_DURATION 3.0
#define DELAY 1.0
char morse_code[] = {'-.-.-', '-..', '...', '-.', '---', '..-.', '--.', '....', '..', '.---', '-.-', '.-..', '--', '-.', '---', '.--.', '----'};
void *thread_func(void *arg) {
    int start = (int)arg;
    char text[MAX_SIZE];
    int i = 0, j = 0;
    srand(time(NULL));
    while (text[i]!= '\0') {
        if (isalpha(text[i])) {
            j = (int)morse_code[text[i] - 'A'];
            if (j == 0) {
                printf("%.1f %.1f\n", DELAY, DELAY);
            } else {
                printf("%.1f %.1f\n", DOT_DURATION, DELAY);
                printf("%.1f %.1f\n", DELAY, DASH_DURATION);
            }
            i++;
        } else if (isdigit(text[i])) {
            printf("%.1f %.1f\n", DELAY, DELAY);
            i++;
        } else {
            printf("%.1f %.1f\n", DELAY, DELAY);
            i++;
        }
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t threads[MAX_THREADS];
    int i;
    char text[MAX_SIZE];
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fgets(text, MAX_SIZE, fp);
    fclose(fp);
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)i);
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}