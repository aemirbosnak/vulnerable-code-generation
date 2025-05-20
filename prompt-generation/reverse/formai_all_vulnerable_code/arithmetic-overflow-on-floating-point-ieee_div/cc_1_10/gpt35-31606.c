//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random sentence
char* generate_sentence()
{
    char *sentence[] = {"The quick brown fox jumps over the lazy dog.", "Jackdaws love my big sphinx of quartz.", "How vexingly quick daft zebras jump!", "Fix problem quickly with galvanized jets.", "My ex pub quiz crowd gave joyful thanks.", "The five boxing wizards jump quickly."};
    int size = sizeof(sentence)/sizeof(sentence[0]);
    srand(time(NULL));
    int index = rand() % size;
    return sentence[index];
}

// Function to calculate and return the time taken to finish typing
double calculate_time(clock_t start_time, clock_t end_time)
{
    double time_taken = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC;
    return time_taken;
}

int main()
{
    printf("Welcome to the C Typing Speed Test!\n");
    printf("Type the following sentence as fast and accurately as you can:\n\n");
    char *sentence = generate_sentence();
    printf("%s\n", sentence);

    char typed_sentence[100];
    scanf("%[^\n]%*c", typed_sentence);
    printf("\n");

    // Comparing the two sentences character by character
    int i,j, errors=0;
    for (i = 0, j = 0; typed_sentence[i] != '\0' && sentence[j] != '\0'; i++, j++)
    {
        if (typed_sentence[i] != sentence[j])
            errors++;
    }
	
    if (strlen(typed_sentence) < strlen(sentence))
        errors += (strlen(sentence) - strlen(typed_sentence));

    //Calculating the score
    double time_taken = calculate_time(clock(), clock());
    int score = (int)(((double)strlen(sentence) * 60)/(5 * time_taken));
    printf("You typed the sentence in %.2f seconds\n", time_taken);
    printf("Typing Speed: %d WPM\n", score);
    printf("Errors: %d\n", errors);
    if (errors == 0)
        printf("Congratulations, you typed the sentence perfectly!\n");
    else
        printf("Keep practicing to improve your typing speed and accuracy!\n");
    return 0;
}