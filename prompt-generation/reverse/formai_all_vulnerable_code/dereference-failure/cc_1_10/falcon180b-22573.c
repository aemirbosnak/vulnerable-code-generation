//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ENTRIES 100
#define MAX_THREADS 10

struct entry {
    char date[11];
    char time[9];
    char content[200];
};

struct entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* time, char* content) {
    strncpy(diary[num_entries].date, date, 11);
    strncpy(diary[num_entries].time, time, 9);
    strncpy(diary[num_entries].content, content, 200);
    num_entries++;
}

void print_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s - %s\n", diary[i].date, diary[i].time, diary[i].content);
    }
}

void* thread_func(void* arg) {
    char* content = (char*)arg;
    add_entry(NULL, NULL, content);
    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    char* content = "Hello, world!";

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void*)content);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    print_entries();

    return 0;
}