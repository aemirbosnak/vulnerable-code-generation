//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define NUM_LIGHTS 4
#define LIGHT_ON 1
#define LIGHT_OFF 0

typedef struct {
    int state;
    char name[20];
} light_t;

light_t lights[NUM_LIGHTS] = {
    {LIGHT_ON, "Living Room"},
    {LIGHT_ON, "Kitchen"},
    {LIGHT_OFF, "Bedroom"},
    {LIGHT_OFF, "Bathroom"}
};

void *light_thread(void *arg) {
    int i = *(int *) arg;
    while (1) {
        printf("Light %s is %s\n", lights[i].name, lights[i].state == LIGHT_ON? "on" : "off");
        sleep(1);
        lights[i].state ^= 1;
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_LIGHTS];
    int i;

    for (i = 0; i < NUM_LIGHTS; i++) {
        pthread_create(&threads[i], NULL, light_thread, (void *) &i);
    }

    while (1) {
        printf("Enter command (on/off/toggle/quit): ");
        char command[10];
        fgets(command, 10, stdin);

        if (strcmp(command, "on") == 0) {
            printf("Enter light number: ");
            int light_num;
            scanf("%d", &light_num);
            lights[light_num].state = LIGHT_ON;
        } else if (strcmp(command, "off") == 0) {
            printf("Enter light number: ");
            int light_num;
            scanf("%d", &light_num);
            lights[light_num].state = LIGHT_OFF;
        } else if (strcmp(command, "toggle") == 0) {
            printf("Enter light number: ");
            int light_num;
            scanf("%d", &light_num);
            lights[light_num].state ^= 1;
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    for (i = 0; i < NUM_LIGHTS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}