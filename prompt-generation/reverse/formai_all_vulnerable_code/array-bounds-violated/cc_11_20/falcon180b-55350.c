//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_LIGHTS 3

typedef struct {
    char name[20];
    int num_lights;
    int lights[MAX_LIGHTS];
} Room;

int main() {
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;
    char choice;

    do {
        printf("Sherlock Holmes' Smart Home Light Control\n");
        printf("A. Add Room\n");
        printf("B. Remove Room\n");
        printf("C. Turn On/Off Lights\n");
        printf("D. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case 'A':
                if(num_rooms >= MAX_ROOMS) {
                    printf("Maximum number of rooms reached.\n");
                } else {
                    printf("Enter room name: ");
                    scanf("%s", rooms[num_rooms].name);
                    rooms[num_rooms].num_lights = 0;
                    printf("Enter number of lights (max %d): ", MAX_LIGHTS);
                    scanf("%d", &rooms[num_rooms].num_lights);
                    for(int i=0; i<rooms[num_rooms].num_lights; i++) {
                        printf("Enter light ID (%d-%d): ", 1, MAX_LIGHTS);
                        scanf("%d", &rooms[num_rooms].lights[i]);
                    }
                    num_rooms++;
                }
                break;

            case 'B':
                printf("Enter room name to remove: ");
                scanf("%s", rooms[num_rooms-1].name);
                num_rooms--;
                break;

            case 'C':
                printf("Enter room name: ");
                scanf("%s", rooms[num_rooms-1].name);
                printf("Enter light ID (1-%d): ", rooms[num_rooms-1].num_lights);
                scanf("%d", &choice);
                if(choice >= 1 && choice <= rooms[num_rooms-1].num_lights) {
                    printf("Enter On/Off: ");
                    scanf("%c", &choice);
                    if(choice == 'O' || choice == 'o') {
                        printf("Light turned on.\n");
                    } else if(choice == 'F' || choice == 'f') {
                        printf("Light turned off.\n");
                    }
                } else {
                    printf("Invalid light ID.\n");
                }
                break;

            case 'D':
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 'D');

    return 0;
}