//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Sherlock Holmes
/* The Case of the Mysterious Tower of Hanoi */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototypes
void moveDisk(int, char, char, char);
void displayInstructions(int);

int main() {
    int numOfDisks;
    char answer;
    
    printf("Greetings Detective. I am glad to see you here.\n");
    printf("There is a puzzle that has been causing quite the stir in our community.\n");
    printf("It is called Tower of Hanoi.\n");
    printf("I have the honor of presenting you with the mystery.\n");
    printf("Are you ready to take on the challenge? (y/n)");
    scanf("%c", &answer);
    
    if (answer == 'y' || answer == 'Y') {
        printf("Excellent! Let us proceed.\n");
        printf("Please enter the number of disks that you would like to use:\n");
        scanf("%d", &numOfDisks);
        
        //display instructions
        displayInstructions(numOfDisks);
        
        //solve puzzle
        moveDisk(numOfDisks, 'A', 'C', 'B');
        
        printf("Congratulations Detective, you have solved the mystery!\n");
        printf("The community is in your debt.\n");
    } else {
        printf("I understand Detective. Please come back when you are ready.\n");
    }
    
    return 0;
}

//function to move disk
void moveDisk(int numOfDisks, char source, char destination, char temp) {
    if (numOfDisks == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    moveDisk(numOfDisks - 1, source, temp, destination);
    
    printf("Move disk %d from %c to %c\n", numOfDisks, source, destination);
    
    moveDisk(numOfDisks - 1, temp, destination, source);
}

//function to display instructions
void displayInstructions(int numOfDisks) {
    printf("Let me explain how the puzzle works.\n");
    printf("There are %d disks in a tower on peg A.\n", numOfDisks);
    printf("The objective is to move the entire stack to peg C,\n");
    printf("but you can only move one disk at a time,\n");
    printf("and you can never put a larger disk on top of a smaller one.\n");
    printf("Do you understand the rules? (y/n)\n");
    
    char answer;
    scanf(" %c", &answer);
    
    if (answer == 'n' || answer == 'N') {
        printf("No problem Detective. Let me explain again.\n");
        displayInstructions(numOfDisks);
    }
}