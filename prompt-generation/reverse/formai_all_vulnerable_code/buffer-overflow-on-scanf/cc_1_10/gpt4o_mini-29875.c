//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void hanoi(int num, char source, char target, char auxiliary) {
    // If there's only one disk, move from source to target
    if (num == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    // Move disks above the current disk to auxiliary peg
    hanoi(num - 1, source, auxiliary, target);
    
    // Move the current largest disk to the target peg
    printf("Move disk %d from %c to %c\n", num, source, target);
    
    // Move the disks from auxiliary to target peg
    hanoi(num - 1, auxiliary, target, source);
}

void sleep_custom(int seconds) {
    printf("Hold your horses! Waiting for %d seconds... \n", seconds);
    sleep(seconds);
}

int main() {
    int number_of_disks;

    printf("Welcome, brave soul, to the Tower of Hanoi!\n");
    sleep_custom(2);

    printf("Enter the number of disks you want to play with (1-10): ");
    scanf("%d", &number_of_disks);
    
    // Validate the number of disks
    if (number_of_disks < 1 || number_of_disks > 10) {
        printf("Ah, the forbidden numbers! Choose wisely next time.\n");
        return 1;
    }

    printf("You've chosen %d disks. Prepare thyself for a mind-bending journey!\n", number_of_disks);
    sleep_custom(2);
    
    printf("Let the stacking commence!\n");
    sleep_custom(1);
    
    // Invoke the recursive hanoi function
    hanoi(number_of_disks, 'A', 'C', 'B');

    printf("All done! You've successfully conquered the Tower of Hanoi.\n");
    sleep_custom(1);
    
    // Ending message
    printf("Now, take a moment to reflect and bask in your glory...\n");
    sleep_custom(2);
    printf("Until we meet again in another mystical challenge!\n");

    return 0;
}