//FormAI DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to get random number
int getRandomNumber(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

//Function to print the array
void printArray(char arr[], int size) {
    printf("\n");
    for(int i=0; i<size; i++) {
        printf(" %c ", arr[i]);
    }
    printf("\n");
}

int main()
{
    //Seed for random number generation
    srand(time(0));

    //Declaring and initializing the character array
    char arr[] = {'G', 'A', 'M', 'E', 'O', 'V', 'E', 'R', '!', '!', '!'};

    //Getting size of the array
    int size = sizeof(arr) / sizeof(arr[0]);

    //Printing the initial array
    printf("Welcome to Game Over!\n");
    printArray(arr, size);

    //Asking user for the number of shuffles
    int shuffleCount;
    printf("\nEnter the number of times you want to shuffle the array: ");
    scanf("%d", &shuffleCount);

    //Looping through the shuffleCount
    for(int i=0; i<shuffleCount; i++) {
        //Generating two random indexes to swap
        int index1 = getRandomNumber(0, size-1);
        int index2 = getRandomNumber(0, size-1);

        //Swapping the elements at the two indexes
        char temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;

        //Printing the shuffled array
        printf("\nAfter shuffle %d", i+1);
        printArray(arr, size);
    }

    //Printing the final message
    printf("\nCongratulations! You completed Game Over!");

    return 0;   
}