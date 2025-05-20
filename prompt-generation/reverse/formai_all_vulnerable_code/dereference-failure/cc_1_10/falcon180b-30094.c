//Falcon-180B DATASET v1.0 Category: System event logger ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_EVENTS 1000
#define MAX_THREADS 10

typedef struct {
    char *message;
    time_t timestamp;
} Event;

typedef struct {
    int id;
    char name[20];
} ThreadData;

Event events[MAX_EVENTS];
int eventCount = 0;

void logEvent(char *message) {
    time_t now = time(NULL);
    strftime(message + strlen(message), 20, " [%Y-%m-%d %H:%M:%S]", localtime(&now));
    events[eventCount++] = (Event){.message = strdup(message),.timestamp = now};
    if (eventCount >= MAX_EVENTS) {
        eventCount = 0;
    }
}

void *threadFunction(void *data) {
    ThreadData *threadData = data;
    char name[20];
    sprintf(name, "Thread %d", threadData->id);
    pthread_setname_np(pthread_self(), name);

    for (int i = 0; i < 5; i++) {
        sleep(1);
        logEvent(threadData->name);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_THREADS; i++) {
        ThreadData data = {.id = i,.name = "Thread"};
        pthread_t thread;
        pthread_create(&thread, NULL, threadFunction, &data);
        pthread_detach(thread);
    }

    sleep(10);

    for (int i = 0; i < eventCount; i++) {
        printf("%s\n", events[i].message);
    }

    return 0;
}