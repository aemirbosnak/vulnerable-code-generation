//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int altitude; // in meters
    int speed;    // in m/s
} Drone;

void initializeDrone(Drone *drone, const char *name) {
    strcpy(drone->name, name);
    drone->altitude = 0;
    drone->speed = 0;
}

void ascend(Drone *drone, int height) {
    drone->altitude += height;
    printf("%s gracefully ascends to a height of %d meters, touching the skies of romance.\n", drone->name, drone->altitude);
}

void descend(Drone *drone, int height) {
    if (drone->altitude < height) {
        printf("%s gently floats down, but cannot go lower than its current height of %d meters.\n", drone->name, drone->altitude);
    } else {
        drone->altitude -= height;
        printf("%s softly descends to a height of %d meters, lost in the beauty of the moment.\n", drone->name, drone->altitude);
    }
}

void setSpeed(Drone *drone, int speed) {
    drone->speed = speed;
    printf("%s sets its speed to %d m/s, ready to dance through the clouds.\n", drone->name, drone->speed);
}

void hover(Drone *drone) {
    printf("%s is now hovering at a serene altitude of %d meters, allowing love to bloom around.\n", drone->name, drone->altitude);
}

void displayStatus(Drone *drone) {
    printf("Current status of %s:\n", drone->name);
    printf("   Altitude: %d meters\n", drone->altitude);
    printf("   Speed: %d m/s\n", drone->speed);
}

void romanticDance(Drone *drone) {
    printf("%s is performing a beautiful dance in the air, swirling and twirling in the gentle embrace of the wind.\n", drone->name);
    ascend(drone, 50);
    setSpeed(drone, 5);
    hover(drone);

    printf("%s has now found a perfect spot in the sky, ready for a gentle spin.\n", drone->name);
}

void whisperToSky() {
    printf("In the soft moonlight, the drone whispers to the sky, a message of love and serenity...\n");
}

int main() {
    Drone myDrone;
    initializeDrone(&myDrone, "Elysium");

    int choice, height;
    
    while(1) {
        printf("\nWhat would you like to command %s to do?\n", myDrone.name);
        printf("1. Ascend\n");
        printf("2. Descend\n");
        printf("3. Set Speed\n");
        printf("4. Hover\n");
        printf("5. Display Status\n");
        printf("6. Dance in the Sky\n");
        printf("7. Whisper to the Sky\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the height to ascend (in meters): ");
                scanf("%d", &height);
                ascend(&myDrone, height);
                break;
            case 2:
                printf("Enter the height to descend (in meters): ");
                scanf("%d", &height);
                descend(&myDrone, height);
                break;
            case 3:
                printf("Enter the speed (in m/s): ");
                scanf("%d", &myDrone.speed);
                setSpeed(&myDrone, myDrone.speed);
                break;
            case 4:
                hover(&myDrone);
                break;
            case 5:
                displayStatus(&myDrone);
                break;
            case 6:
                romanticDance(&myDrone);
                break;
            case 7:
                whisperToSky();
                break;
            case 8:
                printf("Until we meet again in the skies, %s shall rest.\n", myDrone.name);
                exit(0);
            default:
                printf("Oh dear, that choice is like missing the chance to dance in the moonlight!\n");
        }
    }
    return 0;
}