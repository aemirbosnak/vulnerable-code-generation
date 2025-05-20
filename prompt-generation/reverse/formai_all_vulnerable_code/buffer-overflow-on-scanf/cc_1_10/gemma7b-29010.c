//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int spectral_power;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Mr. Bartholomew", 1, 3},
    {"Mrs. Amelia", 2, 2},
    {"The Bloody Bride", 3, 5},
    {"The Dancing Demon", 4, 4},
    {"The Whispering Ghost", 5, 3}
};

void enter_haunted_house(int room_num) {
    printf("You have entered room %d.\n", room_num);

    for (int i = 0; i < MAX_GHOSTS; i++) {
        if (ghosts[i].room_num == room_num) {
            printf("A ghostly presence has been detected: %s\n", ghosts[i].name);

            switch (ghosts[i].spectral_power) {
                case 1:
                    printf("The ghost whispers secrets.\n");
                    break;
                case 2:
                    printf("The ghost moves objects around.\n");
                    break;
                case 3:
                    printf("The ghost creates illusions.\n");
                    break;
                case 4:
                    printf("The ghost can manipulate time.\n");
                    break;
                case 5:
                    printf("The ghost can possess you.\n");
                    break;
            }
        }
    }

    printf("Please enter a command: ");
    char command[20];
    scanf("%s", command);

    if (strcmp(command, "leave") == 0) {
        printf("You have left the haunted house.\n");
    } else {
        printf("Invalid command.\n");
    }
}

int main() {
    enter_haunted_house(1);
    return 0;
}