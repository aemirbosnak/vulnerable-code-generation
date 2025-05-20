//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define MAX_LIGHTS 10
#define LIGHT_ON 1
#define LIGHT_OFF 0

typedef struct {
    int id;
    char name[20];
    int status; // 1 for ON, 0 for OFF
} Light;

Light lights[MAX_LIGHTS];
pthread_mutex_t lock;

void initialize_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i;
        snprintf(lights[i].name, sizeof(lights[i].name), "Light_%d", i + 1);
        lights[i].status = LIGHT_OFF;
    }
}

void *light_status_updater(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        for (int i = 0; i < MAX_LIGHTS; i++) {
            if (lights[i].status == LIGHT_ON) {
                printf("%s is ON\n", lights[i].name);
            } else {
                printf("%s is OFF\n", lights[i].name);
            }
        }
        pthread_mutex_unlock(&lock);
        sleep(5);
    }
    return NULL;
}

void turn_on_light(int id) {
    pthread_mutex_lock(&lock);
    if (id >= 0 && id < MAX_LIGHTS) {
        lights[id].status = LIGHT_ON;
        printf("%s turned ON\n", lights[id].name);
    } else {
        printf("Invalid Light ID\n");
    }
    pthread_mutex_unlock(&lock);
}

void turn_off_light(int id) {
    pthread_mutex_lock(&lock);
    if (id >= 0 && id < MAX_LIGHTS) {
        lights[id].status = LIGHT_OFF;
        printf("%s turned OFF\n", lights[id].name);
    } else {
        printf("Invalid Light ID\n");
    }
    pthread_mutex_unlock(&lock);
}

void list_lights() {
    pthread_mutex_lock(&lock);
    printf("Listing lights:\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%d: %s [%s]\n", lights[i].id + 1, lights[i].name, lights[i].status == LIGHT_ON ? "ON" : "OFF");
    }
    pthread_mutex_unlock(&lock);
}

void display_menu() {
    printf("\nSmart Home Light Control\n");
    printf("1. Turn ON Light\n");
    printf("2. Turn OFF Light\n");
    printf("3. List Lights\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

int main() {
    pthread_t updater_thread;
    int option, light_id;

    pthread_mutex_init(&lock, NULL);
    initialize_lights();

    if (pthread_create(&updater_thread, NULL, light_status_updater, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    while (1) {
        display_menu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter Light ID to turn ON (1-%d): ", MAX_LIGHTS);
                scanf("%d", &light_id);
                turn_on_light(light_id - 1);
                break;
            case 2:
                printf("Enter Light ID to turn OFF (1-%d): ", MAX_LIGHTS);
                scanf("%d", &light_id);
                turn_off_light(light_id - 1);
                break;
            case 3:
                list_lights();
                break;
            case 4:
                printf("Exiting...\n");
                pthread_cancel(updater_thread);
                pthread_join(updater_thread, NULL);
                pthread_mutex_destroy(&lock);
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
    return 0;
}