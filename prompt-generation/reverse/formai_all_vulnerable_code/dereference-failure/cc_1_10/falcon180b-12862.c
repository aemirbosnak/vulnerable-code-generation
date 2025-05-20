//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_CITIES 10
#define NUM_THREADS 3

struct city {
    int id;
    int temperature;
    int humidity;
    int wind_speed;
};

struct city cities[NUM_CITIES];

void update_weather(int city_id) {
    int new_temperature = cities[city_id].temperature + rand() % 10 - 5;
    int new_humidity = cities[city_id].humidity + rand() % 10;
    int new_wind_speed = cities[city_id].wind_speed + rand() % 10;

    cities[city_id].temperature = new_temperature;
    cities[city_id].humidity = new_humidity;
    cities[city_id].wind_speed = new_wind_speed;
}

void *thread_func(void *arg) {
    int thread_id = *((int *) arg);
    int city_id = thread_id * NUM_CITIES / NUM_THREADS;

    while (1) {
        update_weather(city_id);
        sleep(1);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < NUM_CITIES; i++) {
        cities[i].id = i + 1;
        cities[i].temperature = rand() % 31 + 1;
        cities[i].humidity = rand() % 101;
        cities[i].wind_speed = rand() % 21 + 1;
    }

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        int *thread_arg = malloc(sizeof(int));
        *thread_arg = i + 1;
        pthread_create(&threads[i], NULL, thread_func, thread_arg);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}