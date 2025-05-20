//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int activity_level;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Mr. Jones", 1, 3},
    {"Mrs. Smith", 2, 2},
    {"Mr. Brown", 3, 4},
    {"Ms. Johnson", 4, 3},
    {"Mr. Davis", 5, 2}
};

int main() {
    int i, j, k;
    time_t t;

    // Seed the random number generator
    srand(time(NULL));

    // Create the haunted house
    for (i = 0; i < MAX_GHOSTS; i++) {
        ghosts[i].room_num = rand() % 5 + 1;
    }

    // Simulate the haunted house
    printf("Welcome to the Haunted House!\n");
    printf("-----------------------\n");

    // Loop through the ghosts
    for (i = 0; i < MAX_GHOSTS; i++) {
        printf("Ghost: %s\n", ghosts[i].name);
        printf("Room Number: %d\n", ghosts[i].room_num);
        printf("Activity Level: %d\n", ghosts[i].activity_level);
        printf("\n");
    }

    // Wait for the user to leave
    printf("Press any key to exit...");
    scanf("%c", &k);

    return 0;
}