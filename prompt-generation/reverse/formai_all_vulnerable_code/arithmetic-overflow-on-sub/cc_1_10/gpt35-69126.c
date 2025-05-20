//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

int main()
{
    printf("Welcome to the C Typing Speed Test!\n\n");
    printf("You will be provided with a random sentence to type, and we will time how fast you can type it.\n");
    printf("Are you ready? Press ENTER to start.\n\n");
    getchar();

    const char* sentences[] = {"The quick brown fox jumps over the lazy dog.", "Programming is fun and challenging.", 
                                "The sky is blue and the grass is green.", "C is my favorite programming language.",
                                "I am learning how to code at OpenAI.", "Computers are amazing machines.", 
                                "The best way to learn is by doing.", "Practice makes perfect!"};
    // Array of sentences for user to type
    
    srand(time(NULL)); // Seed time for random sentence selection
    int random_index = rand() % 8; // Select random sentence

    printf("Type this sentence: \n\n%s\n\n", sentences[random_index]);

    clock_t start_time = clock(); // Start timer

    char user_input[200];
    fgets(user_input, sizeof(user_input), stdin); // Get input from user

    clock_t end_time = clock(); // End timer

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC; // Time taken to type

    int accuracy = 0;
    int errors = 0;

    for(int i = 0; i < strlen(user_input); i++)
    {
        if(isalpha(sentences[random_index][i])) // Check if character is alphabetical
        {
            if(tolower(user_input[i]) == tolower(sentences[random_index][i])) // Check if alphabets match ignoring case
                accuracy++; // If yes, increment accuracy
            else
                errors++; // If not, increment errors
        }
    }

    int words_typed = 1;

    for(int i = 0; i < strlen(user_input); i++)
    {
        if(user_input[i] == ' ')
            words_typed++;
    }

    printf("\nAccuracy: %d/%d\n", accuracy, strlen(sentences[random_index])); // Print accuracy
    printf("Errors: %d\n", errors); // Print errors
    printf("Words per minute: %.0f\n", (words_typed / time_taken) * 60); // Print words per minute

    return 0;
}