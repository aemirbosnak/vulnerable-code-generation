//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main() {
    printf("Welcome to the Typing Speed Test. In this test, you need to type out a Sherlock Holmes story as fast as you can without making any errors.\n");
    printf("\nThe story you need to type is:\n\n");

    //Sherlock Holmes story
    char sherlock[] = "It was in the year ‘95 that a combination of events, into which I need not enter, caused Mr. Sherlock Holmes and myself to spend some weeks in one of our great university towns, and it was during this time that the small but instructive adventure which I am about to relate befell us. It will be obvious that any details which would help the reader to exactly identify the college or the criminal would be injudicious and offensive. So painful a scandal may well be allowed to die out. With due discretion, however, it might be communicated to the proper authorities, and smoked out, so to speak, for the benefit of the world.";
    
    printf("%s\n", sherlock); //print the story for the user to read

    printf("\nWhen you are ready, start typing the story in the box below. Please make sure that you do not make any errors.\n\n"); 

    //set up variables
    int wrong = 0;
    int correct = 0;
    int i = 0;
    char player_input[1024];

    //start timer
    double time_spent = 0.0;
    clock_t begin = clock();

    //get player input
    fgets(player_input, 1024, stdin);

    //remove newline from input
    player_input[strcspn(player_input, "\n")] = 0;

    //loop through each character of input and compare to story
    while (player_input[i] != '\0') {
        if (player_input[i] == sherlock[i]) {
            correct++;
        } else {
            wrong++;
        }
        i++;
    }

    //calculate accuracy
    double accuracy = (double)correct / (double)(correct+wrong) * 100;

    //stop timer and calculate time taken
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    //print results
    printf("\nYou took %.2lf seconds to type the story.\n", time_spent);
    printf("You made %d errors.\n", wrong);
    printf("Your accuracy was %.2lf%%.\n", accuracy);

    //determine WPM
    double wpm = (double)(strlen(player_input) / 5) / (time_spent / 60);
    printf("Your typing speed was %.2lf words per minute.\n", wpm);

    return 0;
}