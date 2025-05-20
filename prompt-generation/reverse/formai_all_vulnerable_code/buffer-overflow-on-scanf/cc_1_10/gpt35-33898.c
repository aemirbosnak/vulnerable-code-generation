//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("Welcome to the C Typing Speed Test!\n");
    printf("We will test your typing speed by asking you to type a particular phrase as quickly and accurately as possible.\n");
    printf("Are you ready to begin?\n\nEnter 'Y' for YES or 'N' for NO: ");

    char start;
    scanf("%c", &start);

    if(start == 'Y' || start == 'y'){
        srand(time(NULL));
        char phrases[10][100] = {
            "The quick brown fox jumps over the lazy dog.",
            "Jackdaws love my big sphinx of quartz.",
            "How vexingly quick daft zebras jump!",
            "The five boxing wizards jump quickly.",
            "Quartz pyramids vex fiendish wizards.",
            "Pack my box with five dozen liquor jugs.",
            "The lazy major was fixing Cupid's broken quiver.",
            "A quick brown fox jumps over the lazy dog.",
            "Waltz, bad nymph, for quick jigs vex!",
            "Blowzy night-fruits vex'd Jack Q."
        };

        int random_num = rand() % 10;
        char phrase[100];

        for(int i=0; i<100; i++){
            phrase[i] = phrases[random_num][i];
        }

        printf("\n\nType the following phrase as quickly and accurately as possible, and press ENTER when finished:\n%s\n", phrase);

        clock_t start_time = clock();

        char user_input[100];
        scanf("%[^\n]", user_input);

        clock_t end_time = clock();

        double time_taken = (double)(end_time - start_time)/CLOCKS_PER_SEC;

        int correct_chars = 0;
        for(int i=0; i<100; i++){
            if(user_input[i] == phrase[i]){
                correct_chars++;
            }
        }

        double wpm = (double)correct_chars/5 / time_taken;
        printf("\n\nResult:\n");
        printf("Time taken: %.2f seconds\n", time_taken);
        printf("Words per minute: %.2f\n", wpm);

    }
    else{
        printf("Okay, maybe next time! Goodbye!");
    }

    return 0;
}