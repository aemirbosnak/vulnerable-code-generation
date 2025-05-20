//FormAI DATASET v1.0 Category: Memory Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to shuffle the elements of an array randomly
void shuffle(int arr[], int size) {
    //use srand to seed the random number generator with current time
    srand(time(NULL));
    for(int i = size - 1; i > 0; i--) {
        //generate a random index between 0 and i
        int j = rand() % (i + 1);
        //swap elements at index i and j
        swap(&arr[i], &arr[j]);
    }
}

int main() {
    //define the array to hold the memory game items
    char items[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int size = sizeof(items) / sizeof(items[0]);
    int board[size * 2];
    //fill the board with the items twice
    for(int i = 0; i < size; i++) {
        board[i] = items[i];
        board[i + size] = items[i];
    }
    //shuffle the board randomly
    shuffle(board, size * 2);
    int current[size * 2];
    //initialize all elements of current to 0
    for(int i = 0; i < size * 2; i++) {
        current[i] = 0;
    }
    int matches = 0;
    int choice1, choice2;
    //game loop
    while(matches < size) {
        //print the board
        for(int i = 0; i < size * 2; i++) {
            if(current[i]) {
                printf("%c ", board[i]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
        //get the first choice from the player
        printf("Choose a card: ");
        scanf("%d", &choice1);
        //check if the selected card is valid and unmatched
        if(choice1 < 0 || choice1 >= size * 2 || current[choice1]) {
            printf("Invalid choice!\n");
            continue;
        }
        //reveal the selected card
        current[choice1] = 1;
        //print the updated board
        for(int i = 0; i < size * 2; i++) {
            if(current[i]) {
                printf("%c ", board[i]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
        //get the second choice from the player
        printf("Choose another card: ");
        scanf("%d", &choice2);
        //check if the selected card is valid and unmatched
        if(choice2 < 0 || choice2 >= size * 2 || current[choice2]) {
            printf("Invalid choice!\n");
            //hide the first card again
            current[choice1] = 0;
            continue;
        }
        //reveal the selected card
        current[choice2] = 1;
        //print the updated board
        for(int i = 0; i < size * 2; i++) {
            if(current[i]) {
                printf("%c ", board[i]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
        //check if the two selected cards match
        if(board[choice1] == board[choice2]) {
            printf("Match found!\n");
            matches++;
            //reset the choices to 0 to prevent the player from selecting them again
            choice1 = 0;
            choice2 = 0;
        } else {
            printf("No match found!\n");
            //hide the selected cards again
            current[choice1] = 0;
            current[choice2] = 0;
        }
    }
    printf("Congratulations! You have matched all pairs!\n");
    return 0;
}