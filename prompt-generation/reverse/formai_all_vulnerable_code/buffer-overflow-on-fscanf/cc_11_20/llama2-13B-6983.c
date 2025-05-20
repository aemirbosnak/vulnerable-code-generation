//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 50

struct guest {
    char name[50];
    char room_no[10];
    int check_in_time;
    int check_out_time;
};

struct room {
    char name[50];
    int capacity;
    int occupancy;
};

int main() {
    // Initialize guest and room structures
    struct guest guest[MAX_GUESTS];
    struct room room[MAX_ROOMS];

    // Read guest information from a file
    FILE *guest_file = fopen("guests.txt", "r");
    if (guest_file == NULL) {
        perror("Failed to open guests.txt");
        return 1;
    }
    int i = 0;
    while (i < MAX_GUESTS) {
        fscanf(guest_file, "%s %s %d %d", guest[i].name, guest[i].room_no, &guest[i].check_in_time, &guest[i].check_out_time);
        i++;
    }
    fclose(guest_file);

    // Read room information from a file
    FILE *room_file = fopen("rooms.txt", "r");
    if (room_file == NULL) {
        perror("Failed to open rooms.txt");
        return 1;
    }
    i = 0;
    while (i < MAX_ROOMS) {
        fscanf(room_file, "%s %d", room[i].name, &room[i].capacity);
        i++;
    }
    fclose(room_file);

    // Check-in and check-out logic
    while (1) {
        printf("Welcome to the C Hotel Management System!\n");
        printf("Current guests: ");
        for (int i = 0; i < MAX_GUESTS; i++) {
            if (guest[i].check_in_time == 0) {
                printf("%s (%s)", guest[i].name, guest[i].room_no);
            }
        }
        printf("\n");

        // Check for check-in requests
        for (int i = 0; i < MAX_GUESTS; i++) {
            if (guest[i].check_in_time == 0) {
                break;
            }
        }
        if (i == MAX_GUESTS) {
            printf("No more check-in requests available.\n");
        } else {
            // Assign room to guest
            for (int i = 0; i < MAX_ROOMS; i++) {
                if (room[i].occupancy < room[i].capacity) {
                    break;
                }
            }
            if (i == MAX_ROOMS) {
                printf("No more rooms available.\n");
            } else {
                guest[i].room_no[0] = room[i].name[0];
                guest[i].room_no[1] = room[i].name[1];
                guest[i].room_no[2] = room[i].name[2];
                guest[i].check_in_time = time(NULL);
                printf("Assigned room %s to guest %s.\n", room[i].name, guest[i].name);
            }
        }

        // Check for check-out requests
        for (int i = 0; i < MAX_GUESTS; i++) {
            if (guest[i].check_out_time > 0) {
                break;
            }
        }
        if (i == MAX_GUESTS) {
            printf("No more check-out requests available.\n");
        } else {
            // Release room
            for (int i = 0; i < MAX_ROOMS; i++) {
                if (room[i].occupancy > 0) {
                    break;
                }
            }
            if (i == MAX_ROOMS) {
                printf("No more rooms available for check-out.\n");
            } else {
                room[i].occupancy--;
                guest[i].check_out_time = time(NULL);
                printf("Released room %s to guest %s.\n", room[i].name, guest[i].name);
            }
        }
    }

    return 0;
}