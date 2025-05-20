#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *job;
    void (*func)(void*);
    void *args;
} Job;

void echo(void *arg) {
    printf("%s\n", (char *)arg);
}

void bomb(void *arg) {
    char buf[64];
    while (1) {
        sscanf((char *)arg, "%64s", buf);
        strcat(buf, " A");
        strcat(buf, (char *)arg);
        write(1, buf, strlen(buf));
    }
}

void schedule_job(Job *job) {
    pthread_t thread_id;

    pthread_create(&thread_id, NULL, job->func, job->args);
    pthread_detach(thread_id);
}

int main(int argc, char *argv[]) {
    Job jobs[16];

    for (int i = 0; i < 16; i++) {
        jobs[i].job = argv[i + 1];
        jobs[i].func = i % 2 == 0 ? echo : bomb;
        jobs[i].args = argv[i + 2];
        schedule_job(&jobs[i]);
    }

    for (int i = 0; i < 16; i++) free(jobs[i].job);

    return 0;
}
