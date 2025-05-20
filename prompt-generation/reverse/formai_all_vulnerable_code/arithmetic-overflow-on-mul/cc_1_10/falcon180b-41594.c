//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#define MAX_CITIES 10
#define DAY_IN_SECONDS 86400

typedef struct {
    char name[20];
    int temperature;
    int humidity;
    int wind_speed;
} City;

City cities[MAX_CITIES];
int num_cities;

void *update_weather(void *arg) {
    int city_id = *(int *) arg;
    City *city = &cities[city_id];

    while (1) {
        sleep(1);
        city->temperature += rand() % 10 - 5;
        city->humidity += rand() % 10 - 5;
        city->wind_speed += rand() % 10 - 5;
    }

    return NULL;
}

void *broadcast_weather(void *arg) {
    int city_id = *(int *) arg;
    City *city = &cities[city_id];

    while (1) {
        sleep(1);
        printf("City %s: Temperature %dC, Humidity %d%, Wind Speed %dkph\n", city->name, city->temperature, city->humidity, city->wind_speed);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i+1);
        scanf("%s", cities[i].name);
    }

    pthread_t threads[num_cities*2];

    for (int i = 0; i < num_cities; i++) {
        pthread_create(&threads[i*2], NULL, update_weather, &i);
        pthread_create(&threads[i*2+1], NULL, broadcast_weather, &i);
    }

    for (int i = 0; i < num_cities*2; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}