//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_STRING_LENGTH 50

typedef struct {
    char name[MAX_STRING_LENGTH];
    int light_status; // 0 for OFF, 1 for ON
} Room;

Room castle[MAX_ROOMS];
int room_count = 0;

// Function to add a new room to the castle
void add_room(char *room_name) {
    if (room_count < MAX_ROOMS) {
        strcpy(castle[room_count].name, room_name);
        castle[room_count].light_status = 0; // Initially OFF
        room_count++;
        printf("Hark! The room '%s' hath been added to the castle!\n", room_name);
    } else {
        printf("Alas! There art no more room for new chambers in our castle!\n");
    }
}

// Function to toggle the lights in a specific room
void toggle_light(char *room_name) {
    for (int i = 0; i < room_count; i++) {
        if (strcmp(castle[i].name, room_name) == 0) {
            castle[i].light_status = !castle[i].light_status; // Toggle the status
            printf("The lights in the chamber '%s' are now %s!\n", room_name,
                   castle[i].light_status ? "ALIGHT" : "doused");
            return;
        }
    }
    printf("Methinks the chamber '%s' doth not exist in this castle!\n", room_name);
}

// Function to check the light status of a room
void check_light_status(char *room_name) {
    for (int i = 0; i < room_count; i++) {
        if (strcmp(castle[i].name, room_name) == 0) {
            printf("In the chamber '%s', the lights are %s!\n", room_name,
                   castle[i].light_status ? "ALIGHT" : "doused");
            return;
        }
    }
    printf("Alas! The chamber '%s' doth not exist!\n", room_name);
}

// Function to list all the rooms and their light status
void list_rooms() {
    if (room_count == 0) {
        printf("The castle is empty of chambers! Go forth and add some!\n");
        return;
    }
    printf("Verily, here is the record of chambers within the castle:\n");
    for (int i = 0; i < room_count; i++) {
        printf("Chamber: '%s', Lights are %s\n", castle[i].name,
               castle[i].light_status ? "ALIGHT" : "doused");
    }
}

// Main function to drive the program
int main() {
    int choice;
    char room_name[MAX_STRING_LENGTH];

    do {
        printf("\n--- The Grand Castle of Light Control ---\n");
        printf("1. Add a Room\n");
        printf("2. Toggle Light in a Room\n");
        printf("3. Check Light Status of a Room\n");
        printf("4. List All Rooms\n");
        printf("5. Exit\n");
        printf("Choose thy fate (1-5): ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                printf("Pray, enter the name of the new chamber: ");
                fgets(room_name, sizeof(room_name), stdin);
                room_name[strcspn(room_name, "\n")] = 0; // Remove newline
                add_room(room_name);
                break;
            case 2:
                printf("Which chamber's lights dost thou wish to toggle? ");
                fgets(room_name, sizeof(room_name), stdin);
                room_name[strcspn(room_name, "\n")] = 0; // Remove newline
                toggle_light(room_name);
                break;
            case 3:
                printf("Seek the light status of which chamber? ");
                fgets(room_name, sizeof(room_name), stdin);
                room_name[strcspn(room_name, "\n")] = 0; // Remove newline
                check_light_status(room_name);
                break;
            case 4:
                list_rooms();
                break;
            case 5:
                printf("Farewell, noble lord or lady! Until we meet again!\n");
                break;
            default:
                printf("That choice is beyond thy ken. Choose again!\n");
        }
    } while (choice != 5);

    return 0;
}