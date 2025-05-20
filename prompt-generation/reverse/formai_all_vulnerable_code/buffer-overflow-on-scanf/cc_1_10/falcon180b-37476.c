//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shapeShift(int shape) {
    switch (shape) {
        case 1:
            printf("You have transformed into a bird!\n");
            break;
        case 2:
            printf("You have transformed into a cat!\n");
            break;
        case 3:
            printf("You have transformed into a fish!\n");
            break;
        default:
            printf("Invalid shape.\n");
            break;
    }
}

int main() {
    int shape = 0;
    int choice;
    srand(time(0));

    while (shape!= 3) {
        printf("What shape do you want to transform into?\n");
        printf("1. Bird\n");
        printf("2. Cat\n");
        printf("3. Fish\n");
        printf("4. Back to human\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                shape = 1;
                break;
            case 2:
                shape = 2;
                break;
            case 3:
                shape = 3;
                break;
            case 4:
                shape = 0;
                break;
            default:
                printf("Invalid choice.\n");
        }

        shapeShift(shape);
    }

    return 0;
}