//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define MAX_WORKOUTS 4

typedef struct {
    char name[20];
    int age;
    float height;
    float weight;
} Client;

typedef struct {
    char name[20];
    int duration;
    int calories_burnt;
} Workout;

Client clients[MAX_CLIENTS];
Workout workouts[MAX_WORKOUTS];

int num_clients = 0;
int num_workouts = 0;

pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t workout_mutex = PTHREAD_MUTEX_INITIALIZER;

void *client_update_thread(void *arg);
void *workout_update_thread(void *arg);

int main() {
    // Initialize default clients
    Client client1 = {"John", 25, 175.0, 75.0};
    Client client2 = {"Emily", 30, 160.0, 60.0};
    Client client3 = {"Michael", 35, 180.0, 85.0};

    clients[0] = client1;
    clients[1] = client2;
    clients[2] = client3;

    num_clients = 3;

    // Initialize default workouts
    Workout workout1 = {"Treadmill", 30, 300};
    Workout workout2 = {"Bicycling", 45, 400};
    Workout workout3 = {"Weightlifting", 60, 500};

    workouts[0] = workout1;
    workouts[1] = workout2;
    workouts[2] = workout3;

    num_workouts = 3;

    // Create client update thread
    pthread_t client_thread;
    pthread_create(&client_thread, NULL, client_update_thread, NULL);

    // Create workout update thread
    pthread_t workout_thread;
    pthread_create(&workout_thread, NULL, workout_update_thread, NULL);

    // Wait for threads to finish
    pthread_join(client_thread, NULL);
    pthread_join(workout_thread, NULL);

    return 0;
}

void *client_update_thread(void *arg) {
    while (1) {
        // Lock mutex before updating clients array
        pthread_mutex_lock(&client_mutex);

        // Add new client if there is space in the array
        if (num_clients < MAX_CLIENTS) {
            Client new_client = {"", 0, 0.0, 0.0};

            printf("Enter client name: ");
            scanf("%s", new_client.name);

            printf("Enter client age: ");
            scanf("%d", &new_client.age);

            printf("Enter client height: ");
            scanf("%f", &new_client.height);

            printf("Enter client weight: ");
            scanf("%f", &new_client.weight);

            clients[num_clients] = new_client;
            num_clients++;
        }

        // Unlock mutex after updating clients array
        pthread_mutex_unlock(&client_mutex);

        // Sleep for 10 seconds before updating again
        sleep(10);
    }
}

void *workout_update_thread(void *arg) {
    while (1) {
        // Lock mutex before updating workouts array
        pthread_mutex_lock(&workout_mutex);

        // Add new workout if there is space in the array
        if (num_workouts < MAX_WORKOUTS) {
            Workout new_workout = {"", 0, 0};

            printf("Enter workout name: ");
            scanf("%s", new_workout.name);

            printf("Enter workout duration: ");
            scanf("%d", &new_workout.duration);

            printf("Enter calories burnt per minute: ");
            scanf("%d", &new_workout.calories_burnt);

            workouts[num_workouts] = new_workout;
            num_workouts++;
        }

        // Unlock mutex after updating workouts array
        pthread_mutex_unlock(&workout_mutex);

        // Sleep for 15 seconds before updating again
        sleep(15);
    }
}