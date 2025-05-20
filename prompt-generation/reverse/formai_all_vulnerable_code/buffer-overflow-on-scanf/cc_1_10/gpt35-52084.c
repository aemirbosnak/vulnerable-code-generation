//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printConspiracyTheory(){
    int num = rand() % 10;
    switch(num){
        case 0:
            printf("The moon landing was faked!\n");
            break;
        case 1:
            printf("The government is controlling the weather!\n");
            break;
        case 2:
            printf("Area 51 is hiding alien technology!\n");
            break;
        case 3:
            printf("The Titanic never actually sank!\n");
            break;
        case 4:
            printf("The Illuminati is secretly controlling the world!\n");
            break;
        case 5:
            printf("The Beatles never actually existed!\n");
            break;
        case 6:
            printf("The CIA killed JFK!\n");
            break;
        case 7:
            printf("9/11 was an inside job!\n");
            break;
        case 8:
            printf("Fluoride in our water is making us docile!\n");
            break;
        case 9:
            printf("The earth is flat!\n");
            break;
        default:
            printf("They're watching us!\n");
            break;
    }
}

int main(){
    srand(time(NULL));
    printf("Welcome to the random conspiracy theory generator!\n");
    printf("Press enter to generate a new theory or q to quit.\n\n");

    char input;
    do{
        scanf("%c", &input);
        if(input != 'q'){
            printConspiracyTheory();
        }
    } while(input != 'q');

    printf("\nThank you for using our generator. Remember, the truth is out there!\n");
    return 0;
}