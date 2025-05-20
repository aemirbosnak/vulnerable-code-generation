//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    srand(time(NULL));

    printf("Welcome to the Haunted House Simulator!\n");
    printf("\n");
    printf("You find yourself standing in front of a creepy old mansion.\n");
    printf("Do you dare to enter? (1: Yes / 2: No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n");
        printf("As you enter the mansion, the door slams shut behind you.\n");
        printf("You hear strange noises coming from different directions, and the air feels heavy with a foul odor.\n");
        printf("You see a dusty old table with three items: a flashlight, a map, and a key.\n");
        printf("Which item will you take? (1: Flashlight / 2: Map / 3: Key): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n");
            printf("You take the flashlight and turn it on.\n");
            printf("You discover a staircase leading down to a dark basement.\n");
            printf("Do you want to go down? (1: Yes / 2: No): ");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("\n");
                printf("You descend the staircase, and your flashlight casts eerie shadows on the walls.\n");
                printf("You hear strange whispers, and the air grows colder with each step.\n");
                printf("Suddenly, the floor beneath you gives way, and you fall into a pit.\n");
                printf("You are trapped forever...\n");
            } else {
                printf("\n");
                printf("You decide not to risk going down to the basement.\n");
                printf("You try to leave the mansion, but the door won't open...\n");
                printf("You are trapped forever...\n");
            }
            break;

        case 2:
            printf("\n");
            printf("You take the map and study it carefully.\n");
            printf("You notice a secret passage marked on the map, leading to a hidden room.\n");
            printf("You follow the map, and it leads you to a bookshelf.\n");
            printf("You move aside the books as indicated on the map, and the bookshelf slides open, revealing a dark passageway.\n");
            printf("Do you want to go through it? (1: Yes / 2: No): ");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("\n");
                printf("You enter the passageway, and the air grows colder and damper.\n");
                printf("You hear strange whispers, and your heart pounds in your chest.\n");
                printf("You finally reach the hidden room, and you see an old chest.\n");
                printf("You open the chest, and it's empty.\n");
                printf("Suddenly, the room fills with thick fog, and you can't see a thing.\n");
                printf("You try to leave, but you stumble and fall, hitting your head hard.\n");
                printf("You pass out and never wake up again...\n");
            } else {
                printf("\n");
                printf("You decide not to risk going through the secret passage.\n");
                printf("You try to leave the mansion, but the door won't open...\n");
                printf("You are trapped forever...\n");
            }
            break;

        case 3:
            printf("\n");
            printf("You take the key and notice that it's rusty and old.\n");
            printf("You try to insert it into the lock of the door, but it won't fit.\n");
            printf("You hear creaky footsteps coming from the hallway.\n");
            printf("You panic and hide behind a curtain.\n");
            printf("A ghostly figure enters the room, and you can see through it.\n");
            printf("It searches the room but doesn't find you.\n");
            printf("After a while, it disappears into thin air.\n");
            printf("You feel lucky to be alive.\n");
            break;

        default:
            printf("\n");
            printf("You didn't make a valid choice.\n");
            printf("You try to leave the mansion, but the door won't open...\n");
            printf("You are trapped forever...\n");
            break;
        }

    } else {
        printf("\n");
        printf("You decide not to enter the mansion.\n");
        printf("You turn around and start to leave, but you trip over a rock and fall.\n");
        printf("You hit your head hard and never wake up again...\n");
    }

    return 0;
}