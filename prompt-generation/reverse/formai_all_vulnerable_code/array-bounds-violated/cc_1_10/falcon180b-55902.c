//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_LIGHTS 5

typedef struct {
    char name[20];
    int status;
} Light;

Light lights[MAX_LIGHTS];

void initLights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].status = FALSE;
    }
}

void turnOnLight(int index) {
    lights[index].status = TRUE;
}

void turnOffLight(int index) {
    lights[index].status = FALSE;
}

void printStatus() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (lights[i].status == TRUE) {
            printf("Light %s is on.\n", lights[i].name);
        } else {
            printf("Light %s is off.\n", lights[i].name);
        }
    }
}

int main() {
    initLights();
    srand(time(NULL));
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].name[0] = 'L';
        lights[i].name[1] = 'i';
        lights[i].name[2] = 'g';
        lights[i].name[3] = 'h';
        lights[i].name[4] = 't';
        lights[i].name[5] = i + '0';
        lights[i].name[6] = '\0';
    }
    int choice;
    do {
        printf("Welcome to the surrealist smart home!\n");
        printf("Please choose an option:\n");
        printf("1. Turn on a light\n");
        printf("2. Turn off a light\n");
        printf("3. Print light status\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Which light do you want to turn on? (0-4)\n");
            int index;
            scanf("%d", &index);
            turnOnLight(index);
            break;
        case 2:
            printf("Which light do you want to turn off? (0-4)\n");
            int index2;
            scanf("%d", &index2);
            turnOffLight(index2);
            break;
        case 3:
            printStatus();
            break;
        case 4:
            printf("Thank you for using the surrealist smart home!\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}