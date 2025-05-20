//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdint.h>

typedef enum {
    UNDER_BRIDGE = 1,
    OVER_MOAT = 2,
    IN_TOWER = 3
} RoomType;

typedef struct {
    RoomType type;
    char *description;
    uint8_t n_neighbors;
    uint16_t neighbors[4];
} Room;

Room castle[16] = {
    { UNDER_BRIDGE, "Beneath the drawbridge, a dank and musty place.", 2, { 1, 2 } },
    { OVER_MOAT, "Upon the drawbridge, overlooking the moat.", 3, { 0, 2, 3 } },
    { UNDER_BRIDGE, "In the guard tower, a narrow and winding staircase.", 2, { 1, 3 } },
    { IN_TOWER, "In the great hall, a vast and echoing chamber.", 4, { 1, 2, 5, 6 } },
    { UNDER_BRIDGE, "In the dungeon, a dark and forbidding place.", 1, { 3 } },
    { IN_TOWER, "In the armory, a well-stocked cache of weapons.", 3, { 3, 6, 7 } },
    { IN_TOWER, "In the library, a vast collection of ancient tomes.", 2, { 3, 7 } },
    { IN_TOWER, "In the treasury, a heavily guarded vault.", 1, { 5 } },
    { OVER_MOAT, "Upon the battlements, a breathtaking view of the countryside.", 3, { 9, 10, 11 } },
    { OVER_MOAT, "In the stables, a bustling hub of activity.", 2, { 8, 10 } },
    { OVER_MOAT, "In the barracks, a home to the castle's brave knights.", 3, { 9, 11, 12 } },
    { OVER_MOAT, "Upon the watchtower, a strategic vantage point.", 2, { 10, 12 } },
    { OVER_MOAT, "In the smithy, a loud and fiery workshop.", 1, { 11 } },
    { OVER_MOAT, "In the kitchens, a fragrant and delicious aroma.", 2, { 12, 14 } },
    { OVER_MOAT, "In the chapel, a place of peace and reflection.", 1, { 13 } },
    { OVER_MOAT, "In the courtyard, a bustling hub of activity.", 3, { 13, 14, 15 } }
};

int main() {
    Room *current_room = &castle[0];
    char input[10];

    printf("Welcome to the Castle of Enigmata!\n");

    while (1) {
        printf("\nYou are now in the %s.\n", current_room->description);

        if (current_room->type == IN_TOWER) {
            printf("You may search for a hidden object in this room.\n");
            printf("Enter a command (search, move, quit): ");
            scanf("%s", input);

            if (strcmp(input, "search") == 0) {
                // Implement search functionality here
            } else if (strcmp(input, "move") == 0) {
                printf("Which direction do you wish to move (n, s, e, w): ");
                scanf("%s", input);

                switch (input[0]) {
                    case 'n':
                        current_room = &castle[current_room->neighbors[0]];
                        break;
                    case 's':
                        current_room = &castle[current_room->neighbors[1]];
                        break;
                    case 'e':
                        current_room = &castle[current_room->neighbors[2]];
                        break;
                    case 'w':
                        current_room = &castle[current_room->neighbors[3]];
                        break;
                }
            } else if (strcmp(input, "quit") == 0) {
                break;
            }
        } else {
            printf("You may move to a neighboring room.\n");
            printf("Which direction do you wish to move (n, s, e, w): ");
            scanf("%s", input);

            switch (input[0]) {
                case 'n':
                    current_room = &castle[current_room->neighbors[0]];
                    break;
                case 's':
                    current_room = &castle[current_room->neighbors[1]];
                    break;
                case 'e':
                    current_room = &castle[current_room->neighbors[2]];
                    break;
                case 'w':
                    current_room = &castle[current_room->neighbors[3]];
                    break;
            }
        }
    }

    printf("Thank you for visiting the Castle of Enigmata!\n");
    return 0;
}