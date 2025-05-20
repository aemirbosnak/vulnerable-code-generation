//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() 
{
    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can travel to different eras, but be careful not to change history.\n");

    int era_choice;
    do {
        printf("Which era would you like to travel to?\n");
        printf("1. Ancient Egypt\n");
        printf("2. Medieval Europe\n");
        printf("3. Wild West America\n");
        printf("4. Futuristic World\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &era_choice);
    } while (era_choice < 1 || era_choice > 4);

    switch (era_choice) {
        case 1:
            printf("Welcome to Ancient Egypt!\n");
            printf("You see the Great Pyramid of Giza in the distance.\n");
            printf("As you walk towards it, you see a group of workers building it.\n");
            printf("You decide to help them out.\n");

            // shape shifting into worker
            printf("You use your time traveling powers to shape shift into a worker.\n");
            printf("Now you blend in with the others and start working on the pyramid.\n");

            // random event
            int event1 = rand() % 3;
            if (event1 == 0) {
                printf("A sandstorm hits the workers, but luckily you were able to find shelter.\n");
            }
            else if (event1 == 1) {
                printf("A group of raiders attack, but you and the workers fend them off.\n");
            }
            else if (event1 == 2) {
                printf("You discover a secret tunnel inside the pyramid, but you make sure not to explore it too much.\n");
            }
            break;

        case 2:
            printf("Welcome to Medieval Europe!\n");
            printf("You see a castle in the distance, but there are knights guarding the entrance.\n");

            // shape shifting into princess
            printf("You use your time traveling powers to shape shift into a princess.\n");
            printf("Now you can enter the castle without suspicion.\n");

            // random event
            int event2 = rand() % 3;
            if (event2 == 0) {
                printf("You meet a handsome prince, but you make sure not to let him fall in love with you.\n");
            }
            else if (event2 == 1) {
                printf("You witness a jousting tournament, but you make sure not to show too much enthusiasm.\n");
            }
            else if (event2 == 2) {
                printf("You discover a secret room inside the castle, but you make sure not to disturb anything.\n");
            }
            break;

        case 3:
            printf("Welcome to Wild West America!\n");
            printf("You see a saloon in the distance, but there are cowboys standing guard outside.\n");
            
            // shape shifting into cowboy
            printf("You use your time traveling powers to shape shift into a cowboy.\n");
            printf("Now you can enter the saloon without suspicion.\n");
             
            // random event
            int event3 = rand() % 3;
            if (event3 == 0) {
                printf("You witness a showdown between two cowboys, but you make sure not to interfere.\n");
            }
            else if (event3 == 1) {
                printf("You gamble in a card game, but you make sure not to cheat.\n");
            }
            else if (event3 == 2) {
                printf("You discover a wanted poster with your own face on it, but you make sure to avoid the law.\n");
            }
            break;

        case 4:
            printf("Welcome to the Futuristic World!\n");
            printf("You see a space station in the distance, but there are robots guarding the entrance.\n");
            
            // shape shifting into cyborg
            printf("You use your time traveling powers to shape shift into a cyborg.\n");
            printf("Now you can enter the space station without suspicion.\n");

            // random event
            int event4 = rand() % 3;
            if (event4 == 0) {
                printf("You witness a space battle, but you make sure not to get involved.\n");
            }
            else if (event4 == 1) {
                printf("You travel to a distant planet, but you make sure to leave nothing but footprints.\n");
            }
            else if (event4 == 2) {
                printf("You discover an advanced technology, but you make sure not to take it with you.\n");
            }
            break;
    }

    printf("Thanks for playing the Time Travel Simulator!\n");
    return 0;
}