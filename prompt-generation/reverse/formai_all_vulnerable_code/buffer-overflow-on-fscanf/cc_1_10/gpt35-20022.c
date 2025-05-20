//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    char str[100], temp[100], try_again;
    int i, j, len, number_of_words = 0, correct_words = 0, incorrect_words = 0;
    clock_t start_time, end_time;
    double time_taken;
    
    // Welcome Message and user instructions
    printf("\t\t\t\tC TYPING SPEED TEST\n\n");
    printf("Instructions:\n");
    printf("- Type the words as quickly and accurately as possible.\n");
    printf("- Press Enter after each word.\n");
    printf("- Type 'Q' to Quit.\n\n");

    do 
    {
        // Read in words from the file and count them
        FILE *fptr;
        fptr = fopen("words.txt", "r");
        if (fptr == NULL) 
        {
            printf("Error! Could not open the file.");
            exit(1);
        }
        while(fscanf(fptr, "%s", temp) != EOF)
        {
            number_of_words++;
        }
        fclose(fptr);

        // Generate a random number and select a word from the file
        srand(time(NULL));
        int random_number = rand() % number_of_words;
        int count = 0;
        fptr = fopen("words.txt", "r");
        while(fscanf(fptr, "%s", str) != EOF)
        {
            if (count == random_number)
            {
                break;
            }
            count++;
        }
        fclose(fptr);

        // Record the starting time and print the word
        printf("Type this word: %s\n", str);
        start_time = clock();

        // Read in the user's input
        scanf("%s", temp);

        // Calculate the time taken and the length of the word
        end_time = clock();
        time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        len = strlen(str);

        // Count the number of correct and incorrect words
        for (i = 0; i < len; i++)
        {
            if (temp[i] != str[i])
            {
                incorrect_words++;
                break;
            }
        }

        if (i == len)
        {
            correct_words++;
        }

        // Check if the user wants to try again or quit
        printf("Time taken: %.2fs\n", time_taken);
        printf("Correct words: %d\n", correct_words);
        printf("Incorrect words: %d\n", incorrect_words);
        printf("Enter 'Y' to Try Again or 'Q' to Quit: ");
        scanf(" %c", &try_again);

        // Reset the counters if the user wants to try again
        if (try_again == 'Y')
        {
            number_of_words = 0;
            correct_words = 0;
            incorrect_words = 0;
        }
    } while (try_again != 'Q');

    printf("\n\nThank you for participating in the C Typing Speed Test!\n");
    printf("Your final scores are:\n");
    printf("Correct words: %d\n", correct_words);
    printf("Incorrect words: %d\n", incorrect_words);
    printf("Program ended.\n");

    return 0;
}