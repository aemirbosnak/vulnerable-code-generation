//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_rooms, num_ghosts, num_doors, num_windows, num_stairs, num_doors_rooms, num_windows_rooms, num_stairs_rooms, num_doors_ghosts, num_windows_ghosts, num_stairs_ghosts;
    int num_doors_used, num_windows_used, num_stairs_used, num_doors_ghosts_scared, num_windows_ghosts_scared, num_stairs_ghosts_scared;
    int room_num, ghost_num, door_num, window_num, stair_num;
    char feature_type;
    int i, j, k;
    srand(time(NULL));

    printf("Number of rooms: ");
    scanf("%d", &num_rooms);
    printf("Number of ghosts: ");
    scanf("%d", &num_ghosts);
    printf("Number of doors: ");
    scanf("%d", &num_doors);
    printf("Number of windows: ");
    scanf("%d", &num_windows);
    printf("Number of stairs: ");
    scanf("%d", &num_stairs);
    printf("Number of rooms with doors: ");
    scanf("%d", &num_doors_rooms);
    printf("Number of rooms with windows: ");
    scanf("%d", &num_windows_rooms);
    printf("Number of rooms with stairs: ");
    scanf("%d", &num_stairs_rooms);
    printf("Number of ghosts scared of doors: ");
    scanf("%d", &num_doors_ghosts);
    printf("Number of ghosts scared of windows: ");
    scanf("%d", &num_windows_ghosts);
    printf("Number of ghosts scared of stairs: ");
    scanf("%d", &num_stairs_ghosts);

    for (i = 1; i <= num_rooms; i++) {
        room_num = i;
        num_doors_used = 0;
        num_windows_used = 0;
        num_stairs_used = 0;
        num_doors_ghosts_scared = 0;
        num_windows_ghosts_scared = 0;
        num_stairs_ghosts_scared = 0;

        for (j = 0; j < num_doors; j++) {
            door_num = rand() % (num_rooms + 1);
            feature_type = 'd';
            if (door_num!= room_num) {
                printf("Room %d has a door in room %d.\n", room_num, door_num);
                printf("Feature type: %c\n", feature_type);
                printf("Feature used: %d\n", num_doors_used);
                num_doors_used++;
            }
        }

        for (j = 0; j < num_windows; j++) {
            window_num = rand() % (num_rooms + 1);
            feature_type = 'w';
            if (window_num!= room_num) {
                printf("Room %d has a window in room %d.\n", room_num, window_num);
                printf("Feature type: %c\n", feature_type);
                printf("Feature used: %d\n", num_windows_used);
                num_windows_used++;
            }
        }

        for (j = 0; j < num_stairs; j++) {
            stair_num = rand() % (num_rooms + 1);
            feature_type ='s';
            if (stair_num!= room_num) {
                printf("Room %d has a stair in room %d.\n", room_num, stair_num);
                printf("Feature type: %c\n", feature_type);
                printf("Feature used: %d\n", num_stairs_used);
                num_stairs_used++;
            }
        }

        if (num_doors_used > 0) {
            printf("Room %d has %d doors.\n", room_num, num_doors_used);
        } else {
            printf("Room %d has no doors.\n", room_num);
        }

        if (num_windows_used > 0) {
            printf("Room %d has %d windows.\n", room_num, num_windows_used);
        } else {
            printf("Room %d has no windows.\n", room_num);
        }

        if (num_stairs_used > 0) {
            printf("Room %d has %d stairs.\n", room_num, num_stairs_used);
        } else {
            printf("Room %d has no stairs.\n", room_num);
        }

        printf("Room %d has %d doors with %d ghosts scared of doors.\n", room_num, num_doors_ghosts, num_doors_ghosts_scared);
        printf("Room %d has %d windows with %d ghosts scared of windows.\n", room_num, num_windows_ghosts, num_windows_ghosts_scared);
        printf("Room %d has %d stairs with %d ghosts scared of stairs.\n", room_num, num_stairs_ghosts, num_stairs_ghosts_scared);

        for (k = 0; k < num_ghosts; k++) {
            ghost_num = k + 1;
            if (rand() % 100 <= num_doors_ghosts) {
                if (num_doors_ghosts_scared > 0) {
                    door_num = rand() % (num_rooms + 1);
                    if (door_num!= room_num) {
                        printf("Ghost %d is scared of doors.\n", ghost_num);
                        printf("Ghost %d is trying to escape through the closest door.\n", ghost_num);
                        printf("Ghost %d is in room %d.\n", ghost_num, room_num);
                        printf("Ghost %d is trying to escape through door %d in room %d.\n", ghost_num, door_num, room_num);
                        printf("Ghost %d is in room %d after escaping through door %d.\n", ghost_num, room_num, door_num);
                        num_doors_ghosts_scared--;
                        num_doors_used--;
                        room_num = door_num;
                    }
                } else {
                    printf("Ghost %d is scared of doors, but there are no doors to escape from.\n", ghost_num);
                }
            } else if (rand() % 100 <= num_windows_ghosts) {
                if (num_windows_ghosts_scared > 0) {
                    window_num = rand() % (num_rooms + 1);
                    if (window_num!= room_num) {
                        printf("Ghost %d is scared of windows.\n", ghost_num);
                        printf("Ghost %d is trying to escape through the closest window.\n", ghost_num);
                        printf("Ghost %d is in room %d.\n", ghost_num, room_num);
                        printf("Ghost %d is trying to escape through window %d in room %d.\n", ghost_num, window_num, room_num);
                        printf("Ghost %d is in room %d after escaping through window %d.\n", ghost_num, room_num, window_num);
                        num_windows_ghosts_scared--;
                        num_windows_used--;
                        room_num = window_num;
                    }
                } else {
                    printf("Ghost %d is scared of windows, but there are no windows to escape from.\n", ghost_num);
                }
            } else if (rand() % 100 <= num_stairs_ghosts) {
                if (num_stairs_ghosts_scared > 0) {
                    stair_num = rand() % (num_rooms + 1);
                    if (stair_num!= room_num) {
                        printf("Ghost %d is scared of stairs.\n", ghost_num);
                        printf("Ghost %d is trying to escape through the closest stair.\n", ghost_num);
                        printf("Ghost %d is in room %d.\n", ghost_num, room_num);
                        printf("Ghost %d is trying to escape through stair %d in room %d.\n", ghost_num, stair_num, room_num);
                        printf("Ghost %d is in room %d after escaping through stair %d.\n", ghost_num, room_num, stair_num);
                        num_stairs_ghosts_scared--;
                        num_stairs_used--;
                        room_num = stair_num;
                    }
                } else {
                    printf("Ghost %d is scared of stairs, but there are no stairs to escape from.\n", ghost_num);
                }
            } else {
                printf("Ghost %d is not scared of any features.\n", ghost_num);
            }
        }
    }

    return 0;
}