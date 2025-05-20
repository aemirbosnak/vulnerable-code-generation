//FormAI DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Function to convert decimal to binary
int* decimalToBinary(int decimalNumber, int binaryNumber[]){
    int index = 0;
    while(decimalNumber > 0){
        binaryNumber[index] = decimalNumber%2;
        decimalNumber = decimalNumber/2;
        index++;
    }
    binaryNumber[index] = -1;   //Marking the end of the array
    return binaryNumber;
}

//Function to print the converted binary array
void printBinaryArray(int binaryNumber[]){
    for(int i=0; binaryNumber[i]!=-1; i++){
        printf("%d", binaryNumber[i]);
    }
}

int main(){
    int decimalNumber, choice;
    int binaryNumber[32];   //Array to hold binary digits with maximum length of 32 bits

    printf("Welcome to Binary Converter game!\n\n");
    printf("This is a multiplayer game, where players take turns to enter a decimal number and the program will convert it into binary.\n");
    printf("The game will continue until one of the players enters -1 as input.\n\n");

    while(1){
        printf("Enter 1 if you want to be the first player or enter 2 if you want to be the second player: ");
        scanf("%d", &choice);

        if(choice != 1 && choice != 2){   //If input is not 1 or 2, prompt user to enter again
            printf("Invalid input! Please enter either 1 or 2.\n");
        } else {
            break;
        }
    }

    while(1){
        printf("\nPlayer %d, enter a decimal number (or -1 to quit game): ", choice);
        scanf("%d", &decimalNumber);

        if(decimalNumber == -1){   //If player enters -1, game ends
            printf("\nGame over! Thanks for playing.\n\n");
            break;
        }

        //Printing the binary equivalent of the entered decimal number
        printf("The binary equivalent of %d is: ", decimalNumber);
        printBinaryArray(decimalToBinary(decimalNumber, binaryNumber));
        printf("\n");

        //Switching players
        if(choice == 1){
            choice = 2;
        } else {
            choice = 1;
        }
    }

    return 0;
}