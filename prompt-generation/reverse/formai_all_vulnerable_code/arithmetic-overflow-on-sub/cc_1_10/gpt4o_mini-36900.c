//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: medieval
#include <stdio.h>

// Function prototypes
void moveDisk(int n, char source, char target, char auxiliary);
void hanoi(int n, char source, char target, char auxiliary);

// Main function - the knight's tale begins!
int main() {
    int number_of_disks;

    // Prologue: The quest for the ancient disks
    printf("Greetings, noble traveler! Enter the number of mystical disks you wish to move in the Tower of Hanoi: ");
    scanf("%d", &number_of_disks);

    // The journey begins!
    printf("\nYour journey to move %d disks from Tower A to Tower C begins!\n", number_of_disks);
    printf("Behold the art of the ancient sorcerers...\n\n");
    
    // Invoke the hanoi function
    hanoi(number_of_disks, 'A', 'C', 'B');

    // Epilogue: The successful quest
    printf("\nThe quest is complete! All disks have been transported from Tower A to Tower C.\n");
    return 0;
}

// Function to move disks from source to target using auxiliary
void moveDisk(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from Tower %c to Tower %c.\n", source, target);
    } else {
        moveDisk(n-1, source, auxiliary, target);
        printf("Move disk %d from Tower %c to Tower %c.\n", n, source, target);
        moveDisk(n-1, auxiliary, target, source);
    }
}

// The grand function that triggers the magic!
void hanoi(int n, char source, char target, char auxiliary) {
    moveDisk(n, source, target, auxiliary);
}

// Tales of olden days, the recursive sorcery
void engraveDiskMovement(int diskNumber, char source, char target) {
    if (diskNumber == 1) {
        printf("A brave knight moves disk from Tower %c to Tower %c!\n", source, target);
    }
}

// Ancient scripts to ease the mind of the dilemma
void wisdomOfTheAges(int n, char source, char target, char auxiliary) {
    printf("The ancient scrolls declare:\n");
    if (n == 1) {
        engraveDiskMovement(1, source, target);
    } else {
        wisdomOfTheAges(n-1, source, auxiliary, target);
        engraveDiskMovement(n, source, target);
        wisdomOfTheAges(n-1, auxiliary, target, source);
    }
}

// The Chamber of Towers managed by the great Warlord
void chamberOfTowers() {
    printf("Welcome to the Chamber of Towers, where skills of persistence are tested!\n");
    printf("Here, three towers stand tall, and many disks lay at their feet, awaiting your command.\n");
}

// Legends of medieval wisdom, a function that embraces them all
void medievalLegends(int number_of_disks) {
    chamberOfTowers();
    if (number_of_disks < 1) {
        printf("Noble one, it seems you have no disks to move. Return when the fates have favored you!\n");
    } else {
        wisdomOfTheAges(number_of_disks, 'A', 'C', 'B');
    }
}