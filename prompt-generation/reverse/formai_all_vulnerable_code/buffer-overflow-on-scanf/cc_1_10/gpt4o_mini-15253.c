//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    char *name;
    int altitude;
    int position_x;
    int position_y;
    int battery_life; // in percentage
} Drone;

void initialize_drone(Drone *d, char *name) {
    d->name = name;
    d->altitude = 0;
    d->position_x = 0;
    d->position_y = 0;
    d->battery_life = 100; // Full charge
}

void ascend(Drone *d, int height) {
    if (d->battery_life <= 0) {
        printf("%s cannot ascend, forsooth! The battery is dead!\n", d->name);
        return;
    }
    d->altitude += height;
    d->battery_life -= height / 5; // Battery drains with altitude
    printf("%s ascends to %d feet in the air, buoyed by love and the wind!\n", d->name, d->altitude);
}

void descend(Drone *d, int height) {
    if (d->altitude < height) {
        printf("%s cannot descend thus! The ground doth beckon her.\n", d->name);
        return;
    }
    d->altitude -= height;
    printf("%s descends gracefully, returning to the earth from whence she came.\n", d->name);
}

void move(Drone *d, int x, int y) {
    if (d->battery_life <= 0) {
        printf("%s cannot move, for the fates have conspired to drain her essence!\n", d->name);
        return;
    }
    d->position_x += x;
    d->position_y += y;
    d->battery_life -= (abs(x) + abs(y)) / 10; // Battery drains with movement
    printf("%s moves to position (%d, %d), drawn by the heart's desire!\n", d->name, d->position_x, d->position_y);
}

void show_status(Drone *d) {
    printf("Alas! The status of %s:\n", d->name);
    printf("Altitude: %d feet\n", d->altitude);
    printf("Position: (%d, %d)\n", d->position_x, d->position_y);
    printf("Battery Life: %d%%\n\n", d->battery_life);
}

void engage(Drone *d) {
    printf("%s doth awaken with wings of freedom!\n", d->name);
    while (d->battery_life > 0) {
        char choice;
        printf("What dost thou wish to command? (a)scent, (d)escent, (m)ove, (s)tatus, (e)xit: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                ascend(d, 10);
                break;
            case 'd':
                descend(d, 10);
                break;
            case 'm':
                move(d, 5, 5); // Move diagonally
                break;
            case 's':
                show_status(d);
                break;
            case 'e':
                printf("%s returns hence, her tasks complete forsooth!\n", d->name);
                return;
            default:
                printf("Alas! That command is but a fleeting whisper in the night.\n");
                break;
        }
        sleep(1);
    }
    printf("%s has succumbed to the dark abyss of battery life!\n", d->name);
}

int main() {
    Drone myDrone;
    initialize_drone(&myDrone, "Juliet");

    printf("Enter the name of thy drone, fairest maiden?: ");
    char drone_name[100];
    scanf("%s", drone_name);
    myDrone.name = drone_name;

    engage(&myDrone);

    printf("The tale of %s is at an end, may her stories linger in the skies.\n", myDrone.name);
    return 0;
}