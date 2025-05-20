//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    int id;
    char *name;
    pthread_t thread;
    void *(*routine)(void *);
    void *args;
} thread_t;

thread_t *create_thread(int id, char *name, void *(*routine)(void *), void *args) {
    thread_t *thread = malloc(sizeof(thread_t));
    thread->id = id;
    thread->name = name;
    thread->routine = routine;
    thread->args = args;
    pthread_create(&thread->thread, NULL, thread->routine, thread->args);
    return thread;
}

void *thread_routine(void *args) {
    thread_t *thread = args;
    printf("Thread %s started\n", thread->name);
    thread->routine(thread->args);
    printf("Thread %s stopped\n", thread->name);
    return NULL;
}

void *light_routine(void *args) {
    int *light = args;
    while (1) {
        if (*light) {
            printf("Light is on\n");
        } else {
            printf("Light is off\n");
        }
        sleep(1);
    }
    return NULL;
}

void *fan_routine(void *args) {
    int *fan = args;
    while (1) {
        if (*fan) {
            printf("Fan is on\n");
        } else {
            printf("Fan is off\n");
        }
        sleep(1);
    }
    return NULL;
}

int main() {
    int light = 0;
    int fan = 0;
    thread_t *light_thread = create_thread(0, "light", light_routine, &light);
    thread_t *fan_thread = create_thread(1, "fan", fan_routine, &fan);
    while (1) {
        char input;
        printf("Enter 'l' to toggle light, 'f' to toggle fan, 'q' to quit: ");
        scanf(" %c", &input);
        switch (input) {
            case 'l':
                light = !light;
                break;
            case 'f':
                fan = !fan;
                break;
            case 'q':
                pthread_cancel(light_thread->thread);
                pthread_cancel(fan_thread->thread);
                free(light_thread);
                free(fan_thread);
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}