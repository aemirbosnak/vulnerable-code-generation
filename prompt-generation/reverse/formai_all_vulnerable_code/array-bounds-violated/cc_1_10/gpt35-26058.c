//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Function to generate random sentences
char* generate_sentence(){
    char* sentences[10] = {"The quick brown fox jumps over the lazy dog",
                            "Jackdaws love my big sphinx of quartz",
                            "How vexingly quick daft zebras jump!",
                            "Pack my box with five dozen liquor jugs",
                            "We promptly judged antique ivory buckles for the next prize",
                            "My ex pub quiz crowd gave joyful thanks",
                            "The five boxing wizards jump quickly",
                            "Waltz, bad nymph, for quick jigs vex",
                            "Amazingly few discotheques provide jukeboxes"};
    int index = rand() % 9;
    return sentences[index];
}

int main(){
    int i;
    char input[100];
    int correct_count = 0;
    int mistake_count = 0;
    time_t start_time, end_time;
    double time_taken;

    printf("Welcome to Typing Speed Test\n");
    printf("You will be given a random sentence to type\n");
    printf("Type the sentence and press enter to check your speed\n");
    printf("Ready? Press enter to start\n");

    // User presses Enter to start the test
    getchar();

    // Generating random sentence
    char* sentence = generate_sentence();
    printf("\n%s\n", sentence);

    // Start timer
    time(&start_time);
    
    // Reading input from user
    fgets(input, 100, stdin);

    // Stripping newline character from input
    input[strlen(input) - 1] = '\0'; 

    // Calculating time taken
    time(&end_time);
    time_taken = difftime(end_time, start_time);

    // Counting correct and incorrect characters
    for(i=0; i<strlen(input); i++){
        if(input[i] == sentence[i]){
            correct_count++;
        }
        else{
            mistake_count++;
        }
    }

    // Printing results
    printf("\n\nTime taken: %.2f seconds\n", time_taken);
    printf("Correct characters: %d\n", correct_count);
    printf("Mistakes: %d\n", mistake_count);

    return 0;
}