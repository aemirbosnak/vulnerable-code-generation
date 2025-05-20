//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void give_fortune();

int main(){

    printf("Welcome to the Automated Fortune Teller\n");
    printf("Think of a question and I will give you an answer\n");
    printf("Press 'q' to quit\n");

    char answer;

    while(1){
        printf("What is your question?\n");
        scanf("%c",&answer);

        if(answer == 'q'){
            printf("Exiting program\n");
            break;
        }
        else{
            srand(time(0)); //for random number generation
            give_fortune();
        }
    }

    return 0;
}

void give_fortune(){

    int rand_num = rand() % 10; //generate a random number from 0-9
    char *fortune;

    switch(rand_num){
        case 0:
            fortune = "It is certain";
            break;
        case 1:
            fortune = "It is decidedly so";
            break;
        case 2:
            fortune = "Without a doubt";
            break;
        case 3:
            fortune = "Yes, definitely";
            break;
        case 4:
            fortune = "You may rely on it";
            break;
        case 5:
            fortune = "As I see it, yes";
            break;
        case 6:
            fortune = "Most likely";
            break;
        case 7:
            fortune = "Outlook good";
            break;
        case 8:
            fortune = "Yes";
            break;
        case 9:
            fortune = "Signs point to yes";
            break;
        default:
            fortune = "Cannot predict now";
            break;

    }

    printf("Your fortune is: %s\n", fortune);

}