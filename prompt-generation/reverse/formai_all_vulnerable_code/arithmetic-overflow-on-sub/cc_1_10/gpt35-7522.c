//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// Disk Space Analyzer
// A unique program that will analyze the C: drive space usage in a puzzling manner

int main(){
    int totalSpace = 100;
    int usedSpace = 40;
    int freeSpace = totalSpace - usedSpace;
    int numFiles = 10;
    int averageSize = usedSpace/numFiles;

    printf("Welcome to the Disk Space Analyzer!\n");
    printf("Today, we will be analyzing the C: drive.\n");
    printf("Total space available: %d GB\n", totalSpace);
    printf("Space used: %d GB\n", usedSpace);
    printf("Space free: %d GB\n", freeSpace);
    printf("Number of files on C: drive: %d\n", numFiles);
    printf("Average file size on C: drive: %d GB\n", averageSize);

    printf("Now for the puzzling part: can you guess how much space each file takes up on average?\n");
    printf("Hint: it's not the same as the average file size!\n");
    printf("Type your guess below:\n");

    int guess;
    scanf("%d", &guess);

    int difference = abs(averageSize - guess);
    if(difference <= 5){
        printf("You're close! The actual average file size is %d GB.\n", averageSize);
    }
    else{
        printf("Sorry, that's not quite right. The actual average file size is %d GB.\n", averageSize);
    }

    printf("Now, let's try another puzzle. Can you guess how much space the largest file on the C: drive takes up?\n");
    printf("Type your guess below:\n");

    int largestSize = 8;
    scanf("%d", &guess);

    difference = abs(largestSize - guess);
    if(difference <= 2){
        printf("You're a genius! The largest file on the C: drive takes up %d GB.\n", largestSize);
    }
    else{
        printf("Sorry, that's not correct. The largest file on the C: drive takes up %d GB.\n", largestSize);
    }

    printf("Thanks for playing the Disk Space Analyzer game! Come back soon!\n");

    return 0;
}